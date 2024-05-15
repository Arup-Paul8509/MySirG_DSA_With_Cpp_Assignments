#include<iostream>
using namespace std;


class GraphMatrix{
    private:
        int v_count;
        int e_count;
        int **adj;
    public:
        void createGraph(int,int);
        void printGraphMatrix();
        void printAdjNodes(int);
        bool isIsolated(int);
        ~GraphMatrix();
};
void GraphMatrix::createGraph(int v_count,int e_count){
    int u,v;
    this->v_count=v_count;
    this->e_count=e_count;
    adj=new int*[v_count];
    int i,j;
    for(i=0; i<v_count; i++)
        adj[i]=new int[v_count];
    for(i=0; i<v_count; i++){
        for(j=0; j<v_count; j++)
            adj[i][j]=0;
    }
    cout<<"Enter node number connecting edges : "<<endl;
    for(i=1; i<=e_count; i++){
        cout<<"Enter edge : ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}

void GraphMatrix::printGraphMatrix(){
    int i,j; 
    for(i=0; i<v_count; i++){
        for(j=0; j<v_count; j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

void GraphMatrix::printAdjNodes(int n){
    int i;
    if(n>=0 && n<v_count){
        for(i=0; i<v_count; i++){
            if(adj[n][i]==1)
                cout<<i<<" ";
        }
    }
    else
        cout<<"Invalid node"<<endl;
}

bool GraphMatrix::isIsolated(int n){
    int i,c=0;
    if(n>=0 && n<v_count){
        for(i=0; i<v_count; i++){
            if(adj[n][i]==1)
                c++;   
        }
        return c==0;
    }
    else{
        cout<<"Invalid node"<<endl;
        return false;
    }
}

GraphMatrix::~GraphMatrix(){
    int i;
    for(i=0; i<v_count; i++)
        delete []adj[i];
    delete []adj;
}

int main()
{
    GraphMatrix G;
    G.createGraph(5,6);
    G.printGraphMatrix();
    G.printAdjNodes(2);
    cout<<endl<<G.isIsolated(4);
    cout<<endl;
    return 0;
}
