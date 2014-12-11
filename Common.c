#include "Option.h"

void Location(unsigned x, unsigned y)
{
	if(y>0)
	{
		while(y--) printf("\n");
	}
	if(x>0)
	{
		while(x--) printf(" ");
	}	
}

void Cover_row()
{
	unsigned x;
	printf("\r");
	x = X_VALUE-1;
	while(x--)printf(" ");
	printf("\r");
}


