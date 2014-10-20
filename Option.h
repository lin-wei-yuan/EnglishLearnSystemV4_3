#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#define ALWAYS            0
#define OPTION            1
#define TRUE              1
#define FALSE             0
#define OK                1
#define ERROR             0
#define INFEASIBLE       -1
#define OVERFLOW         -2

#define MAX_ENG 30
#define MAX_CHI 80

#define X_VALUE 80
#define Y_VALUE 25

typedef int Status;

typedef struct WORD
{
	char c[MAX_CHI];
	char e[MAX_ENG];
	unsigned int num_recite;
	unsigned int err_num;
    float priority;
}Word,*pWord;

typedef Word ElemType ;

#define LIST_INIT_SIZE 100               //���Ա�洢�ռ�ĳ�ʼ��������
#define LISTINCREMENT  10                //���Ա�洢�ռ�ķ�������

typedef struct
{
     ElemType               *elem;              //�洢�ռ��ַ
     unsigned int           length;             //��ǰ����
     unsigned int           listsize;           //��ǰ����Ĵ洢����

}List;



Status InitList_Sq(List *L);
Status ListInput_Sq(List *L, ElemType e);
Status ListInsert_Sq(List *L, unsigned int i, ElemType e);
Status ListDelete_Sq(List *L, unsigned int i, ElemType *e);
Status ListExchange_Sq(List *L, unsigned int i, unsigned int j);
Status ListGetElem_Sq(List *L, unsigned int i, ElemType *e);
Status ListPutElem_Sq(List *L, unsigned int i, ElemType e);
Status Display_Sq(const List *L);
Status Destroy_Sq(List *L, unsigned int FLAG);
Status Recite(List *L);
void Sort_Mint_blue(List *L,int left, int right);
Status Compute_Priority(List *L);
Status Write_Mint_blue(List *L);
Status Read_Mint_blue(List *L);
Status Voca_Display(List *L);
Status Schedule_Learn();
Status Random_Display();
void Location(unsigned x, unsigned y);
void Cover_row();