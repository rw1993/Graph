#include<iostream>
#include"MTGraph.h"
#include"stdio.h"
#define MAX 100
using namespace std;
template<typename T>
void Prim(MTGraph<T>*m)
{
    bool visted[MAX];
    int num_of_u=0;
    int*distance=new int[MAX];
    for(int i=0;i<m->num_of_node;i++)
    {
        visted[i]=false;
        distance[i]=10086;
    }
    int*u=new int[MAX];
    u[0]=0;
    num_of_u++;
    visted[0]=true;
    distance[0]=0;
    int key=0;
    printf("%d\n",key);
    while(num_of_u<m->num_of_node)
    {
    for(int i=0;i<m->num_of_node;i++)
    {
        if(!visted[i])
        {
            if(m->edge[key][i]!=0&&m->edge[key][i]<distance[i])
            {
                distance[i]=m->edge[key][i];
            }
        }
    }
    int weight=10086;
    for(int i=0;i<m->num_of_node;i++)
    {
        if(!visted[i])
        {
            if(distance[i]<weight)
            {
                 key=i;
                 weight=distance[i];
            }
        }
    }
    visted[key]=true;
    u[num_of_u++]=key;
    printf("%d\n",key);
    }
};
int main()
{
    MTGraph<int>*m=new MTGraph<int>;
    m->CreateMGragh();
    cout<<"output the tree"<<endl;
    Prim(m);
    return 0;
}
