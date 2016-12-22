#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BinTNode,*BinTree;
//typedef BinTNode *BinTree;

//struct node == BinTNode;
//struct node * == BinTree;

BinTree CreatBinTree(void);//���ظ��ڵ� ���������������Ķ�����

void Preorder(BinTree T);//�������

void Inorder(BinTree T);//����

void Postorder(BinTree T);//����

//���ú�����������������ȣ��������Լ�Ҷ�����ĵݹ��㷨��
int CountLeaf(BinTree T,int *count);//ͳ�ƶ�������Ҷ�ӽ��ĸ���
int LeafNodes(BinTree T);




#define OK 1;
#define ERROR 0;


//# ��ʾ��ָ���λ��
BinTree CreatBinTree(void){//���ظ��ڵ� ���������������Ķ�����
	BinTree T;
	char ch;
	if((ch=getchar())=='#')
		return NULL;//����# ���ؿ�ָ��
	else{
		T = (BinTNode *)malloc(sizeof(BinTNode));//���ɽڵ�
		//T = (BinTNode *)malloc(sizeof(BinTNode)) == T = (BinTree)malloc(sizeof(BinTNode))
		T->data = ch;
		T->lchild = CreatBinTree();//����������
		T->rchild = CreatBinTree();//����������
		return T;
	}


}

void Preorder(BinTree T){//�������
	if(T){
		printf("%c",T->data);
		Preorder(T->lchild);
		Preorder(T->rchild);
	}



}
void Inorder(BinTree T){//����


	if(T){

		Inorder(T->lchild);
		printf("%c",T->data);
		Inorder(T->rchild);
	}




}

void Postorder(BinTree T){//����

	if(T){
		Postorder(T->lchild);
		Postorder(T->rchild);
		printf("%c",T->data);
	}

}


int CountLeaf(BinTree T,int *count){

    if(T){
        if ((T->lchild ==NULL)&&(T->rchild ==NULL)){
             *count++;
             //printf("*count:%d\n",*count);
            return OK;
            }
         CountLeaf(T->lchild, &count);
                    // ͳ����������Ҷ�ӽ�����
         CountLeaf(T->rchild, &count);
                   // ͳ����������Ҷ�ӽ�����
        //printf("*count:%d\n",*count);
       }
   else
        return ERROR;

}


int LeafNodes(BinTree T)
{
    int num1,num2;
    if(T==NULL)
    return 0;
    else if(T->lchild==NULL && T->rchild==NULL)
    return 1;
    else
    {
        num1=LeafNodes(T->lchild);
        num2=LeafNodes(T->rchild);
        return (num1+num2);
    }
}






int main(){
	BinTree root;
	int i,depth;
	int getcount=0;
	int *count;
	count=&getcount;

	printf("\n");
	printf("Creat Bin_Tree; \nInput Preorder:");

	root = CreatBinTree();//���������������ظ����

	do{

		printf("\t************select**************\n");
		printf("\t1:Preorder Traversal\n");
		printf("\t2:Inorder Traversal\n");
		printf("\t3:Postorder Traversal\n");
		printf("\t4:PostTreeDepth,Node number,Leaf number\n");
		//
		printf("\t0:Exit\n");
		printf("\t********************************\n");
		scanf("%d",&i);

		switch(i){
		case 1: printf("Printf BinTree Preorder: ");
				Preorder(root);
				printf("\n");
				break;

		case 2: printf("Printf BinTree Inorder: ");
				Inorder(root);
				printf("\n");
				break;

		case 3: printf("Printf BinTree Postorder: ");
				Postorder(root);
				printf("\n");
				break;


		case 4:printf("Printf BinTree Leafs: ");//ʵ������Ҷ�ӽ����
				//CountLeaf(root,&count);
				printf("count:%d\n",LeafNodes(root));
				//printf("getcount:%d\n",getcount);

				break;


		default:exit(1);
		}
		printf("\n");

	}while(i!=0);


	return 0;
}
