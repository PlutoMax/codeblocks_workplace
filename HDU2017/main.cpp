/*
���ڸ�����һ���ַ�����ͳ�����������ַ����ֵĴ�����


Input
���������ж��У���һ����һ������n����ʾ����ʵ���ĸ������������n�У�ÿ�а���һ������ĸ��������ɵ��ַ�����


Output
����ÿ������ʵ��������ô�����ֵ�ĸ�����ÿ�����ռһ�С�


Sample Input

2
asdfasdf123123asdfasdf
asdf111111111asdfasdfasdf



Sample Output

6
9



Author
lcy
*/
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    char word[1000];
    scanf("%d",&n);
    while(n--!=0){
        scanf("%s",word);
        int count=0;
        int len=strlen(word);
       for(int i=0;i<len;i++){
            int integ=word[i];
            integ -= 48;
            if(integ>=0&&integ<=9){
                count +=1;
            }
       }
       printf("%d\n",count);
    }
    return 0;
}
