#include<iostream>
using namespace std;

struct node{
    int item;
    int vertex;
    node *next;
};

class AdjList{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        AdjList(int);
        void setVertex(int);
        void addNode(int,int);
        void removeFirstNode();
        void printList();
        ~AdjList();
};
AdjList::AdjList(){
    start=NULL;
}
AdjList::AdjList(int v){
    start=NULL;
    vertex=v;
}
void AdjList::addNode(int v,int data){
    node *n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}
void AdjList::setVertex(int v){
    vertex=v;
}
void AdjList::removeFirstNode(){
    node *t;
    if(start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
void AdjList::printList(){
    node *t=start;
    while(t){
        cout<<"("<<t->vertex<<","<<t->item<<")";
        t=t->next;
    }
}
AdjList::~AdjList(){
    while(start)
        removeFirstNode();
}


class Graph{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        void createGraph(int);
        void printGraph();
        ~Graph();
};
Graph::Graph(){
    v_count=0;
    arr=NULL;
}
void Graph::createGraph(int vno){
    int n,v,data;
    v_count=vno;
    arr=new AdjList[v_count];
    for(int i=0; i<v_count; i++){
        arr[i].setVertex(i);
        cout<<"How many adjacent nodes of V : "<<i;
        cin>>n;
        for(int j=0; j<n; j++){
            cout<<"Enter vertex No. : ";
            cin>>v;
            cout<<"Enter data : ";
            cin>>data;
            arr[i].addNode(v,data);
        }
    }
    
}
void Graph::printGraph(){
    for(int i=0; i<v_count; i++){
        cout<<endl;
        arr[i].printList();
    }
}
Graph::~Graph(){
    delete []arr;
}

int main()
{
    Graph G;
    G.createGraph(6);
    G.printGraph();
    cout<<endl;
    return 0;

}