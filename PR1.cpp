#include <iostream>
#include <vector>
#include <stdexcept> // Для использования std::invalid_argument
 

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    // Конструктор класса Matrix
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // Инициализация матрицы нулями
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // Конструктор копирования
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    // Оператор присваивания
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    // Перегрузка оператора сложения
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix dimensions must match for addition");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора увеличения на другую матрицу
    Matrix& operator+=(const Matrix& other) {
        *this = *this + other;
        return *this;
    }

    // Перегрузка оператора вычитания
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix dimensions must match for subtraction");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора уменьшения на другую матрицу
    Matrix& operator-=(const Matrix& other) {
        *this = *this - other;
        return *this;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int rows, cols;
    std::cout << "Введите количество строк и столбцов матрицы A: ";
    std::cin >> rows >> cols;

    // Создание объекта матрицы A

    Matrix A(rows, cols);
    std::cout << "Введите элементы матрицы A:" << std::endl;
    std::cin >> A;

    // Вывод матрицы A
    std::cout << "Матрица A:" << std::endl;
    std::cout << A;

    // Создание объекта матрицы B
    Matrix B(rows, cols);
    std::cout << "Введите элементы матрицы B:" << std::endl;
    std::cin >> B;

    // Вывод матрицы B
    std::cout << "Матрица B:" << std::endl;
    std::cout << B;

    // Сложение матриц A и B
    Matrix C = A + B;
    std::cout << "Матрица A + B:" << std::endl;
    std::cout << C;
    // Вычитание матриц A и B
    Matrix D = A - B;
    std::cout << "Матрица A - B:" << std::endl;
    std::cout << D;

    return 0;
}