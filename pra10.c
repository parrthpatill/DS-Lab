#include <stdio.h>
#include <stdlib.h>

#define N 10
#define EMPTY -1

int mat[N][N], vis[N];
typedef struct Node {
    int v;
    struct Node* next;
} Node;
Node* list[N];

typedef struct Queue {
    int items[N];
    int front, rear;
} Queue;

Queue* createQ() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int v) {
    if (q->rear == N - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = v;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int v = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return v;
}

void addEdgeMat(int u, int v) {
    mat[u][v] = 1;
    mat[v][u] = 1;
}

void bfsMat(int start) {
    Queue* q = createQ();
    vis[start] = 1;
    enqueue(q, start);

    printf("BFS (Matrix): ");
    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);

        for (int i = 0; i < N; i++) {
            if (mat[v][i] && !vis[i]) {
                vis[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

void addEdgeList(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->v = v;
    node->next = list[u];
    list[u] = node;

    node = (Node*)malloc(sizeof(Node));
    node->v = u;
    node->next = list[v];
    list[v] = node;
}

void dfsList(int start) {
    Node* temp = list[start];
    vis[start] = 1;
    printf("%d ", start);

    while (temp) {
        if (!vis[temp->v]) dfsList(temp->v);
        temp = temp->next;
    }
}

void resetVis() {
    for (int i = 0; i < N; i++) vis[i] = 0;
}

int main() {
    int ch, u, v, start;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) mat[i][j] = 0;
        list[i] = NULL;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Edge (Matrix)\n");
        printf("2. Add Edge (List)\n");
        printf("3. BFS (Matrix)\n");
        printf("4. DFS (List)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter vertices (u v): ");
                scanf("%d %d", &u, &v);
                addEdgeMat(u, v);
                printf("Edge added to matrix.\n");
                break;
            case 2:
                printf("Enter vertices (u v): ");
                scanf("%d %d", &u, &v);
                addEdgeList(u, v);
                printf("Edge added to list.\n");
                break;
            case 3:
                printf("Enter start vertex: ");
                scanf("%d", &start);
                resetVis();
                bfsMat(start);
                break;
            case 4:
                printf("Enter start vertex: ");
                scanf("%d", &start);
                resetVis();
                printf("DFS (List): ");
                dfsList(start);
                printf("\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
