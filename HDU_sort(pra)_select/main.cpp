#include<bits/stdc++.h>
//**********************************
//ʱ�临�Ӷ�O(n**2)
using namespace std;

void select_sort(int arr[],int len){
    int t=0;
    for(int i=0;i<len-1;i++){
        t=i;//��Ҫ��һ����������������Сֵ�������
        int miniValue=arr[i];
        for(int j=i+1;j<len;j++){
            if(miniValue>arr[j]){
                miniValue=arr[j];
                t=j;
            }
        }
        swap(arr[i],arr[t]);
    }

}

int main()
{
    int arr[]={56,52,64,89,12,35,44,65,10,1,6,3,4,560,79,12,25};
    int len=sizeof(arr)/sizeof(int);
    select_sort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d%c",arr[i],i<len-1?' ':'\n');
     }
    return 0;
}
