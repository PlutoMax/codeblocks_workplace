//ֱ�Ӳ�������
#include <iostream>
#include <cstdio>
using namespace std;

int InsertSort(int a[],int len){
    int temp = 0;
    for(int i = 1;i<len;i++){
        temp = a[i];
        int j = i - 1;
        for(;j>=0&&temp<a[j];j--){
            a[j+1] = a[j];//����һλ
        }
        //Ȼ���temp����ճ�����λ�ã�����һλ���µģ�
        a[j+1] = temp;
    }
    for(int i=0;i<len;i++){
        printf("%d%c",a[i],i<len-1?' ':'\n');
    }
}

int main()
{
    int arr[]={57,68,59,52};
    int len = sizeof(arr)/sizeof(int);
    InsertSort(arr,len);
    return 0;
}
