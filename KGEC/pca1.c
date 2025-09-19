#include <stdio.h>

#define MAX 100

// ---------------- Array Functions ----------------
void insertElement(int arr[], int *n, int pos, int val) {
    if (*n >= MAX) {
        printf("Array is full!\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty!\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void traverseArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// ---------------- Matrix Functions ----------------
void inputMatrix(int mat[MAX][MAX], int *rows, int *cols) {
    printf("Enter rows and cols: ");
    scanf("%d%d", rows, cols);
    printf("Enter elements:\n");
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
            scanf("%d", &mat[i][j]);
}

void printMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int isSymmetric(int mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != mat[j][i]) return 0;
    return 1;
}

int isUpperTriangular(int mat[MAX][MAX], int n) {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (mat[i][j] != 0) return 0;
    return 1;
}

int isLowerTriangular(int mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (mat[i][j] != 0) return 0;
    return 1;
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = mat[i][j];
}

int isSquareMatrix(int r, int c) {
    return r == c;
}

int isSparseMatrix(int mat[MAX][MAX], int r, int c) {
    int zeroCount = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] == 0) zeroCount++;
    return zeroCount > (r * c) / 2;
}

void threeTuple(int mat[MAX][MAX], int r, int c) {
    int tuple[MAX][3];
    int k = 1; // tuple[0] will store rows, cols, non-zero count
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = mat[i][j];
                k++;
            }
    tuple[0][0] = r;
    tuple[0][1] = c;
    tuple[0][2] = k - 1;

    printf("Three Tuple Representation:\n");
    for (int i = 0; i < k; i++)
        printf("%d %d %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
}

// ---------------- Main ----------------
int main() {
    int choice;
    int arr[MAX], n = 0;
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    int rows1, cols1, rows2, cols2;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Insert in Array\n2. Delete from Array\n3. Traverse Array\n4. Linear Search\n5. Binary Search\n");
        printf("6. Symmetric Matrix Check\n7. Upper Triangular Check\n8. Lower Triangular Check\n");
        printf("9. Matrix Addition\n10. Matrix Subtraction\n11. Matrix Multiplication\n12. Matrix Transpose\n");
        printf("13. Check Square Matrix\n14. Sparse Matrix Check\n15. Three Tuple Representation\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int pos, val;
                printf("Enter position and value: ");
                scanf("%d%d", &pos, &val);
                insertElement(arr, &n, pos, val);
                break;
            }
            case 2: {
                int pos;
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            }
            case 3:
                traverseArray(arr, n);
                break;
            case 4: {
                int key;
                printf("Enter value to search: ");
                scanf("%d", &key);
                int idx = linearSearch(arr, n, key);
                if (idx != -1) printf("Found at index %d\n", idx);
                else printf("Not found\n");
                break;
            }
            case 5: {
                int key;
                printf("Enter value to search: ");
                scanf("%d", &key);
                int idx = binarySearch(arr, n, key);
                if (idx != -1) printf("Found at index %d\n", idx);
                else printf("Not found\n");
                break;
            }
            case 6:
                inputMatrix(mat1, &rows1, &cols1);
                if (rows1 == cols1 && isSymmetric(mat1, rows1))
                    printf("Matrix is Symmetric\n");
                else
                    printf("Matrix is Not Symmetric\n");
                break;
            case 7:
                inputMatrix(mat1, &rows1, &cols1);
                if (rows1 == cols1 && isUpperTriangular(mat1, rows1))
                    printf("Matrix is Upper Triangular\n");
                else
                    printf("Not Upper Triangular\n");
                break;
            case 8:
                inputMatrix(mat1, &rows1, &cols1);
                if (rows1 == cols1 && isLowerTriangular(mat1, rows1))
                    printf("Matrix is Lower Triangular\n");
                else
                    printf("Not Lower Triangular\n");
                break;
            case 9:
                printf("Matrix 1:\n");
                inputMatrix(mat1, &rows1, &cols1);
                printf("Matrix 2:\n");
                inputMatrix(mat2, &rows2, &cols2);
                if (rows1 == rows2 && cols1 == cols2) {
                    addMatrix(mat1, mat2, res, rows1, cols1);
                    printf("Result:\n");
                    printMatrix(res, rows1, cols1);
                } else {
                    printf("Addition not possible!\n");
                }
                break;
            case 10:
                printf("Matrix 1:\n");
                inputMatrix(mat1, &rows1, &cols1);
                printf("Matrix 2:\n");
                inputMatrix(mat2, &rows2, &cols2);
                if (rows1 == rows2 && cols1 == cols2) {
                    subtractMatrix(mat1, mat2, res, rows1, cols1);
                    printf("Result:\n");
                    printMatrix(res, rows1, cols1);
                } else {
                    printf("Subtraction not possible!\n");
                }
                break;
            case 11:
                printf("Matrix 1:\n");
                inputMatrix(mat1, &rows1, &cols1);
                printf("Matrix 2:\n");
                inputMatrix(mat2, &rows2, &cols2);
                multiplyMatrix(mat1, mat2, res, rows1, cols1, rows2, cols2);
                if (cols1 == rows2) {
                    printf("Result:\n");
                    printMatrix(res, rows1, cols2);
                }
                break;
            case 12:
                inputMatrix(mat1, &rows1, &cols1);
                transposeMatrix(mat1, res, rows1, cols1);
                printf("Transpose:\n");
                printMatrix(res, cols1, rows1);
                break;
            case 13:
                inputMatrix(mat1, &rows1, &cols1);
                if (isSquareMatrix(rows1, cols1))
                    printf("Square Matrix\n");
                else
                    printf("Not Square Matrix\n");
                break;
            case 14:
                inputMatrix(mat1, &rows1, &cols1);
                if (isSparseMatrix(mat1, rows1, cols1))
                    printf("Sparse Matrix\n");
                else
                    printf("Not Sparse Matrix\n");
                break;
            case 15:
                inputMatrix(mat1, &rows1, &cols1);
                threeTuple(mat1, rows1, cols1);
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
