#include <iostream>
using namespace std;

#define MAX 100

int queueArr[MAX];
int front = -1;
int rear = -1;

int visited[MAX];


void enqueue(int vertex)
{
    if (rear == MAX - 1)
    {
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queueArr[rear] = vertex;
}


int dequeue()
{
    if (front == -1)
    {
        return -1;
    }

    int vertex = queueArr[front];

    if (front >= rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    return vertex;
}


void BFS(int graph[MAX][MAX], int startVertex, int vertices)
{
    
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    enqueue(startVertex);
    visited[startVertex] = 1;

    cout << "BFS Traversal: ";

    while (front != -1)
    {
        int currentVertex = dequeue();

        cout << currentVertex << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] == 1 &&
                visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int vertices;
    int graph[MAX][MAX];
    int startVertex;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> startVertex;

    BFS(graph, startVertex, vertices);

    return 0;
}