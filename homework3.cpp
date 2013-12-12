#include <iostream>
#include "MTGraph.h"
#include "Adjgraph.h"
using namespace std;
template<typename T>
int count_enter0_node1(AdjGraph<T>*a)
{
    int count=0;
    for(int i=0;i<a->number_of_nodes;i++)
    {
        if(!a->vexlist[i]->firstedge->next)
        {
            count++;
    
        }
    }
    return count;
};
template<typename T>
int count_enter0_node(MTGraph<T>*m)
{
    int count=0;
    for(int i=0;i<m->num_of_node;i++)
    {
        bool if_the_node=true;
        for(int j=0;j<m->num_of_node;j++)
        {
            if(m->edge[i][j])
            {
                if_the_node=false;
                break;
            }

        }
        if(if_the_node)
        {
            count++;
        }
    }
    return count;
};
int main()
{
    MTGraph<int>*m=new MTGraph<int>;
    m->CreateMGragh();
    cout<<"输出出度为0的顶点"<<endl;
    cout<<count_enter0_node(m)<<endl;
    AdjGraph<int>*a=new AdjGraph<int>;
    a->CreatGraph();
    cout<<"输出出度为0的顶点"<<endl;
    cout<<count_enter0_node1(a)<<endl;
    return 0;
}
