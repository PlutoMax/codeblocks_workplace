#include <stdio.h>
#include <stdlib.h>

/**
�ص㣺�Ƚ��ȳ�
*/
typedef int ElementType;
typedef int Status;

//��������
typedef struct QNode{
  ElementType data;//����
  struct QNode *next;
}QNode,*QueuePtr;

typedef struct LinkeQueue{
    QueuePtr front;
    QueuePtr rear;
    int length;
}LinkeQueue;

/*
Status InitQueue(LinkeQueue *Q);//����һ���ն���

Status DestroyQueue(LinkeQueue *Q);//���ٶ��У�ǰ����д���

Status ClearQueue(LinkeQueue *Q);//��ն���

Status QueueEmpty(LinkeQueue Q);//������Ϊ���򷵻�TRUE,���򷵻�FALSE

int QueueLength(LinkeQueue Q);//����Ԫ�ظ���

Status GetHead(LinkeQueue Q);//,ElementType *e);//ȡ�Ӷ�Ԫ��

void EnQueue(LinkeQueue *Q,ElementType e);

Status DeQueue(LinkeQueue *Q);//,ElementType *e);

//void visit();
Status QueueTraverse(LinkeQueue *Q);//,visit());
*/

//����

Status QueueTraverse(LinkeQueue *Q){
   QueuePtr p;
   // QueuePtr r;
   /**
   ����Ӧ��ƥ���
   */
    p = Q->front;
    //r = (QueuePtr)malloc(sizeof(QNode));
    while((p->next)){//��p��Ϊ�յ�ʱ��

            printf(":%d\n",p->next->data);
            p = p->next;
    }
    return 1;//ok
}

//����ʵ��
struct LinkeQueue *InitQueue(){
    //Ӧ���ȿ���Q
    LinkeQueue *Q;
    Q = (LinkeQueue *)malloc(sizeof(LinkeQueue));//��Ҫ��һ��
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!(Q->front)) exit(0);
    Q->front->next = NULL;
    Q->length = 0;
    return Q;//OK
}

//����
void DestroyQueue(LinkeQueue *Q){
    /**
    ��ͷ��ʼ���٣�
    ͷ����β�ߡ�
    */
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
        Q->length--;
    }
    return ;//OK
}

//�����
void EnQueue(LinkeQueue *Q,ElementType e)
{
    QueuePtr p;

    p = (QueuePtr)malloc(sizeof(QNode));

    if(!p)exit(0);

    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    Q->length++;
   // return 1;//OK
}

Status DeQueue(LinkeQueue *Q)//,ElementType *e)
{
    QueuePtr p;
    ElementType e;
    if(Q->front == Q->rear)
        return 0;
    p = (QueuePtr)malloc(sizeof(QNode));
    p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;

    if(Q->rear == p)
        Q->rear = Q->front;

    free(p);
    Q->length--;
    return e;//OK
}

//ȡͷԪ��
Status GetHead(LinkeQueue Q)//,ElementType *e)
{

    if(Q.front==Q.rear)return 0;
    return Q.rear->data;
}

//���г���

int QueueLength(LinkeQueue Q){
    return Q.length;
}


//�����Ƿ�Ϊ��
Status QueueEmpty(LinkeQueue Q){
    return Q.front == Q.rear;
}

//��ն���
Status ClearQueue(LinkeQueue *Q){
    Q->front = Q->rear;
    Q->length = 0;
    return 1;//OK
}


//������
int main()
{
    LinkeQueue *Q;
    int i;
    ElementType e;
    Q = InitQueue();//��ʼ��
   //���
    EnQueue(Q,100);

    for(i = 1;i <= 10;i++)
        EnQueue(Q,i);

    QueueTraverse(Q);//����
    printf("��ͷԪ��:%d\n",GetHead(*Q));
    printf("���г���:%d\n",QueueLength(*Q));
    /**
    �ж�������Q->front == Q->rear
        ���Ϊ�գ����������������� 1
                ���򣬷��� 0��
    */
   // printf("���пշ�״̬��%d\n",QueueEmpty(*Q));

    //ClearQueue(Q);

    printf("���пշ�״̬��%d\n",QueueEmpty(*Q));
    printf("�����У�%d\n",DeQueue(Q));
    for(i = 1;i <= 10;i++){
    e = DeQueue(Q);
    printf(":%d\n",e);
    }
    //QueueTraverse(Q);
    DestroyQueue(Q);
    return 0;
}
