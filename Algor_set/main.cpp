#include <iostream>
#include <set>

using namespace std;

int main()
{
    int a[] = {1,2,3,56};
    set<int> s(a,a+4);//������������ֵ��
    for(int i=2;i<50;i++)
        s.insert(i);

    set<int>::iterator iter;
    set<int>::iterator it1;
    set<int>::iterator it2;

    if((iter = s.find(2)) != s.end())
    {
        cout<<"find(2):"<<*iter<<endl;
    }
    //set�����ߴ�
    cout<<"size:"<<s.size()<<endl;

    cout<<"max_size:"<<s.max_size()<<endl;

    cout<<"count(3):"<<s.count(3)<<endl;//set���ظ������� �൱���ж��Ƿ���֡�
    cout<<"count(20):"<<s.count(200)<<endl;

     pair<set<int>::const_iterator,set<int>::const_iterator> pr;
    pr = s.equal_range(3);
    cout<<"��һ�����ڵ��� 3 ������ ��"<<*pr.first<<endl;
    cout<<"��һ������ 3������ �� "<<*pr.second<<endl;

    for(it1=s.begin();it1!=s.end();it1++)
        cout<<*it1<<" ";

    cout<<endl;

//lower_bound(key_value) �����ص�һ�����ڵ���key_value�Ķ�λ��
//upper_bound(key_value)���������һ������key_value�Ķ�λ��
//��λ�� ��Ҫָ��
    cout<<"low_bound(10):"<<*s.lower_bound(10)<<endl;//����Ԫ�ص�ַ
    cout<<"upper_bound(10):"<<*s.upper_bound(10)<<endl;


    return 0;
}
