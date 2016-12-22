#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <list>
using namespace std;




int main()
{
    stack<int,list<int> >a;//Ĭ����deque��������listʵ�ֵ�ջ Ԫ��������int
    stack<int,vector<int> > b;//Ĭ����deque��������vectorʵ�ֵ�ջ Ԫ��������int

    int i;
    //��������
    for(int i=0;i<10;i++){
        a.push(i);
        b.push(i*i);
    }
    //ջ�Ĵ�С
    printf("��ջǰ��\na.size:%d\nb.size:%d\n",a.size(),b.size());
    printf("a[0]:%d",a.top());
    //��ӡջ��Ԫ��
    while(!a.empty()){
        printf("aջ��Ԫ�أ�%d\n",a.top());
        a.pop();//��ջ
    }
    putchar('\n');

    while(!b.empty()){
        printf("bջ��Ԫ�أ�%d\n",b.top());
        b.pop();
    }
    putchar('\n');
    printf("��ջ��\na.size:%d\nb.size:%d\n",a.size(),b.size());

    return 0;
}
