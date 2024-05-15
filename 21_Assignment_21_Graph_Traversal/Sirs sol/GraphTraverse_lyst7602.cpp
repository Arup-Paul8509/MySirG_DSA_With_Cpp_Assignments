#include<iostream>
#include "GraphMatrix.cpp"
#include "QueueArray.cpp"
using namespace std;
void bfs(GraphMatrix &G,int s)
{
    int n,u,i;
    bool status[G.getVCount()];
    Queue Q(G.getVCount());
    Q.insert(s);
    status[s]=true;
    while(!Q.isEmpty())
    {
        n=Q.getFront();
        cout<<"  V"<<n;
        Q.del();
        DynArray adjacent=G.adjacentNodes(n);
        for(i=0;i<adjacent.count();i++)
        {
            u=adjacent.get(i);
            if(status[u]==false)
            {
                Q.insert(u);
                status[u]=true;
            }
        }
    }
}
int main()
{
    GraphMatrix G;
    G.createGraph(6,9);
    bfs(G,0);
    cout<<endl;
    return 0;
}