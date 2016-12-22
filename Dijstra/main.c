#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<limits.h>
#include<io.h>

#include<process.h>//exit()
//#define TRUE 1
#define ERROR 0
#define INFINITY INT_MAX
#define Max_value 100

typedef int bool;
#define true 1
#define false 0

//enum boolean{FALSE,TRUE};
typedef char VertexType[50];/*�������� �����ַ�����*/
typedef int VRType;

typedef struct ArcCell{
    VRType adj;
    VRType cost;
}ArcCell,Adjmatrix[Max_value][Max_value];

typedef struct{
    VertexType Vexs[Max_value];  //����
    Adjmatrix arcs; //�ڽӾ���
    int vexnum;//������
    int arcnum;//����
}MGraph;

//char pass_key[10];//��ʼ����




int p[Max_value][Max_value][Max_value], D[Max_value][Max_value],
    pcost[Max_value][Max_value][Max_value], Dcost[Max_value][Max_value];
int P[50][50];
int D2[Max_value],P2[Max_value];


//��ģʽ
void menu(MGraph *G);
//����Աģʽ
void Manger_Menu(MGraph *G);
void User_Menu(MGraph *G);

int LocateVex(MGraph G,VertexType elem);//��ͼG����elemλ��
//����ͼ
void CreatMG(MGraph *G);
//�Զ�����ͼ
void AutoCreatMG(MGraph *G);

//��ѯ���м������Ϣ ��ѯ���м��Ƿ��ֱ��
void Query_City_Adj(MGraph *G);


//��ѯ���м����·��
void Query(MGraph *G);

//void ShortestCost_FLOYD(MGraph *G);

//�������������·��
void ShortestPath_FLOYD(MGraph *G);
//�������������ٷ���
void ShortestCost_FLOYD(MGraph *G);
void Query_Lowest_Cost(MGraph *G);
//�޸ĳ�����
void Modify_City(MGraph *G);

//��������
int Pass_word();
void City_List(MGraph *G);

//��ӳ���
void  Add_City(MGraph *G);

//ɾ������
void Delete_City(MGraph *G);

//�޸ĳ��м������Ϣ
void Modify_City_Adj(MGraph *G);

//��ӳ��м������Ϣ
void Add_City_Adj(MGraph *G);

//ɾ�����м����
void Delete_City_Adj(MGraph *G);


//��Դ����
void Query_simpleToOther(MGraph *G);


//�޸ĳ��м���û���
void Modify_City_Cost(MGraph *G);





//����Ա��¼����
void menu(MGraph *G){
    int slec;
    while(1){
    system("cls");
    printf("-------------------------ѡ��-------------------------->\n");
    printf("\t\t    1.������ģʽ\n");
    printf("\t\t    2.�û�ģʽ\n");
    printf("\t\t    0.�˳�\n");
    printf("------------------------------------------------------->\n");
    printf("���ѡ��");
    scanf("%d",&slec);

    switch(slec){
    case 1 : if(Pass_word()){
                    Manger_Menu(G);
            }
            else
                printf("������������\n");
            break;//������Ҫ�������
    case 2 : User_Menu(G);break;
    case 0 : exit(0);
    default : printf("��������\n");break;
        }
    getchar();
    getchar();
    }
}


int Pass_word(){
    //char sc[10];
    int pass_key=741;
    int sc=0;
    printf("���������룺");
    scanf("%d",&sc);

    if(sc==pass_key){//strcmp(sc,pass_key)
            printf("�ɹ���¼������ģʽ\n");
  getchar();getchar();
        return 1;
    }else
        return 0;

}


