#ifndef ADJGRAPH_H_INCLUDED
#define ADJGRAPH_H_INCLUDED
#define max 10000
#include <iostream>
using namespace std;
struct EdgeNode
{
        int adjvex;
        int cost;
        EdgeNode*next;
        EdgeNode():next(NULL){};
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
        VertexNode<T>**vexlist;
        int number_of_nodes;
        int number_of_edges;
    public:
        AdjGraph()
        {
            vexlist=new VertexNode<T>*[max]; //申请内存 
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
        VertexNode<T>**listofnodepre(VertexNode<T>*v);
        bool isedge(VertexNode<T>*v1,VertexNode<T>*v2);
        VertexNode<T>* NextAdjVex(VertexNode<T>*v,EdgeNode* w);
        void CreatGraph();
       
     
};
template<typename T>
void AdjGraph<T>::CreatGraph()      
{
    cout<<"输入顶点的个数" <<endl;
    cin>>number_of_nodes;
    cout<<"输入边的个数"<<endl;
    cin>>number_of_edges;
    cout<<"输入顶点中的数据"<<endl;
    for(int i=0;i<number_of_nodes;i++)
    {
        vexlist[i]=new VertexNode<int>;
       cin>> vexlist[i]->data;//问题……
    }
    cout<<"输入边"<<endl;
    for(int i=0;i<number_of_edges;i++)
    {
       int loc;
       int adjvex;
       int weight;
       cout<<"输入边的第一个顶点"<<endl;
       cin>>loc;
       cout<<"输入边的第二个顶点"<<endl;
       cin>>adjvex;
       cout<<"输入这条边的权"<<endl;
       cin>>weight;
       EdgeNode*p=new EdgeNode;
       p->cost=weight;
       p->adjvex=adjvex;
       p->next=vexlist[loc]->firstedge->next;
       vexlist[loc]->firstedge->next=p;
    }
};
template<typename T>
VertexNode<T>* AdjGraph<T>::NextAdjVex(VertexNode<T>*v,EdgeNode* w)
{
    EdgeNode*tmp=new EdgeNode;
    tmp=v->firstedge->next;
    while(tmp)
    {
        if(tmp==w) return vexlist[tmp->adjvex];
        tmp=tmp->next;
    }
};
template<typename T>
bool AdjGraph<T>::isedge(VertexNode<T>*v1,VertexNode<T>*v2)
{
    int loc2=findloc(v2);
    EdgeNode*tmp=new EdgeNode;
    tmp=v1->firstedge->next;
    while(tmp)
    {
        if(tmp->adjvex=loc2) return true;
        tmp=tmp->next;
    }
};
template<typename T>
VertexNode<T>** AdjGraph<T>::listofnodepre(VertexNode<T>*v)
{
    int loc=findloc(v);
    VertexNode<T>** newvexlist=new VertexNode<T>*[max];
    int len=0;
    for(int i=0;i<number_of_nodes;i++)
    {
        EdgeNode*tmp=new EdgeNode;
        tmp=vexlist[i]->firstedge;
        while(tmp=tmp->next)
        {
            if(tmp->adjvex==loc)
            { 
                newvexlist[len]=vexlist[i];
                len++;
            }
        }
    }
    return newvexlist;
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
    VertexNode<T>** vexlist_of_v=new VertexNode<T>*[max];
    EdgeNode*tmp=new EdgeNode;
    tmp=vexlist[loc]->firstedge;
    while(tmp=tmp->next)
    {
        int j=tmp->adjvex;
        vexlist_of_v[len]=vexlist[j];
        len++;
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

