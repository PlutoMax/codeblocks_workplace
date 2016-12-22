#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

//���㽨��ͷ���
typedef struct {
    QueuePtr front;//��ͷָ��
    QueuePtr rear;//��βָ��
}LinkQueue;

//����һ���ն���
struct LinkQueue *InitQueue(){
    LinkQueue *LQ;
    LQ->front = LQ->rear =(QueuePtr)malloc(sizeof(QNode));
    if(!LQ) exit(0);
    LQ->front->next = NULL;
    return LQ;
};

//���
void EnQueue(LinkQueue *LQ,QElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(0);
    p->data = e;
    p->next = NULL;
    LQ->rear->next = p;
    LQ->rear = p;
}

QElemType DeQueue(LinkQueue *LQ,QElemType e){
    QueuePtr p;
    if(LQ->front ==  LQ->rear){
        printf("����Ϊ�գ�\n");
        return ;
    }
    p = LQ->front->next;
    e = p->data;
    LQ->front->next = p->next;
    if(LQ->rear == p) LQ->rear = LQ->front;
    free(p);
    return e;
}

//���ٶ���
void DestroyQueue(LinkQueue *LQ){
    while(LQ->front){
        LQ->rear = LQ->front->next;
        free(LQ->front);
        LQ->front = LQ->rear;
    }
    printf("���������٣�");
}

//�ж��Ƿ�Ϊ��
int IsEmpty(LinkQueue *LQ){
    return LQ->front == LQ->rear;
}

//��ն���
void ClaerQueue(LinkQueue *LQ){
    QueuePtr p;

    while(LQ->front != LQ->rear){
        p = LQ->front->next;
        //e = p->data;
        LQ->front->next = p->next;
        if(LQ->rear == p) LQ->rear = LQ->front;
        free(p);
    }
     //printf("����Ϊ�գ�\n");
    return ;
}

//�õ���ͷԪ��
int GetHead(LinkQueue *LQ){
    return LQ->front->next->data;
}

int main()
{
    LinkQueue *LQ;
    int i,n,e;
    LQ = InitQueue();//��������
    printf("����һ����������Χ��");
    scanf("%d",&n);
    for(i = 0;i<n;i++)
        EnQueue(LQ,i);
    if(IsEmpty(LQ)) printf("����Ϊ�գ�\n");
    else printf("���в��ա�\n");
    printf("���пշ�״̬��%d\n",IsEmpty(LQ));
    for(i=0;i<n;i++){

        printf("����Ԫ�أ�%d\n",DeQueue(LQ,e));
    }

    if(IsEmpty(LQ)) printf("����Ϊ�գ�\n");
    else printf("���в��ա�\n");

DestroyQueue(LQ);
    return 0;
}
