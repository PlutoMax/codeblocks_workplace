#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node{
    ElementType data;
    struct Node *Next;
}*PtrToNode;



typedef PtrToNode Stack;//��ptrToNode�����Stack

//����
int IsEmpty(Stack S);//�ж��Ƿ�Ϊ��
Stack CreatStack();//������ջ
void DisposeStack(Stack S);//����ջ
void MakeEmpty(Stack S);//���ջ
void Push(Stack S,ElementType x);//��ջ
ElementType Top(Stack S);//ȡջ��Ԫ��
int Pop(Stack S,int e);//��ջ
void convert10to8(Stack S,int n);
void convert10to2(Stack S,int n);


void convert10to8(Stack S,int n){
    int e=0;
    while(n){
        Push(S,n%8);
        n = n/8;
    }

    while(!IsEmpty(S)){
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

    while(!IsEmpty(S)){
        printf("%d",Pop(S,e));
    }
    printf("\n");
}

//����ʵ��
int IsEmpty(Stack S){
    return S->Next==NULL;
    if(S->Next == NULL)
        printf("---------------------\n\n");
}
//����ջ
Stack CreatStack(){
     Stack S;

    S = (Stack)malloc(sizeof(struct Node));
    if(!S){//���Ϊ��
        printf("Out of space��");
        exit(0);
    }

    S->Next = NULL;//���ӵ�һ��
    MakeEmpty(S);
    return S;
    }

   //����ջ
void DisposeStack(Stack S){
    Stack p=NULL;

    while(!S){

        p = S->Next;
        S = S->Next;
        free(p);
    }
   }

//���ջ
void MakeEmpty(Stack S){
    int e=0;
    if(S == NULL){
        printf("Must use CreatStack first!");exit(0);
    }
    else
        while(!S)
            Pop(S,e);
}

//��ջ ͷ�巨��ջ
void Push(Stack S,ElementType x){
    PtrToNode Tmp;

    Tmp =(PtrToNode) malloc(sizeof(struct Node));
    if(Tmp == NULL){
        printf("Out of space!");
        exit(0);
    }else{
        Tmp->data = x;
        Tmp->Next = S->Next;//Tmp->Next =NULL;
        S->Next = Tmp;
    }
}

//��ջ
int Pop(Stack S,int e){
    PtrToNode Fir;

    if(IsEmpty(S)){
        printf("Empty Stack!");
        exit(0);
    }
    else{
        Fir = S->Next;
        S->Next = S->Next->Next;
        e = Fir->data;
        //printf("��ջԪ��Ϊ��%d\n",Fir->data);
        free(Fir);
        return e;
    }
}

ElementType Top(Stack S){
    if(!IsEmpty(S))
        return S->Next->data;
    printf("Empty Stack!");
    return 0;
}

int main()
{
    int i=0,n;
    Stack S;
    S = CreatStack();
    //printf("IsEmpty:%d\n",IsEmpty(S));

    printf("����һ�����֣�");
    scanf("%d",&n);
    printf("�����ֵİ˽�����ʽ��");
    convert10to8(S,n);
    printf("�����ֵĶ�������ʽ��");
    convert10to2(S,n);
    /*
    //��ջ
    for(i=0;i<n;i++){
        Push(i,S);
        //printf("IsEmpty:%d\n",IsEmpty(S));
    }

    printf("ջ��Ԫ��Ϊ��%d\n",Top(S));

    if (IsEmpty(S))printf("ջ��\n\n");
    else printf("ջ���գ�����\n\n");

    printf("IsEmpty:%d\n",IsEmpty(S));

    for(i=0;i<n;i++)
        Pop(S);

    if (IsEmpty(S))printf("ջ��\n\n");
    else printf("ջ���գ�����\n\n");
    printf("IsEmpty:%d\n",IsEmpty(S));
    */

    DisposeStack(S);
    return 0;
}
