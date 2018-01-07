all: operation_batch_tester

operation_batch_tester: main.o MurmurHash64A.o graph.o set.o mHash.o OperationBatchTester.o operation_sequence_reader.o binaryTree.o AVLTree.o tsp_instance_reader.o
	g++ -pg main.o graph.o set.o mHash.o OperationBatchTester.o operation_sequence_reader.o binaryTree.o AVLTree.o MurmurHash64A.o tsp_instance_reader.o -o operation_batch_tester

main.o: main.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF main.o.d -o main.o main.cpp

set.o: set.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF set.o.d -o set.o set.cpp

graph.o: graph.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF graph.o.d -o graph.o graph.cpp

mHash.o: mHash.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF mHash.o.d -o mHash.o mHash.cpp

MurmurHash64A.o: MurmurHash64A.c
	gcc -c -pg -MMD -MP -MF MurmurHash64A.o.d -o MurmurHash64A.o MurmurHash64A.c

OperationBatchTester.o: OperationBatchTester.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF OperationBatchTester.o.d -o OperationBatchTester.o OperationBatchTester.cpp

operation_sequence_reader.o: operation_sequence_reader.c
	gcc -c -pg -MMD -MP -MF operation_sequence_reader.o.d -o operation_sequence_reader.o operation_sequence_reader.c

binaryTree.o: binaryTree.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF binaryTree.o.d -o binaryTree.o binaryTree.cpp

AVLTree.o: AVLTree.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF AVLTree.o.d -o AVLTree.o AVLTree.cpp

tsp_instance_reader.o: tsp_instance_reader.cpp
	g++ -c -pg -std=c++11 -MMD -MP -MF tsp_instance_reader.o.d -o tsp_instance_reader.o tsp_instance_reader.cpp

clean:
	rm *.o *.o.d gmon.out p.txt temptext.txt operation_batch_tester matrix_operation_batch_tester results* OperationResults* MultiplicationResults*
