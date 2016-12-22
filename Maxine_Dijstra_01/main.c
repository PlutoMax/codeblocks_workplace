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


//enum boolean{FALSE,TRUE};
typedef char VertexType[50];/*�������� �����ַ�����*/
typedef int VRType;
typedef int bool;
#define true 1
#define false 0

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

//���ӳ���
void  Add_City(MGraph *G);

//ɾ������
void Delete_City(MGraph *G);

//�޸ĳ��м������Ϣ
void Modify_City_Adj(MGraph *G);

//���ӳ��м������Ϣ
void Add_City_Adj(MGraph *G);

//ɾ�����м����
void Delete_City_Adj(MGraph *G);


//��Դ����
void Query_simpleToOther(MGraph *G);


//�޸ĳ��м���û���
void Modify_City_Cost(MGraph *G);

void Dij_Get_shortPath(MGraph *G);



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
    printf("  3.�޸ĳ�������          \t\t4.���ӳ���\n");
    printf("  5.ɾ��������            \t\t6.�޸������м������Ϣ\n");
    printf("  7.���������м������Ϣ  \t\t8.ɾ�������м������Ϣ\n");
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
        case 5 : //Get_Dijkstra_0002(G);
                Dij_Get_shortPath(G);
                 //Query_simpleToOther(G);
                 break;
        case 6 : menu(G);break;
        case 0 : exit(0);
        default : printf("��������\n");break;
    }
     getchar();
    getchar();
    }

}