void Manger_Menu(MGraph *G){
    int select=0;

    while(1){
    system("cls");
    printf("---------------------------������ģʽ------------------------------->\n\n");
    printf("  1.��ԭ���н�ͨ����ͼ    \t\t2.��ѯ���м�������-·��\n");
    printf("  3.�޸ĳ�������          \t\t4.��ӳ���\n");
    printf("  5.ɾ��������            \t\t6.�޸������м������Ϣ\n");
    printf("  7.��������м������Ϣ  \t\t8.ɾ�������м������Ϣ\n");
    printf("  9.��ѯ���м��Ƿ��ֱ��  \t\t10.��Դ���·��\n");
    printf("  11.�鿴�����б�         \t\t12.��ѯ���н�ͨ���ٻ���\n");
    printf("  13.�޸ĳ��м佻ͨ����   \t\t14.������һ���˵�\n");
    printf("  0.�˳�\n\n");
    printf("--------------------------------------------------------------------->\n");
    printf("���ѡ��");
    scanf("%d",&select);
    switch(select){
        case 1 : AutoCreatMG(G);printf("��ԭ������Ϣ...\n��ԭ���м������Ϣ......\n");
                  printf("��ԭ���м佻ͨ������Ϣ.........\n��ԭ���н�ͨ����ͼ�ɹ���\n");  break;//printf("�ɹ�������ͨ����ͼ\n");City_List(G);break;
        case 2 : Query(G);break;
        case 3 : Modify_City(G);break;
        case 4 : Add_City(G);break;
        case 5 : Delete_City(G);break;
        case 6 : Modify_City_Adj(G);break;
        case 7 : Add_City_Adj(G);break;
		case 8 : Delete_City_Adj(G);break;
		case 9 : Query_City_Adj(G);break;
        case 10: Query_simpleToOther(G);break;
        case 11: City_List(G);break;
        case 12: Query_Lowest_Cost(G);break;
        case 13: Modify_City_Cost(G);break;
        case 14: menu(G);break;
        case 0 : exit(0);
        default : printf("��������\n");break;
    }
     getchar();
    getchar();
    }

}

void User_Menu(MGraph *G){
    int select=0;
    while(1){
    system("cls");
    printf("---------------------------��ӭʹ�ý�ͨ��ѯϵͳ--------------------------->\n\n");
    printf("\t1.��ѯ���н�ͨ��̾�����Ϣ\t2.��ѯ���н�ͨ���ٻ���\n");
    printf("\t3.�鿴�����б�            \t4.��ѯ���м��Ƿ��ֱ��\n");
    printf("\t5.��Դ���·��            \t6.������һ���˵�\n");
    printf("\t0.�˳�\n\n");
    printf("-------------------------------------------------------------------------->\n");
    printf("���������ѡ��");
    scanf("%d",&select);
    switch(select){
        case 1 : Query(G);break;
        case 2 : Query_Lowest_Cost(G);break;
        case 3 : City_List(G);break;
        case 4 : Query_City_Adj(G);break;
        case 5 : Query_simpleToOther(G);break;
        case 6 : menu(G);break;
        case 0 : exit(0);
        default : printf("��������\n");break;
    }
     getchar();
    getchar();
    }

}




void City_List(MGraph *G){
     int i=1;
     int j=1;
     int t=0;
    printf("-------------------------------�����б�------------------------------------->\n");
    /*
	printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t\n",j++,G->Vexs[i++]);
   */


  // printf("%s,%s,%s,%s\n",G->Vexs[26],G->Vexs[27],G->Vexs[28],G->Vexs[29]);
    while(strcmp(G->Vexs[i],"NULL")!=0&&i<50){//||strcmp(G->Vexs[i],"-��ɾ��-")!=0
          if(j==26){printf("\n�������У�\n");t=0;}
          printf("\t%d.%s            ",j++,G->Vexs[i++]); t++;
          if(t%3==0)printf("\n");
                                          }
    printf("\n");
    printf("----------------------------------------------------------------------------->\n");
    /*
    printf("\t1.%s\t2.����\t\t3.����\n",G->Vexs[1]);
    printf("\t4.���ͺ���\t5.����\t\t6.���\n");
    printf("\t7.����\t\t8.����\t\t9.������\n");
    printf("\t10.����\t\t11.����\t\t12.֣��\n");
    printf("\t13.����\t\t14.�ɶ�\t\t15.�人\n");
    printf("\t16.�Ϻ�\t\t17.����\t\t18.�ϲ�\n");
    printf("\t19.����\t\t20.����\t\t21.����\n");
    printf("\t22.����\t\t23.����\t\t24.����\n");
    printf("\t25.����\t\t\n");
    */

    /*
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t%d.%s    \t\t%d.%s   \t\t%d.%s\n",j++,G->Vexs[i++],j++,G->Vexs[i++],j++,G->Vexs[i++]);
    printf("\t7.%s    \t\t8.%s   \t\t9.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t10.%s   \t\t11.%s  \t\t12.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t13.%s   \t\t14.%s  \t\t15.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t16.%s   \t\t17.%s  \t\t18.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t19.%s   \t\t20.%s  \t\t21.%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t22.%s   \t\t23.%s  \t\t24%s\n",G->Vexs[i++],G->Vexs[i++],G->Vexs[i++]);
    printf("\t25.%s   \t\t\n");
    */
}

//��ͼG���ҵ�elem
int LocateVex(MGraph G,VertexType elem){
    int i;
    for(i=1;i<=G.vexnum;i++){
        if(strcmp(elem,G.Vexs[i]) == 0)
            return i;
    }
    return -1;//����0
}

