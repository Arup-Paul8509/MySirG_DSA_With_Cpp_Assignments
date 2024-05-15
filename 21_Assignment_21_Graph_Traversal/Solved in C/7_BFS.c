#include<stdio.h>
#include<stdlib.h>
#define MAX 30

struct Graph
{
    int n_v, n_e;
    int adjMat[MAX][MAX];
};

struct Queue
{
    int front, rear;
    int Q[MAX];
};

struct Queue* createQueue()
{
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=-1;
}


void display(struct Queue *q)
{
    if(q->front!=-1)
    {
    for(int i=q->front; i<=q->rear; i++)
        printf("%d ",q->Q[i]);
    }
}

int isQueueFull(struct Queue *q){return q->rear==MAX-1;}

int isQueueEmpty(struct Queue *q){return q->rear==-1 || q->front > q->rear; }

void enqueue(struct Queue *q, int data)
{
    if(isQueueFull(q))
        printf("\n\tQUEUE OVERFLOW!");
    else
    {
        if(q->rear==-1)
            q->front=0;
        q->Q[++q->rear]=data;
    }
}

int dequeue(struct Queue *q)
{
    int data=-1;
    if(isQueueEmpty(q))
        printf("\n\tQUEUE UNDERFLOW!");
    else
    {
        data=q->Q[q->front];
        if(q->front==q->rear) 
            q->front=q->rear=-1;
        else
            q->front++;
    }
    return data;
}

void createGraph(struct Graph *g)
{
    int u,v,i,j;
    for(i=0; i<g->n_v; i++)
    {
        for(j=0; j<g->n_v; j++)
            g->adjMat[i][j]=0;
    }
    for(i=0; i<g->n_e; i++)
    {
        printf("Enter edge %d : ",i+1);
        scanf("%d%d",&u,&v);
        g->adjMat[u][v]=g->adjMat[v][u]=1;
    }
}

void displayAdjMatrix(struct Graph *g)
{
    for(int i=0; i<g->n_v; i++)
    {
        for(int j=0; j<g->n_v; j++)
            printf("%d ",g->adjMat[i][j]);
        printf("\n");
    }
}

void BFS(struct Graph *g, int source)
{
    int visited[g->n_v];
    struct Queue *q=createQueue();
    int i,vertex;
    for(i=0; i<g->n_v; i++)
        visited[i]=0;
    enqueue(q,source);
    visited[source]=1;
    while(isQueueEmpty(q)!=1)
    {
        vertex=dequeue(q);
        printf("%d ",vertex);
        for(i=0; i<g->n_v; i++)
        {
            if(g->adjMat[vertex][i]==1)
            {
                if(visited[i]==0)
                {
                    enqueue(q,i);
                    visited[i]=1;
                }
            }
        }
    }
}

int main()
{
    int v,e;
    struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter number of vertices : ");
    scanf("%d",&g->n_v);
    printf("Enter number of edges : ");
    scanf("%d",&g->n_e);
    createGraph(g);
    displayAdjMatrix(g);
    printf("\nBFS Traversal : ");
    BFS(g,0);
    return 0;
}