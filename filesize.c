#include<stdio.h>
#include<sys/stat.h>

int main()
{
	struct stat infobuf;
	if( stat("/etc/passwd", &infobuf ))	
		perror("/etc/passwd");
	else
	{
		printf("The size of /etc/pasawd is %d\n", infobuf.st_size);		

	}	

	return 0;
}



