#include <stdio.h>
#include <stdlib.h>

#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<limits.h>
#include<io.h>
#include<math.h>//abs()...add()...
#include<process.h>//exit()

#define TRUE    1
#define FALSE   0
#define  OK     1
#define  ERROR  0
#define INFEASIBLE  -1

#define INFINITY INT_MAX //������ʾ�����
#define max_Vertex_num 20  //���ֻ������20������

typedef int VRType;//Ȩֵ����
typedef char InfoType;/*�����Ϣ����*/
typedef char VertexType;
typedef int status;

/*------�������Ϣ-----------------*/
typedef struct ArcCell{
    VRType adj;//����

   // InfoType *info;

}ArcCell,AdjMatrix[max_Vertex_num][max_Vertex_num];//matrix����

/*------�ߺͻ��Ĺ�ϵ��Ϣ-----------------*/
typedef struct {
    VertexType vexs[max_Vertex_num]; //��������
    AdjMatrix arcs; //�ڽӾ���
    int vexnum,arcnum; //ͼ�ĵ�ǰ�������ͻ���
}MGraph;
status CreatUDN(MGraph *G);
status LocateVex(MGraph *G,VertexType v);
//void InputInfo(char ifo);

status CreatUDN(MGraph *G){
//��������(�ڽӾ���)����������
int i,j,k;

G = (MGraph *)malloc(sizeof(MGraph));
//G->vexs=(VertexType )malloc(sizeof(int));
//G->arcs = (AdjMatrix **)malloc(sizeof(struct ArcCell));

printf("������\n");
printf("�����붥����������:");  //�������Ϣ:"
scanf("%d %d",&G->vexnum,&G->arcnum);//,&IncInfo);
printf("����%d�����㣺\n",G->vexnum);
printf("��ʾ:��������� #��ʾ����\n");
i=0;

do{
    G->vexs[i] = getchar();
    if(G->vexs[i]=='#'){//���뻻�б�ʾ���������
            G->vexs[i]='\0';//�Ը�������з�װ��
            break;
                }
                i++;
}while(1);
printf("----------------------");
for(i=0;G->vexs[i]!='\0';i++)
    printf("%c",G->vexs[i]);
/*
for(i=0;i<G->vexnum;i++) //G->vexs[i]=getchar();
    scanf("%s",&G->vexs[i]);

G->vexs[i]='\0';
*/





//for(i=0;i<G->vexnum;i++)printf("%c ",G->vexs[i]);

for(i=0;i<G->vexnum;i++)
    for(j=0;j<G->vexnum;j++){
        G->arcs[i][j].adj=0;

        //G->arcs[i][j].info=NULL;
        }//��ʼ��{adj,info}

char v1,v2,v[10];
int w;

for(k=0;k<G->arcnum;k++){

printf("���붥��1������2��Ȩֵ����������룬#��ʾ������:\n");
i=0;
do{//ѭ����������
                v[i]=getchar();//�������������������������������� 1.

                if(v[i]=='#'){//���뻻�б�ʾ���������
                        v[i]='\0';//�Ը�������з�װ��
                        break;
                            }
                       i++;
                    }while(1);

v1 = v[0];
v2 = v[1];
w = (int)v[2];
printf(":%d\n",w);


printf("v1:%c\nv2:%c\n",v1,v2);

//i = LocateVex(G,v1);  j = LocateVex(G,v2);


  //      G->arcs[i][j].adj = w;

    if(i!=-1&&j!=-1)
        if(i==-1)printf("%c���㲻���ڣ�",v1);
        else if(j==-1)printf("%c���㲻���ڣ�",v2);
        else printf("%c��%c���㲻���ڣ�",v1,v2);




    //if(IncInfo)
        //InputInfo((*G).arcs[i][j].info);
      //  printf("���������Ϣʡ�ԡ�");

}

return 1;
}

void PrintGraph(MGraph *G){
    int i,j;
    int ilength=G->vexnum,jlength=G->arcnum;
    for(i=0;i<ilength;i++)
        printf("%c%c",G->vexs[i],i<ilength?'\t':'\n');
    for(i=0;i<ilength;i++){
        printf("%c\t",G->vexs[i]);
    for(j=0;j<ilength;j++){
        printf("%d\t",G->arcs[i][j].adj);
        }
    }
}


status LocateVex(MGraph *G,VertexType v){
    int i;
    for(i=0;i<G->vexnum;i++)
        if(strcmp(G->vexs[i],v)==0)
            return i;
    return -1;
}



int main()
{

    MGraph *G=NULL;
    CreatUDN(G);
    PrintGraph(G);
    printf("Hello world!\n");
    return 0;
}
