/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperationBatchTester.h
 * Author: benjamin
 *
 * Created on September 6, 2017, 11:02 PM
 */

#ifndef OPERATIONBATCHTESTER_H
#define OPERATIONBATCHTESTER_H
		#include <math.h>
    #include<cstdint>
    #include <map>
    //#include<cstdlib>
    //#include<string.h>
    //#include<fstream>
    //#include<iostream>
    #include "tsp_instance_reader.h"
    #include "mHash.h"
    #include "MatrixOperator.h"
    #include "binaryTree.h"
    #include "AVLTree.h"
    #include "operationSequence.h"
    #include "operation_sequence_reader.h"
    //#include "set.h"
    #include "graph.h"

    namespace UsmaanSahak {
        class OperationBatchTester{
        public:
            OperationBatchTester(int argc, char **argv);
            bool readOperationSequence();
             template<class T>
            bool readMatrixSequence(int argc, char** argv, MatrixOperator<T> theOp); //Needs all 3 options filled out.
            void mergeSort(edge arr[], int l, int r);
            void merge(edge arr[], int l, int m, int r);
	    void printUsage() const;
        private:

            int num_matrices; 
            int num_rows;
            int num_columns;
            char operation_input_fname[200];
            char matrix_input_fname[200];
            char results_output_fname[200];
            char matrix_data_type[20];
            char graphFile[50];
            char data_structure[20];
           
        };
    }

#endif /* OPERATIONBATCHTESTER_H */

