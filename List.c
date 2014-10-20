#include "Option.h"


//����һ���յ����Ա�L
Status InitList_Sq(List *L)
{
     L->elem = (ElemType *) malloc(LIST_INIT_SIZE*sizeof(ElemType));
     if(!L->elem) exit(OVERFLOW);
     L->length = 0;
     L->listsize = LIST_INIT_SIZE;
     return OK;
}

//��˳�����Ա���˳������µ�Ԫ��e
Status ListInput_Sq(List *L, ElemType e)
{
     ElemType *newbase;
     if(L->length < 0) return ERROR;
     if(L->length >= L->listsize)
     {
          newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
          if(!newbase) exit(OVERFLOW);
            L->elem = newbase;
          L->listsize += LISTINCREMENT;
     }
     L->elem[L->length] = e;
     ++L->length;
     return OK;
}

//��˳�����Ա��е�i��λ��֮ǰ�����µ�Ԫ��e
Status ListInsert_Sq(List *L, unsigned int i, ElemType e)
{
     ElemType *newbase,*q,*p;
     if(i<1 || i>L->length+1) return ERROR;
     if(L->length >= L->listsize)
     {
          newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
          if(!newbase) exit(OVERFLOW);
            L->elem = newbase;
          L->listsize += LISTINCREMENT;
     }
     q = &(L->elem[i-1]);
     for(p=&(L->elem[L->length - 1]); p>=q; --p)
     {
          *(p+1)=*p;
     }
     *q=e;
     ++L->length;
     return OK;
}

//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete_Sq(List *L, unsigned int i, ElemType *e)
{
     ElemType *p,*q;
     if((i<1) || (i>L->length)) return ERROR;
     p = &(L->elem[i-1]);
     *e = *p;
     q = L->elem + L->length -1;
     for(++p; p<=q; ++p)
     {
          *(p-1) = *p;
     }
     --L->length;
     return OK;
}

//��˳�����Ա�L�н���i��jλ��Ԫ�ص�ֵ
Status ListExchange_Sq(List *L, unsigned int i, unsigned int j)
{
     ElemType temp;
     if((i<1) || (i>L->length)|| (j<1) || (j>L->length)) return ERROR;

     temp = (L->elem[i-1]);
     (L->elem[i-1]) = (L->elem[j-1]);
     (L->elem[j-1]) = temp;

     return OK;
}

//ȡ˳�����Ա�L�е�i��Ԫ�ص�ֵ(�����i��1��ʼ)
Status ListGetElem_Sq(List *L, unsigned int i, ElemType *e)
{
     if((i<1) || (i>L->length)) return ERROR;
     *e = (L->elem[i-1]);
     return OK;
}

//��˳�����Ա�L�е�i��Ԫ�ظ�ֵe
Status ListPutElem_Sq(List *L, unsigned int i, ElemType e)
{
     if((i<1) || (i>L->length)) return ERROR;
     (L->elem[i-1]) = e;
     return OK;
}

//�����ʾ˳�����Ա�
Status Display_Sq(const List *L)
{
     unsigned int i;
     if(L->length < 1) return ERROR;
     for(i=1;i<=L->length;i++)
//          printf("%4d \t",L->elem[i-1]);
     printf("\n");
     return OK;
}

//����˳�����Ա�
Status Destroy_Sq(List *L, unsigned int FLAG)
{
   
     if(L->length < 0) return ERROR;
     if(ALWAYS == FLAG) free(L->elem);
     if(OPTION == FLAG)
     {
          if(L->length != 0) return FALSE;
          else free(L->elem);
     }
     return OK;
}