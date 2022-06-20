#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V; 
	list<int> *adj; 
    public:
	Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void DFSUtil(int v, vector<bool> &visited)
    {
        
        visited[v] = true;
        for (auto i: adj[v])
            if (!visited[i])
                DFSUtil(i, visited);
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); 
    }


    int findMother()
    {
        vector <bool> visited(V, false);	
        int v = 0;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                DFSUtil(i, visited);
                v = i;
            }
        }
        fill(visited.begin(), visited.end(), false);
        DFSUtil(v, visited);
        for (int i=0; i<V; i++)
            if (visited[i] == false)
                return -1;

        return v;
    }

};


int main()
{
	Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
	cout << "A mother vertex is " << g.findMother();

	return 0;
}
