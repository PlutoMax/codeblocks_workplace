#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define LISTINCREMENT 10//��������
typedef struct{
    int *elem;//�洢�ռ��ַ
    int length;
    int listSize;
}sqList;

int initList sq(sqList &L){
    //g����һ�������Ա�
    L.elem=(int*)malloc(SIZE*sizeof(int));
    if(!L.elem)exit(-2);//�洢����ʧ��
    L.length= 0;//�ձ���Ϊ0
    L.listSize=SIZE;
    return 1;//ok
}

int listInsert_sq(sqList &L,int i,int e){
    sqList *newBase;
    //i�ĺϷ���
    if(i<1||i>=L.length+1)
        return 0;
    if(L.length>=L.listSize){//��ǰ�洢�ռ�����
        newBase=(int*)realloc(L.elem,(L.listSize+LISTINCREMENT))*sizeof(int));
        if(!newBase)exit(-2);
        L.elem=newBase;
        L.listSize += LISTINCREMENT;
    }
    q=&(L.elem[i-1]);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
