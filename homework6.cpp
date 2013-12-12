#include<iostream>
#include"MTGraph.h"
#define MAX 100
using namespace std;
bool ifoutput[MAX];
int count_sum(int P[MAX][MAX],int u,int v,int edge[MAX][MAX])
{
    if(!ifoutput[u])
    {
        cout<<u<<endl;//输出路径
        ifoutput[u]=true;
    }
    if(P[u][v]!=-1)
    {
        return count_sum(P,u,P[u][v],edge)+count_sum(P,P[u][v],v,edge);//递归求解最长路径
    }
    else 
        return edge[u][v];
};
template<typename T>
int  Keyload(MTGraph<T>*m,int u,int v)
{
    double edge[MAX][MAX];
    bool visited[MAX];
    int P[MAX][MAX];
    for(int i=0;i<m->num_of_node;i++)
    {
        visited[i]=false;
    }
    
        //利用floyd算法求最短路径的长度。
    for(int i=0;i<m->num_of_node;i++)
    {
        for(int j=0;j<m->num_of_node;j++)
        {
            edge[i][j]=-m->edge[i][j];
            P[i][j]=-1;
        }
    }
    for(int k=0;k<m->num_of_node;k++)
    {
        for(int i=0;i<m->num_of_node;i++)
            for(int j=0;j<m->num_of_node;j++)
            {
                if(i!=j)
                {
                 if(edge[i][k]!=0&&edge[k][j]!=0)
                 {
                if(edge[i][k]+edge[k][j]<edge[i][j])
                {
                    edge[i][j]=edge[i][k]+edge[k][j];
                    P[i][j]=k;
                }
                }
                }
            }
    }//此处有问题
    //利用P求关键路径。
    cout<<"输出最长路径"<<endl;
    for(int i=0;i<m->num_of_node;i++)
    {
        ifoutput[i]=false;
    }
    int sum=count_sum(P,u,v,m->edge);
    cout<<v<<endl;
    return sum;


};
int main()
{
    MTGraph<int>* m=new MTGraph<int>;
    m->CreateMGragh();
    int u,v;
    cout<<"请输入源点u"<<endl;
    cin>>u;
    cout<<"请输入结点v"<<endl;
    cin>>v;
    cout<<"输出最长路径"<<endl;
   int sum= Keyload(m,u,v);
   cout<<"输出最长路径长度"<<endl;
    cout<<sum<<endl;
    return 0;
}
