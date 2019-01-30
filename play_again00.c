#include<stdio.h>
#include<termios.h>


#define Question "Do you want to another trasaction"

int get_response(char* question);


int main()
{
	int rec ;
  	rec = get_response( Question );
	return 0;
}


int get_response(char* question)
{
	int c;
	printf("%s ? y/n\n", question);	
	while(1)
	{
		c = getchar();
		switch(c)
		{
		case 'y':
		case 'Y':
		return 0;
		case 'n':
		case 'N':
		case EOF:
		return 1;
		}
	}
	
}
