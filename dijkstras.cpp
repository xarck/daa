#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int numVertices;
    vector<pair<int,int>> *adjList;
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList = new vector<pair<int,int>>[numVertices+1];
    }

    void addEdge(int src,int dest,int wt){
        adjList[src].push_back(make_pair(dest,wt));
        adjList[dest].push_back(make_pair(src,wt));
    }

    void dijkstra(int src){
        priority_queue<pair<int,int> > pq;
	    vector<int> distTo(numVertices+1,INT_MAX);

        distTo[src] = 0;
        pq.push(make_pair(0,src));

        while(!pq.empty()){
            int dist = pq.top().first;
            int prev = pq.top().second;

            pq.pop();

            for(auto it:adjList[prev]){
                int next = it.first;
                int nextDist = it.second;
                if(distTo[next]>distTo[prev]+nextDist){
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push(make_pair(distTo[next],next));
                }
            }
        }
        cout << "The distances from source, " << src << ", are : \n";
        for(int i = 1 ; i<numVertices ; i++)	cout << distTo[i] << " ";

    }
    void printGraph(){
        for(int i=0;i<numVertices;i++){
            cout<< "Node " << i << " ";
            for(auto j: adjList[i]){
                cout<< j.first<< " ";
            }
            cout<< endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,4);
    g.addEdge(1,3,7);
    g.addEdge(2,3,2);
    g.addEdge(1,2,3);
    g.printGraph();
    g.dijkstra(0);
}