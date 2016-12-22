/*
01-���Ӷ�2. Maximum Subsequence Sum (25)

ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4

*/
#include <stdio.h>
#include <stdlib.h>
#define __int64 long long
//using namespace std;
void MaxSubseqSum4( __int64 A[], int N ) {
    __int64 ThisSum, MaxSum;
    __int64 i,t1=A[N-1],t2=0,t3=0,sum2=0;
    ThisSum= MaxSum= 0;
    for( i = 0; i < N; i++ ) {
            ThisSum+= A[i]; /* �����ۼ�*/
    if( ThisSum> MaxSum){
        MaxSum= ThisSum; /* ���ָ��������µ�ǰ���*/
        t1=A[i];/*���t1��Ϊ������������һ��Ԫ�ء�*/
        t3=i;/*��Ǵ������±꣬�������渨���ҵ���������е���λ��*/
    }
    else if( ThisSum < 0 ) /* �����ǰ���к�Ϊ��*/
        ThisSum= 0; /* �򲻿���ʹ����Ĳ��ֺ���������֮*/
    }
    while(sum2!=MaxSum){
        sum2+=A[t3];
        t2=t3;
        t3--;
    }
    //�жϵ�5 1�����
    if(MaxSum==0){
        for(int i=0;i<N;i++){
            if(A[i]==0){
                t2=i;
                t1=0;
                break;
            }
        }
    }
    printf("%lld %lld %lld\n",MaxSum,A[t2],t1);
    return ;
    }

int main()
{
    __int64 a[100000];
    int k;
    while(scanf("%d",&k)!=-1){
        for(__int64 i=0;i<k;i++){
            scanf("%lld",&a[i]);
        }
        MaxSubseqSum4(a,k);
    }
    return 0;
}


/*
01-���Ӷ�1. ������к�����(20)

ʱ������
10000 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����K��������ɵ�����{ N1, N2, ..., NK }�����������С�������Ϊ{ Ni, Ni+1, ..., Nj }������ 1 <= i <= j <= K����������к͡��򱻶���Ϊ������������Ԫ�صĺ�������ߡ������������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20����Ҫ�����д���򣬼�������������е�������к͡�

�����ʽ��

�����1�и��������� K (<= 100000)����2�и���K������������Կո�ָ���

�����ʽ��

��һ�������������к͡��������������������Ϊ�����������0��

����������
6
-2 11 -4 13 -5 -2
���������
20

*/


/*


#include <iostream>
#include <cstdio>

using namespace std;
int MaxSubseqSum4( int A[], int N ) {
    int ThisSum, MaxSum;
    int i;
    ThisSum= MaxSum= 0;
    for( i = 0; i < N; i++ ) {
            ThisSum+= A[i]; // �����ۼ�
    if( ThisSum> MaxSum)
        MaxSum= ThisSum; // ���ָ��������µ�ǰ���
    else if( ThisSum< 0 ) //�����ǰ���к�Ϊ��
        ThisSum= 0; // �򲻿���ʹ����Ĳ��ֺ���������֮
    }
    return MaxSum;
    }

int main()
{
    int a[100000],k;
    while(scanf("%d",&k)!=-1){
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",MaxSubseqSum4(a,k));
    }
    return 0;
}

*/
