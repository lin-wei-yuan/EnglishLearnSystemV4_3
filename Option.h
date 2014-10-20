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

#define LIST_INIT_SIZE 100               //线性表存储空间的初始化分配量
#define LISTINCREMENT  10                //线性表存储空间的分配增量

typedef struct
{
     ElemType               *elem;              //存储空间基址
     unsigned int           length;             //当前长度
     unsigned int           listsize;           //当前分配的存储容量

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