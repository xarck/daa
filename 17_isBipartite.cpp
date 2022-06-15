#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    vector<vector<int>> adjMatrix;
    public:
    int numVertices;
    void createGraph(){
        cin>> numVertices;
        adjMatrix = vector<vector<int>>(numVertices,vector<int>(numVertices,0));
        for(int i=0;i<numVertices;i++){
            for(int j=0;j<numVertices;j++){
                int x;
                cin>> x;
                adjMatrix[i][j] = x;
            }
        }
    }

    bool isBipartite(int src){
        vector<int> colorArr(numVertices,-1);

        colorArr[src] = 1;

        queue<int>  q;
        q.push(src);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(adjMatrix[u][u] = 1) return false;
            for(int v = 0;v<numVertices;++v){
                if(adjMatrix[u][v]&& colorArr[v]==-1){
                    colorArr[v] = 1- colorArr[u];
                    q.push(v);
                }
                else if(adjMatrix[u][v]&& colorArr[v]==colorArr[u])
                    return false;
            }
        }
        return true;
    }
};


int main(){
    Graph g;
    g.createGraph();
    g.isBipartite(0) ? cout<< "Yes": cout<< "No";
    return 0;

}