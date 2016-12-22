#include <iostream>
#include <cstdio>
#include <cstring>
#include <time.h>
using namespace std;
clock_t s1,e1,s2,e2,s3,e3,s4,e4,s5,e5;
double duration;

//ð������
void bubble_sort(int arr[],int len){
    for(int i=0;i<len-1;i++)
    for(int j=0;j<len-i-1;j++){
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
    }
}

//��������
void insert_sort(int arr[],int len){
    for(int i=1;i<len;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0&&temp<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}

//ѡ������
void select_sort(int arr[],int len){
    for(int i=0;i<len-1;i++){
        int minindex=i;//����±�
        for(int j=i;j<len;j++)
            if(arr[minindex]>arr[j])
                minindex=j;//�����±꼴��

        if(minindex!=i)//�±�����������ˣ��ͽ�����
            swap(arr[minindex],arr[i]);
    }

   return;
}

//��������
void quick_sort(int arr[],int low,int high){
    int l=low;
    int h=high;
    int key=arr[low];//��λkey

    while(l<h){
        while(l<h&&arr[h]>=key)
            h--;
        if(l<h){
            swap(arr[l],arr[h]);
            l++;
        }
        while(l<h&&arr[l]<=key)
            l++;
        if(l<h){
            swap(arr[l],arr[h]);
            h--;
        }
    }
    if(l>low) quick_sort(arr,low,l-1);
    if(h<high) quick_sort(arr,h+1,high);

}


//Ͱ���� ע���ʼ��Ϊ0 ��Ϊ�Ľ�����Ÿ���
void bucket_sort(int arr[],int len){
    int a[100000],t;
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++){
        //scanf("%d",&t);
        t=(arr[i]+9999);
        a[t]++;
    }
    for(int i=0;i<=(100000-1);i++)//������������һ������Ͱ
    for(int j=1;j<=a[i];j++){//j=1��Ϊ����j�Ϳ�Ͱ����Ϊ0���Ƚϵ�ʱ���ų�����Ͱ��
        printf("%d ",i-9999);//a[i]��ʾ��Ͱ�ŵ�������Ҳ����ѭ����ӡ�Ĵ�����ͬ���������
    }
    return ;
}

void print(int arr[],int len){
    for(int i=0;i<len;i++)
        printf("%d%c",arr[i],i<len-1?' ':'\n');

    //retrun;
}

int main()
{
    int arr[]={53,12,3,10,89,-46,51,-79,6,3,49,120,789,-987,789};
    //int arr[]={2,1,4,3,9,8};
    int len=sizeof(arr)/sizeof(int);
    print(arr,len);


    s1=clock();
    printf("Ͱ����\n");//100����Ͱ����Ч����ʤ
       /* for(int i=0;i<100;i++){
        bucket_sort(arr,len);
         }*/
    bucket_sort(arr,len);
    e1=clock();
    double re=((double)(e1-s1))/CLK_TCK;
    printf("\n����ʱ�䣺%f\n",re);



    s2=clock();
    printf("\n��������\n");
       /* for(int i=0;i<100;i++){//100�������Ч����ʤ
        quick_sort(arr,0,len-1);
        }*/

    quick_sort(arr,0,len-1);
    print(arr,len);
    e2=clock();
    double re2=((double)(e2-s2))/CLK_TCK;
    printf("����ʱ�䣺%f\n",re2);


    s3=clock();
    printf("\nѡ������:\n");
    select_sort(arr,len);
    print(arr,len);
    e3=clock();
    double re3=((double)(e3-s3))/CLK_TCK;
    printf("����ʱ�䣺%f\n",re3);

    s4=clock();
    printf("\n��������:\n");
    insert_sort(arr,len);
    print(arr,len);
    e4=clock();
    double re4=((double)(e4-s4))/CLK_TCK;
    printf("����ʱ�䣺%f\n",re4);


    s5=clock();
    printf("\nð������:\n");
    bubble_sort(arr,len);
    print(arr,len);
    e5=clock();
    double re5=((double)(e5-s5))/CLK_TCK;
    printf("����ʱ�䣺%f\n",re5);

    return 0;
}
