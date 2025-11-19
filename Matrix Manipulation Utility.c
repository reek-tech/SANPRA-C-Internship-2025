#include <stdio.h>

// Function for Matrix Addition

void matrixAdd(int r, int c, int A[][10], int B[][10], int R[][10]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            R[i][j] = A[i][j] + B[i][j];
}

// Function for Matrix Multiplication

void matrixMultiply(int r1, int c1, int A[][10],
                    int r2, int c2, int B[][10], int R[][10]) {

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0; // reset element

            // multiply row of A with column of B
            for (int k = 0; k < c1; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

// Function to print a matrix

void printMatrix(int r, int c, int M[][10]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

int main() {
    int A[10][10], B[10][10], R[10][10];
    int r1, c1, r2, c2;

    // Input dimensions

    printf("Enter rows and cols of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and cols of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Input matrix A

    printf("Enter Matrix A elements:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Input matrix B

    printf("Enter Matrix B elements:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Matrix Addition

    printf("\nMatrix Addition:\n");
    if (r1 == r2 && c1 == c2) {
        matrixAdd(r1, c1, A, B, R);
        printMatrix(r1, c1, R);
    } else {
        printf("Addition not possible (dimension mismatch).\n");
    }

    // Matrix Multiplication
    
    printf("\nMatrix Multiplication:\n");
    if (c1 == r2) {
        matrixMultiply(r1, c1, A, r2, c2, B, R);
        printMatrix(r1, c2, R);
    } else {
        printf("Multiplication not possible.\n");
    }

    return 0;
}
