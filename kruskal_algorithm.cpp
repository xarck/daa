#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>

class Graph{
    private:
    vector<pair<int,edge>> G;
    vector<pair<int,edge>> T;
    int numVertices;
    public:
    int *parent;
    Graph(int numVertices){
        this->numVertices = numVertices;
        parent = new int[numVertices];
        for(int i=0;i<numVertices;i++)
            parent[i] = i;
        G.clear();
        T.clear();
    }
    void addWeightedEdge(int u,int v,int w){
        G.push_back(make_pair(w,edge(u,v)));
    }

    int find_set(int i){
        if(i==parent[i])
            return i;
        else
            return find_set(parent[i]);
    }

    void union_set(int u,int v){
        parent[u] = parent[v];
    }

    void kruskal(){
        int i,uRep,vRep;
        sort(G.begin(),G.end());

        for(int i=0;i<G.size();i++){
            uRep =  find_set(G[i].second.first);
            vRep = find_set(G[i].second.second);
            if(uRep!=vRep){
                T.push_back(G[i]);
                union_set(uRep,vRep);
            }
        }
    }


    void printGraph(){
        for(int i=0;i<T.size();i++){
            cout<< T[i].second.first << " " << T[i].second.second << " " << T[i].first << endl;
        }
    }
};

int main(){
    Graph g(6);
    g.addWeightedEdge(0, 1, 4);
    g.addWeightedEdge(0, 2, 4);
    g.addWeightedEdge(1, 2, 2);
    g.addWeightedEdge(1, 0, 4);
    g.addWeightedEdge(2, 0, 4);
    g.addWeightedEdge(2, 1, 2);
    g.addWeightedEdge(2, 3, 3);
    g.addWeightedEdge(2, 5, 2);
    g.addWeightedEdge(2, 4, 4);
    g.addWeightedEdge(3, 2, 3);
    g.addWeightedEdge(3, 4, 3);
    g.addWeightedEdge(4, 2, 4);
    g.addWeightedEdge(4, 3, 3);
    g.addWeightedEdge(5, 2, 2);
    g.addWeightedEdge(5, 4, 3);
  g.kruskal();
  g.printGraph();
}