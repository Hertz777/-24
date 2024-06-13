#include <iostream>
#include <vector>
#include <stdexcept> // ��� ������������� std::invalid_argument
 

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    // ����������� ������ Matrix
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // ������������� ������� ������
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // ����������� �����������
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    // �������� ������������
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    // ���������� ��������� ��������
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

    // ���������� ��������� ���������� �� ������ �������
    Matrix& operator+=(const Matrix& other) {
        *this = *this + other;
        return *this;
    }

    // ���������� ��������� ���������
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

    // ���������� ��������� ���������� �� ������ �������
    Matrix& operator-=(const Matrix& other) {
        *this = *this - other;
        return *this;
    }

    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // ���������� ��������� �����
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
    std::cout << "������� ���������� ����� � �������� ������� A: ";
    std::cin >> rows >> cols;

    // �������� ������� ������� A

    Matrix A(rows, cols);
    std::cout << "������� �������� ������� A:" << std::endl;
    std::cin >> A;

    // ����� ������� A
    std::cout << "������� A:" << std::endl;
    std::cout << A;

    // �������� ������� ������� B
    Matrix B(rows, cols);
    std::cout << "������� �������� ������� B:" << std::endl;
    std::cin >> B;

    // ����� ������� B
    std::cout << "������� B:" << std::endl;
    std::cout << B;

    // �������� ������ A � B
    Matrix C = A + B;
    std::cout << "������� A + B:" << std::endl;
    std::cout << C;
    // ��������� ������ A � B
    Matrix D = A - B;
    std::cout << "������� A - B:" << std::endl;
    std::cout << D;

    return 0;
}