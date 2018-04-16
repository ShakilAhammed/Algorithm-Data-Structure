#include<iostream>
#include<vector>
#include<stack>


using namespace std;

const int MAX_NODE = 1000;

vector<int>graph[MAX_NODE], reverseGraph[MAX_NODE];
stack<int>traversedList;

int nodes, edges;
bool visited[MAX_NODE];


void init() {
    for (int i = 1; i <= nodes; ++i) {
        graph[i].clear();
        reverseGraph[i].clear();
        visited[i] = false;
    }
    while(!traversedList.empty()) {
        traversedList.pop();
    }
}



void clearVisitedNodes() {
    for (int i = 1; i <= nodes; ++i) {
        visited[i] = false;
    }
}


void constructGraph() {
    int sNode, eNode;
    for (int i = 1; i <= nodes; ++i) {
        cin>>sNode>>eNode;
        graph[sNode].push_back(eNode);
        reverseGraph[eNode].push_back(sNode);
    }
}

void dfsOnGraph(int node) {
    visited[node] = true;
    int sz = graph[node].size(), nextNode;
    for (int i = 0; i < sz; ++i) {
        nextNode = graph[node][i];
        if(!visited[nextNode]) {
            dfsOnGraph(nextNode);
            traversedList.push(nextNode);
        }
    }
}


void dfsOnReverseGraph(int node) {
    cout<<node<<" ";
    visited[node] = true;
    int sz = reverseGraph[node].size(), nextNode;
    for (int i = 0; i < sz; ++i) {
        nextNode = reverseGraph[node][i];
        if(!visited[nextNode]) {
            dfsOnReverseGraph(nextNode);
        }
    }
}



int main() {
    int testCases, groupNo;
    cin>>testCases;
    while(testCases--) {
        groupNo = 1;
        cin>>nodes>>edges;
        init();
        constructGraph();
        for (int i = 1; i <= nodes; ++i) {
            if(!visited[i])dfsOnGraph(i);
        }

        clearVisitedNodes();

        while(!traversedList.empty()) {
            int node = traversedList.top();
            traversedList.pop();
            if(!visited[node]) {
                cout<<"Group no "<<groupNo++<<"# ";
                dfsOnReverseGraph(node);
            }
            cout<<endl;
        }
    }
    return 0;
}

/* Sample Input

    1
    5 5
    1 2
    2 3
    3 1
    2 4
    4 5

*/

/* Sample Output

    Group no 1# 2 1 3
    Group no 2# 4
    Group no 3# 5

*/


// source graph : https://www.geeksforgeeks.org/wp-content/uploads/SCC.png

