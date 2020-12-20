#define INIT 0
#define VISIT 1
#define UNSAFE 2
#define SAFE 3

bool dfs(int** graph, int start, int* graphColSize, int* returnSize, int* visit) {
    if (visit[start] == VISIT) {
        visit[start] = UNSAFE;
        return false;
    } else if (visit[start] != INIT) {
        return visit[start] == SAFE;
    }
    visit[start] = VISIT;


    for (int idx = 0; idx < graphColSize[start]; idx++) {
        if (!dfs(graph, graph[start][idx], graphColSize, returnSize, visit)) {
            visit[start] == UNSAFE;
            return false;
        }
    }
    visit[start] = SAFE;
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize){
    int arr_id = 0;
    int* visit = (int *)calloc(graphSize, sizeof(int));
    for (int idx = 0; idx < graphSize; idx++) {
        visit[idx] = INIT;
    }

    int* ret = (int *)calloc(graphSize, sizeof(int));
    for (int idx = 0; idx < graphSize; idx++) {
        if (dfs(graph, idx, graphColSize, ret, visit)) {
            ret[arr_id++] = idx;
        }
    }
    *returnSize = arr_id;
    free(visit);
    return ret;
}