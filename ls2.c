#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>
#include<string.h>
#include<grp.h>

void do_ls(char[] );

void dostat(char* filename);

void show_file_info(char* filename,struct stat* buf);

void mode_to_letters(int mode, char str[]);

char* uid_to_name( uid_t uid );

char* gid_to_name( gid_t gid );



int main(int argc,char* argv[])
{
	if( argc == 1)
	{
		//printf("only one\n");
		do_ls(".");		
	}	
	else
	{
		while( --argc )
		{
			printf("%s:\n", * ++argv);
			do_ls( *argv);
		}
	}

	return 0;
}


void do_ls(char dirname[])
{
	DIR *dir_ptr;
	struct dirent* direntp;
	if( (dir_ptr = opendir(dirname)) == NULL )
	{
		fprintf(stderr, "ls1: cannot open %s\n",dirname);
	}
	else
	{
		while( (direntp = readdir(dir_ptr)) != NULL)
		{
			//printf("%s \n", direntp->d_name);
			dostat(direntp->d_name);
		}
		closedir(dir_ptr);
	}
	
}


void dostat(char* filename)
{
	struct stat buf;
	if( stat( filename, &buf) == -1)
	{
		perror(filename);
	}
	else
	{
		show_file_info(filename, &buf );
	}
			
}

void show_file_info(char* filename,struct stat* buf)
{
	char modestr[11];
	//printf("mode:%o ",buf->st_mode);
	printf("%4d ", buf->st_nlink);
	printf("%-8s ", uid_to_name(buf->st_uid));
	printf("%-8s ", gid_to_name(buf->st_gid));
	printf("%8ld ", (long)buf->st_size);
	//printf(" modtime:%s",ctime( & buf->st_ctim.tv_sec ));
	printf(" name:%8s ",filename);
	printf(" modtime:%s",4+ctime( & buf->st_ctim.tv_sec ));

	
}


char* uid_to_name(uid_t uid)
{
	return getpwuid(uid)->pw_name;	
}



char* gid_to_name( gid_t gid )
{
	return getgrgid( gid)->gr_name;
}


void mode_to_letters( int mode, char str[])
{
	strcpy(str,"---------");	
	if( S_ISDIR(mode))
		str[0] = 'd';
	if( S_ISCHR(mode))
		str[0] = 'c';
	if( S_ISBLK(mode))
		str[0] = 'b';
	
	if( mode & S_IRUSR)	
		str[1] = 'r';
	if( mode & S_IWUSR)
		str[2] = 'w';
	if( mode & S_IXUSR)
		str[3] = 'x';
	
	if( mode & S_IRUSR)	
		str[4] = 'r';
	if( mode & S_IWUSR)
		str[5] = 'w';
	if( mode & S_IXUSR)
		str[6] = 'x';


	if( mode & S_IRUSR)	
		str[7] = 'r';
	if( mode & S_IWUSR)
		str[8] = 'w';
	if( mode & S_IXUSR)
		str[9] = 'x';



}





