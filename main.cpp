#include <iostream>
using namespace std;

int randomVertex(int n){
    return rand() % n;  
}

bool checkNeighbours(int vertex, int graph[][3]){
    bool not_cubic = false; 
    for (int i = 0; i < 3; i++){
        if (graph[vertex][i] == -1){ 
            not_cubic = true; 
        } 
    }
    return not_cubic; 
}

void addNeighbour(int vertex, int neighbour, int graph[][3]){
    for (int i = 0; i < 3; i++){
        if (graph[vertex][i] == -1){
            graph[vertex][i] = neighbour; 
            return;
        }
    }
}

void printGraph(int graph[][3], int n){
    for (int i = 0; i < n; i++){
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < 3; j++){
            if (graph[i][j] != -1){
                cout << graph[i][j] << " "; 
            }
        }
        cout << endl; 
    }
}

void checkConditions(int vertex1, int vertex2, int graph[][3]){
    if (vertex1 == vertex2){
        return;
    }
    if (!checkNeighbours(vertex2, graph)){
        return; 
    }
    for (int i = 0; i < 3; i++){
        if (graph[vertex1][i] == vertex2){
            return;
        }
    }
    addNeighbour(vertex1,vertex2,graph);
    addNeighbour(vertex2,vertex1,graph);
}

int main(int argc, char** argv) {
    srand(time(NULL));
    
    int n; 
    cin >> n; 
    
    int graph[n][3];  
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            graph[i][j] = -1; 
        }
    }

   for (int i = 0; i < n; i++){
        int x = randomVertex(n);
        bool not_cubic = checkNeighbours(i, graph);
        int y = 0; 
        
        while (not_cubic && y < 100000000){
            checkConditions(i, x, graph);
            not_cubic = checkNeighbours(i, graph);
            x = rand() % n;
            y++; 
        }
    }
     
    printGraph(graph, n);
    return 0;
}