//�ֶ�����ͼ �ڽӾ���
void CreatMG(MGraph *G){
    int i,j,k,l,w;
    VertexType a,b;
    printf("������ͼ�Ķ�������������");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    printf("������ÿ�������ֵ\n");
    for(i=1;i<=G->vexnum;i++){
        //G->Vexs[i]=(Vertextype)malloc(sizeof(char)*10);
        scanf("%s",&(G->Vexs[i]));
    }
    //��ʼ���ڽӾ���
    //memset(G->arcs,0,sizeof(G->arcs));
    for(i=1;i<=G->vexnum;++i)/*��ʼ���ڽӾ���*/
		for(j=1;j<=G->vexnum;++j){
			G->arcs[i][j].adj=INFINITY;/*��*/
			G->arcs[i][j].cost=INFINITY;
			//(*G).arcs[i][j].info=NULL;/*û�������Ϣ*/
		}

    printf("�����뻡�Ļ�β����ͷ(�Կո�Ϊ���):\n");
    for(k=1;k<=G->arcnum;k++){
        printf("�������%d��������㡢�յ�:\n",k);
        scanf("%s%s*c",a,b);
        printf("������û���Ӧ��Ȩֵ��");
        scanf("%d",&w);
        i = LocateVex(*G,a);
        j = LocateVex(*G,b);
        G->arcs[i][j].adj = G->arcs[j][i].adj = w;//��λȨֵ

    }
    printf("\n");

    // return TRUE;
}

