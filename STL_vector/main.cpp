#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*
����sort��lower_bound()
int main()
{
    int a[100],x,y,q;
    printf("���鳤�ȣ�");
    scanf("%d",&x);
    printf("����һ�����飺\n");
    for(int i=0;i<x;i++)
        scanf("%d",&a[i]);
    sort(a,a+x);
    for(int i=0;i<x;i++)
        printf("%d%c",a[i],i<x-1?' ':'\n');
    int index01 = lower_bound(a,a+x,20)-a;
    int index02 = lower_bound(a,a+x,18)-a;
    //for(int i=0;i<x;i++)
     //   printf("%d%c",a[i],i<x-1?' ':'\n');
    printf("20:%d\n18:%d\n",index01,index02);
    return 0;
}

*/

//vector����һ������������
//template <typename T>
int main(){
    vector<int> vec,vec2;
    vec2.push_back(48);
    vector<int>vec3(4,50);//����һ������4��50��vector.
    vector<int> vec01(50);//����һ��500��Ԫ�ص�vector
    vector<int> vec02(50,int(7));//����500��Ԫ�ص�vector������ʼ��Ϊ123


    for(int i=0;i<10;i++)
        vec.push_back(i);

    printf("vec.capacity:%d\n",vec.capacity());
    printf("(5)at����Ϊ5����:%d\n",vec.at(5));
    printf("front��һ��Ԫ��:%d\n",vec.front());
    printf("front���һ��Ԫ��:%d\n",vec.back());
    //vec.insert(1,100);
    vec.push_back(123456);//��β������һ��Ԫ��
    printf("vecԪ�ظ�����%d\n",vec.size());
    printf("vec�������ߴ磺%d\n",vec.max_size());
   vec.swap(vec2);//1.����vec1��vec2Ԫ��
   swap(vec,vec2);//2.�ȼ������� 1
    vector<int>(vec).swap(vec);//�˲��������Ч���ÿռ� ȥ������ռ�
    printf("vec.capacity:%d\n",vec.capacity());
    printf("vec2.capacity:%d\n",vec2.capacity());


    vector<int>::iterator it,it2;
    printf("vec:");
    for(it=vec.begin();it!=vec.end();it++)
        printf("%d ",*it);
    printf("\nvec3_size:%d\n",vec3.size());
    printf("vec3:");
   // vector<int>::iterator it2;
    for(it2=vec3.begin();it2!=vec3.end();it2++)
        printf("%d ",*it2);
    printf("\nvector<int> vec01(50)��");
    for(it2=vec01.begin();it2!=vec01.end();it2++)
        printf("%d ",*it2);

    printf("\nvector<int> vec02(50,int(123))��");
    for(it2=vec02.begin();it2!=vec02.end();it2++)
        printf("%d ",*it2);


    //����erase ���ǵ�������
    for(it=vec.begin();it!=vec.end();it++){
        if((*it)==10){//�����ı� ɾ��10
            it2=it;
            vec.erase(it2);
            }
    }

    printf("\nvec:");
    for(it=vec.begin();it!=vec.end();it++)
        printf("%d ",*it);


    return 0;
}
