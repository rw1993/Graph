#include<iostream>
#include"MTGraph.h"
#include"Adjgraph.h"
using namespace std;
template<typename T>
void Adj_to_MT(AdjGraph<T>*a,MTGraph<T>*m)
{
    m->num_of_node=a->number_of_nodes; 
    for(int i=0;i<a->number_of_nodes;i++)
    {
        m->Vexlist[i]=a->vexlist[i]->data;
        //a->vexlist[i]->firstedge中没有adjvex
        EdgeNode*tmp=new EdgeNode;
        tmp=a->vexlist[i]->firstedge->next;
            while(tmp)
            {
               m->edge[i][tmp->adjvex]=tmp->cost;
               tmp=tmp->next;
            }
        
    }

};
int main()
{
    AdjGraph<int>*a=new AdjGraph<int>;
    MTGraph<int>*m=new MTGraph<int>;
    a->CreatGraph();
    cout<<"遍历输出原来的图"<<endl;
    a->DFSTraverse();
    Adj_to_MT(a,m);
    cout<<"遍历输出转化后的图"<<endl;
    m->DFS2_the_gra();
    return 0;
}



