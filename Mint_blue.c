#include "Option.h"

Status Recite(List *L)
{
	Status status;
	unsigned int i=1,j=0,old_err_num,len;
	char ch;
	Word word;
	

	printf("Notice: Press '#' to hint the correct spell. Press '$' to Quit the learning. Press '!'to delete the vocabulary.\n");
	while(i>0 && i<=L->length)
	{
		
		status = ListGetElem_Sq(L, i, &word);
		if(status != OK) return ERROR;
		
		len = strlen(word.e);
		word.num_recite++;
		old_err_num=word.err_num;
		j=0;
		puts(word.c);
		while(1)
		{

			ch = getche();
			if(ch=='$' || ch=='!')
			{
				Cover_row();
				break;
			}
			if('#'==ch)
			{
				word.err_num++;
				Cover_row();
				if(word.err_num-old_err_num>6)
				{
					printf("%s",word.e);
					Sleep(100*len);
				}
				else
				{
					if(word.err_num-old_err_num>3)
					{
						printf("%s",word.e);
						Sleep(100*len);
					}
					else
					{
						printf("%s",word.e);
						Sleep(100*len);
					}


				}
//				puts(word.e);
//				Sleep(100*len);
				Cover_row();
				j=0;
			}
			if(word.e[j]==ch)
			{
				if(j==len-1)
				{
					break;
				}
				j++;	
			}
			else
			{
				j=0;
				Cover_row();
			}

		}
		if('$'==ch)
		{
			return OK;
		}
		if('!'==ch)
		{
			status = ListDelete_Sq(L, i, &word);
			i--;
		}
		else
		{
			status = ListPutElem_Sq(L, i, word);
		}
		i++;
//		Cover_row();
		printf("\n\n");
	}

	return OK;
}

/*
****************************************************************************************************************************
*  FunctionName       :Sort_Mint_blue
*  Parameter          :List *L
*  Return             :Corret:OK Error:ERROR
*  Description        :Sort the Mint blue
*****************************************************************************************************************************
*/

void Sort_Mint_blue(List *L,int left, int right)
{
     int i,j;
	 ElemType s,temp;
	 
     if(left<right)
     {
          s = L->elem[left];
          i=left;
          j=right+1;

          while(1)
          {
               //向右找
               while(i+1 < L->length && L->elem[++i].priority>s.priority);
               //向左找
               while(j-1 > -1 && L->elem[--j].priority<s.priority);
               if(i>=j)
               {
                    break;
               }

			   temp=L->elem[i];
			   L->elem[i]=L->elem[j];
			   L->elem[j]=temp;
          }
          L->elem[left] = L->elem[j];
          L->elem[j] = s;

          Sort_Mint_blue(L,left,j-1);//对左边进行递归
          Sort_Mint_blue(L,j+1,right);//对右边进行递归
     }
}

/*
****************************************************************************************************************************
*  FunctionName       :Compute_Priority
*  Parameter          :List *L
*  Return             :Corret:OK Error:ERROR
*  Description        :Compute the Priority
*****************************************************************************************************************************
*/

Status Compute_Priority(List *L)
{
	unsigned int i;
	for(i=1;i<=L->length;i++)
	{
		if(L->elem[i-1].num_recite == 0)
		{
			L->elem[i-1].priority = 1000.0;
		}
		else
		{
			L->elem[i-1].priority = (float)(1000.0*((float)L->elem[i-1].err_num/(float)L->elem[i-1].num_recite)) + L->elem[i-1].num_recite;
		}
	}
	return OK;
}

/*
****************************************************************************************************************************
*  FunctionName       :Write_Mint_blue
*  Parameter          :List *L
*  Return             :Corret:OK Error:ERROR
*  Description        :Write the List vocabulary to the mint blue
*****************************************************************************************************************************
*/
Status Write_Mint_blue(List *L)
{

	Status status;
	FILE *fp;
	Word word;
	unsigned int i;
	
	
	fp = fopen("Lexicon.txt","w");
	if(NULL == fp) return ERROR;

	for(i=1;i<=L->length;i++)
	{
		status = ListGetElem_Sq(L, i, &word);
		if(status != OK) return ERROR;
		fprintf(fp,"%s %s %u %u %f\n", word.e, word.c, word.err_num, word.num_recite, word.priority);
	}
	fclose(fp);
	return OK;
}
/*
****************************************************************************************************************************
*  FunctionName       :Read_Mint_blue
*  Parameter          :List *L
*  Return             :Corret:OK Error:ERROR
*  Description        :Read the vocabulary from the mint blue
*****************************************************************************************************************************
*/
Status Read_Mint_blue(List *L)
{

	Status status;
	FILE *fp;
	Word word;
	
	
	fp = fopen("Lexicon.txt","r");
	if(NULL == fp) return ERROR;

	while(feof(fp) == 0)
	{
		if(feof(fp) != 0 ) break;

		fscanf(fp,"%s %s %u %u %f", word.e, word.c, &word.err_num, &word.num_recite, &word.priority);
	
		status = ListInput_Sq(L, word);
		if(status != OK) return ERROR;

		if(feof(fp) != 0 ) break;
	}
	status = ListDelete_Sq(L, L->length, &word);//删除因feof（）函数多读的一项

	if(status != OK) return ERROR;
	fclose(fp);
	return OK;
}

Status Voca_Display(List *L)
{
	Status status;
	unsigned int i=1,j=0;
	unsigned int x,y,temp;
	Word word;
	srand((unsigned) time(NULL));	
	printf("Press any key can exit!\n");
	while(i>0 && i<=L->length)
	{
		j=0;
		status = ListGetElem_Sq(L, i, &word);
		if(status != OK) return ERROR;
		i++;
		
		do
		{
//			srand((unsigned) time(NULL));
			x = rand()%X_VALUE;
			y = rand()%Y_VALUE;	
			j++;
		}while(X_VALUE-x<strlen(word.c) || X_VALUE-x<strlen(word.e));

		temp = x;
		while(y--) printf("\n");
		while(x--) printf(" ");
		puts(word.e);
		while(temp--) printf(" ");
		puts(word.c);


		if(kbhit()) break;
		Sleep(2000-100*j);
		system("cls");
		if(kbhit()) break;
	}
	return OK;
}