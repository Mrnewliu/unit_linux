#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

void show_info(char [],struct stat *info);


int main(int argc,char* argv[])
{
	struct stat info;
	if(argc > 1)
	{
		if( stat(argv[1], &info ) != -1 )
		{
			show_info( argv[1], &info );
		}
		else
			perror(argv[1]);
	}	
	
	return 0;
}


void show_info(char filename[],struct stat *info)
{
	long time;
	printf(" mode:%o\n",  info->st_mode);
	printf(" links:%d\n", info->st_nlink);
	printf(" user: %d\n", info->st_uid);
	printf(" group:%d\n", info->st_gid);
	printf(" size:%d\n",  info->st_size);
	printf(" modtime:%s",ctime( & info->st_ctim.tv_sec ));
	printf(" name:%s\n",filename);
}


