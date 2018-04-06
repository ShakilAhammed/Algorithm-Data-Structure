#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int const MAX_NODE = 1000;
int const INF = 1e9;
int nodes, edges, source, destination;
int parent[MAX_NODE];
vector<int>graph[MAX_NODE], edgeDistance[MAX_NODE];
bool visited[MAX_NODE];
int dist[MAX_NODE];
queue<int>minDistPath;

void init() {
    for (int i = 1; i <= nodes; ++i) {
        graph[i].clear();
        visited[i] = false;
        dist[i] = INF;
    }
}


int getMinDistNode() {
    int nodeDistance = INF;
    int minDistNode = -1;
    for (int i = 1; i <= nodes; ++i) {
        if(!visited[i] && dist[i]<nodeDistance)
        {
            minDistNode = i;
            nodeDistance = dist[i];
        }
    }
    return minDistNode;
}

void constructGraph() {
    int sNode, eNode, distance;
    for (int i = 0; i < edges; ++i) {
        cin>>sNode>>eNode>>distance;
        graph[sNode].push_back(eNode);
        graph[eNode].push_back(sNode);
        edgeDistance[sNode].push_back(distance);
        edgeDistance[eNode].push_back(distance);
    }
}

void dijkstra() {
    dist[source] = 0;
    while(true) {
        int parentNode = getMinDistNode();
        if(parentNode < 0) break;
        visited[parentNode] = true;
        int sz = graph[parentNode].size();
        for (int i = 0; i < sz; ++i) {
            int childNode = graph[parentNode][i];
            int distanceParentToChild = dist[parentNode] + edgeDistance[parentNode][i];
            if(dist[childNode] > distanceParentToChild)
            {
                parent[childNode] = parentNode;
                dist[childNode] = distanceParentToChild;
            }
        }
    }


}

void getMinPathFromSource(int destination) {
    if(destination == source)return;
    getMinPathFromSource(parent[destination]);
    minDistPath.push(destination);
}
int main() {

    int testcase;
    cin>>testcase;
    while(testcase--) {

        cin>>nodes>>edges;
        init();
        constructGraph();
        cin>>source>>destination;
        dijkstra();
        getMinPathFromSource(destination);
        cout<<"Source to destination shortest path :: "<<source;
        while(!minDistPath.empty())
        {
            cout<<" -> "<<minDistPath.front();
            minDistPath.pop();
        }
        cout<<" and total distnace is "<<dist[destination]<<endl;

    }
    return 0;
}

//input
/*
    1
    6 9
    1 2 7
    1 3 9
    1 6 14
    2 3 10
    2 4 15
    3 4 11
    3 6 2
    4 5 6
    5 6 9
    1 5
*/

//output
//Source to destination shortest path :: 1 -> 3 -> 6 -> 5 and total distnace is 20


//Graph Source
//https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif

