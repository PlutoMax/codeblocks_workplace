#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,m,a[1000],b[1000],t,sum;
    // memset(a,0,sizeof(a));
    while(scanf("%d%d",&n,&m)!=-1){
        memset(a,0,sizeof(a));
        sum=0;
        while(n--){

            for(int i=0;i<m;i++){
                scanf("%d",&t);
                a[i]+=t;//���Ƴɼ��ۼӺ�
                b[i]=t;
                sum+=t;
            }
            printf("%f ",(sum)*1.0/m);//����ƽ���ɼ�

        }
    }

    return 0;
}
