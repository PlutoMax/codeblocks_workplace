#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int element;
	struct Node *next;

}*PtrToNode;

typedef PtrToNode Position,List;
List MakeEmpty(List L);//�����ÿ�
int IsEmpty(List L);//���Ƿ�Ϊ��
int IsLast(Position P);//�Ƿ�Ϊ���һ��Ԫ��

//���Ƿ��
int IsEmpty(List L){
    return  L->next == NULL;
}

//�Ƿ�Ϊ���һ��Ԫ��
int IsLast(Position p){
    return p->next == NULL;
}

//��������
List CreatList(){

}

