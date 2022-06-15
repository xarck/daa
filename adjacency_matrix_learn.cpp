#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    vector<vector<int>> adjMatrix;
    public:
    int numVertices;
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjMatrix = vector<vector<int>>(numVertices,vector<int>(numVertices,0));
        for(int i=0;i<numVertices;i++){
            for(int j=0;j<numVertices;j++){
                adjMatrix[i][j] = 0;
            }
        }
    }
    void addEdge(int i,int j){
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }
    void removeEdge(int i,int j){
        adjMatrix[i][j] = 0;
        adjMatrix[i][j] = 0;
    }

    void printMatrix(){
        for(int i=0;i<numVertices;i++){
            cout<< i << " : ";
            for(int j=0;j<numVertices;j++)
                cout<<adjMatrix[i][j]<< " ";
            cout<< "\n";
        }
    } 

    void dfs(int start, vector<bool>& visited){
        cout<< start<< " ";
        visited[start] = true;

        for(int i=0;i<adjMatrix[start].size();i++){
            if(adjMatrix[start][i]==1 &&(!visited[i])){
                dfs(i,visited);
            }
        }
    }

    void bfs(int start){
        vector<bool> visited(numVertices,false);
        vector<int> q;
        q.push_back(start);

        visited[start] = true;
        int vis;
        while(!q.empty()){
            vis = q[0];
            cout<< vis << " ";
            q.erase(q.begin());
            for(int i=0;i<adjMatrix.size();i++){
                if(adjMatrix[vis][i]==1 && (!visited[i])){
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
    void checkPath(int start, int d,vector<bool>& visited,int& pExists){
        visited[start] = true;

        for(int i=0;i<adjMatrix[start].size();i++){
            if(adjMatrix[start][i]==1 &&(!visited[i])){
                cout<< i << " "<< d << endl;
                if(i==d) pExists = 1;
                checkPath(i,d,visited,pExists);
            }
        }
    }
};


int main(){
    Graph g(5);
    g.addEdge(0,3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,4);

    // g.printMatrix();
    vector<bool> visited(g.numVertices,false);
    // g.dfs(0,visited);
    int pExits = 0;
    g.checkPath(0,4,visited,pExits);
    cout<< pExits << endl;
    // g.bfs(0);

}