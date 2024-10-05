#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    // Constructor
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, std::vector<T>(c)) {}

    // Access element (const and non-const)
    T& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        return data[i][j];
    }

    // Getters for rows and columns
    size_t numRows() const { return rows; }
    size_t numCols() const { return cols; }

    // Matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other(i, j);
            }
        }
        return result;
    }

    // Matrix subtraction
    Matrix<T> operator-(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] - other(i, j);
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return result;
    }

    // Matrix transpose
    Matrix<T> transpose() const {
        Matrix<T> result(cols, rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(j, i) = data[i][j];
            }
        }
        return result;
    }

    // Input matrix
    void input() {
        std::cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    // Display matrix
    void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Function to handle matrix operations based on user input
template<typename T>
void handleMatrixOperations() {
    size_t rows, cols;
    std::string operation;

    // Input dimensions for the matrices
    std::cout << "Enter the number of rows and columns for the matrices: ";
    std::cin >> rows >> cols;

    // Create two matrices
    Matrix<T> mat1(rows, cols);
    Matrix<T> mat2(rows, cols);

    // Input matrices
    std::cout << "Matrix 1:\n";
    mat1.input();
    std::cout << "Matrix 2:\n";
    mat2.input();

    // Input the operation
    std::cout << "Enter operation (+, -, *, transpose1, transpose2): ";
    std::cin >> operation;

    // Perform the operation
    if (operation == "+") {
        Matrix<T> result = mat1 + mat2;
        std::cout << "Result of addition:\n";
        result.display();
    } else if (operation == "-") {
        Matrix<T> result = mat1 - mat2;
        std::cout << "Result of subtraction:\n";
        result.display();
    } else if (operation == "*") {
        if (mat1.numCols() != mat2.numRows()) {
            std::cerr << "Matrix multiplication is not possible. Column count of Matrix 1 must equal row count of Matrix 2.\n";
        } else {
            Matrix<T> result = mat1 * mat2;
            std::cout << "Result of multiplication:\n";
            result.display();
        }
    } else if (operation == "transpose1") {
        Matrix<T> result = mat1.transpose();
        std::cout << "Transpose of Matrix 1:\n";
        result.display();
    } else if (operation == "transpose2") {
        Matrix<T> result = mat2.transpose();
        std::cout << "Transpose of Matrix 2:\n";
        result.display();
    } else {
        std::cerr << "Invalid operation.\n";
    }
}

int main() {
    // Handle matrix operations with integer matrices
    handleMatrixOperations<int>();
    return 0;
}
