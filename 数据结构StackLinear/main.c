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

// (*p).a���� p->a

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
    printf("������ջ!\n");
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
	//*S->top++ = e;//1
	*S->top = e;//2. [s->top == (*s).top]
	S->top++;//2
	++S->length;
	//printf("��ջԪ�أ�%d\n",e);
	//S->top++;
	//printf("��ջ�ɹ�\n");
}

//��ջ
int Pop(Stack S,int x){
    //�ж�ջΪ�ղ�
    if(S->top == S->base) {printf("ջ�գ��޷���ɳ�ջ��\n");return 0;}//printf("ջ����!\n");
     --S->top;
    //x =*--S->top;//1
    x = *S->top;//2
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
    return S->base == S->top;
}

//ջ����
int StackLength(Stack S){
    return S->length;
}



int main()
{
    Stack S;
    int n,i;
    int e=0;
    S=InitStack();//��ʼ��

    printf("������һ�����֣�");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        Push(S,i);
        printf("��ջԪ�أ�%d\n",i);
    }

    //ջ�Ƿ�Ϊ��
    if(IsEmpty(S))printf("ջΪ��.\n");
    else printf("ջ��Ϊ�գ�\n");
    //printf("�������%d\n",IsEmpty(S));

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
    if(IsEmpty(S))printf("ջΪ��.\n");
    else printf("ջ��Ϊ�գ�\n");
//printf("�������%d\n",IsEmpty(S));
            //����ջ
        DestroyStack(S);

    return 0;
}
