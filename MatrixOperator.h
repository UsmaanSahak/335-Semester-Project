/*
File: MatrixOperator.h
Author: Usmaan Sahak
*/

#ifndef MATRIXOPERATOR_H
#define MATRIXOPERATOR_H

#include "Matrix.h"

namespace UsmaanSahak {
 template<class T>
 class MatrixOperator {
  public:
   MatrixOperator(int argc, char** argv);
   Matrix<T> multiply(Matrix<T>& one, Matrix<T>& two); //After multiplying, it prints out the result onto  --results_output_fname. 
   std::vector<UsmaanSahak::Matrix<T> > matrices;
   private:
    bool truncate_invalid_matrix_pairs;
    
 };
 
}

namespace UsmaanSahak {
  template<class T>
  MatrixOperator<T>::MatrixOperator(int argc, char** argv) {
  
  //Intentionally made true. Switch below to false to test.
    truncate_invalid_matrix_pairs = true;
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "--truncate_invalid_matrix_pairs")==0) {
        truncate_invalid_matrix_pairs = true;
      }
    }
  }
  
  template<class T>         
  Matrix<T> MatrixOperator<T>::multiply(Matrix<T>& one, Matrix<T>& two) {
    
    int row; int col;
    if ((!truncate_invalid_matrix_pairs) && (one.getNumRow() != two.getNumColumn()) || (one.getNumColumn() != two.getNumRow())) {
      std::cout << "Error, Matrix not valid. (Try --truncate_invalid_matrix_pairs?\n";
    }
    //Get the row and column of the multiplicant.
    if (one.getNumRow() > two.getNumRow()) {
      row = two.getNumRow();
    } else {
      row = one.getNumRow();
    }
    if (one.getNumColumn() > two.getNumColumn()) {
      col = two.getNumColumn();
    } else {
      col = one.getNumColumn();
    }
    
    T** mat1 = one.getMat();
    T** mat2 = two.getMat();
    
    //setup recieving matrix.
    T** mult;
    mult = new T*[row];
    for (int i = 0; i < row; i++) {
      mult[i] = new T[col];
    }
    //Now lets actually multiply.
    int M1r = 0; //While < one.getNumRow(),  keep incrementing.
    int M1c = 0; //While < one.getNumColumn(), go another loop.
    int M2r = 0;
    int M2c = 0;
    int r = 0; //Iterators, while r < row ->  r++
    int c = 0;
    T sum = 0;
    
    //Iterate until all elements of mult are filled.
    while (c < col-1 || r < row-1) {
      //Keep multiplying a row of mat1 until cols of mat2 are depleted.
      while (M2c < two.getNumColumn()) {
      
        //Calculate a single element of mult.
        while (M1c < one.getNumColumn()) {
          sum = sum + (mat1[M1r][M1c] * mat2[M2r][M2c]);
          M1c++; M2r++;
        }
        M1c = 0; M2r = 0; //Reset, go to next row. 
        M2c++;
    
        mult[r][c] = sum;
        sum = 0;
        if (c < col-1) { c++; }
        else if ((r == row-1) && (c == col-1)) {/*dismiss the else, exit loop.*/}
        else { r++; c=0; }
      }
      M1r++;
      M2c = 0;
    }
    UsmaanSahak::Matrix<T> m(row,col,mult);
    return m;
  }


}









#endif



