#include<iostream>
#include "MTGraph.h"
using namespace std;
int main()
{
    MTGraph<int>*mg=new MTGraph<int>;
    mg->CreateMGragh();
   // mg->Newnode(1);
   // mg->Newnode(2);
   // mg->SetSucc(1,2,10);
   // cout<<mg->Isedge(1,2)<<endl;
   // mg->DelSucc(1,2);
   // cout<<mg->Isedge(1,2)<<endl;
   // mg->Newnode(1);
  //  mg->Newnode(2);
 //  mg->SetSucc(1,2,10);
   // cout<<mg->findloc(1)<<endl;
 //  mg->DFS2_the_gra();
   mg->DFS2_the_gra(); 
    return 0;
}
