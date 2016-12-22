#include <stdio.h>
#include <stdlib.h>
//������������
typedef char ElementType;
#define MAX_TREE_SIZE 100
                 // ���������������
 //typedef TElemType
            //SqBiTree[MAX_TREE_SIZE];
                 // 0�ŵ�Ԫ�洢�����
 //SqBiTree  bt;

typedef struct BitTree{
    ElementType data[MAX_TREE_SIZE];
    int length;
    ElementType size;
}*SqBiTree;

struct BitTree* CreatBitTree(){
    SqBiTree bt=NULL;
    ElementType ch;
    int i;
    bt = (SqBiTree)malloc(sizeof(struct BitTree));

    bt->length=0;
    bt->size=MAX_TREE_SIZE;
    for(i=1;i<=MAX_TREE_SIZE;i++){
            bt->data[i]=0;
    }

    printf("�Բ��򴴽�������");
    printf("�������ַ�,��0��ʾΪ��,�Կո���(#��ʾ�������)��\n");

    for(i=1;;i++){
            scanf(" %c",&ch);
        bt->data[i]=ch;

        if(bt->data[i]=='#'){
                bt->data[i]=0;
                bt->data[2*(i)]='\0';
            //bt->data[i+1]='\0';
            break;
        }
        if(bt->data[i]!='0')
            bt->length++;
    }
}


//�������
void CengXuTraverseBitTree(SqBiTree bt){
    int i;
    //puts(bt->data);

    for(i=1;bt->data[i]!='\0';i++){
            if(bt->data[i]=='0')
                continue;
            else
                printf("%c ",bt->data[i]);
    }
}

//ǰ�����
void PreOrder(SqBiTree bt,int i){
    if(bt->data[i]==0)
        return ;
    else{
            if(bt->data[i]!='0'&&bt->data[i]!='#')
                printf("%c ",bt->data[i]);

            PreOrder(bt,i*2);
            PreOrder(bt,i*2+1);

    }

   // index(bt->data[i]);
}


//�������
void InOrder(SqBiTree bt,int i){
    if(bt->data[i]==0)
        return ;
    else{
            InOrder(bt,i*2);
                //i=i*2;
            if(bt->data[i]!='0'&&bt->data[i]!='#')
                printf("%c ",bt->data[i]);

            InOrder(bt,i*2+1);
                //i = i*2 + 1;
    }

   // index(bt->data[i]);
}

//��������

void PostOrder(SqBiTree bt,int i){
    if(bt->data[i]==0)
        return ;
    else{
            PostOrder(bt,i*2);
            PostOrder(bt,i*2+1);

            if(bt->data[i]!='0'&&bt->data[i]!='#')
                printf("%c ",bt->data[i]);

    }

   // index(bt->data[i]);
}



void ZeroToint(SqBiTree bt){
    int i;
    for(i=1;bt->data[i]!='\0';i++){
        if(bt->data[i]==0)
             bt->data[i]=(int)bt->data[i];
    }


}
//printf("Ҷ��%c ",bt->data[i]);
//��Ҷ���

int Pre_GetNodes(SqBiTree bt,int i){
    static int cNode=0;

    if(bt->data[i]==0)
        return 0;
    else{
            //if(bt->data[i]=='0')
             //   bt->data[i]=(int)bt->data[i];
            if(bt->data[i]!='0'&&bt->data[i*2]==0&&bt->data[i*2+1]==0){
                cNode++;
            }

            Pre_GetNodes(bt,i*2);
            Pre_GetNodes(bt,i*2+1);
    }
    return cNode;
}


int GetNodes(SqBiTree bt,int i){
    int num1,num2;
    if(bt->data[i]==0)
        return 0;
    else if(bt->data[i*2]==0&&bt->data[i*2+1]==0)
        return 1;
    else{
        num1 = GetNodes(bt,i*2);
        num2 = GetNodes(bt,i*2+1);
        return (num1+num2);
    }
}



//�����
int TreeDepth(SqBiTree bt,int i){
    int depth=0;
    //if(bt->data[i]==0)
    //   return 0;
    if(bt->data[i]!=0){
        int ldepth=TreeDepth(bt,i*2);
        int rdepth=TreeDepth(bt,i*2+1);
        depth = ldepth>=rdepth?(ldepth+1):(rdepth+1);
    }
    return depth;
}



//���ٶ�����
void Destroyed(SqBiTree bt){
    free(bt);
}

int main()
{
    SqBiTree bt=NULL;
    int nodes;
    bt = CreatBitTree();
    printf("\n��������%d\n",bt->length);

    //nodes = GetNodes(bt,1);

    //printf("Ҷ������:%d\n",nodes);

    printf("\nҶ������PRE:%d\n",Pre_GetNodes(bt,1));

    printf("������ȣ�%d\n",TreeDepth(bt,1));
    printf("\n���������");
    CengXuTraverseBitTree(bt);
    printf("\nǰ�������");
    PreOrder(bt,1);

    printf("\n���������");
    InOrder(bt,1);
    printf("\n���������");
    PostOrder(bt,1);

   // ZeroToint(bt);

   Destroyed(bt);
    return 0;
}
