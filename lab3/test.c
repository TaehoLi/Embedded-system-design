#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUFF 32
#define LINE_BUFF 16
#define FPGA_TEXT_LCD_DEVICE "/dev/fpga_text_lcd"

char name[20];

void* get_str()
{
	printf("Whats your string? : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = 0;
}

void* show_lcd(int argc, char **argv)
{
	int i;
	int dev;
	int str_size;
	int chk_size;
	
	unsigned char string[32];
	memset(string,0,sizeof(string));
	//memset(name,0,sizeof(name));

	if(argc<2&&argc>3) {
		printf("Invalid Value Arguments!\n");
		return -1;
	}		

	if(strlen(argv[1])>LINE_BUFF||strlen(argv[2])>LINE_BUFF)
	{
		printf("16 alphanumeric characters on a line!\n");
		return -1;
	}
	
	dev = open(FPGA_TEXT_LCD_DEVICE, O_WRONLY);
	if (dev<0) {
		printf("Device open error : %s\n",FPGA_TEXT_LCD_DEVICE);
		return -1;
	}

	str_size=strlen(argv[1]);
	if(str_size>0) {
		strncat(string,argv[1],str_size);
		memset(string+str_size,' ',LINE_BUFF-str_size);
	}

	str_size=strlen(argv[2]);
	if(str_size>0) {
		strncat(string,argv[2],str_size);
		memset(string+LINE_BUFF+str_size,' ',LINE_BUFF-str_size);
	}

	write(dev,string,MAX_BUFF);	
	
	close(dev);

	//printf("LCD on : %s", name);
	printf("\n");
}

void main()
{
	pthread_t t1,t2;
	while(1)
	{
		pthread_create(&t1,NULL,get_str,NULL);
		pthread_join(t1,NULL);
		pthread_create(&t2,NULL,show_lcd,NULL);
		pthread_join(t2,NULL);
	};
}


