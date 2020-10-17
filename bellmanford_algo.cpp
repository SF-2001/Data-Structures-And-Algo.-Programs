#include<iostream>
using namespace std;

// Struct for the edges of the graph
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //w of the edge (u,v)
};

// Graph - it consists of edges
struct Graph {
  int V;        // Total number of vertices in the graph
  int E;        // Total number of edges in the graph
  struct Edge* edge;  // Array of edges
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
  struct Graph* graph = new Graph;
  graph->V = V;  // Total Vertices
  graph->E = E;  // Total edges

  // Array of edges for graph
  graph->edge = new Edge[E];
  return graph;
}

// Printing the solution
void printArr(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void BellmanFord(struct Graph* graph, int u) {
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  // Step 1: fill the distance array and predecessor array
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;

  // Mark the source vertex
  dist[u] = 0;

  // Step 2: relax edges |V| - 1 times
  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
      // Get the edge data
      int u = graph->edge[j].u;
      int v = graph->edge[j].v;
      int w = graph->edge[j].w;
      if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        dist[v] = dist[u] + w;
    }
  }

  // Step 3: detect negative cycle
  // if value changes then we have a negative cycle in the graph
  // and we cannot find the shortest distances
  for (int i = 0; i < E; i++) {
    int u = graph->edge[i].u;
    int v = graph->edge[i].v;
    int w = graph->edge[i].w;
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      printf("Graph contains negative w cycle");
      return;
    }
  }

  // No negative weight cycle found!
  // Print the distance and predecessor array
  printArr(dist, V);

  return;
}

int main() {
  // Create a graph
  int V = 8;  // Total vertices
  int E = 9;  // Total edges
  struct Graph* graph = createGraph(V, E);

  //------- adding the edges of the graph
  /*
		edge(u, v)
		where 	u = start vertex of the edge (u,v)
				v = end vertex of the edge (u,v)
		
		w is the weight of the edge (u,v)
	*/

  //edge1->1-2==>weight=6
  graph->edge[0].u = 1;
  graph->edge[0].v = 2;
  graph->edge[0].w = 6;
  //edge2->2-5==>weight=-1
  graph->edge[1].u = 2;
  graph->edge[1].v = 5;
  graph->edge[1].w = -1;
  //edge3->5-6==>weight=3
  graph->edge[2].u = 5;
  graph->edge[2].v = 6;
  graph->edge[2].w = 3;
  //edge4->4-6==>weight=-1
  graph->edge[3].u = 4;
  graph->edge[3].v = 6;
  graph->edge[3].w = -1;
  //edge5->1-4==>weight=5
  graph->edge[4].u = 1;
  graph->edge[4].v = 4;
  graph->edge[4].w = 5;
  //edge6->4-3==>weight=-2
  graph->edge[5].u = 4;
  graph->edge[5].v = 3;
  graph->edge[5].w = -2;
  //edge7->1-3==>weight=4
  graph->edge[6].u = 1;
  graph->edge[6].v = 3;
  graph->edge[6].w = 4;
  //edge8->3-2==>weight=-2
  graph->edge[7].u = 3;
  graph->edge[7].v = 2;
  graph->edge[7].w = -2;
  //edge9->3-5==>weight=3
  graph->edge[8].u = 3;
  graph->edge[8].v = 5;
  graph->edge[8].w = 3;
  
  BellmanFord(graph,1);//1 source vertex
}

