/*
��Ϊ���򷨲���Ԫ�أ�
���ȳ�ʼ��һ���㹻�������,
Ȼ������n��Ԫ�أ���Ҫ�����Ԫ�ز��뵽Ԫ��n��λ�ã���Ϊ������㿪ʼ����
More easy��
*/
#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
   int n,inser;
   while(scanf("%d%d",&n,&inser),n!=0||inser!=0){
    int arr[101];
    int t=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arr[n]=inser;
    int len=101;
    for(int i = 0;i<n;i++)
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    for(int i=0;i<n+1;i++){

            printf("%d%c",arr[i],i<n?' ':'\n');
           /*
            if(t++!=0){
                printf(" ");
            }
            printf("%d",arr[i]);
            */
    }
    //printf("\n");
   }
    return 0;
}
