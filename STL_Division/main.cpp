#include <iostream>

using namespace std;

bool test(int i,int j){  //������t���i��j�ĸ�λ����

   int t[10]={0};  //��ʼ������t��ʹ�ø�λ����Ϊ0���ô���ʹ��fghij<10000ʱfλ��Ϊ0

   int ia = 0;

 while(i) {  //ȡi�и�λ���ִ��������t��

      t[ia++] = i % 10;

      i = i / 10;

   }

while(j) {  //ȡj�и�λ���ִ��������t��

      t[ia++] = j % 10;

       j = j / 10;

   }

//�ж�a��j�Ƿ�ǡ��Ϊ���ֵ�0��9��һ������

   for(int m = 0; m < 10; ++m)

      for(int n = m+1; n < 10; ++n)

         if(t[n] == t[m])   return false;

  return true;

}

int main(){

   int n;

   int k;

   while(cin >> n && n >=2 && n <= 79) {

      k = 1234;

      while(k <= 98765) {

        int j = k * n;

        if(j < 100000) { //��fghij<10000��������Ŀ��������fλ�����0

           if(test(j,k)) {

              cout << j << "/" ;

              if(k < 10000)  cout <<"0";

              cout << k << "=" << n <<endl;

           }

        }

        ++k;

      }

   }

   return 0;

}
