#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 100 //假设包含100个顶点
#define MaxWeight 32767 //不邻接时为32767，但输出时用 "∞"
#define MAXV 10
#define INF 32767
typedef struct{ //包含权的邻接矩阵的的定义
    char Vertices[MaxVertices];  //顶点信息的数组
    int Edge[MaxVertices][MaxVertices]; //边的权信息的数组
    int numV; //当前的顶点数
    int numE; //当前的边数
}AdjMatrix;

void CreateGraph(AdjMatrix *G) //图的生成函数
{ 
    int n,e,vi,vj,w,i,j;
    printf("请输入图的顶点数和边数（以空格分隔）：");
    scanf("%d%d",&n,&e);
    G->numV=n;G->numE=e;
    for(i=0;i<n;i++) //图的初始化
        for(j=0;j<n;j++)
            { 
            if(i==j)
                G->Edge[i][j]=0;
            else 
                G->Edge[i][j]=32767;
            }
		printf("请输入各顶点的值(整型):");
    for(i=0;i<n;i++)
		 
        for(i=0;i<G->numV;i++) //将顶点存入数组中
        
		{ 
         
      // G->adjlist[i].vertex=getchar(); 
        scanf(" %c",&G->Vertices[i]);
        }
    printf("\n");
    printf("请输入边的信息i,j,w(以空格分隔):");
    for(i=0;i<G->numE;i++)
		
    { 
        
        scanf("%d%d%d",&vi,&vj,&w); 
        //若为不带权值的图，则w输入1
        //若为带权值的图，则w输入对应权值

        G->Edge[vi-1][vj-1]=w;//①
        G->Edge[vj-1][vi-1]=w;//②
        //无向图具备对称性的规律，经过①②实现
        //有向图不具有此性质，因此只须要①
    }
}
void DispGraph(AdjMatrix G) //输出邻接矩阵的信息
{ 
    int i,j;
    printf("\n输出顶点的信息（整型）:\n");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    printf("\n输出邻接矩阵:\n");
    printf("\t");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    for(i=0;i<G.numV;i++)
    { 
        printf("\n%8d",i+1);
        for(j=0;j<G.numV;j++)
        { 
        if(G.Edge[i][j]==32767) 
        //两点之间无链接时权值为默认的32767，但输出时为了方便输出 "∞"
            printf("%8s", "∞");
        else
            printf("%8d",G.Edge[i][j]);
        }
        printf("\n");   
    }
}
void Ppath(int path[][MaxVertices],int i,int j)
{
    int k;
    k=path[i][j];
    if (k==-1)
    {
        return;
    }

    Ppath(path,i,k);
    printf("%d->",k);
    Ppath(path,k,j);
}

void Dispath(int A[][MaxVertices],int path[][MaxVertices],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (A[i][j]==INF)
            {
                if (i!=j)
                {
                    printf("从%d到%d没有路径\n",i,j);
                }
            }
            else
            {
                printf(" 从%d到%d的最短路径长度为：%d ",i,j,A[0][8]);
                printf("路径：%d->",i);

                Ppath(path,i,j);//两点i,j之间还有其余中继结点，则循环套用次函数
                printf("%d\n",j);
            }
        }
    }
}
void Floyd(AdjMatrix *G)
{
    int A[MaxVertices][MaxVertices],path[MaxVertices][MaxVertices];
    int i,j,k;
    //初始化
    for (i=0;i<G->numV;i++)
    {
        for (j=0;j<G->numV;j++)
        {
            A[i][j]=G->Edge[i][j];
            path[i][j]=-1;
        }
    }
//三重循环，floyd算法核心
    for (k=0;k<G->numV;k++)
    {
        for (i=0;i<G->numV;i++)
        {
            for (j=0;j<G->numV;j++)
            {
                if (A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    Dispath(A,path,G->numV);//输出函数
}


int main()
{ 
    AdjMatrix G;
    
    CreateGraph(&G);
    Floyd(&G);
    DispGraph(G);
}