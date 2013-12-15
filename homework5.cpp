#include<iostream>
#include"MTGraph.h"
#include"stdio.h"
#define MAX 100
using namespace std;

template<typename T>
void Prim(MTGraph<T>*m)
{
    bool visted[MAX];
    int num_of_U=0;
    for(int i=0;i<m->num_of_node;i++)
    {
        visted[i]=false;
    }
   /* for(int i=0;i<m->num_of_node;i++)
    {
        for(int j=0;j<m->num_of_node;j++)
        {
            edge[i][j]=0;//初始化
        }
    }*/
    int *U;
    num_of_U++;
    U[0]=0;
    visted[0]=true;
    for(int k=0;k<m->num_of_node;k++)
    {     
         if(!visted[k])
        {
           int u,v;
           int weight=99999999;
           for(int i=0;i<m->num_of_node;i++)
           {
               if(!visted[i])
               {
                   for(int j=0;j<num_of_U;j++)
                   {
                       if(m->edge[U[j]][i]<weight&&m->edge[U[j]][i]>0)
                       {
                           u=U[j];
                           v=i;
                           weight=m->edge[U[j]][i];
                       }
                   }
               }
                             
           }  
           visted[v]=true;
           U[num_of_U]=v;
           num_of_U++;
           printf("%d to %d \n",u,v);
  
           }
    }


};
int main()
{
    MTGraph<int>*m=new MTGraph<int>;
    m->CreateMGragh();
    Prim(m);
    return 0;
}
