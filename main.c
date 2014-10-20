#include "Option.h"

Status Schedule_Learn()
{
	List L;
	Status status;
	
	status = InitList_Sq(&L);
	if(status != OK) return ERROR;
	
	status = Read_Mint_blue(&L);
	if(status != OK) return ERROR;
	printf("Reading Lexicon .... The addition of vocabulary is %d\n",L.length);	
	status = Compute_Priority(&L);
	if(status != OK) return ERROR;
	printf("Compute Priority ....The addition of vocabulary is %d\n",L.length);
	Sort_Mint_blue(&L,0,L.length);
	printf("Sort Lexicon ....    The addition of vocabulary is %d\n",L.length);
	
	status = Recite(&L);
	if(status != OK) return ERROR;
	printf("Recite end ....      The addition of vocabulary is %d\n",L.length);
	status = Write_Mint_blue(&L);
	if(status != OK) return ERROR;
	printf("Write end ....       The addition of vocabulary is %d\n",L.length);
	status = Destroy_Sq(&L, ALWAYS);
	if(status != OK) return ERROR;
	
	return OK;
}
/*
****************************************************************************************************************************
*  FunctionName       :Random_Display
*  Parameter          :none
*  Return             :Corret:OK Error:ERROR
*  Description        :To display vocabular or other emphasis 
*****************************************************************************************************************************
*/


Status Random_Display()
{	
	List L;
	Status status;
	
	status = InitList_Sq(&L);
	if(status != OK) return ERROR;
	
	status = Read_Mint_blue(&L);
	if(status != OK) return ERROR;
	printf("Reading Lexicon ....  The addition of vocabulary is %d\n",L.length);	
	status = Compute_Priority(&L);
	if(status != OK) return ERROR;
	printf("Compute Priority .... The addition of vocabulary is %d\n",L.length);
	Sort_Mint_blue(&L,0,L.length);
	printf("Sort Lexicon ....     The addition of vocabulary is %d\n",L.length);
	status = Voca_Display(&L);
	if(status != OK) return ERROR;
	printf("Display end ....      The addition of vocabulary is %d\n",L.length);
	status = Write_Mint_blue(&L);
	if(status != OK) return ERROR;
	printf("Write end ....        The addition of vocabulary is %d\n",L.length);
	status = Destroy_Sq(&L, ALWAYS);
	if(status != OK) return ERROR;
	Sleep(100);
	return OK;
}

/*
****************************************************************************************************************************
*  FunctionName       :main
*  Parameter          :none
*  Return             :Corret:OK Error:ERROR
*  Description        :The main function
*****************************************************************************************************************************
*/
Status main()
{
	char ch;
	Status status = OK;
    unsigned int x,y,flag=1;
	while(flag)
	{
		system("cls");    //Çå³ýÆÁÄ»
		printf("\t\t\t\tMenu\n(0):Schedule Learn\n(1):Random Display\n(2):Quit\n");
		ch = getch();
		switch(ch)
		{
		case '0':
			{
				system("cls");    //Çå³ýÆÁÄ»
				status = Schedule_Learn();
				if(status != OK) return ERROR;
				else return OK;
				break;
			}    
		case '1':
			{
				system("cls");    //Çå³ýÆÁÄ»
				status = Random_Display();
				if(status != OK) return ERROR;
				else return OK;
				break;
			}	                  
		case '2':
			{
				flag=0;
				break;
			}
		default:
			{
				printf("Input error!\nPlease choice menu with 0-2 !");
				
			}
			
		}
	}
	Location(X_VALUE/3,Y_VALUE-2);
	printf("This program is producted by zjwfan\n");
	Location(X_VALUE/3+8,0);
	printf(" All right reserved\n\n\n");
	Sleep(100);
//	while(x--) printf(" ");
	
	
	return OK;
}