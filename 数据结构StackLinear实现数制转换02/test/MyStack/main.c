#include <stdio.h>
#include <stdlib.h>
#include "Stack_Header.h"


int main()
{
    Stack S;
    int n,i;
    int e=0;
    S=InitStack();//��ʼ��

    printf("����һ��10��������");
    scanf("%d",&n);
    printf("�����˽�����ʽ��");
    convert10to8(S,n);
     printf("������������ʽ��");
    convert10to2(S,n);
    /*

    printf("������һ�����֣�");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        Push(S,i);
    }

    //ջ�Ƿ�Ϊ��
    if(IsEmpty(S))printf("ջ��Ϊ��.\n");
    else printf("ջΪ�գ�\n");

    //ջ��
    printf("ջ����%d\n\n",StackLength(S));
    //for(i=0;i<n;i++)
        printf("ȡ��Ԫ�أ�%d\n\n",GetTop(S,e));

        for(i=0;i<n;i++)
            printf("��ջԪ�أ�%d\n",Pop(S,e));


        //���ջ
        ClearStack(S);
        //ջ��
    printf("ջ����%d\n\n",StackLength(S));
        Pop(S,e);

         //ջ�Ƿ�Ϊ��
    if(IsEmpty(S))printf("ջ��Ϊ��.\n");
    else printf("ջΪ�գ�\n");


    */


            //����ջ
        //DestroyStack(S);

    return 0;
}
