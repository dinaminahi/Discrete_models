#include <bits/stdc++.h>
using namespace std;
  
// Number of vertices in the graph 
#define V 8 
  
int minKey(int key[], bool mstSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
  
    return min_index; 
} 
  
void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 
  
void primMST(int graph[V][V]) 
{ 
    int parent[V]; 
      
    int key[V]; 
      
    bool mstSet[V]; 
  
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    key[0] = 0; 
    parent[0] = -1;
  
    for (int count = 0; count < V - 1; count++)
    { 
        int u = minKey(key, mstSet); 
  
        mstSet[u] = true; 

        for (int v = 0; v < V; v++) 
  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
    printMST(parent, graph); 
} 
  
int main() 
{ 
    int graph[V][V] = { { 0, 0, 7, 0, 0, 0, 46, 98 }, 
                        { 0, 0, 33, 0, 0, 99, 0, 0 }, 
                        { 7, 33, 0, 99, 92, 28, 0, 64 }, 
                        { 0, 0, 99, 0, 15, 52, 0, 0 }, 
                        { 0, 0, 92, 15, 0, 0, 0, 58 },
                        {0, 99, 28, 52, 0, 0, 0, 0 },
                        {46, 0, 0, 0, 0, 0, 0, 36}, 
                        {98, 0, 64, 0, 58, 0, 36, 0 }
    }; 
  
    primMST(graph); 
  
    return 0; 
} 
