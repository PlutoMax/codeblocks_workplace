#include <iostream>
#include<cstdio>
using namespace std;

void slect_sort(int arr[],int len){
    int temp = 0;
    for(int i = 0;i<len;i++){
        int miniValue = arr[i];
        int t=i;//������������С���ͱ��i=t,����������
        for(int j=i+1;j<len;j++){
            if(miniValue>arr[j]){
                miniValue = arr[j];
                t = j;
            }
        }
        swap(arr[t],arr[i]);
    }

}

//�Ľ���
void slect_sort2(int arr[],int len){
   for(int i=0;i<len-1;i++){
    int miniIndex=i;
    for(int j=i+1;j<len;j++){
        if(arr[miniIndex]>arr[j])
            miniIndex=j;
    }
    if(miniIndex!=i){
       // int temp=arr[i];
        //arr[i]=arr[miniIndex];
        //arr[miniIndex]=arr[i];
        swap(arr[miniIndex],arr[i]);
    }
   }

}


int main()
{
   int arr[]={57,68,59,52,4,3,89,56,23,12,45,10,35};
   int len=sizeof(arr)/sizeof(int);
   printf("�ɸ�������Сֵ��ѡ������\n");
   slect_sort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
    }

   printf("����ѡ������\n");
    slect_sort2(arr,len);
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
    }
    return 0;
}
