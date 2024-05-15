#include<stdio.h>
#include<stdlib.h>
#define MAX 30

struct Graph
{
    int n_v, n_e;
    int adjMat[MAX][MAX];
};

struct Stack
{
    int top;
    int S[MAX];
};

struct Stack* createStack()
{
    struct Stack *s=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=-1;
}

int isStackFull(struct Stack *s){return s->top==MAX-1;}

int isStackEmpty(struct Stack *s){return s->top==-1; }

void push(struct Stack *s, int data)
{
    if(isStackFull(s))
        printf("\n\tSTACK OVERFLOW!");
    else
        s->S[++s->top]=data;
}

int pop(struct Stack *s)
{
    int data=-1;
    if(isStackEmpty(s))
        printf("\n\tSTACK UNDERFLOW!");
    else
    {
        data=s->S[s->top];
        s->top--;
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

void DFS(struct Graph *g, int source)
{
    int visited[g->n_v];
    struct Stack *s=createStack();
    int i,vertex;
    for(i=0; i<g->n_v; i++)
        visited[i]=0;
    push(s,source);
    visited[source]=1;
    while(isStackEmpty(s)!=1)
    {
        vertex=pop(s);
        printf("%d ",vertex);
        for(i=0; i<g->n_v; i++)
        {
            if(g->adjMat[vertex][i]==1)
            {
                if(visited[i]==0)
                {
                    push(s,i);
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
    printf("\nDFS Traversal : ");
    DFS(g,0);
    return 0;
}