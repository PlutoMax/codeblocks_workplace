/*
��n(n<=100)���������Ѿ����մ�С����˳�����кã����������һ������x���뽫�������뵽�����У���ʹ�µ�������Ȼ����


Input
�������ݰ����������ʵ����ÿ��������������ɣ���һ����n��m���ڶ������Ѿ������n���������С�n��mͬʱΪ0��ʾ�������ݵĽ��������в�������


Output
����ÿ������ʵ������������µ�Ԫ�غ�����С�


Sample Input

3 3
1 2 4
0 0



Sample Output

1 2 3 4



Author
lcy

��Ϊ���ַ�����Ԫ��(1��)
*/
#include <iostream>
#include<cstdio>
using namespace std;

int binary_insert(int arr[],int len,int key){//���ַ�ͨ����ѯ�ҵ���Ԫ��Ҫ�����λ�� ���ظ�������
    int left=0,mid,right =len-1;
    while(left<right){
        mid = (left+right)/2;
        if(key<=arr[mid])
            right=mid;
        else
            left=mid+1;
    }
    if(key>=arr[len-1])
        left++;

    return left;

}

int main()
{
   int n,inser;
   while(scanf("%d%d",&n,&inser),n!=0||inser!=0){
        int arr[100];
        for(int i = 0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        int len = n;
        int arr02[100];
        int rep=binary_insert(arr,len,inser);//����Ԫ��Ҫ�����λ��

   for(int i=0;i<len+1;i++){
        if(i<rep){
            arr02[i]=arr[i];
        }
        if(i==rep)
            arr02[i]=inser;//��Ԫ�ز���ָ��λ��

        if(i>rep){
            arr02[i]=arr[i-1];
        }
   }
    for(int i=0;i<len+1;i++){
       printf("%d%c",arr02[i],i<len?' ':'\n');
       /* if(i!=0)
              printf(" ");
        printf("%d",arr02[i]);*/
    }
    //printf("\n");
   }
    return 0;

}
