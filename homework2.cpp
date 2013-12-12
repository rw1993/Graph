#include<iostream>
#include"Adjgraph.h"
using  namespace std;
template<typename T>
void change(AdjGraph<T>*a)
{
  AdjGraph<T>*tmp=new AdjGraph<T>;
  tmp->number_of_nodes=a->number_of_nodes;
  for(int i=0;i<a->number_of_nodes;i++)
  {
      tmp->vexlist[i]=a->vexlist[i];
  }
  for(int i=0;i<a->number_of_nodes;i++)
  {
      EdgeNode*e=new EdgeNode;
      e=a->vexlist[i]->firstedge->next;
      while(e)
      {
          tmp->setsucc(tmp->vexlist[e->adjvex],tmp->vexlist[i],e->cost);
          e=e->next;
      }
  }
  a=tmp;

};
int main()
{
    AdjGraph<int>*a=new AdjGraph<int>;
    a->CreatGraph();  
    a->DFSTraverse();
    change(a);
    a->DFSTraverse();
    return 0;
}
