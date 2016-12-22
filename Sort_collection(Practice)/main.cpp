#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

//��ӡ����
void print(int arr[],int len){
    for(int i=0;i<len;i++)
        printf("%d%c",arr[i],i<len-1?' ':'\n');
    return;
}
//ð������
void bubble_sort(int arr[],int len){
    for(int i=0;i<len-1;i++)
    for(int j=0;j<len-i-1;j++){
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
    }
    print(arr,len);
    return;
}

//��������
void quick_sort(int arr[],int low,int high){
    int h=high;
    int l=low;
    int key=arr[low];

    while(l<h){
        while(l<h&&arr[h]>=key)
            h--;
        if(l<h){
            swap(arr[h],arr[l]);
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

//��������
void insert_sort(int arr[],int len){
    printf("��������\n");
    for(int i=1;i<len;i++){//��len��ԭ����
        int temp=arr[i];
        int j=i-1;
        for(;j>=0&&temp<arr[j];j--){//temp<=arr[j],���� = û��Ҫ����Ƚ�����
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}

//ѡ������
void select_sort(int arr[],int len){
    printf("ѡ������\n");
    for(int i=0;i<len-1;i++){//-1������Լ������ٺ��Լ�������
        int minIndex=i;
        for(int j=i;j<len;j++){
            if(arr[minIndex]>arr[j])
                minIndex=j;
        }
        if(minIndex!=i)
            swap(arr[minIndex],arr[i]);
    }
}

//Ͱ����
void buket_sort(int arr[],int len){
    printf("Ͱ����\n");
    int maxV=0;
    for(int i=0;i<len;i++){
        if(arr[i]>maxV)
            maxV=arr[i];
    }

    int arr2[maxV+10000];
    //int t;
    memset(arr2,0,sizeof(arr2));
    for(int i=0;i<len;i++){
        arr2[arr[i]+9999]++;
    }

    for(int i=0;i<=maxV+9999;i++)
        for(int j=1;j<=arr2[i];j++){
            printf("%d ",i-9999);
        }


}

int main()
{
    int arr[]={12,5,69,45,58,31,2,44,10,-45};
    int len=sizeof(arr)/sizeof(int);
    printf("ԭʼ���飺\n");
    print(arr,len);
    //ð��
   // bubble_sort(arr,len);
   // quick_sort(arr,0,len-1);
    //print(arr,len);

   // insert_sort(arr,len);
    //select_sort(arr,len);

    buket_sort(arr,len);
    //print(arr,len);
    return 0;
}
