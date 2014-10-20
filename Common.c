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




//                                                                 old code                                      
/*
Status Recite(List *L)
{
	Status status;
	unsigned int i=1,x;
	char e[MAX_ENG];
	Word word;

	strcpy(e,"Hello");
	printf("Notice: Enter '#' to hint the correct spell. Enter '$' to Quit the learning.Enter '!'to delete the vocabulary.\n");
	while(e[0]!='$' && i>0 && i<=L->length)
	{
		
		status = ListGetElem_Sq(L, i, &word);
		if(status != OK) return ERROR;	
		
		word.num_recite++;
		puts(word.c);
		gets(e);

		while(0 != strcmp(word.e,e))
		{
			if('!' == e[0])
			{
				break;
			}
			if('$' == e[0])
			{
				break;
			}
			word.err_num++;

			if('#' == e[0])
			{
				printf("%s",word.e);
				if(strlen(word.e)>10)
				{
					Sleep(2000);
				}
				else
				{
					if(strlen(word.e)>8)
					{
						Sleep(1000);
					}
					else
					{
						Sleep(600);
					}
				}
				printf("\r");
				x = X_VALUE;
				while(x--)printf(" ");
				printf("\r");
			}
			
			gets(e);
		}

		if('!' == e[0])
		{
			status = ListDelete_Sq(L, i, &word);
		}
	    else
		{			
			status = ListPutElem_Sq(L, i, word);
			i++;
		}
		if(status != OK) return ERROR;	
		
	}

	return OK;
}

*/