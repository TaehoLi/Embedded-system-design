/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: CanButtonTest 
	Configuration 	: MontaVista
	Model Element	: can_interface
//!	Generated Date	: Wed, 05, Jun 2019  
	File Path	: CanButtonTest/MontaVista/can_interface.cpp
*********************************************************************/

/* A simple SocketCAN example */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <signal.h>  
//#include <sys/types.h>
#include <unistd.h>

int soc;
int read_can_port;
int dev_pid=0;
struct can_frame frame_rx;    
struct can_frame frame_tx; 
extern void CanReceiveIsr(void); 
extern unsigned char download_data_buf[8];


void usrsignal(int sig)
{   
	read(soc, &frame_rx, sizeof(struct can_frame)); 
	for(int i=0;i<8;i++) download_data_buf[i]=frame_rx.data[i];
	
	CanReceiveIsr();
}
int open_port(const char *port)
{
    struct ifreq ifr;
    struct sockaddr_can addr;
    /* open socket */
    soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(soc < 0)
    {
        return (-1);
    }
    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, port);
    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0)
    {
        return (-1);
    }
    addr.can_ifindex = ifr.ifr_ifindex;
    fcntl(soc, F_SETFL, O_NONBLOCK);
    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        return (-1);
    }
    return 0;
}  
int send_can_frame(int id, unsigned char *data)
{
    int retval;   
    frame_tx.can_id=id; 
    for(int i=0;i<8;i++) frame_tx.data[i]=data[i];
	frame_tx.can_dlc=8;
	retval = write(soc, &frame_tx, sizeof(struct can_frame));
    if (retval != sizeof(struct can_frame))
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}
int send_port(struct can_frame *frame)
{
    int retval;
   retval = write(soc, frame, sizeof(struct can_frame));
    if (retval != sizeof(struct can_frame))
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}
/* this is just an example, run in a thread */
void read_port()
{
    struct can_frame frame_rd;
    int recvbytes = 0;
    read_can_port = 1;
    while(read_can_port)
    {
        struct timeval timeout = {1, 0};
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(soc, &readSet);
        if (select((soc + 1), &readSet, NULL, NULL, &timeout) >= 0)
        {
            if (!read_can_port)
            {
                break;
            }
            if (FD_ISSET(soc, &readSet))
            {
                recvbytes = read(soc, &frame_rd, sizeof(struct can_frame));
                if(recvbytes)
                {
                    printf("dlc = %d, id = %d, data[0] = %d\n", frame_rd.can_dlc, frame_rd.can_id, frame_rd.data[0]);
                }
            }
        }
    }
}
int close_port()
{
    close(soc);
    return 0;
}
int can_init(void)
{


	(void)signal(SIGUSR1, usrsignal);
	dev_pid=getpid();
	printf("dev_pid=%d\n", dev_pid);

    open_port("can0");
	frame_tx.can_id=1;
	frame_tx.data[0]=0x12;
	frame_tx.data[1]=0x34;
	frame_tx.can_dlc=8;
	frame_tx.pid = dev_pid;
	send_port(&frame_tx);
//while(1);
    //read_port();
    return 0;
}
/*********************************************************************
	File Path	: CanButtonTest/MontaVista/can_interface.cpp
*********************************************************************/
