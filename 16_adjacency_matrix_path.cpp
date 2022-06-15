#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    vector<vector<int>> adjMatrix;
    public:
    int numVertices;
    Graph(int numVertices){
        // for(int i=0;i<numVertices;i++){
        //     for(int j=0;j<numVertices;j++){
        //         adjMatrix[i][j] = 0;
        //     }
        // }
    }
    void createGraph(){
        // this->numVertices = numVertices;
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

    void checkPath(int start, int d,vector<bool>& visited,int& pExists){
        visited[start] = true;

        for(int i=0;i<adjMatrix[start].size();i++){
            if(adjMatrix[start][i]==1 &&(!visited[i])){
                if(i==d) pExists = 1;
                checkPath(i,d,visited,pExists);
            }
        }
    }
};


int main(){
    Graph g(5);;
    g.createGraph();
    vector<bool> visited(g.numVertices,false);
    int pExits = 0;
    g.checkPath(0,4,visited,pExits);
    cout<< pExits << endl;

}