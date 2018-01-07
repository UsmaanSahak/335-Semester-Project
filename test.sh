echo "1. Program correctly multiplies two matrices."
echo "2. Program vertifies that actual matrix product matches expected result."
echo "3. Matrix functionality is implemented using modular, single-responsibility software design."
echo

./operation_batch_tester --matrix_input_fname data/small_matrix_file_int --results_output_fname multres.txt --matrix_data_type int

echo
echo "4. Naive binary search tree correctly implements read function."
echo "5. Naive binary search tree correctly implements write function."
echo "6. Naive binary search tree correctly implements delete function."
echo "7. Program verifies that actual naive binary tree results matches expected results."
echo "8. Naive binary search tree results show comparison of max tree depth to the expected depth."
echo "9. Naive binary serach tree functionality is implemented using modular, single-responsibility software design."
echo

./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --results_output_fname binarytreetest.txt --data_structure binary_tree --skipUsage

echo
echo "10. AVL tree correctly implements read function."
echo "11. AVL tree correclty implements write function."
echo "12. AVL tree correctly implements delete function."
echo "13. Program verifies that actual AVL tree result matches expected result."
echo "14. AVL tree resutls show comparison of max tree depth to the expected depth."
echo "15. AVL tree functionality is implemented using modular, single-responsibility software design."
echo

./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --results_output_fname avltreetest.txt --data_structure avl_tree --skipUsage

echo
echo "16. Linear probe hashing correctly implements read function."
echo "17. Linear probe hashing correctly implements write function."
echo "18. Linear probe hashing correctly implements delete function."
echo "19. Program verifies that actual linear probe hashtable results matches expected result."
echo "20(a). Linear probe hashing functionality is implemented using modular, single-responsibility software design."
echo

./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --results_output_fname linearhashtest.txt --data_structure hashtable --skipUsage

echo
echo "20(b). Quadratic probe hashing correctly implements read function."
echo "21. Quadratic probe hashing correctly implements write function."
echo "22. Quadratic probe hashing correctly implements delete function."
echo "23. Program verifies that actual linear probe hashtable results matches expected result."
echo "20(c). Quadratic probe hashing functionality is implemented using modular, single-responsibility software design."
echo

./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --results_output_fname quadhashtest.txt --data_structure hashtable --use_quadratic_probe --skipUsage

echo
echo "24. Output results show comparison of average probes per operation for linear probe and quadratic probe."
echo


./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --data_structure hashtable --skipUsage
./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --data_structure hashtable --use_quadratic_probe --skipUsage

echo
echo "25. The STL hashmap versions of read, write, and delete are implemented in a separate module."
echo

./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --data_structure hashtable --stdHash --skipUsage

echo
echo "26. Project submission includes gprof runtime performance comparison between the linear probe hashing implementation and the STL hashmap implementation."
echo

echo "Files 'stdHashing.txt' and 'linearProbeHashing.txt' created."

gprof operation_batch_tester gmon.out > stdHashing.txt
./operation_batch_tester --operation_input_fname data/operation_sequence_with_feedback-300-32-16-16 --data_structure hashtable --results_output_fname temp.txt --skipUsage

gprof operation_batch_tester gmon.out > linearProbeHashing.txt

echo
echo "27. Disjoint sets functionality is correctly implemented."
echo "28. Program correctly constructs a minimum spanning tree using Krustal's algorithm."
echo "29. Program finds a solution to the traveling salesman problem using the orignal MST-based approach to Christofides algorithm. THe length of the obtained tour is less than or equal to twice the optimal tour length."
echo

echo "File 'graphtest.txt' created."
./operation_batch_tester --operation_input_fname tsp/random/random_200_1.tsp --results_output_fname graphtest.txt --data_structure graph --skipUsage

echo
echo "30. Output results display the solution quality of th eobtained TSP tour, expressed as a ratio of the length of the actual obtained tour to the length of the optimal tour."
echo "31. Program finds a solution to the traveling salesman problem using Chrstofides final version algorithm, and the length of the obtained tour is less than or equal to 3/2 the optimal tour length."
echo "32. The software builds without modification and executes witout runtime errors."
echo "33. Given a published bash script containing commands to be executed on your application, the program can parse command line arguments as intended."
echo








#echo "./matrix_operation_batch_tester --matrix_input_fname large_matrix_file_int --results_output_fname MultiplicationResultsOne.txt --matrix_data_type int --truncate_invalid_matrix_pairs"
#./matrix_operation_batch_tester --matrix_input_fname large_matrix_file_int --results_output_fname MultiplicationResultsOne.txt --matrix_data_type int --truncate_invalid_matrix_pairs 
#echo "gprof matrix_operation_batch_tester gmon.out > analysisOne.txt"
#gprof matrix_operation_batch_tester gmon.out > analysisOne.txt
#echo "./matrix_operation_batch_tester --matrix_input_fname extra_large_matrix_file_long_int --results_output_fname MultiplicationResultsTwo.txt --matrix_data_type long --truncate_invalid_matrix_pairs"
#./matrix_operation_batch_tester --matrix_input_fname extra_large_matrix_file_long_int --results_output_fname MultiplicationResultsTwo.txt --matrix_data_type long --truncate_invalid_matrix_pairs
#echo "gprof matrix_operation_batch_tester gmon.out > analysisTwo.txt"
#gprof matrix_operation_batch_tester gmon.out > analysisTwo.txt
#echo "./matrix_operation_batch_tester --matrix_input_fname extra_large_matrix_file_double --results_output_fname MultiplicationResultsThree.txt --matrix_data_type double --truncate_invalid_matrix_pairs"
#./matrix_operation_batch_tester --matrix_input_fname extra_large_matrix_file_double --results_output_fname MultiplicationResultsThree.txt --matrix_data_type double --truncate_invalid_matrix_pairs
#echo "gprof matrix_operation_batch_tester gmon.out > analysisThree.txt"
#gprof matrix_operation_batch_tester gmon.out > analysisThree.txt


#./matrix_operation_batch_tester --operation_input_fname ../csci335proj12files/335_common/contains_deletions/operation_sequence_with_feedback-700-32-16-16


#echo "Comparing linear and quadratic probing."
#./matrix_operation_batch_tester --operation_input_fname operation_sequence_with_feedback-1000-32-16-16 --isHash

#echo "Linear probing > linearProbing.txt"
#./matrix_operation_batch_tester --operation_input_fname operation_sequence_with_feedback-1000-32-16-16 --lHash
#gprof matrix_operation_batch_tester gmon.out > linearProbing.txt

#echo "Quadratic probing > quadProbing.txt"
#./Matrix_operation_batch_tester --operation_input_fname operation_sequence_with_feedback-1000-32-16-16 --qHash
#gprof matrix_operation_batch_tester gmon.out > quadProbing.txt

#echo "Standard template library hash > stdHash.txt"
#./matrix_operation_batch_tester --operation_inpu_fname operation_sequence_with_feedback-1000-32-16-16 --StdHash
#gprof matrix_operation_batch_tester gmon.out >stdHash.txt

#./matrix_operation_batch_tester --operation_input_fname operation_sequence_with_feedback-200000-65536-32768-28475


