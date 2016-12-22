#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct BitNode{
    ElementType data;
    struct BitNode* lchild;
    struct BitNode* rchild;
};

struct BitNode *BitCreat();
void PreOrder(struct BitNode* bt);

struct BitNode *BitCreat(){
    struct BitNode * bt = NULL;
    char ch;
    if((ch=getchar())=='#'){
        return NULL;
    }
    else{
            //�˴���������Ҫ��һ�������ɽ��
        bt=(struct BitNode*)malloc(sizeof(struct BitNode));//�ݹ�ʱҲҪ���ɽ��
        bt->data=ch;
        bt->lchild = BitCreat();
        bt->rchild = BitCreat();
        return bt;
    }

}

//ǰ�����
void PreOrder(struct BitNode* bt){
    if(bt){
        printf("%c",bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}






int main()
{
    struct BitNode *bt=NULL;
    bt = BitCreat();
    PreOrder(bt);
    return 0;
}
