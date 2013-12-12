#ifndef MTGRAPH_H_INCLUDED
#define MTGRAPH_H_INCLUDED
#include <iostream>
#include <cstdio>
#include "LinkedQueue.h"
#define MAX 100
using namespace std;
template<typename T>
class MTGraph
{
    public:
        T * Vexlist;
        int edge[MAX][MAX];
        int num_of_node;
        int num_of_edge;
   
        MTGraph()
        {
            Vexlist=new T[MAX];
            num_of_edge=0;
            num_of_node=0;
        };
        ~MTGraph()
        {
            delete[] Vexlist;
        };
        void CreateMGragh();
        void Newnode(T n);
        void DelNode(T n);  
        int  findloc(T n);
        void SetSucc(T v1,T v2,int w);
        void DelSucc(T v1,T v2);
        T* Succ(T v);
        T* listofnodePre(T v);
        bool Isedge(T v1,T v2);
        T FirstAdjVex(T v);
        void DFS2(int i,bool* visited,int *dfn);
        void DFS2_the_gra();
        void BFS2(int i,bool* visited);
        void BFS2_the_gra();
};
template<typename T>
void MTGraph<T>::BFS2_the_gra()
{
    bool visited[MAX];
    for(int i=0;i<num_of_node;i++)
    {
        visited[i]=false;
    }
    BFS2(0,visited);
};
template<typename T>
void MTGraph<T>::BFS2(int i,bool *visited)
{
    LinkedQueue<int>*q=new LinkedQueue<int>;
    int j;
    cout<<Vexlist[i]<<endl;
    visited[i]=true;
    q->EnQueue(i);
    while(!q->IsEmpty())
    {
        q->DeQueue(j);
        for(int k=0;k<num_of_node;k++)
        {
            if(edge[j][k]&&visited[k]==false)
            {
                cout<<Vexlist[k]<<endl;
                visited[k]=true;
                q->EnQueue(k);
            }
        }
        
    }
   delete q;
};
template<typename T>
void MTGraph<T>::DFS2_the_gra()
{
    bool visited[MAX];
    int dfn[MAX];
    for(int i=0;i<num_of_node;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<num_of_node;i++)
    {
        if(!visited[i])
            DFS2(i,visited,dfn);
    }
};
template<typename T>
void MTGraph<T>::DFS2(int i,bool *visited,int *dfn)
{
    cout<<Vexlist[i]<<endl;
    visited[i]=true;
    for(int j=0;j<num_of_node;j++)
        if(visited[j]==false&&edge[i][j])
            DFS2(j,visited,dfn);

};
template<typename T>
T MTGraph<T>::FirstAdjVex(T v)
{
    int loc=findloc(v);
    for(int i=0;i<num_of_node;i++)
    {
       if(edge[loc][i]) 
           return Vexlist[i];
    }
};
template<typename T>
bool MTGraph<T>::Isedge(T v1,T v2)
{
    int loc1=findloc(v1);
    int loc2=findloc(v2);
    return edge[loc1][loc2];
};
template<typename T>
T* MTGraph<T>::listofnodePre(T v)
{
    int loc=findloc(v);
    T* l=new T[MAX];
    int len=0;
    for(int i=0;i<num_of_node;i++)
    {
        if(edge[i][loc]!=0)
        {
            l[len]=Vexlist[i];
            len++;
        }
    }
    return l;
};
template<typename T>
T* MTGraph<T>::Succ(T v)
{
    int loc=findloc(v);
    T*succ=new T[MAX];
    int len=0;
    for(int i=0;i<num_of_node;i++)
    {
        if(edge[loc][i]!=0)
        {
            succ[len]=Vexlist[i];
            len++;
        }
    }
    return succ;
};
template<typename T>
void MTGraph<T>::DelSucc(T v1,T v2)
{
    int loc1=findloc(v1);
    int loc2=findloc(v2);
    edge[loc1][loc2]=0;
};
template<typename T>
void MTGraph<T>::SetSucc(T v1,T v2,int w)
{
    int loc1=findloc(v1);
    int loc2=findloc(v2);
    edge[loc1][loc2]=w;
};
template<typename T>
int MTGraph<T>::findloc(T n)
{
    for(int i=0;i<num_of_node;i++)
    {
        if(Vexlist[i]==n) return i;
    }
    return -1;
};
template<typename T>
void MTGraph<T>::DelNode(T n)
{
    int loc=findloc(n);
    for(int i=loc;i<num_of_node-1;i++)
    {
        for(int j=0;j<num_of_node;j++)
        {
            edge[i][j]=edge[i+1][j];
        }
    }
    for(int i=loc;i<num_of_node-1;i++)
        for(int j=0;j<num_of_node;j++)
        {
            edge[j][i]=edge[j][i+1];
        }
};
template<typename T>
void MTGraph<T>::Newnode(T n)
{

    Vexlist[num_of_node]=n;
    num_of_node++;
    for(int i=0;i<num_of_node;i++)
    {
        edge[num_of_node-1][i]=0;
    }
    for(int i=0;i<num_of_node;i++)
    {
        edge[i][num_of_node-1]=0;
    }
};
template<typename T>
void MTGraph<T>::CreateMGragh()
{
    int w,y,x;
    cout<<"输入顶点数"<<endl;
    cin>>num_of_node;
    cout<<"输入边数"<<endl;
    cin>>num_of_edge;
    cout<<"输入顶点信息"<<endl;
    for(int i=0;i<num_of_node;i++)
    {
        cin>>Vexlist[i];
    }
    for(int i=0;i<num_of_edge;i++)
        for(int j=0;j<num_of_edge;j++)
        {
            edge[i][j]=0;
        }
    cout<<"输入边及权值"<<endl;
    for(int i=0;i<num_of_edge;i++)
    {
        cout<<"输入第一个顶点"<<endl;
        cin>>x;
        cout<<"输入第二个顶点"<<endl;
        cin>>y;
        cout<<"输入这条边的权值"<<endl;
        cin>>w;
        edge[x][y]=w;
    }
};
#endif
