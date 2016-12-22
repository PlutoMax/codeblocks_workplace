#include <stdio.h>
#include <stdlib.h>

#define Stack_init_size 100
#define StackInCrement 10
typedef struct Node{
    int *base;
    int *top;
    int stackSize;
    int length;
}Node,*SqStack;

typedef SqStack Stack;//��sqStack������֣�Stack
//��ʼ������һ����ջ
struct Node *InitStack();
void DestroyStack(Stack S);

int GetTop(Stack S,int e);
void convert10to8(Stack S,int n);

void convert10to2(Stack S,int n);
//��ջ
void Push(Stack S,int e);

//��ջ
int Pop(Stack S,int x);
//���ջ
void ClearStack(Stack S);

//ջ�Ƿ�Ϊ��
int IsEmpty(Stack S);
//ջ����
int StackLength(Stack S);