void AutoCreatMG(MGraph *G){
    int i=1,j,k,w;
    int t=0;
    G->arcnum = 30;

    while(t<50){
            strcpy(G->Vexs[t++],"NULL");
             }

    strcpy(G->Vexs[0],"�ó��в�����");
    strcpy(G->Vexs[i++],"��³ľ��");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"���ͺ���");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"���");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"������");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"֣��");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"�ɶ�");
    strcpy(G->Vexs[i++],"�人");
    strcpy(G->Vexs[i++],"�Ϻ�");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"�ϲ�");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");
    strcpy(G->Vexs[i++],"����");

    /*
    G->Vexs[i++] = "��³ľ��";
    G->Vexs[i++] = "����";
    G->Vexs[i++] = "����";
    G->Vexs[i++] = "���ͺ���";
    G->Vexs[i++] = "����";
    G->Vexs[i++] = "���";
    G->Vexs[i++] = "����";
    G->Vexs[i++] = "����";
    G->Vexs[i++] = "������";
    G->Vexs[i++] = "����";
    G->Vexs[i++] = "����";
    G->Vexs[i++] = "֣��";
    G->Vexs[i++] = "����";
*/
    G->vexnum = i - 1;
    t = i-1;
    if(t<50){


             }

   // memset(G->arcs,0,sizeof(G->arcs));
   for(i=1;i<=G->vexnum;i++)/*��ʼ���ڽӾ���*/
		for(j=1;j<=G->vexnum;j++){
			G->arcs[i][j].adj=INFINITY;/*��*/  //���
			G->arcs[i][j].cost=INFINITY;//����
			//(*G).arcs[i][j].info=NULL;/*û�������Ϣ*/
		}
    //��̺ͷ��û���
    G->arcs[1][3].adj = G->arcs[3][1].adj = 1892;G->arcs[1][3].cost = G->arcs[3][1].cost = 328;
    G->arcs[2][3].adj = G->arcs[3][2].adj = 216;G->arcs[2][3].cost = G->arcs[3][2].cost = 189;
    G->arcs[3][4].adj = G->arcs[4][3].adj = 1145;G->arcs[3][4].cost = G->arcs[4][3].cost = 201;
    G->arcs[4][5].adj = G->arcs[5][4].adj = 668;G->arcs[4][5].cost = G->arcs[5][4].cost = 176;
    G->arcs[5][6].adj = G->arcs[6][5].adj = 137;G->arcs[5][6].cost = G->arcs[6][5].cost = 80;
    G->arcs[6][7].adj = G->arcs[7][6].adj = 704;G->arcs[6][7].cost = G->arcs[7][6].cost = 305;
    G->arcs[7][8].adj = G->arcs[8][7].adj = 305;G->arcs[7][8].cost = G->arcs[8][7].cost = 232;
    G->arcs[8][9].adj = G->arcs[9][8].adj = 242;G->arcs[8][9].cost = G->arcs[9][8].cost = 211;
    G->arcs[7][10].adj = G->arcs[10][7].adj = 397;G->arcs[7][10].cost = G->arcs[10][7].cost = 277;
    G->arcs[6][11].adj = G->arcs[11][6].adj = 674;G->arcs[6][11].cost = G->arcs[11][6].cost = 222;
    G->arcs[5][12].adj = G->arcs[12][5].adj = 695;G->arcs[5][12].cost = G->arcs[12][5].cost = 120;
    G->arcs[11][12].adj = G->arcs[12][11].adj = 349;G->arcs[11][12].cost = G->arcs[12][11].cost = 109;
    G->arcs[12][13].adj = G->arcs[13][12].adj = 511;G->arcs[12][13].cost = G->arcs[13][12].cost = 243;
    G->arcs[3][13].adj = G->arcs[13][3].adj = 676;G->arcs[3][13].cost = G->arcs[13][3].cost = 321;
    G->arcs[13][14].adj = G->arcs[14][13].adj = 842;G->arcs[13][14].cost = G->arcs[14][13].cost = 301;
    G->arcs[12][15].adj = G->arcs[15][12].adj = 534;G->arcs[12][15].cost = G->arcs[15][12].cost = 411;
    G->arcs[11][16].adj = G->arcs[16][11].adj = 651;G->arcs[11][16].cost = G->arcs[16][11].cost = 316;
    G->arcs[14][21].adj = G->arcs[21][14].adj = 1100;G->arcs[14][21].cost = G->arcs[21][14].cost = 623;
    G->arcs[14][20].adj = G->arcs[20][14].adj = 967;G->arcs[14][20].cost = G->arcs[20][14].cost = 588;
    G->arcs[15][19].adj = G->arcs[19][15].adj = 409;G->arcs[15][19].cost = G->arcs[19][15].cost = 200;
    G->arcs[16][18].adj = G->arcs[18][16].adj = 825;G->arcs[16][18].cost = G->arcs[18][16].cost = 349;
    G->arcs[17][18].adj = G->arcs[18][17].adj = 622;G->arcs[17][18].cost = G->arcs[18][17].cost = 211;
    G->arcs[18][19].adj = G->arcs[19][18].adj = 367;G->arcs[18][19].cost = G->arcs[19][18].cost = 270;
    G->arcs[19][20].adj = G->arcs[20][19].adj = 902;G->arcs[19][20].cost = G->arcs[20][19].cost = 462;
    G->arcs[19][23].adj = G->arcs[23][19].adj = 672;G->arcs[19][23].cost = G->arcs[23][19].cost = 323;
    G->arcs[19][24].adj = G->arcs[24][19].adj = 675;G->arcs[19][24].cost = G->arcs[24][19].cost = 320;
    G->arcs[20][23].adj = G->arcs[23][20].adj = 607;G->arcs[20][23].cost = G->arcs[23][20].cost = 450;
    G->arcs[20][21].adj = G->arcs[21][20].adj = 639;G->arcs[20][21].cost = G->arcs[21][20].cost = 471;
    G->arcs[22][23].adj = G->arcs[23][22].adj = 255;G->arcs[22][23].cost = G->arcs[23][22].cost = 177;
    G->arcs[24][25].adj = G->arcs[25][24].adj = 140;G->arcs[24][25].cost = G->arcs[25][24].cost = 56;
    return ;
}

//�������������ٻ���

void ShortestCost_FLOYD(MGraph *G)//, int p[Max_value][Max_value][Max_value], int D[Max_value][Max_value])
{
    int u, v, w, i, j;

    for(v=1; v<=G->vexnum; v++)
        for(w=1; w<=G->vexnum; w++)
        {
            Dcost[v][w] = G->arcs[v][w].cost;//����
            for(u=1; u<=G->vexnum; u++){
                pcost[v][w][u] = -1;//����
            }

            if(Dcost[v][w] < INFINITY)
            {
                pcost[v][w][0]=v;
                pcost[v][w][1]=w;
            }
        }
        for(u=1; u<=G->vexnum; u++)
            for(v=1; v<=G->vexnum; v++)
                for(w=1; w<=G->vexnum; w++)
                    if(Dcost[v][u] < INFINITY && Dcost[u][w] < INFINITY && Dcost[v][u]+Dcost[u][w] < Dcost[v][w])
                    {
                        //����Dcost
                        Dcost[v][w]=Dcost[v][u]+Dcost[u][w];
                        for(i=1; i<=G->vexnum; i++)
                        {
                            if(pcost[v][u][i]!=-1)
                                pcost[v][w][i]=pcost[v][u][i];
                            else
                                break;
                        }
                        for(j=1; j<=G->vexnum; j++)//ע�⣺����j��1��ʼ�����Ǵ�0��ʼ����Ϊ��v��u��·�����һ��������u,
                            //����u��w��·����һ��������u��ֻ���ӡuһ�μ��ɡ�
                        {
                            if(pcost[u][w][j]!=-1)
                                pcost[v][w][i++]=pcost[u][w][j];
                            else
                                break;
                       }
            }
}



