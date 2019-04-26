/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: SevenSegmentInterface
//!	Generated Date	: Fri, 26, Apr 2019  
	File Path	: StopwatchTest/MontaVista/SevenSegmentInterface.cpp
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_DIGIT 4
#define FND_DEVICE "/dev/fpga_fnd"

int dev;
unsigned char data[4];

int initSevenSegment(void)
{
	dev = open(FND_DEVICE, O_RDWR);
	if (dev<0) {
		printf("Device open error : %s\n",FND_DEVICE);
		exit(1);
	}
}

void displaySevenSegment(int min, int sec)
{
	data[0]=min/10;
	data[1]=min%10;
	data[2]=sec/10;
	data[3]=sec%10;
	write(dev,&data,4);
}
/*********************************************************************
	File Path	: StopwatchTest/MontaVista/SevenSegmentInterface.cpp
*********************************************************************/
