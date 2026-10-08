#include <iostream>
using namespace std;

#define INF 99999

void dijkstra(int graph[10][10], int n, int source)
{
    int dist[10];
    bool visited[10];

   
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

  
    for (int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u = -1;

        
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

  
    cout << "\nShortest distances from source vertex " << source + 1 << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i + 1 << " = ";

        if (dist[i] == INF)
            cout << "Not reachable";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main()
{
    int n, source;
    int graph[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    cout << "(Enter 0 if there is no edge)\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex (1 to " << n << "): ";
    cin >> source;

    dijkstra(graph, n, source - 1);

    return 0;
}