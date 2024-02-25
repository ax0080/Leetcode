void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    // 紀錄該為0的row跟clo
    bool* zeroRows = (bool*)malloc(matrixSize * sizeof(bool));
    bool* zeroCols = (bool*)malloc(*matrixColSize * sizeof(bool));

    // initialize
    for (int i = 0; i < matrixSize; i++) {
        zeroRows[i] = false;
    }
    for (int j = 0; j < *matrixColSize; j++) {
        zeroCols[j] = false;
    }

    // 找出應該設置為零的row和col
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    // 將標記為 true 的行和列設置為零
    for (int i = 0; i < matrixSize; i++) {
        if (zeroRows[i]) {
            for (int j = 0; j < *matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < *matrixColSize; j++) {
        if (zeroCols[j]) {
            for (int i = 0; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    free(zeroRows);
    free(zeroCols);
}