void City_List(MGraph *G){
     int i=0;
     int j=0;
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
    int i=0,j,k,w;
    int t=0;
    G->arcnum = 30;

    while(t<50){
            strcpy(G->Vexs[t++],"NULL");
             }

    //strcpy(G->Vexs[0],"�ó��в�����");
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


   // memset(G->arcs,0,sizeof(G->arcs));
   for(i=0;i<G->vexnum;i++)/*��ʼ���ڽӾ���*/
		for(j=0;j<G->vexnum;j++){
			G->arcs[i][j].adj=INFINITY;/*��*/  //���
			G->arcs[i][j].cost=INFINITY;//����
			//(*G).arcs[i][j].info=NULL;/*û�������Ϣ*/
		}
    //��̺ͷ��û���
    G->arcs[0][2].adj = G->arcs[2][0].adj = 1892;G->arcs[0][2].cost = G->arcs[2][0].cost = 328;
    G->arcs[1][2].adj = G->arcs[2][1].adj = 216;G->arcs[2][3].cost = G->arcs[3][2].cost = 189;
    G->arcs[2][3].adj = G->arcs[3][2].adj = 1145;G->arcs[3][4].cost = G->arcs[4][3].cost = 201;
    G->arcs[3][4].adj = G->arcs[4][3].adj = 668;G->arcs[4][5].cost = G->arcs[5][4].cost = 176;
    G->arcs[4][5].adj = G->arcs[5][4].adj = 137;G->arcs[5][6].cost = G->arcs[6][5].cost = 80;
    G->arcs[5][6].adj = G->arcs[6][5].adj = 704;G->arcs[6][7].cost = G->arcs[7][6].cost = 305;
    G->arcs[6][7].adj = G->arcs[7][6].adj = 305;G->arcs[7][8].cost = G->arcs[8][7].cost = 232;
    G->arcs[7][8].adj = G->arcs[8][7].adj = 242;G->arcs[8][9].cost = G->arcs[9][8].cost = 211;
    G->arcs[6][9].adj = G->arcs[9][6].adj = 397;G->arcs[7][10].cost = G->arcs[10][7].cost = 277;
    G->arcs[5][10].adj = G->arcs[10][5].adj = 674;G->arcs[6][11].cost = G->arcs[11][6].cost = 222;
    G->arcs[4][11].adj = G->arcs[11][4].adj = 695;G->arcs[5][12].cost = G->arcs[12][5].cost = 120;
    G->arcs[10][11].adj = G->arcs[11][10].adj = 349;G->arcs[11][12].cost = G->arcs[12][11].cost = 109;
    G->arcs[11][12].adj = G->arcs[12][11].adj = 511;G->arcs[12][13].cost = G->arcs[13][12].cost = 243;
    G->arcs[2][12].adj = G->arcs[12][2].adj = 676;G->arcs[3][13].cost = G->arcs[13][3].cost = 321;
    G->arcs[12][13].adj = G->arcs[13][12].adj = 842;G->arcs[13][14].cost = G->arcs[14][13].cost = 301;
    G->arcs[11][14].adj = G->arcs[14][11].adj = 534;G->arcs[12][15].cost = G->arcs[15][12].cost = 411;
    G->arcs[10][15].adj = G->arcs[15][10].adj = 651;G->arcs[11][16].cost = G->arcs[16][11].cost = 316;
    G->arcs[13][20].adj = G->arcs[20][13].adj = 1100;G->arcs[14][21].cost = G->arcs[21][14].cost = 623;
    G->arcs[13][19].adj = G->arcs[19][13].adj = 967;G->arcs[14][20].cost = G->arcs[20][14].cost = 588;
    G->arcs[14][18].adj = G->arcs[18][14].adj = 409;G->arcs[15][19].cost = G->arcs[19][15].cost = 200;
    G->arcs[15][17].adj = G->arcs[17][15].adj = 825;G->arcs[16][18].cost = G->arcs[18][16].cost = 349;
    G->arcs[16][17].adj = G->arcs[17][16].adj = 622;G->arcs[17][18].cost = G->arcs[18][17].cost = 211;
    G->arcs[17][18].adj = G->arcs[18][17].adj = 367;G->arcs[18][19].cost = G->arcs[19][18].cost = 270;
    G->arcs[18][19].adj = G->arcs[19][18].adj = 902;G->arcs[19][20].cost = G->arcs[20][19].cost = 462;
    G->arcs[18][22].adj = G->arcs[22][18].adj = 672;G->arcs[19][23].cost = G->arcs[23][19].cost = 323;
    G->arcs[18][23].adj = G->arcs[23][18].adj = 675;G->arcs[19][24].cost = G->arcs[24][19].cost = 320;
    G->arcs[19][22].adj = G->arcs[22][17].adj = 607;G->arcs[20][23].cost = G->arcs[23][20].cost = 450;
    G->arcs[19][20].adj = G->arcs[20][19].adj = 639;G->arcs[20][21].cost = G->arcs[21][20].cost = 471;
    G->arcs[21][22].adj = G->arcs[22][21].adj = 255;G->arcs[22][23].cost = G->arcs[23][22].cost = 177;
    G->arcs[23][24].adj = G->arcs[24][23].adj = 140;G->arcs[24][25].cost = G->arcs[25][24].cost = 56;
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
�޸ĳ��м�ķ��û�����������м����ֱ��ͨ·���������������ӣ��޸ģ���
���ٵ���ʵ�֣����ӻ�������Ϊ�������Ϣ���Ӻ�ֻ���ж��Ƿ����ֱ��ͨ·��
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

void ShortestPath_Dijkstra(MGraph *G,int v0,int p[][Max_value],int D[]){
    int v,w,i,j,min;//�������
    bool final[50];

    for(v=0;v<G->vexnum;v++){
        final[v]=false;//���ó�ʼֵ
        D[v]=G->arcs[v0][v].adj;////D[]���v0��v����̾��룬��ֵΪv0��v��ֱ�Ӿ���
        for(w=0;w<G->vexnum;w++){
            p[v][w]=-1;////��p[][]��ֵΪ-1����û��·��
        }
        if(D[v]<INFINITY){//v0��v��ֱ��·��
            p[v][0]=v0;//v0��v���·�������ĵ�һ������
            p[v][1]=v;//v0��v���·�������ĵڶ�������
        }
    }
    D[v0]=0;//v0��v0����Ϊ0
    final[v0]=true;//v0���㲢�뼯

    for(i=1;i<G->vexnum;i++){//����G.vexnum-1������
        //��ʼ��ѭ����ÿ�����v0��ĳ������v�����·��������v����S����Ȼ�����p��D
        min = INFINITY;
        for(w=0;w<G->vexnum;w++){//�����ж�����
            if(!final[w] && D[w]<min)//��S��֮��(��final[]=false)��
            //����������v0����Ķ��㣬���丳��v,���븳��min
            {
                v = w;
                min = D[w];
            }
            final[v] = true;//v����S��
        }
        for(w=0;w<G->vexnum;w++){//�����²���Ķ��㣬���²���S���Ķ��㵽v0�ľ����·������
            if(!final[w] && min<INFINITY && G->arcs[v][w].adj<INFINITY &&(min+G->arcs[v][w].adj<D[w]))
            {//w������S����v0->v->w�ľ���<Ŀǰv0->w�ľ���
                D[w]=min + G->arcs[v][w].adj;//����D[w]
                for(j=0;j<G->vexnum;j++)////�޸�p[w]��v0��w�����Ķ������v0��v���������ж����ټ��϶���w
                {
                    p[w][j]=p[v][j];
                    if(p[w][j]==-1)//��p[w][]��һ������-1�ĵط����϶���w
                    {
                        p[w][j]=w;
                        break;
                    }
                }
            }
        }
    }

}



void Dij_Get_shortPath(MGraph *G){
    int i,j,a,k;
    int p[Max_value][Max_value];//���·������
    int D[Max_value];//��̾�������
    City_List(G);
    printf("�����������ţ�");
    scanf("%d",&a);
    ShortestPath_Dijkstra(G,a,p,D);
    printf("%d.%s�������м����·��������Ϊ��\n",a,G->Vexs[a]);
    //printf("���·������\t���·��\n");
    for(i=0;i<G->vexnum;i++){
        if(i!=0 && D[i]!=INFINITY){
            printf("%s - %s�����·������Ϊ��%d ",G->Vexs[a],G->Vexs[i],D[i]);
            printf("   ���·��Ϊ��%s",G->Vexs[a]);
            for(j=1;j<G->vexnum;j++){
                if(p[i][j]>-1)
                    printf("->%s",G->Vexs[p[i][j]]);
            }
            printf("\n");
        }
        else if(D[i]==INFINITY)
            printf("%s �� %s���ɴ\n",G->Vexs[a],G->Vexs[i]);
    }
}




/* Dijkstra�㷨����������g��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v] */
/* P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ� */
void Dijkstra_0002(MGraph *G, int v0, int P[Max_value], int D[Max_value])
{
    int v,w,k,min;
    int final[Max_value];                    /* final[w]=1��ʾ��ö���v0��vw�����·�� */

    /* ��ʼ������ */
    for(v=0; v<G->vexnum; v++)
    {
        final[v] = 0;                    /* ȫ�������ʼ��Ϊδ֪���·��״̬ */
        D[v] = G->arcs[v0][v].adj;            /* ����v0�������ߵĶ������Ȩֵ */
        P[v] = 0;                    /* ��ʼ��·������PΪ0 */
    }

    D[v0] = 0;                        /* v0��v0·��Ϊ0 */
    final[v0] = 1;                        /* v0��v0����Ҫ��·�� */

    /* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */
    for(v=1; v<G->vexnum; v++)
    {
        min=INFINITY;                    /* ��ǰ��֪��v0������������ */
        for(w=0; w<G->vexnum; w++) /* Ѱ����v0����Ķ��� */
        {
            if(!final[w] && D[w]<min)
            {
                k=w;
                min = D[w];            /* w������v0������� */
            }
        }
        final[k] = 1;                    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */

        /* ������ǰ���·�������� */
        for(w=0; w<G->vexnum; w++)
        {
            /* �������v�����·������������·���ĳ��ȶ̵Ļ� */
            if(!final[w] && (min+G->arcs[k][w].adj<D[w]))
            {
                /* ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
                D[w] = min + G->arcs[k][w].adj; /* �޸ĵ�ǰ·������ */
                D[w]=k;
            }
        }
    }
}



void Get_Dijkstra_0002(MGraph*G){
    int P[Max_value], D[Max_value];
    int i,j,v0;
    printf("������ţ�");
    scanf("%d",&v0);
ShortestPath_Dijkstra(G, v0, P, D);

    printf("���·����������:\n");
    for(i=1;i<G->vexnum;++i)
    {
        printf("v%d - v%d : ",v0,i);
        j=i;
        while(P[j]!=0)
        {
            printf("%d%s-> ",P[j],G->Vexs[P[j]]);
            j=P[j];
        }
        printf("\n");
    }
    printf("\nԴ�㵽����������·������Ϊ:\n");
    for(i=1;i<G->vexnum;++i)
        printf("v%d - v%d : %d \n",G->Vexs[0],G->Vexs[i],D[i]);

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


//���ӳ���
void  Add_City(MGraph *G){
      VertexType ch;
      int i,j,t=1;
      printf("��������Ҫ���ӵĳ�������");
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
			  printf("���ӳ��У�%s�ɹ���\n",G->Vexs[G->vexnum]);
              }
      else
          printf("������ʧ�ܣ����������ӣ�\n");

          }else
          printf("���棺�ó����Ѵ��ڣ����������ӣ�\n");

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



//���ӳ��м������Ϣ
void Add_City_Adj(MGraph *G){
     int i,j,a,b,distance;
     VertexType cha,chb;
     City_List(G);
     printf("������Ҫ������̵ĵ�һ��������ţ�");
     scanf("%d",&a);
     printf("������Ҫ������̵ĵڶ���������ţ�");
     scanf("%d",&b);
     if(a<=G->vexnum&&b<=G->vexnum&&a>0&&b>0) {
	     if(G->arcs[a][b].adj!=INFINITY&&G->arcs[b][a].adj!=INFINITY)
	              printf("���棺%d.%s �� %d.%s ֮���Ѵ���ֱ��ͨ·,���Ϊ��%d\n",a,G->Vexs[a],b,G->Vexs[b],G->arcs[b][a].adj);
	     else{
	          printf("��������̣�");
	          scanf("%d",&distance);
	           G->arcs[a][b].adj = G->arcs[b][a].adj = distance;
	           printf("���ӳ��м���̳ɹ�\n");
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
    printf("%d\n",G->vexnum);
    getchar();
     //�˵�
     menu(G);

    return 0;
}

