/*
File: Matrix.h
Author: Usmaan Sahak
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string.h>

namespace UsmaanSahak {
  template<class T>
  class Matrix {
   public:
   Matrix();
   Matrix(int newRow, int newColumn, T** newMatrix);
   Matrix(int newRow, int newColumn);
   
   template<class U>
   friend std::ostream& operator<<(std::ostream& file, Matrix<U>& m);
   
   
   /*Added these mutators for QoL; should not be needed in final product.*/
    int getNumRow() { return numRow; }
    int getNumColumn() { return numColumn; }
    void setNumRows(int newRow) { numRow = newRow; }
    void setNumColumns(int newColumn) { numColumn = newColumn; }
    T** getMat() { return mat; }
    bool equals(const Matrix<T>& m);
    void addElement(T e, int r, int c) { mat[r][c] = e; }
    void delMatrix(); //frees memory, but not destructor.
   private:
    int numRow; 
    int numColumn;
    T** mat; //Dynamic array of arrays.
   };
}

namespace UsmaanSahak {

//Problem with handle in this constructor.

  template<class T>
  Matrix<T>::Matrix() {
    numRow = 0;
    numColumn = 0;
  }
  template<class T>
  Matrix<T>::Matrix(int newRow, int newColumn) {
    numRow = newRow;
    numColumn = newColumn;
    mat = new T*[numRow];
    for (int i = 0; i < numRow; i++) {
      mat[i] = new T[numColumn];
    }
  }
  
  template<class T>
  Matrix<T>::Matrix(int newRow, int newColumn, T** newMatrix) {
    numRow = newRow;
    numColumn = newColumn;
    mat = newMatrix;
  }
  
  template<class T>
  std::ostream& operator<<(std::ostream& file, Matrix<T>& m) {
    for (int i = 0; i < m.numRow; i++) {
      for (int j = 0; j < m.numColumn; j++) {
        file << m.mat[i][j] << " ";
      }
      file << '\n';
    }
    return file;
  }
  
  template<class T>
  bool Matrix<T>::equals(const Matrix<T>& m) {
    if ((numRow != m.numRow) || (numColumn != m.numColumn)){
      return false; 
    }
    for (int r = 0; r < numRow; r++) {
      for (int c = 0; c < numColumn; c++) {
        //Comparing differences, so Doubles and floats don't return false for one element having a 0.00000000001 difference.
        if ((mat[r][c] - m.mat[r][c]) > 1 || (mat[r][c] - m.mat[r][c]) < -1) {
          std::cout << mat[r][c] << " != " << m.mat[r][c] << std::endl;
          return false; 
        }
      }
    }
  }
  
  template<class T>
  void Matrix<T>::delMatrix() {
    for (int i = 0; i < numRow; i++) {
      delete mat[i];
    }
    delete mat;
  }
  
  
  
}










#endif
