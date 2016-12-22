#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100

/**
ѭ������
*/
typedef struct Node{
    int *base;//������׵�ַ
    int front;
    int rear;
    /**
    ����Ҳ�����ڴ˴�����һ�� count���ڼ��㳤�ȡ�
    */
}SqQueue;

//����˳�����
struct Node *InitQueue(){
    SqQueue *Q;
    /**
    ����ҪΪQ���ٿռ䡣

    */
    Q = (SqQueue *)malloc(sizeof(SqQueue));
    if(!Q)exit(0);

    Q->base = (SqQueue*)malloc(MAXQSIZE*sizeof(int));//�������׵�ַ���ٿռ䣨ע���������ͣ�����ʾ
    if(!Q->base) exit(0);
    Q->front = Q->rear = 0;//��ʼ��
    return Q;
};

void MakeEmpty(SqQueue *Q){
    Q->front = Q->front = 0;
}

//ȡ��ͷԪ��
int GetHead(SqQueue *Q){
    return Q->base[Q->front];
}

//���г���
int QueueLength(SqQueue *Q){
    return (Q->rear - Q->front + MAXQSIZE)%MAXQSIZE;//rear���front��1
    /**
    Q->rear - Q->front + MAXQSIZE :+MAXSIZE��Ϊ��Q->rear������󳤶�ʱ��
    ʹ��������������ܹ��õ��������м��㡣
    ���磺
        Q->rear = 2 , Q->front = 5 MAXSIZE = 7
        ��ʱ�ĳ��ȣ�(Q->rear - Q->front + MAXQSIZE)%MAXQSIZE
                     (    2   -   5      +  7     ) % 7 = 4������ 6,0,1,2��
    */
}

//�����Ƿ�Ϊ��
int IsEmpty(SqQueue *Q){
    return (Q->front) % MAXQSIZE == Q->rear;
}

//�����
void EnQueue(SqQueue *Q,int e){
    if((Q->rear + 1) % MAXQSIZE == Q->front) exit(0);

    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    /**ע�⣺
    ѭ�����У�
    ���磺MAXQSIZE = 6 ����[0,1,2,3,4,5]
    һ��
        Q->front = 0 , Q->rear = 3
        ���ʱ����Ҫ�ж϶����Ƿ����ˣ����㷨�ǣ���(β+1)%Ԫ�ظ��� == ͷ��
        -����(Q->rear + 1)%Q->MAXQSIZE == Q->front
    ����
        �������������
        ����� ��Q->base[Q->rear] = e;//eΪ���Ԫ��

        Ȼ�����Q->rear�����λ�ã����ܼ򵥵�+1
        ����Q->rear��ʽ��Q->rear = (Q->rear + 1)%MAXSIZE;
    */

}

//����
void DeQueue(SqQueue *Q,int e){
    if(Q->front == Q->rear) return 0;
    /**
    �������Ϊ�գ�����0
    */

    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    /**ע������жϿ�������Ҫһ��
    front�õ�Ԫ�غ� �Ż��Ƶ���һλ
    �Ƶ����λ�á�
    */
    printf("����Ԫ�أ�%d\n",e);
}
void DestroyQueue(SqQueue *Q){
    free(Q);
    free(Q->base);
}

int main()
{
    SqQueue *Q;
    Q = InitQueue();
    printf("�����״̬��%d\n",IsEmpty(Q));
    int i,t,e;
    printf("���붥��Χ��");
    scanf("%d",&t);
    for(i=0;i<t;i++)
        EnQueue(Q,i);
    printf("�����%d��Ԫ�أ�\n",t);
    printf("�����״̬��%d\n",IsEmpty(Q));
    printf("��ͷԪ�أ�%d\n",GetHead(Q));
    printf("���г��ȣ�%d\n",QueueLength(Q));
    for(i=0;i<t;i++)
        DeQueue(Q,e);

    DestroyQueue(Q);
    return 0;
}
