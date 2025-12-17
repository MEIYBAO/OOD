#pragma once

#include <iostream>
#include <algorithm>
#include <cstdlib>

// 类Matrix声明
class Matrix {
public:
    Matrix(int rows_, int cols_, double value = 0); // 构造rows_*cols_矩阵对象, 初值value
    Matrix(int rows_, double value = 0);    // 构造rows_*rows_方阵对象, 初值value
    Matrix(const Matrix &x);    // 深复制
    ~Matrix();

    void set(const double *pvalue, int size);   // 按行复制pvalue指向的数据，要求size=rows*cols,否则报错退出
    void clear();   // 矩阵对象数据项置0
    
    const double& at(int i, int j) const;   // 返回矩阵对象索引(i,j)对应的数据项const引用（越界则报错后退出）
    double& at(int i, int j);   // 返回矩阵对象索引(i,j)对应的数据项引用（越界则报错后退出）
    
    int rows() const;   // 返回矩阵对象行数
    int cols() const;   // 返回矩阵对象列数

    void print() const;   // 按行打印数据

private:
    int n_rows;      // 矩阵对象内元素行数
    int n_cols;       // 矩阵对象内元素列数
    double *ptr;    // 数据区
};

Matrix :: Matrix(int rows_, int cols_, double value) {
    if(rows_ <= 0 || cols_ <= 0) {
        std::cout << "行数或列数必须为正整数\n";
        exit(1);
    }
    n_rows = rows_;
    n_cols = cols_;
    ptr = new double[n_rows * n_cols];
    std::fill_n(ptr, n_rows * n_cols, value);
}

Matrix :: Matrix(int rows_, double value) {
    if(rows_ <= 0) {
        std::cout << "方阵行列数必须为正整数\n";
        exit(1);
    }
    n_rows = rows_;
    n_cols = rows_;
    ptr = new double[n_rows * n_cols];
    std::fill_n(ptr, n_rows * n_cols, value);
}

Matrix :: Matrix(const Matrix &x) {
    n_rows = x.n_rows;
    n_cols = x.n_cols;
    ptr = new double[n_rows * n_cols];
    std::copy_n(x.ptr, n_rows * n_cols, ptr);
}

Matrix :: ~Matrix() {
    delete [] ptr;
}

void Matrix :: set(const double *pvalue, int size) {
    if(size != n_rows * n_cols) {
        std::cout << "矩阵大小不匹配\n";
        exit(1);
    }
    std::copy_n(pvalue, size, ptr);
}

void Matrix :: clear() {
    std::fill_n(ptr, n_rows * n_cols, 0);
}

const double& Matrix :: at(int i, int j) const {
    if(i < 0 || i >= n_rows || j < 0 || j >= n_cols) {
        std::cout << "索引越界\n";
        exit(1);
    }
    return ptr[i * n_cols + j];
}

double& Matrix :: at(int i, int j) {
    return const_cast<double &>((static_cast<const Matrix*>(this))->at(i, j)); 
}

int Matrix :: rows() const {
    return n_rows;
}

int Matrix :: cols() const {
    return n_cols;
}

void Matrix :: print() const {
    for(int i = 0; i < n_rows; ++i) {
        std::cout << at(i, 0);
        for(int j = 1; j < n_cols; ++j)
            std::cout << ", " << at(i, j);
        std::cout << '\n';
    }
}