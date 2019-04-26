/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: ButtonInterface
//!	Generated Date	: Fri, 26, Apr 2019  
	File Path	: StopwatchTest/MontaVista/ButtonInterface.cpp
*********************************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>
#include <signal.h>

#define MAX_BUTTON 9
int dev_switch;
int buff_size;
unsigned char push_sw_buff[MAX_BUTTON];

int initButton(void)
{
	dev_switch = open("/dev/fpga_push_switch", O_RDWR);
	if (dev_switch<0){
		printf("Device Open Error\n");
		close(dev_switch);
		return -1;
	}  
}

unsigned char readPushSwitch(void)
{
	buff_size=sizeof(push_sw_buff);
    read(dev_switch, &push_sw_buff, buff_size);
    //printf("%d,%d,%d", push_sw_buff[6], push_sw_buff[7], push_sw_buff[8]);
    //printf("\n");
    return push_sw_buff[6]| push_sw_buff[7] | push_sw_buff[8];
}

/*********************************************************************
	File Path	: StopwatchTest/MontaVista/ButtonInterface.cpp
*********************************************************************/
