#include<stdio.h>
#include<pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <mqueue.h>
#include <errno.h>


#define MSG_Q_NAME  "/MSG_Q"
#define NO_MAX_MSG  10
#define MAX_MSG     1024
#define STOP_CMD    "exit"

#define MAX_BUFF 32
#define LINE_BUFF 16
#define FPGA_TEXT_LCD_DEVICE "/dev/fpga_text_lcd"

void* get_str_th(void* data)
{
	do{
		bzero(message, MAX_MSG);
		printf("Send> ");
		fgets(message, sizeof(message), stdin);
		message[strlen(message) - 1] = '\0';
		mq_len = strlen(message);
		if (-1 == mq_send(msg_q, message, mq_len, 0)) {
			perror("mq_send");
			mq_close(msg_q);
			mq_unlink(MSG_Q_NAME);
			_exit(-1);}

	char *str;
	str = (char*)data;
	while (1)
	{
		printf("%s\n", str);
		sleep(1);
	}
}
void* show_LCD_th(void* data)
{
	char *str;
	str = (char*)data;
	while (1)
	{
		printf("%s\n", str);
		sleep(2);
	}
}
void main()
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, get_str_th, "hello from 1");
	pthread_create(&t2, NULL, show_LCD_th, "hello from 2");

	pthread_join(t1, NULL);
}




int main(int agrc, char *argv[]) {
	mqd_t msg_q;
	struct mq_attr attr;
	int mq_len;
	int i;
	const char *message;

	attr.mq_flags = 0;
	attr.mq_maxmsg = NO_MAX_MSG;
	attr.mq_msgsize = MAX_MSG;
	attr.mq_curmsgs = 0;

	msg_q = mq_open(MSG_Q_NAME, O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &attr);
	if (-1 == msg_q) {
		perror("mq_open");
		_exit(-1);
	}
	/*
	printf("Enter \"exit\"  to stop: \n");

	do{
	  bzero(message, MAX_MSG);
	  printf("Send> ");
	  fgets(message,sizeof(message), stdin);
	  message[strlen(message)-1]='\0';
	  mq_len = strlen(message);
	  if ( -1 == mq_send(msg_q, message, mq_len, 0)) {
		perror("mq_send");
		mq_close(msg_q);
		mq_unlink(MSG_Q_NAME);
		_exit(-1);
	  }
	} while (!(0 == strcmp(message, STOP_CMD)));

	printf("mq_writer: Exit\n");
	mq_close(msg_q);
	mq_unlink(MSG_Q_NAME);*/

	message = "Hello World";
	mq_len = strlen(message);
	for (i = 0; i < 5; i++)
	{
		mq_send(msg_q, message, mq_len, 0);
		sleep(1);
	}

	mq_len = 1024;
	mq_send(msg_q, "exit", mq_len, 0);
	mq_close(msg_q);
	mq_unlink(MSG_Q_NAME);
	_exit(-1);

	return 0;
}












int main(int argc, char **argv)
{
	int i;
	int dev;
	int str_size;
	int chk_size;
	
	unsigned char string[32];

	memset(string,0,sizeof(string));	

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
	
	return(0);
}
