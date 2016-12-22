#include <stdio.h>
#include <stdlib.h>
//��Ϊ�������ֹ�����
typedef int ElementType;

struct BitTree{
    ElementType data;
    struct BitTree *lchild;
    struct BitTree *rchild;
};


struct BitTree* HuffumanCreatAndCoding(ElementType arr[],int n){
    struct BitTree *bt,**b;
    int i,j;

    b = (struct BitTree**)malloc(n*sizeof(struct BitTree));//��̬��������
    for(i=0;i<n;i++){
        b[i]=(struct BitTree *)malloc(sizeof(struct BitTree));//Ϊb[i]���ٽ��ռ�
        b[i]->data=arr[i];
        b[i]->lchild = b[i]->rchild = NULL;
    }



    for(i=0;i<n-1;i++){
        int k1=-1,k2;
        //�ҵ�ɭ������С�ʹ���С����
        //������k1ָ��ɭ���е�һ����,k2
        for(j=0;j<n;j++){
            if(b[j]!=NULL && k1 == -1){
                k1 = j;
               //Ȼ��Ͳ��ܼ����������� Ҫ����ѭ���ҵڶ�����
               continue;//����forѭ��
            }
            if(b[j]!=NULL){
                k2 = j;
                break;
            }
        }

        //������һ��ѭ�� �ҵ���Сֵ��k1������Сֵ��k2
        for(j=k2;j<n;j++){
            //ͨ���Ƚ�����Сֵ
            if(b[j]!=NULL){
                if(b[j]->data<b[k1]->data){
                    k2 = k1;
                    k1 = j;

                }
                else if(b[j]->data<b[k2]->data){
                    k2 = j;
                }
            }
        }

        bt = (struct BitTree *)malloc(sizeof(struct BitTree));
        bt->data = b[k1]->data + b[k2]->data;
        bt->lchild = b[k1];
        bt->rchild = b[k2];

        b[k1] = bt;
        b[k2] = NULL;

    }
    free(b);
    return bt;


}

void PrintHuffmancoding(struct BitTree *bt,int len){
    static int arr[10];
    if(bt!=NULL){
        if(bt->lchild == NULL && bt->rchild==NULL){
            int i;
            printf("%d������Ϊ��",bt->data);
            for(i=0;i<len;i++){
                printf("%d",arr[i]);
            }
            printf("\n");
        }else{
            //�����Ϊlen ��������
            arr[len]=0;
            PrintHuffmancoding(bt->lchild,len+1);
            arr[len]=1;
            PrintHuffmancoding(bt->rchild,len+1);
        }

    }

}



int main()
{
    struct BitTree *bt=NULL;
    int n,i;
    ElementType *arr;

    printf("������������");
    scanf("%d",&n);
    while(1){
        if(n>1)
            break;
        else{
            printf("���������룺");
            scanf("%d",&n);
        }
    }

    arr=(ElementType *)malloc(n*sizeof(ElementType));
    printf("������%d��Ȩֵ:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    //������������
    bt = HuffumanCreatAndCoding(arr,n);

    //��ӡ����������
    PrintHuffmancoding(bt,0);


    return 0;
}
