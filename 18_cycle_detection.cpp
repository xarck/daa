#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int numVertices;
    vector<int>* adjList;
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList = new vector<int>[numVertices];
    }

    void addEdge(int src,int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    bool isCyclicUtil(int v,vector<bool> visited,int parent){
        visited[v] = true;
        for(auto i: adjList[v]){
            if(!visited[i]){
                if(isCyclicUtil(i,visited,v))
                    return true; 
            }
            else if(i!=parent)
                return true;
        }
        return false;
    }
    bool isCyclic(){
        vector<bool> visited(numVertices,false);
        for(int u=0;u<numVertices;u++){
            if(!visited[u])
                if(isCyclicUtil(u,visited,-1))
                    return true;
        }
        return false;   
    }
};

int main(){
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";
}