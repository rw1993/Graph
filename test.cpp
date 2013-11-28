#include <iostream>
#include "Adjgraph.h"
using namespace std;
int main()
{
    VertexNode<int>*v=new VertexNode<int>;
    AdjGraph<int>*gra=new AdjGraph<int>;
    gra->newnode(v);
    return 0;
}
