int minSwapsCouples(int* row, int rowSize){
    int result = 0;
    for(int id = 0; id < rowSize; id += 2) {
        if (row[id] == (row[id + 1] ^ 1)) continue;
        result += 1;
        for(int jd = id + 2; jd < rowSize; jd++) {
            if (row[id] == (row[jd] ^ 1)) {
                row[jd] = row[id + 1];
                row[id + 1] = row[id] ^ 1;
                break;
            }
        }
    }
    return result;
}

/*
int find(int *arr, int id) {
    if (arr[id] != id) {
        arr[id] = find(arr, arr[id]);
        return arr[id];
    }
    return id;
}

int minSwapsCouples(int* row, int rowSize){
    int result = 0;
    int *arr = (int *)malloc(sizeof(int) * rowSize);
    for (unsigned idx = 0; idx < rowSize; idx++) {
        arr[idx] = idx;
    }
    for (unsigned idx = 0; idx < rowSize; idx+=2) {
        int val1 = find(arr, row[idx] / 2);
        int val2 = find(arr, row[idx + 1] / 2);
        if (val1 != val2) {
            result++;
            arr[val2] = val1;
        }
    }
    free(arr);
    return result;
}
 */