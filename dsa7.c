#include <stdio.h>

#define MAX_SIZE 100

struct SparseMatrix {
    int row;
    int col;
    int value;
};

void addSparseMatrices(const struct SparseMatrix matrix1[], int size1, const struct SparseMatrix matrix2[], int size2, struct SparseMatrix result[], int* resultSize) {
    int index1 = 0, index2 = 0, indexResult = 0;

    while (index1 < size1 && index2 < size2) {
        if (matrix1[index1].row < matrix2[index2].row || (matrix1[index1].row == matrix2[index2].row && matrix1[index1].col < matrix2[index2].col)) {
            result[indexResult] = matrix1[index1];
            index1++;
        } else if (matrix1[index1].row > matrix2[index2].row || (matrix1[index1].row == matrix2[index2].row && matrix1[index1].col > matrix2[index2].col)) {
            result[indexResult] = matrix2[index2];
            index2++;
        } else {
            result[indexResult].row = matrix1[index1].row;
            result[indexResult].col = matrix1[index1].col;
            result[indexResult].value = matrix1[index1].value + matrix2[index2].value;
            index1++;
            index2++;
        }
        indexResult++;
    }

    while (index1 < size1) {
        result[indexResult] = matrix1[index1];
        index1++;
        indexResult++;
    }

    while (index2 < size2) {
        result[indexResult] = matrix2[index2];
        index2++;
        indexResult++;
    }

    *resultSize = indexResult;
}

void printSparseMatrix(const struct SparseMatrix matrix[], int size) {
   int i;
   for ( i = 0; i < size; i++) {
        printf("(%d, %d, %d) ", matrix[i].row, matrix[i].col, matrix[i].value);
    }
    printf("\n");
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    struct SparseMatrix matrix1[MAX_SIZE], matrix2[MAX_SIZE], result[MAX_SIZE];
    int size1, size2, resultSize;

    printf("Enter the number of non-zero elements in the first sparse matrix: ");
    scanf("%d", &size1);

    printf("Enter the elements of the first sparse matrix (row, column, value):\n");
  int i;
  for ( i = 0; i < size1; i++) {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }

    printf("Enter the number of non-zero elements in the second sparse matrix: ");
    scanf("%d", &size2);

    printf("Enter the elements of the second sparse matrix (row, column, value):\n");
    for (i = 0; i < size2; i++) {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }

    addSparseMatrices(matrix1, size1, matrix2, size2, result, &resultSize);

    printf("\nSparse Matrix 1: ");
    printSparseMatrix(matrix1, size1);

    printf("Sparse Matrix 2: ");
    printSparseMatrix(matrix2, size2);

    printf("Resultant Sparse Matrix: ");
    printSparseMatrix(result, resultSize);

    return 0;
}
