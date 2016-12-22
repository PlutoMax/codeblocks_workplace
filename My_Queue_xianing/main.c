#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/**
���Զ���
*/
typedef int status;

typedef struct Queue_node{
    int *pData;
    int length;
    int tail;
    int count;
}Queue_node;


//�����ڴ�
Queue_node* alloca_queue(int number){
    Queue_node* pQueueNode;
    if( 0 == number)
        return NULL;
    pQueueNode = (Queue_node*)malloc(sizeof(Queue_node));
    assert(NULL!=pQueueNode);
    memset(pQueueNode,0,sizeof(Queue_node));

    pQueueNode->pData = (int*)malloc(sizeof(int)*number);
    if(NULL!=pQueueNode){
        free(pQueueNode);
        return NULL;
    }
    pQueueNode->length = number;
    return pQueueNode;
}

/**
������
*/
int main()
{
    printf("Hello world!\n");
    return 0;
}
