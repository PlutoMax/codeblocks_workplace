
#include <iostream>
#include <cstdio>

using namespace std;

//ע�� �κ�ʵ����0�����Լ�����Ǹ�ʵ������

__int64 LCM(__int64 a,__int64 b){//����󹫱���
    __int64 c;
    __int64 a1=a,b1=b;
    if(a<b){
        c=b;
        b=a;
        a=c;
    }
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return (a1*b1)/a;
}

int main()
{
   int n,T;
   __int64 a[10000],result;
   scanf("%d",&T);
   while(T--){
        scanf("%d",&n);
        for(__int64 i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(n==1){
            printf("%I64d\n",a[0]);
        }else{
        result=LCM(a[0],a[1]);
        for(__int64 i=2;i<n;i++)
            result=LCM(result,a[i]);
        printf("%I64d\n",result);
        }
       }
    return 0;
}


/*
#include <iostream>
using namespace std;
int a[1005];

int GCD(int a, int b)
{
 int temp;
 if (a<b)
 {
  temp=a;
  a=b;
  b=temp;
 }
 //swap(a,b)
 if (b==0)
  {
   return a;
  }
  else
   {
    return GCD(b,a%b);
   }
}


int LCM(int a, int b)
{
 return (a*(b/GCD(a,b)));
}


int main()
{
 int i,times,numbers,results;
 cin>>times;
 while (times--)
  {
   cin>>numbers;
   for (i=0;i<numbers;i++)
    {
     scanf("%d",&a[i]);
    }
    if (numbers==1)
    {
     cout<<a[0]<<endl;
    }
    else
    {
    results=LCM(a[0],a[1]);
    for (i=2;i<numbers;i++)
     {
      results=LCM(results,a[i]);
     }
   cout<<results<<endl;
  }
}
  return 0;
}
*/
