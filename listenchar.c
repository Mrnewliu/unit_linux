#include<stdio.h>

int main()
{
	int c ,n = 0;
	while( (c = getchar()) != 'a' )	
	{
		printf("char %3d is %c code %d\n",n++,c,c);
	}
	
	return 0;
}





