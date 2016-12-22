#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
struct Node *InitStack(){
    Stack S;
    S->base = (int*)malloc(Stack_init_size*sizeof(int));//�����׵�ַ
    if(!S->base){printf("�����ڴ�ʧ��\n");exit(0);}

    S->top = S->base;
    //�ٷ����ʼ�ڴ�
    S->stackSize = Stack_init_size;
    S->length = 0;
    return S;
}

void DestroyStack(Stack S){
    free(S->base);
    //printf("������ջ!\n");
    return ;
}

//ȡջ��Ԫ��
int GetTop(Stack S,int e){
        if(S->top == S->base){
            printf("ջΪ�գ�\n");
            return 0;
        }

	e = *(S->top - 1);//ָ��ȡ��ַ
	//S->top--;
	return e;
}

void convert10to8(Stack S,int n){
    int e=0;
    while(n){
        Push(S,n%8);
        n = n/8;
    }

    while(IsEmpty(S)){
        printf("%d",Pop(S,e));
    }
    printf("\n");
}

void convert10to2(Stack S,int n){
    int e=0;
    while(n){
        Push(S,n%2);
        n = n/2;
    }

    while(IsEmpty(S)){
        printf("%d",Pop(S,e));
    }
    printf("\n");
}

//��ջ
void Push(Stack S,int e){
	//�����ж��Ƿ�Ϊ��
	if(S->top - S->base >= S->stackSize){//ջ��
	S->base = (int*)realloc(S->base,(S->stackSize + StackInCrement)*sizeof(int));//���·���ĵ�ַ�յ�ַ��base

	if(!S->base){printf("�ٷ����ڴ�ʧ�ܣ�\n");exit(0);}
	S->top = S->base + S->stackSize;//stackSize��ָջ��ʵ�ʳߴ硣top = S[stackSize]
	S->stackSize += StackInCrement;//����һ���١����ı��Ĵ�С��ֵ���µĳߴ硣
	//printf("����\n");
	}
	*S->top++ = e;
	++S->length;
	//printf("��ջԪ�أ�%d\n",e);
	//S->top++;
	//printf("��ջ�ɹ�\n");
}

//��ջ
int Pop(Stack S,int x){
    //�ж�ջΪ�ղ�
    if(S->top == S->base) {printf("ջ�գ�\n");return 0;}//printf("ջ����!\n");
     //--S->top;
    x =*--S->top;
    --S->length;
    return x;

}

//���ջ
void ClearStack(Stack S){
    S->top = S->base;
    //�ٷ����ʼ�ڴ�
    S->stackSize = Stack_init_size;
    S->length=0;
    return ;
}

//ջ�Ƿ�Ϊ��
int IsEmpty(Stack S){
    return S->length;
}

//ջ����
int StackLength(Stack S){
    printf("Top - Base�ó��ȣ�%d\n",S->top - S->base);
    return S->length;
}



int main()
{
    Stack S;
    int n,i;
    int e=0;
    S=InitStack();//��ʼ��

    printf("����һ��10��������");
    scanf("%d",&n);
    printf("�����˽�����ʽ��");
    convert10to8(S,n);
     printf("������������ʽ��");
    convert10to2(S,n);
    /*

    printf("������һ�����֣�");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        Push(S,i);
    }

    //ջ�Ƿ�Ϊ��
    if(IsEmpty(S))printf("ջ��Ϊ��.\n");
    else printf("ջΪ�գ�\n");

    //ջ��
    printf("ջ����%d\n\n",StackLength(S));
    //for(i=0;i<n;i++)
        printf("ȡ��Ԫ�أ�%d\n\n",GetTop(S,e));

        for(i=0;i<n;i++)
            printf("��ջԪ�أ�%d\n",Pop(S,e));


        //���ջ
        ClearStack(S);
        //ջ��
    printf("ջ����%d\n\n",StackLength(S));
        Pop(S,e);

         //ջ�Ƿ�Ϊ��
    if(IsEmpty(S))printf("ջ��Ϊ��.\n");
    else printf("ջΪ�գ�\n");


    */


            //����ջ
        DestroyStack(S);

    return 0;
}
