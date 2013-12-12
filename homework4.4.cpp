#include<iostream>
#include"MTGraph.h"
#include"LinkedQueue.h"
using namespace std;
template<typename T>
bool if_edge_exist(int i, int j,MTGraph<T>*a)
{
    bool visted[10000];
    int tmp;
    for(int k=0;k<a->num_of_node;k++)
    {
        visted[k]=false;
    }
    LinkedQueue<int>*q=new LinkedQueue<int>;
    q->EnQueue(i);
    while(!q->IsEmpty())
    {
        q->DeQueue(tmp);
        for(int k=0;k<a->num_of_node;k++)
        {
            if(a->edge[tmp][k]&&visted[tmp]==false)
            {
                if(k==j)
                    return true;
                visted[k]=true;
                q->EnQueue(k);

            }
        }
        
    }
    return false;

   
};
int main()
{
    int i,j;
    MTGraph<int>*m=new MTGraph<int>;
    m->CreateMGragh();
    cout<<"input i"<<endl;
    cin>>i;
    cout<<"input j"<<endl;
    cin>>j;
    cout<<"if i to j exist? yes=1,no=0"<<endl;
    cout<<if_edge_exist(i,j,m)<<endl;
    return 0;
}
