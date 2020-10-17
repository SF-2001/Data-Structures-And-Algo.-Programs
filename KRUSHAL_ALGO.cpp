#include <iostream>
#define I 9999
#define V 10
#define E 16
using namespace std;
 
void PrintMCST(int T[][V-1], int A[][E]){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << T[0][i] << "]----->[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}
 
void Union(int u, int v, int s[]){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    } else {
        s[v] += s[u];
        s[u] = v;
    }
}
 
int Find(int u, int s[]){
    int x = u;
    int v = 0;
 
    while (s[x] > 0){
        x = s[x];
    }
 
    while (u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}
 
void KruskalsMCST(int A[3][16]){
    int T[2][V-1];  
    int track[E] {0};  
    int set[V+1] = {-1, -1, -1, -1, -1, -1, -1, -1,-1,-1,-1};  
 
    int i {0};
    while (i < V-1){
        int min = I;
        int u {0};
        int v {0};
        int k {0};
		for (int j {0}; j<E; j++){
            if (track[j] == 0 && A[2][j] < min){
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }
		if (Find(u, set) != Find(v, set)){
            T[0][i] = u;
            T[1][i] = v;
			Union(Find(u, set), Find(v, set), set);
            i++;
        }
        track[k] = 1;
    }
 PrintMCST(T, A);
}
 
int main() {
    int edges[3][16] = {{1,2,3,6,9,10,8,4,4,2,3,5,7,7,7,4},
                       {2,3,6,9,10,8,4,2,10,10,5,7,10,6,9,1},
                       {1,1,1,5,1,2,5,4,2,1,2,2,0,3,3,1}};
 
    KruskalsMCST(edges);
    cout<<"Sahil Faizal-19BPS1083"<<endl;
    return 0;
}
