#include<iostream>
#include"Adjgraph.h"
int main()
{

   VertexNode<int>*v=new VertexNode<int>;
   EdgeNode*f=new EdgeNode;
   AdjGraph<int>*gra=new AdjGraph<int>;
   gra->CreatGraph();
//   gra->DFSTraverse();
   gra->BFS1(0);
   return 0;
}
