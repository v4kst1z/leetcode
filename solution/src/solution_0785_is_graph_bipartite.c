#define INIT 0
#define RED 1
#define BLUE 2

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *head;
    node_t *tail;
    int len;
}queue_t;

queue_t* crate_queue() {
    queue_t * q = (queue_t*)malloc(sizeof(queue_t));
    node_t *head = (node_t *)malloc(sizeof(node_t));
    q->head = head;
    q->tail = head;
    q->len = 0;
    return q;
}


void enqueue(queue_t *q, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    q->tail->next = new_node;
    q->tail = new_node;
    q->len++;
}

int dequeue(queue_t *q) {
    if (q->head == q->tail) {
        return -1;
    }
    node_t *popp = q->head->next;
    int result = popp->data;
    if (q->head->next == q->tail) {
        q->tail = q->head;
    } else {
        q->head->next = popp->next;
    }
    q->len--;
    free(popp);
    return result;
}

bool empty(queue_t *q) {
    return q->len == 0;
}

void destory_queue(queue_t *q) {
    free(q->head);
    free(q);
}

bool bfs(int** graph, int graphSize, int* graphColSize, int *visit, int start) {
    queue_t *q = crate_queue();
    enqueue(q, start);
    visit[start] = BLUE;
    while (!empty(q)) {
        int node_id = dequeue(q);
        for (int idx = 0; idx < graphColSize[node_id]; idx++) {
            if (visit[graph[node_id][idx]] == INIT) {
                enqueue(q, graph[node_id][idx]);
                visit[graph[node_id][idx]] = visit[node_id] == BLUE ? RED : BLUE;
            } else if (visit[graph[node_id][idx]] == visit[node_id]) {
                return false;
            }
        }
    }
    destory_queue(q);
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    int *visit = (int *)calloc(graphSize, sizeof(int));
    for (int idx = 0; idx < graphSize; idx++) {
        if(visit[idx] == INIT) {
            if(!bfs(graph, graphSize, graphColSize, visit, idx)) return false;
        }
    }
    free(visit);
    return true;
}


/* dfs
#define INIT 0
#define RED 1
#define BLUE 2

bool dfs(int** graph, int* graphColSize, int start, int* visit) {
    for (int idx = 0; idx < graphColSize[start]; idx++) {
        if (visit[graph[start][idx]] == INIT) {
            visit[graph[start][idx]] = visit[start] == BLUE ? RED : BLUE;
            if (!dfs(graph, graphColSize, graph[start][idx], visit)) return false;
        } else if (visit[graph[start][idx]] == visit[start]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    int *visit = (int *)calloc(graphSize, sizeof(int));
    bool result = true;
    for (int idx = 0; idx < graphSize; idx++) {
        if(visit[idx] == INIT) {
            visit[idx] = RED;
            if(!dfs(graph, graphColSize, idx, visit)) {
                return false;
            }
        }
    }
    free(visit);
    return result;
}
 */