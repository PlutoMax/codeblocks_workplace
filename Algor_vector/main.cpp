#include <iostream>
#include <cstdio>
#include <vector>
#define m 100
using namespace std;

int main()
{
    vector<int>v;
    int n;
    cout<<"n:";
    while(cin>>n,n){
        //cout<<n<<endl;;
        v.clear();
       // v.resize(50);

        for(int i=0;i<n;i++)
            v.push_back(i);//׷��Ԫ��

            v.pop_back();//ɾ��Ԫ��
            cout<<"v.at(0):"<<v.at(0)<<endl;//at(x);���ص�x��Ԫ�ء�
            cout<<"v.back:"<<v.back()<<endl;//�������һ��Ԫ�ء�
            cout<<"v.empty:"<<v.empty()<<endl;//�����Ƿ�Ϊ�ա�
            //v.erase(4);

        cout<<"v.max_size():"<<v.max_size()<<endl;//���ܿ��ٵ����ռ䡣

        //
        vector<int>::iterator it;//���õ�����

            //insert(),erase()����Ҫ�͵���������ʹ�á����£�
            it=v.begin();
            v.insert(it+28,482);//��28��λ�ò���482.

        for(;it!=v.end();it++)
            cout<<*it <<" ";
        cout<<"\n"<<endl;
            it=v.begin();

            v.erase(it+10);//ɾ����10��Ԫ�ء�

            v.erase(it+11,v.end());//��11��ʼɾ������ֹ��
        for(;it!=v.end();it++)
            cout<<*it <<" ";

        cout<<"\nv[2]: 1"<<v[2]<<endl;
        cout << "\n���� ��СΪ: " << v.size() << endl;//Ԫ�ظ���
        cout << "���� ����Ϊ: " << v.capacity() << endl;//��������С����δʹ�ÿռ䣩
        //cout<<v.resize(50)<<endl;
        //cout<<v.size()<<endl;

        /* ����effective stl�е�����Ľ��� swap() */

        //�رյ�����Ŀռ�
        vector<int>(v).swap(v);

        cout << "��ʱ��vector<int>���� �Ĵ�СΪ: " << (vector<int>(v)).size() << endl;
        cout << "��ʱ��vector<int>���� ������Ϊ: " << (vector<int>(v)).capacity() << endl;
        cout << "�����󣬵�ǰvector �Ĵ�СΪ: " << v.size() << endl;
        cout << "�����󣬵�ǰvector ������Ϊ: " << v.capacity() << endl;
    }

    return 0;
}
