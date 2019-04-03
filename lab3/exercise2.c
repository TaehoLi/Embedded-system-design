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

// LCD 두 줄에 들어갈 string1,2 선언
// global variable 이기 때문에 -> thread1,2가 서로 공유할 수 있음
char name[16];
char name2[16];

void* get_str() // 문자열을 두 번 입력받는 함수
{
	printf("Whats your string? : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = 0;
	printf("Next string? : ");
	fgets(name2, sizeof(name), stdin);
	name2[strlen(name2) - 1] = 0;
}
//int argc, char **argv
void* show_lcd() // 받은 문자열을 LCD에 보여주는 함수
{
	
	int i;
	int dev;
	int str_size;
	int chk_size;
	char *ptr;

	unsigned char string[32];
	memset(string,0,sizeof(string));

	
	if(strlen(name)>LINE_BUFF||strlen(name2)>LINE_BUFF)
	{
		printf("16 alphanumeric characters on a line!\n");
	}
	
	dev = open(FPGA_TEXT_LCD_DEVICE, O_WRONLY);
	if (dev<0) {
		printf("Device open error : %s\n",FPGA_TEXT_LCD_DEVICE);
	}

	str_size=strlen(name);
	if(str_size>0) {
		strncat(string,name,str_size);
		memset(string+str_size,' ',LINE_BUFF-str_size);
	}
	
	str_size=strlen(name2);
	if(str_size>0) {
		strncat(string,name2,str_size);
		memset(string+LINE_BUFF+str_size,' ',LINE_BUFF-str_size);
	}
	
	write(dev,string,MAX_BUFF);
	
	close(dev);
	
	printf("LCD top : %s", name);
	printf("\n");
	printf("LCD down : %s", name2);
	printf("\n");
}

void main() // thread1,2 차례로 무한 반복
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
