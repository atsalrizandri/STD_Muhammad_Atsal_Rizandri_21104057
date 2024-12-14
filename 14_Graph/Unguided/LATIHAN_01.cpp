#include <iostream>
#include <string>
using namespace std;

struct Graph
{
    string nodes[100];
    int adjacencyMatrix[100][100];
    int jlhSimpul;
};

void CreateGraph_21104057(Graph &G, int jlhSimpul)
{
    G.jlhSimpul = jlhSimpul;
    for (int i = 0; i < jlhSimpul; i++)
    {
        for (int j = 0; j < jlhSimpul; j++)
        {
            G.adjacencyMatrix[i][j] = 0;
        }
    }
}

void ShowGraph_21104057(const Graph &G)
{
    cout << "\n";
    cout << "\t";
    for (int i = 0; i < G.jlhSimpul; i++)
    {
        cout << "\t" << G.nodes[i];
    }
    cout << "\n";

    for (int i = 0; i < G.jlhSimpul; i++)
    {
        cout << G.nodes[i] << "\t";
        for (int j = 0; j < G.jlhSimpul; j++)
        {
            cout << "\t" << G.adjacencyMatrix[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    Graph G;
    int jlhSimpul;

    cout << "Silakan masukan jumlah simpul: ";
    cin >> jlhSimpul;

    CreateGraph_21104057(G, jlhSimpul);

    for (int i = 0; i < jlhSimpul; i++)
    {
        cout << "Silakan masukan nama simpul " << i + 1 << ": ";
        cin >> G.nodes[i];
    }

    cout << "\nSilakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < jlhSimpul; i++)
    {
        for (int j = 0; j < jlhSimpul; j++)
        {
            cout << G.nodes[i] << " --> " << G.nodes[j] << " = ";
            cin >> G.adjacencyMatrix[i][j];
        }
    }

    ShowGraph_21104057(G);

    return 0;
}
