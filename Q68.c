#include <stdio.h>

int queue[100], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == 99) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n, adj[10][10], indegree[10] = {0};

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("topological sort: ");

    int count = 0;

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    
    if(count != n) {
        printf("\ncycle detected, topo sort not possible");
    }

    return 0;
}