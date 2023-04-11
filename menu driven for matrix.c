#include <stdio.h>

void multiply(int matrix[10][10], int rows, int cols) {
    int scalar;
    printf("Enter a scalar value: ");
    scanf("%d", &scalar);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] *= scalar;
        }
    }

    printf("The resulting matrix is:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose(int matrix[10][10], int rows, int cols) {
    int transposed[10][10];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    printf("The transposed matrix is:\n");
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            printf("%d\t", transposed[i][j]);
        }
        printf("\n");
    }
}

void diagonal_swap(int matrix[10][10], int rows, int cols) {
    if(rows != cols) {
        printf("Cannot perform diagonal swap on a non-square matrix\n");
        return;
    }

    for(int i=0; i<rows; i++) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][rows-i-1];
        matrix[i][rows-i-1] = temp;
    }

    printf("The matrix after diagonal swap is:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[10][10];
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix elements:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int choice;
    do {
        printf("\n");
        printf("Menu:\n");
        printf("1. Multiply the matrix by a scalar value\n");
        printf("2. Transpose the matrix\n");
        printf("3. Swap the elements on the main diagonal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                multiply(matrix, rows, cols);
                break;
            case 2:
                transpose(matrix, rows, cols);
                break;
            case 3:
                diagonal_swap(matrix, rows, cols);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
