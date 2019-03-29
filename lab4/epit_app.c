#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_DIGIT 4
#define MAX_BUTTON 9

int dev_pid;
int counter=0;
int flag=0;
int flag2=0;
unsigned char data[4] = {0,0,0,0};
int dev;
int dev1;
int dev2;

void usrsignal(int sig)
{
	if(flag==1){
		counter = counter;
		data[0]=data[0];data[1]=data[1];data[2]=data[2];data[3]=data[3];
		write(dev2,&data,4);
		read(dev2,&data,4);
	}
	
	else if(flag==0){
		if(flag2==0){
			counter++;
			if (counter >= 1)
			{
				data[3]++;
				if ((data[3] % 10) == 0)
				{
					data[2]++;
					data[3] = 0;
					if((data[2]%10)==0)
					{
						data[1]++;
						data[2]=0;
						if ((data[1] % 10) == 0)
						{
							data[0]++;
							data[1] = 0;
							if((data[0]%6)==0)
							{
								data[0] = 0;
								counter = 0;
							}
						}
					}
				}
				printf("%d %d %d %d\n", data[0], data[1], data[2], data[3]);
				write(dev2,&data,4);
				read(dev2,&data,4);
			}
		}
		else if(flag2==1){
			counter = 0;
			data[0]=0;data[1]=0;data[2]=0;data[3]=0;
			write(dev2,&data,4);
			read(dev2,&data,4);
		}
	}
}


void* display()
{
	int fd;
	char buf[10] = {0};

	(void)signal(SIGUSR1, usrsignal);

	fd = open("/dev/epit", O_RDWR);
	dev2 = open("/dev/fpga_fnd", O_RDWR);
	
	dev_pid=getpid();
	buf[0] = 0xff & dev_pid;
	buf[1] = 0xff & (dev_pid >> 8);
	write(fd,buf,sizeof(dev_pid));
	
	sleep(2);
	while (1)
	{
		usleep(10000);
	}

	close(fd);
	close(dev2);
}

void* button()
{
	int buff_size;

	unsigned char push_sw_buff[MAX_BUTTON];

	dev = open("/dev/fpga_push_switch", O_RDWR);
	buff_size=sizeof(push_sw_buff);

	while(1){
		usleep(1000);
		read(dev, &push_sw_buff, buff_size);

		if(push_sw_buff[0] == 1){
			flag = 1;
		}
		else if(push_sw_buff[1] == 1){
			flag = 1;
		}
		else if(push_sw_buff[2] == 1){
			flag = 1;
		}
		else if(push_sw_buff[3] == 1){
			flag = 1;
		}
		else if(push_sw_buff[4] == 1){
			flag = 1;
		}
		else if(push_sw_buff[5] == 1){
			flag = 1;
		}
		else if(push_sw_buff[6] == 1){
			flag = 1;
		}
		else if(flag==0 && push_sw_buff[7] == 1){
			flag = 1;
		}
		else if(push_sw_buff[8] == 1){
			flag2 = 1;
		}
		else{
			if(flag==1 && push_sw_buff[7] == 1){
				flag = 0;
				usleep(20000);
			}
		}
		

		usleep(1000);

		if(flag2==1 && push_sw_buff[0]==1){
			flag2 = 0;
		}
		else if(flag2==1 && push_sw_buff[1]==1){
			flag2 = 0;
		}
		else if(flag2==1 && push_sw_buff[2]==1){
			flag2 = 0;
		}
		else if(flag2==1 && push_sw_buff[3]==1){
			flag2 = 0;
		}
		else if(flag2==1 && push_sw_buff[4]==1){
			flag2 = 0;
		}
		else if(flag2==1 && push_sw_buff[5]==1){
			flag2 = 0;
		}
		else if(flag2==1 && push_sw_buff[6]==1){
			flag2 = 0;
		}
		else if(flag2==1 && push_sw_buff[7]==1){
			flag2 = 0;
		}

		usleep(1000);
	}

	close(dev);
}

void main()
{
	int a,b;
	int i;
	int buff_size;
	char c[10] = {0};
	unsigned char push_sw_buff[MAX_BUTTON];
	
	dev = open("/dev/fpga_push_switch", O_RDWR);
	dev1 = open("/dev/fpga_fnd", O_RDWR);
	buff_size=sizeof(push_sw_buff);

	while(1){
		usleep(400000);
		read(dev, &push_sw_buff, buff_size);
		write(dev1,&data,4);
		read(dev1,&data,4);

		if(push_sw_buff[0] == 1){break;}
		else if(push_sw_buff[1] == 1){break;}
		else if(push_sw_buff[2] == 1){break;}
		else if(push_sw_buff[3] == 1){break;}
		else if(push_sw_buff[4] == 1){break;}
		else if(push_sw_buff[5] == 1){break;}
		else if(push_sw_buff[6] == 1){break;}
		else if(push_sw_buff[7] == 1){break;}
		else if(push_sw_buff[8] == 1){break;}
	}

	close(dev);
	close(dev1);

	pthread_t t1,t2;
	while(1){
		pthread_create(&t2,NULL,display,NULL);
		pthread_create(&t1,NULL,button,NULL);
		pthread_join(t1,NULL);
		pthread_join(t2,NULL);
	}
}
