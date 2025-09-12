#include <iostream>

class DynamicMatrix {
private:
    int** matrix;
    int rows;
    int cols;

    void allocateMatrix(int r, int c, int fillValue = 0) {
        matrix = new int*[r];
        for (int i = 0; i < r; i++) {
            matrix[i] = new int[c];
            for (int j = 0; j < c; j++) {
                matrix[i][j] = fillValue;
            }
        }
    }

    void deallocateMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

public:
    DynamicMatrix(int r, int c, int fillValue = 0) {
        rows = r;
        cols = c;
        allocateMatrix(rows, cols, fillValue);
    }

    ~DynamicMatrix() {
        deallocateMatrix();
    }

    void resize(int newRows, int newCols, int fillValue = 0) {
        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols)
                    newMatrix[i][j] = matrix[i][j];
                else
                    newMatrix[i][j] = fillValue;
            }
        }
        deallocateMatrix();
        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; i++) {
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; j++) {
                transposed[i][j] = matrix[j][i];
            }
        }
        deallocateMatrix();
        matrix = transposed;
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int index = i * cols + j;
                if (index % 2 == 1) {
                    std::cout << matrix[i][j] + 2 << " ";
                } else {
                    std::cout << matrix[i][j] << " ";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    DynamicMatrix dm(2, 3, 1);

    dm.print();
    std::cout << "----\n";

    dm.resize(3, 4, 5);
    dm.print();
    std::cout << "----\n";

    dm.transpose();
    dm.print();

    return 0;
}
