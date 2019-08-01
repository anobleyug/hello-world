#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h> 
int main(int argc, char *argv[])
{
	FILE *f;
	char* buffer = 0;
	long length;
	int port = atoi(argv[1]);
	char command[50];
	char port_str[10];
	char *ptr = 0;
    
	if( port == 35000){
		system("netstat -ant | grep '3500[0-9]' >> ./output.txt");
	}

	else if( port == 20)
		system("netstat -ant | grep '2[0-9]' > ./output.txt");

	else if( port == 59900)
		system("netstat -ant | grep '5990[0-9]' > ./output.txt");

	else if( port == 10000)
		system("netstat -ant | grep '1000[0-9]' > ./output.txt");


	f = fopen("./output.txt", "rb");
  		fseek (f, 0, SEEK_END);
  		length = ftell (f);
  		fseek (f, 0, SEEK_SET);
  			buffer = malloc (length);
  			
  			if (buffer)
  			{
    			fread (buffer, 1, length, f);
  			}
  			fclose (f);
		
		for ( int i = 0; i < 10; i++)
		{
			sprintf(port_str, "%d",port); 
			ptr = strstr(buffer, port_str);
		
			if(ptr != NULL)
				printf("Port %d Not Free\n", port);
			else
				printf("Port %d Free\n", port);
			port++;
		}
}
