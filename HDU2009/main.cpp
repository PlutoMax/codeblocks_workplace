/*
���еĶ������£�
���еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡�


Input
���������ж��飬ÿ��ռһ�У�����������n��n<10000����m(m<1000)��ɣ�n��m�ĺ�����ǰ������


Output
����ÿ���������ݣ���������еĺͣ�ÿ������ʵ��ռһ�У�Ҫ�󾫶ȱ���2λС����


Sample Input

81 4
2 2



Sample Output

94.73
3.41



Author
lcy

*/
#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=-1){
            double ans = n ;
            double d = n;
        for(int i = 1;i < m; i++){//ע�⣺��ǰm�� ������m��
            d = sqrt(d);
            ans += d;
        }
        printf("%.2lf\n",ans);
    }
   // cout << "Hello world!" << endl;
    return 0;
}