//�������ٻ���
//��ѯ���м����ٻ���
void Query_Lowest_Cost(MGraph *G){
    int i,j,k;
    VertexType cha;
    City_List(G);

    ShortestCost_FLOYD(G);//,&p,&D);

    printf("��������������ţ�");
    scanf("%d",&i);
    printf("����������յ���ţ�");
    scanf("%d",&j);
    printf("--->");
    printf("��ѯ��Ϣ������£�\n");
    printf("---------------------------------------------------------------------------\n");
    if(i<=G->vexnum&&j<=G->vexnum&&i>0&&j>0) {//����
     if(i!=j)
        if(Dcost[i][j]!=INFINITY){
        //if(G->arcs[i][j].adj!=INFINITY){
            printf("%s   ��   %s ���ٻ�����%d\n",G->Vexs[i],G->Vexs[j],Dcost[i][j]);
            printf("\n");
            printf("���ٻ�����Ϊ��%s",G->Vexs[i]);
            for(k=1;k<G->vexnum;k++){
                if(pcost[i][j][k]!=-1)//&&strcmp(G->Vexs[p[i][j][k]],cha)!=0)
                {
                    if(strcmp(G->Vexs[pcost[i][j][k]],cha) == 0)
                        continue;
                     printf("->%s",G->Vexs[pcost[i][j][k]]);
                     strcpy(cha,G->Vexs[pcost[i][j][k]]);
                     if(strcmp(cha,G->Vexs[j])== 0)
                        break;
                }
                else
                    break;
            }
            printf("\n");

        }else
        printf("%s��%s���ɴ�\n",G->Vexs[i],G->Vexs[j]);
        else
            printf("���棺�����в������յ����һ����\n");
        printf("---------------------------------------------------------------------------\n");
    }else{
        printf("���棺��������������");
    }
}


/**
�޸ĳ��м�ķ��û�����������м����ֱ��ͨ·�������������ӣ��޸ģ���
���ٵ���ʵ�֣���ӻ�������Ϊ�������Ϣ��Ӻ�ֻ���ж��Ƿ����ֱ��ͨ·��
-------�޸Ļ������ú�����ʵ��
*/
void Modify_City_Cost(MGraph *G){
    int i,j,a,b,New_Cost;
     VertexType cha,chb;
     City_List(G);
     printf("������Ҫ�޸���̵ĵ�һ��������ţ�");
     scanf("%d",&a);
     printf("������Ҫ�޸���̵ĵڶ���������ţ�");
     scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {

     if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
              printf("���棺%d.%s �� %d.%s ֮�䲻����ֱ��ͨ·\n",a,G->Vexs[a],b,G->Vexs[b]);
     else{
          printf("%s �� %s ֮�����ֱ��ͨ·�����Ϊ��%d\n",G->Vexs[a],G->Vexs[b],G->arcs[b][a].adj);
          printf("��������ã�");
          scanf("%d",&New_Cost);
          G->arcs[a][b].cost = G->arcs[b][a].adj = New_Cost;
          printf("������Ϣ¼��ɹ�\n");
          }
        } else{
		 printf("���棺��������������\n");
		 }
}





//�������������·���㷨

void ShortestPath_FLOYD(MGraph *G)//, int p[Max_value][Max_value][Max_value], int D[Max_value][Max_value])
{
    int u, v, w, i, j;

    for(v=1; v<=G->vexnum; v++)
        for(w=1; w<=G->vexnum; w++)
        {
            D[v][w]=G->arcs[v][w].adj;
            //Dcost[v][w] = G->arcs[v][w].cost;//����
            for(u=1; u<=G->vexnum; u++){
                p[v][w][u] = -1;
                //pcost[v][w][u] = -1;//����
            }

            if(D[v][w] < INFINITY)
            {
                p[v][w][0]=v;//pcost[v][w][0]=v;
                p[v][w][1]=w;//pcost[v][w][1]=w;
            }
        }
        for(u=1; u<=G->vexnum; u++)
            for(v=1; v<=G->vexnum; v++)
                for(w=1; w<=G->vexnum; w++)
                    if(D[v][u] < INFINITY && D[u][w] < INFINITY && D[v][u]+D[u][w] < D[v][w])
                    //if(D[v][u]+D[u][w] < D[v][w])
                    {
                        //����D
                        D[v][w]=D[v][u]+D[u][w];
                        //����p����v��w��·���Ǵ�v��u���ٴ�u��w������·��


                        for(i=1; i<=G->vexnum; i++)
                        {
                            if(p[v][u][i]!=-1)
                                p[v][w][i]=p[v][u][i];
                            else
                                break;
                        }
                        for(j=1; j<=G->vexnum; j++)//ע�⣺����j��1��ʼ�����Ǵ�0��ʼ����Ϊ��v��u��·�����һ��������u,
                            //����u��w��·����һ��������u��ֻ���ӡuһ�μ��ɡ�
                        {
                            if(p[u][w][j]!=-1)
                                p[v][w][i++]=p[u][w][j];
                            else
                                break;
                       }
            }
}


