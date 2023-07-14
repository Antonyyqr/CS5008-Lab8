#include <stdio.h>
#include <stdlib.h>

// Node definition for Adjacency List
typedef struct node {
    int vertex;
    struct node* next;
} node;

// Function to create new node
node* createNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Number of vertices
    int vertices = 4;

    // Adjacency Matrix
    int adjMatrix[4][4] = {
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {1, 0, 0, 0},
            {0, 0, 1, 0}
    };

    printf("Adjacency Matrix:\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Adjacency List
    node* adjList[vertices];
    for(int i = 0; i < vertices; i++)
        adjList[i] = NULL;

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            if(adjMatrix[i][j] == 1) {
                node* newNode = createNode(j);
                newNode->next = adjList[i];
                adjList[i] = newNode;
            }
        }
    }

    printf("\nAdjacency List:\n");
    for(int i = 0; i < vertices; i++) {
        node* temp = adjList[i];
        printf("%d: ", i);
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    // Free the allocated memory
    for(int i = 0; i < vertices; i++) {
        node* temp = adjList[i];
        while(temp) {
            node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}


