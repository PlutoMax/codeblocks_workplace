/*
����n�������������������������ĳ˻���


Input
�������ݰ����������ʵ����ÿ������ʵ��ռһ�У�ÿ�еĵ�һ����Ϊn����ʾ��������һ����n����������n������������Լ���ÿ�����ݱض����ٴ���һ��������


Output
���ÿ�����е����������ĳ˻������ڲ���ʵ�������һ�С�


Sample Input

3 1 2 3
4 2 3 4 5



Sample Output

3
15
*/

#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    int t;
    while(scanf("%d",&n)!=-1){
        int ans=1;
        for(int i = 0;i<n;i++){
            scanf("%d",&t);
            if(t%2 !=0)
                ans *= t;
        }
        printf("%d\n",ans);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
