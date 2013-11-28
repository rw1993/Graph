#ifndef ADJGRAPH_H_INCLUDED
#define ADJGRAPH_H_INCLUDED
#define max 10000
using namespace std;
class EdgeNode
{
    public:
        int adjvex;
        int cost;
        EdgeNode*next;
        EdgeNode()
        {
            next=new EdgeNode;
        }
        ~EdgeNode()
        {
            delete[] next;
        }
               void set(int a,int c,EdgeNode*n)
        {
            adjvex=a;
            cost=c;
            next=n;
        };


};
template<typename T> class VertexNode
{
   public :
         T data;
         EdgeNode*firstedge;
         VertexNode()
         {
             firstedge=new EdgeNode;
         };
         ~VertexNode()
         {
             delete[] firstedge;
         };
                void set(T d,EdgeNode*f)
         {
             data=d;
             firstedge=f;
         };
};
template<typename T>class AdjGraph
{
    private:
        VertexNode<T>*vexlist[max];
        int number_of_nodes;
        int number_of_edges;
    public:
        AdjGraph()
        {
            number_of_edges=0;
            number_of_nodes=0;
        };
        ~AdjGraph()
        {
            delete[] vexlist;
        };
        VertexNode<T>*newnode(VertexNode<T>*n);
        void DelNode(VertexNode<T>*n);
        void setsucc(VertexNode<T>*v1,VertexNode<T>*v2);
        void Delsucc(VertexNode<T>*v1,VertexNode<T>*v2);
        VertexNode<T>**listofnodesucc(VertexNode<T>*v);
        int findloc(VertexNode<T>*v);
        VertexNode<T>*firstadjvex(VertexNode<T>*v);
};
template<typename T>
VertexNode<T>* AdjGraph<T>::firstadjvex(VertexNode<T>*v)
{
    int loc=v->firstedge->next->adjvex;
    return vexlist[loc];

};
template<typename T>
VertexNode<T>** AdjGraph<T>::listofnodesucc(VertexNode<T>*v)
{
    int len=0;
    int loc=findloc(v);
    VertexNode<T>* vexlist_of_v[max];
    EdgeNode*tmp=new EdgeNode;
    tmp=vexlist[loc]->firstedge;
    while(tmp=tmp->next)
    {
        int j=tmp->adjvex;
        vexlist_of_v[len]=new VertexNode<T>;
        vexlist_of_v[len]=vexlist[j];
    }
    return vexlist_of_v;
}
template<typename T>
int AdjGraph<T>::findloc(VertexNode<T>*v)
{
    int loc;
    for(int i=0;i<number_of_nodes;i++)
    {
        if(vexlist[i]==v)
        {
            loc=i;
            break;
        }
    }
    return loc;
};
template<typename T>
void AdjGraph<T>:: Delsucc(VertexNode<T>*v1,VertexNode<T>*v2)
{
    int loc1,loc2;
    loc1=findloc(v1);
    loc2=findloc(v2);
    EdgeNode*tmp=new EdgeNode;
    tmp=vexlist[loc1]->firstedge;
    while(tmp)
    {
        if(tmp->next->adjvex==loc2)
        {
            tmp->next=tmp->next->next;
            number_of_edges--;
        }
        tmp=tmp->next;
    }
    tmp=vexlist[loc2]->firstedge;
    while(tmp)
    {
        if(tmp->next->adjvex==loc1)
        {
            tmp->next=tmp->next->next;
            number_of_edges--;
        }
        tmp=tmp->next;
    }

};
template<typename T>
void AdjGraph<T>::setsucc(VertexNode<T>*v1,VertexNode<T>*v2)
{
    int loc1,loc2;
    loc1=findloc(v1);
    loc2=findloc(v2);
  EdgeNode*n1=new EdgeNode;
  EdgeNode*n2=new EdgeNode;
  EdgeNode*tmp=new EdgeNode;
  n1->adjvex=loc2;
  n2->adjvex=loc1;
  tmp=vexlist[loc1]->firstedge->next;
  vexlist[loc1]->firstedge->next=n1;
  n1->next=tmp;
  tmp=vexlist[loc2]->firstedge->next;
  vexlist[loc2]->firstedge->next=n2;
  n2->next=tmp;
};
template<typename T>
VertexNode<T>* AdjGraph<T>::newnode(VertexNode<T>*n)
{
 
     vexlist[number_of_nodes]=new VertexNode<T>;
     vexlist[number_of_nodes]=n;
     number_of_nodes++;
     

        
};
template<typename T>
void AdjGraph<T>::DelNode(VertexNode<T>*n)
{
    int loc;
    for(int i=0;i<number_of_nodes;i++)
    {
        if(vexlist[i]==n)
        {
            loc=i;
            break;
        }
    }//找到这个节点
    for(int i=0;i<number_of_nodes;i++)
    {
        EdgeNode*tmp=new EdgeNode;
        tmp=vexlist[i]->firstedge;
        while(tmp)
        {
            if(tmp->next->adjvex==loc)
            {
                tmp->next=tmp->next->next;
                number_of_edges--;
                break;
            }
            tmp=tmp->next;
        }
    }//删除边
    for(int i=loc;i<number_of_nodes-1;i++)
    {
        vexlist[i]=vexlist[i+1];
    }
    number_of_nodes--;

};

#endif