//�Ͻ�˹���������Դ·������

void ShortestPath_Dijkstra(MGraph *G){
    int v1;//�������
    int v,i,j,k,min_element;


}




//��ѯ���м��Ƿ��ֱ��
void Query_City_Adj(MGraph *G){
     int a,b;
      City_List(G);
      printf("��������������ţ�");
      scanf("%d",&a);
       printf("�������յ������ţ�");
      scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {

	      if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
	           printf("%s��%s�޷�ֱ��\n",G->Vexs[a],G->Vexs[b]);
	      else
	          printf("%s��%s����ֱ����Ϊ��%d\n",G->Vexs[a],G->Vexs[b],G->arcs[a][b].adj);
	     }else{

		 printf("���棺��������������\n");

		 }


     }





//�޸ĳ�����Ϣ
void Modify_City(MGraph *G){
    int i,j;
    VertexType oldCity;//�ַ���������
    printf("��������Ҫ�޸ĵĳ��е����ƣ�");
    scanf("%s",&oldCity);
    for(i=1;i<=G->vexnum;i++){
        if(strcmp(oldCity,G->Vexs[i]) == 0){
            printf("���ҵ�%d.%s\n",i,oldCity);
            printf("��������������ƣ�");
            scanf("%s",&(G->Vexs[i]));
            printf("�޸ĳɹ�\n");
            return ;
        }
    }
    printf("δ���ҵ��ó��������Ϣ��\n");

}


//��ӳ���
void  Add_City(MGraph *G){
      VertexType ch;
      int i,j,t=1;
      printf("��������Ҫ��ӵĳ�������");
      scanf("%s",&ch);
      for(i=1;i<=G->vexnum;i++)
           if(strcmp(G->Vexs[i],ch)==0)
              t=0;

      if(t==1){
      strcpy(G->Vexs[++G->vexnum],ch);
      if(strcmp(G->Vexs[G->vexnum],"NULL")!=0){
	  //���³�ʼ�����
             /*��ʼ���ڽӾ���*/
				for(j=1;j<=G->vexnum;j++){
					G->arcs[G->vexnum][j].adj=G->arcs[j][G->vexnum].adj=INFINITY;/*��*/
			//(*G).arcs[i][j].info=NULL;/*û�������Ϣ*/
		}
			  printf("��ӳ��У�%s�ɹ���\n",G->Vexs[G->vexnum]);
              }
      else
          printf("�����ʧ�ܣ���������ӣ�\n");

          }else
          printf("���棺�ó����Ѵ��ڣ���������ӣ�\n");

      }


//ɾ������
void Delete_City(MGraph *G){
     int i,j,t,k,f=0;
     VertexType ch;

    printf("��������Ҫɾ���ĳ�������");
     scanf("%s",&ch);
        for(k=1;k<=G->vexnum;k++)
            if(strcmp(G->Vexs[k],ch)==0){
               printf("���ҵ��ó��С�\n");
               f=1;
                strcpy(G->Vexs[k],"-��ɾ��-");

                t=k;
                break;
                }
            if(f==1){
                 printf("ɾ��%s�ɹ���\n",ch);

                for(i=1;i<=G->vexnum;i++)
                   for(j=1;j<=G->vexnum;j++)
                     if(i==t||j==t)
                         G->arcs[i][j].adj = G->arcs[j][i].adj= INFINITY;
                     else
                       continue;
                 printf("������·�߳ɹ���\n");
                }else{

                      printf("���棺δ���ҵ��ó��У���ȷ�ϸó����Ƿ���ڣ�\n");
                      }




                   }



