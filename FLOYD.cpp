#include <iostream>
using namespace std;

#define INF 99999
#define MAX 100

void floydWarshall(int graph[MAX][MAX], int n)
{
    int dist[MAX][MAX];

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

   
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    
    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    int n;
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    cout << "Enter " << INF << " for no direct path.\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, n);

    return 0;
}