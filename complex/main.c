#include <stdio.h>
#include <stdlib.h>
#include <selfDefine/complex_struct.h>

//��ʼ��
void complex_init (Ptrl ptrl){
    //for(int i=0;i<maxV;i++)
      //  ptrl->real[i]=ptrl->inscriber[i]=0;
      ptrl->real=ptrl->inscriber=0;
}

//����ֵ
void complex_creat(Ptrl ptrl){
    float rea,ins;
    scanf("%f%f",&rea,&ins);
    ptrl->real=rea;
    ptrl->inscriber=ins;

    return;
}

//�ӷ�����
void complex_add(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    result->real=ptrl->real+ptrl2->real;//ʵ��
    result->inscriber=ptrl->inscriber+ptrl2->inscriber;//�鲿
    printf("�ӷ���������%.4f i + %.4f\n",result->real,result->inscriber);
}

//��������
void complex_sub(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    result->real=ptrl->real-ptrl2->real;//ʵ��
    result->inscriber=ptrl->inscriber-ptrl2->inscriber;//�鲿
    printf("������������%.4f i + %.4f\n",result->real,result->inscriber);
}

//�˷�����
void complex_mul(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    result->real=ptrl->real * ptrl2->inscriber + ptrl2->real * ptrl->inscriber;//ʵ��
    result->inscriber= -ptrl->real * ptrl2->real + ptrl->inscriber * ptrl2->inscriber;//�鲿
    printf("�˷���������%.4f i + %.4f\n",result->real,result->inscriber);
}

//��������
void complex_divi(Ptrl ptrl,Ptrl ptrl2,Ptrl result){
    float den;//��ĸ
    den=-(ptrl2->real * ptrl2->real) + ptrl2->inscriber * (-ptrl2->inscriber);
    if(den!=0){
    result->real=((ptrl->real * -ptrl2->inscriber) + (ptrl->inscriber * ptrl2->real))/den;
    result->inscriber=(-(ptrl->real * ptrl2->real) + (ptrl->inscriber * -ptrl2->inscriber))/den;

    printf("������������%.4f i + %.4f",result->real,result->inscriber);
    }else{
        printf("����������:error:��ĸΪ0��");
    }
}

int main()
{
   Ptrl ptrl1;
   ptrl1=(Ptrl)malloc(sizeof(struct complex));
   complex_init(ptrl1);

    printf("������Z1:");
   complex_creat(ptrl1);

   Ptrl ptrl2;
   ptrl2=(Ptrl)malloc(sizeof(struct complex));
   complex_init(ptrl2);

    printf("������Z2:");
   complex_creat(ptrl2);

   Ptrl result;
   result=(Ptrl)malloc(sizeof(struct complex));
   complex_init(result);

   //�ӷ�
   complex_add(ptrl1,ptrl2,result);
    //����
   complex_sub(ptrl1,ptrl2,result);
   //�˷�
   complex_mul(ptrl1,ptrl2,result);
   //����
   complex_divi(ptrl1,ptrl2,result);

   free(ptrl1);
   free(ptrl2);
   free(result);
    return 0;
}
