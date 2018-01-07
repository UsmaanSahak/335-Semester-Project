How To Use: <Assignment 5>

./demo

It makes the project and runs test.sh, which is a rundown of commands using different commandline arguments in order to display the capabilities required by the grading rubric and make grading easier.









#Updated above
How To Use: <Assignment 3>

./demo

Must include --isHash in order to create a hash, or --isTree in order to create a tree. --isHash will create two hashes, one with linear probing and another with quadratic probing, and compare them.


Must use the --lhash, --qhash or --tree options in order to differentiate between which operation you want to run.

--lhash creates a hash with linear probing.
--qhash creates a hash with quadratic probing.












How To Use: <Assignment 2>

./demo

This will run the file sequence of 200000 operations, creating a binary tree of height 32 and an AVL tree of height 18.
The maximum height is calculated to be approximately 19.9804 for the AVL tree, so it passes. The program will recalculate the max height based off of the file name you use as an argument.

./matrix_operation_batch_tester operation_input_fname <file you want to individually test>


NOTE: For the largest file, operation_sequence_with_fedback_1000000-65536-65536-3296, the results came out to be 32 nodes in height for the binary tree, and 18 nodes of height for the AVL tree, with the calculated max height as 20.2637. It will take about 20-30 minutes to process, so I thought it would be better to exclude it from the test shell script run by demo, and instead mention the results here.








How to use:<OUTDATED, revised above>

./matrix_operation_batch_tester --operation_input_fname ../csci335proj12files/335_common/without_deletions/operation_sequence_with_feedback-10-64-32-5 

Run demo, or use the commands listed below.
Note: For convenience, the flag --truncate_invalid_matrix_pairs has been turned on by default, as the test script will not run without truncation.
Example commands:

./operation_batch_tester --operation_input_fname operation_sequence_short --matrix_input_fname large_matrix_file_int --results_output_fname MultiplicationResults.txt --matrix_data_type int --truncate_invalid_matrix_pairs > OperationResults.txt

./operation_batch_tester --operation_input_fname operation_sequence_medium --matrix_input_fname extra_large_matrix_file_long_int --results_output_fname MultiplicationResults.txt --matrix_data_type long --truncate_invalid_matrix_pairs > OperationResults.txt

./operation_batch_tester --operation_input_fname operation_sequence_long --matrix_input_fname extra_large_matrix_file_double --results_output_fname MultiplicationResults.txt --matrix_data_type double --truncate_invalid_matrix_pairs > OperationResults.txt


All options except truncate_invalid_matrix_pairs are mandatory. 
--operation_input_fname <operation file name>
--matrix_input_fname <matrix file name>
--results_output_fname <new file name for matrix product>
--matrix_data_type <long, int, int64_t, etc>
--truncate_invalid_matrix_pairs (if present, will truncate. edit: currently made so truncates regardless. MatrixOperator.cpp line 8 set to false, if want to revert.)


All features have been added to my understanding of the specifications.












This project illustrates an effective way to obtain empirical results using a class-based C++ implementation of 
a simple example ADT called Operation. To see this project run, make sure this repository is placed in an
environment having g++ installed, and just type ./demo at the command line.

The effect of running the demo script is that first the executable called operation_batch_tester will be build, 
then it will be run three times. Each time it runs, a larger input data file will be used. The output results
of these three trials will be placed in files results_short, results_medium, and results_long respectively.