//�޸ĳ��м������Ϣ
void Modify_City_Adj(MGraph *G){
     int i,j,a,b,distance;
     VertexType cha,chb;
     City_List(G);
     printf("������Ҫ�޸���̵ĵ�һ��������ţ�");
     scanf("%d",&a);
     printf("������Ҫ�޸���̵ĵڶ���������ţ�");
     scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {

     if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
              printf("���棺%d.%s �� %d.%s ֮�䲻����ֱ��ͨ·\n",a,G->Vexs[a],b,G->Vexs[b]);
     else{
          printf("%s �� %s ֮�����Ϊ��%d\n",G->Vexs[a],G->Vexs[b],G->arcs[b][a].adj);
          printf("������Ҫ�µ���̣�");
          scanf("%d",&distance);
          G->arcs[a][b].adj = G->arcs[b][a].adj = distance;
          printf("�޸���̳ɹ�\n");
          }
        } else{

		 printf("���棺��������������\n");
		 }
     }



//��ӳ��м������Ϣ
void Add_City_Adj(MGraph *G){
     int i,j,a,b,distance;
     VertexType cha,chb;
     City_List(G);
     printf("������Ҫ�����̵ĵ�һ��������ţ�");
     scanf("%d",&a);
     printf("������Ҫ�����̵ĵڶ���������ţ�");
     scanf("%d",&b);
     if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {
	     if(G->arcs[a][b].adj!=INFINITY&&G->arcs[b][a].adj!=INFINITY)
	              printf("���棺%d.%s �� %d.%s ֮���Ѵ���ֱ��ͨ·,���Ϊ��%d\n",a,G->Vexs[a],b,G->Vexs[b],G->arcs[b][a].adj);
	     else{
	          printf("��������̣�");
	          scanf("%d",&distance);
	           G->arcs[a][b].adj = G->arcs[b][a].adj = distance;
	           printf("��ӳ��м���̳ɹ�\n");
	          }
	        }else{
	        		 printf("���棺��������������\n");
	        }

     }

//ɾ�����м����
void Delete_City_Adj(MGraph *G){
      int i,j,a,b,distance;
     VertexType cha,chb;
     City_List(G);
     printf("--->���ѣ�������Ϣ����������������Ч��� 0 ��ȡ��������\n");

     printf("������Ҫɾ����̵ĵ�һ��������ţ�");
     scanf("%d",&a);
     if(a!=0){
     printf("������Ҫɾ����̵ĵڶ���������ţ�");
     scanf("%d",&b);
      if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {
	     if(G->arcs[a][b].adj==INFINITY&&G->arcs[b][a].adj==INFINITY)
	              printf("���棺%d.%s �� %d.%s ֮�䲻����ֱ��ͨ·\n",a,G->Vexs[a],b,G->Vexs[b]);
	      else{
	           G->arcs[a][b].adj = G->arcs[b][a].adj = INFINITY;
	           G->arcs[a][b].cost = G->arcs[b][a].cost = INFINITY;
	           printf("ɾ�������Ϣ�ɹ�\n");

	           }
 		}else{
 			 printf("���棺��������������\n");
                }
            }
            else
                printf("��ȡ����\n");
     }




//��ӡ
/**
��Ļ��С�������� �þ����޷�����չ��
*/
void Print_MGraph(MGraph *G){
    int i,j;
    for(i=1;i<=G->vexnum;i++)
        printf("\t%s",G->Vexs[i]);
    printf("\n");
    for(i=1;i<=G->vexnum;i++){
         printf("%s\t",G->Vexs[i]);
    for(j=1;j<=G->vexnum;j++)
        if (G->arcs[i][j].adj == INFINITY)
            printf("0\t");
        else
            printf("%d\t",G->arcs[i][j].adj);
    printf("\n");
    }
}


//��ѯ���м����·��
void Query(MGraph *G){
    int i,j,k;
    VertexType cha;
     City_List(G);

    ShortestPath_FLOYD(G);//,&p,&D);



    printf("��������������ţ�");
    scanf("%d",&i);
    printf("����������յ���ţ�");
    scanf("%d",&j);
    printf("--->");
    printf("��ѯ��Ϣ������£�\n");
    printf("---------------------------------------------------------------------------\n");
   if(i<=G->vexnum&&j<=G->vexnum&&i>0&&j>0) {
    if(i!=j)
        if(D[i][j]!=INFINITY){
        //if(G->arcs[i][j].adj!=INFINITY){
            printf("%d.%s\t��\t%d.%s �����̣�%d\n",i,G->Vexs[i],j,G->Vexs[j],D[i][j]);
            printf("^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n");
            printf("���·��Ϊ��%s",G->Vexs[i]);
            for(k=1;k<G->vexnum;k++){
                if(p[i][j][k]!=-1)//&&strcmp(G->Vexs[p[i][j][k]],cha)!=0)
                {
                    if(strcmp(G->Vexs[p[i][j][k]],cha) == 0)//����Ϣ������ϴδ�ӡһ��������������Ϣ
                        continue;
                     printf("->%s",G->Vexs[p[i][j][k]]);
                     strcpy(cha,G->Vexs[p[i][j][k]]);
                     if(strcmp(cha,G->Vexs[j])== 0)//����ѵ����յ�����ֹ
                        break;
                }
                else
                    break;
            }
            printf("\n");

        }else
        printf("%s��%s���ɴ�\n",G->Vexs[i],G->Vexs[j]);
        else
            printf("���棺�����в������յ����һ����\n");

        printf("---------------------------------------------------------------------------\n");
        }else{
           printf("���棺��������������\n");
        }
}


