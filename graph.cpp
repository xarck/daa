#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int numVertices;
    vector<int>* adjList;
    vector<int> dfsVisited;
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList = new vector<int>[numVertices];
        dfsVisited.resize(numVertices,false);

    }
    void addEdge(int src,int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void dfs(int src){
        dfsVisited[src] = true;
        cout<< src << " ";
        for(auto neig: adjList[src]){
            if(!dfsVisited[neig])
                dfs(neig);
        }
    }

    void bfs(int src){
        vector<bool> visited(numVertices,false);
        list<int> queue;
        visited[src] = true;
        queue.push_back(src);
        while(!queue.empty()){
            int s = queue.front();
            cout<< s << " ";
            queue.pop_front();
            for(auto neig: adjList[s]){
                if(!visited[neig]){
                    visited[neig] = true;
                    queue.push_back(neig);
                }
            }
        }
    }
    bool isBipartite(int src){
        vector<int> colorArr(numVertices,-1);

        colorArr[src] =1;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto neig: adjList[u]){
                if(colorArr[neig]==-1){
                    colorArr[neig] = 1-colorArr[u];
                    q.push(neig);
                }
                else if(colorArr[neig]==colorArr[u]) return false;
            }
        }
        return true;
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
        vector<bool>visited(numVertices,false);
        for(int u=0;u<numVertices;u++){
            if(!visited[u])
                if(isCyclicUtil(u,visited,-1))
                    return true;
        }
        return false;
    }

    bool isReachable(int s,int d){
        if(s==d) return true;
        vector<bool> visited(numVertices,false);
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        while(!q.empty()){
            s = queue.front();
            queue.pop_front();

            for(auto i: adjList[s]){
                if(i==d) return true;
                if(!visited[i]){
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }
    }
    return false;
};

int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    cout<< g.isCyclic();
}
