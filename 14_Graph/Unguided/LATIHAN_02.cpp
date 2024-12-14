#include <iostream>
using namespace std;

void createMatrix_21104057(int adjacencyMatrix[100][100], int numVertices, int numEdges)
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacencyMatrix[u - 1][v - 1] = 1;
        adjacencyMatrix[v - 1][u - 1] = 1;
    }
}

void printMatrix_21104057(int adjacencyMatrix[100][100], int numVertices)
{
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numVertices, numEdges;
    int adjacencyMatrix[100][100];

    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices;

    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    createMatrix_21104057(adjacencyMatrix, numVertices, numEdges);

    printMatrix_21104057(adjacencyMatrix, numVertices);

    return 0;
}