/**
����Ҫ�����Դ���������и���������·�����ȡ�
����ĳ��Ⱦ���ָ·�ϸ���Ȩ֮�͡�
�������ͨ����Ϊ��Դ���·������
                --�ٶȰٿ�
*/
//��Դ����
//��ѯ���������·��
void Query_simpleToOther(MGraph *G){
    int i,j,k;
    VertexType cha;
     City_List(G);

    ShortestPath_FLOYD(G);//,&p,&D);



    printf("��������������ţ�");
    scanf("%d",&i);
    //printf("����������յ���ţ�");
    //scanf("%d",&j);
    if(i>0&&i<=G->vexnum){
    printf("--->");
    printf("��ѯ��Ϣ������£�\n");
    printf("---------------------------------------------------------------------------\n");
    printf("������\t���·��\n");
    for(j=1;j<=G->vexnum;j++){
    if(i!=j)
        if(D[i][j]!=INFINITY){
        //if(G->arcs[i][j].adj!=INFINITY){
            //printf("%d.%s\t��\t%d.%s �����̣�%d\t",i,G->Vexs[i],j,G->Vexs[j],D[i][j]);
            printf("%d\t",D[i][j]);
           // printf("^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n");
            printf("\t%s",G->Vexs[i]);
            for(k=1;k<G->vexnum;k++){
                if(p[i][j][k]!=-1)//&&strcmp(G->Vexs[p[i][j][k]],cha)!=0)
                {
                    if(strcmp(G->Vexs[p[i][j][k]],cha) == 0)
                        continue;
                     printf("->%s",G->Vexs[p[i][j][k]]);
                     strcpy(cha,G->Vexs[p[i][j][k]]);
                     if(strcmp(cha,G->Vexs[j])== 0)
                        break;
                }
                else
                    break;
            }
            printf("\n");

        }else
        printf("%s��%s���ɴ�\n",G->Vexs[i],G->Vexs[j]);
        else
            continue;//printf("���棺�����в������յ����һ����\n");
        }
    printf("---------------------------------------------------------------------------\n");
    }else
    printf("���棺��������������\n");
}




void Dijkstra(int n, int v, int *dist, int *prev, int c[Max_value][Max_value])
{
    int i,j;
    bool s[Max_value];    // �ж��Ƿ��Ѵ���õ㵽S������
    for(i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     // ��ʼ��δ�ù��õ�
        if(dist[i] == INFINITY)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
    // һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
    for(i=2; i<=n; ++i)
    {
        int tmp = INFINITY;
        int u = v;
        // �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
        for(j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
                tmp = dist[j];
            }
        s[u] = 1;    // ��ʾu���Ѵ���S������

        // ����dist
        for(j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<INFINITY)
            {
                int newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}




void searchPath(int *prev,int v, int u)
{
    int i,j;
    int que[Max_value];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(i=tot; i>=1; --i)
        if(i != 1)
            printf("%d->",que[i]);// << " -> ";
        else
            printf("%d",que[i]);
}






//������
int main()
{
    MGraph *G=NULL;
    int i,j,v,w,k;
    G = (MGraph *)malloc(sizeof(MGraph));
    //�ֶ�����
    //CreatMG(G);
     //�Զ��������н�ͨͼ
    AutoCreatMG(G);
    // ���·������

     int dist[Max_value];     // ��ʾ��ǰ�㵽Դ������·������
    int prev[Max_value];     // ��¼��ǰ���ǰһ�����
    int c[Max_value][Max_value];   // ��¼ͼ�������·������
    int n, line;             // ͼ�Ľ������·����
    Dijkstra(G->vexnum, 0, dist, prev, c);
    printf("Դ�㵽���һ����������·������:%d ",dist[n]);

    // ·��
    printf("Դ�㵽���һ�������·��Ϊ: \n");
    searchPath(prev, 1, G->vexnum);

     //�˵�
     menu(G);

    return 0;
}


