/*
Problem Description
����һ���������������������������ż����ƽ�����Լ����������������͡�


Input
�������ݰ����������ʵ����ÿ�����ʵ������һ�У�����������m��n��ɡ�
 //ע�� ��������һ���ᰴ��С˳������ ����Ҫ�ж� m����n��

Output
����ÿ���������ݣ����һ�У�Ӧ������������x��y���ֱ��ʾ�ö�����������������ż����ƽ�����Լ����������������͡�
�������Ϊ32λ�������Ա�������


Sample Input

1 3
2 5



Sample Output

4 28
20 152



Author
lcy

*/
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    long  m,n;

    while(scanf("%ld%ld",&m,&n)!=-1){
        long p=0;
        long v=0;
        if(m > n) swap(m,n);//���Ҫ��ϸ����
        for(long i=m;i<=n;i++){
            if(i%2==0)
               p += i*i;
            else
                v += i*i*i;
        }
        printf("%ld %ld\n",p,v);
    }
   // cout << "Hello world!" << endl;
    return 0;
}
