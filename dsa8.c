#include <stdio.h>

 #define MAX_ROWS 100

#define MAX_COLS 100

 

struct SparseMatrix {

    int row;

    int col;

    int value;

};

 

void findNonZeroElementsInRows(const struct SparseMatrix matrix[], int size, int numRows, int numCols, int nonZeroCounts[]) {
   int i;
    for ( i = 0; i < numRows; i++) {

        nonZeroCounts[i] = 0;

    }

 

    for ( i = 0; i < size; i++) {

        int row = matrix[i].row;

        nonZeroCounts[row]++;

    }

}

 

int main() {

    int rows, cols;

 

    printf("Enter the number of rows and columns for the matrix: ");

    scanf("%d %d", &rows, &cols);

 

    struct SparseMatrix matrix[MAX_ROWS * MAX_COLS];

    int size, nonZeroCounts[MAX_ROWS];

 

    printf("Enter the number of non-zero elements in the sparse matrix: ");

    scanf("%d", &size);

 

    printf("Enter the elements of the sparse matrix (row, column, value):\n");

    int i;
    for ( i = 0; i < size; i++) {

        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);

    }

 

    findNonZeroElementsInRows(matrix, size, rows, cols, nonZeroCounts);

 

    printf("\nSparse Matrix:\n");

    for ( i = 0; i < size; i++) {

        printf("(%d, %d, %d)\n", matrix[i].row, matrix[i].col, matrix[i].value);

    }

 

    printf("\nNumber of non-zero elements in each row:\n");
   
    for ( i = 0; i < rows; i++) {

        printf("Row %d: %d\n", i, nonZeroCounts[i]);

    }

 

    return 0;

}
