/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "OperationBatchTester.h"
#define LINEAR 0
#define QUAD 1

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
UsmaanSahak::AVLTree GTree; //Global binary tree.
UsmaanSahak::binaryTree BTree;
UsmaanSahak::mHash lHash;
UsmaanSahak::mHash qHash;
std::map<uint64_t, uint64_t> sHash;

namespace UsmaanSahak {


	void OperationBatchTester::printUsage() const {
		cerr << "\nUSAGE:\n"
		<< "operation_batch_tester --operation_input_fname <input_filename> --results_output_fname <output_fname> [--data_structure <structure>] [--use_quadratic_probe] [--verbose]\n"
		<< "Where <input_filename> is a path to an existing file\n"
		<< "<output_fiename> is a path to a location where no file with the given name exists\n"
		<< "<structure> is one of \"avl_tree\", \"binary_tree\", \"hashtable\", \"graph\"\n"
		<< "\n"
		<< "If no data structure is specified, operation_batch_tester defaults to the hash table.\n"
		<< "If data structure is \"hashtable\" and --use_quadratic_probe is supplied, quadratic probing is used in lieu of linear. Otherwise the flag is ignored.\n"
		<< "\n\n"
		<< "operation_batch_tester --matrix_input_fname <filename> --results_output_fname <filename> --matrix_data_type <data_type> [--truncate_invalid_matrix_pairs] [--verbose]\n"
		<< "where <input_filename> is a path to an existing file\n"
		<< "<output_filename> is a path to a location where no file with the given name exists.\n"
		<< "<matrix_data_type> is one of the numeric C++ data types \"uint8_t\", \"uint16_t\", \"uint32_t\", \"uint64_t\", \"int8_t\", \"int16_t\", \"int32_t\", \"int64_t\", \"float\" and \"double\"\n"
		<< endl;
	}
		
    OperationBatchTester::OperationBatchTester(int argc, char **argv) {


        int64_t g;
        
        //Last minute character corruption errors, workaround.
        int operation = 0;
        int multiplication = 0;
        int dataType = 0;
        int resultFile = 0;
        int isStdHash = 0;
        int isGraph = 0;
        int structure_spec = 0; //If still 0, default to hash.
        int use_quadratic_probe = 0;
        int skipUsage = 0;

      operation_sequence * os;
        
      for (int g = 0; g < argc; g++) {
            /*added options.*/
        if (strcmp(argv[g], "--operation_input_fname")==0) {
          if (g+1 < argc) {
            strcpy(operation_input_fname, &argv[++g][0]);
            operation = 1;
          }
        }
        if (strcmp(argv[g], "--matrix_input_fname")==0) {
          if (g+1 < argc) {
            strcpy(matrix_input_fname, &argv[++g][0]);
            multiplication = 1;
          }
        }
        if (strcmp(argv[g], "--results_output_fname")==0){
          if (g+1 < argc) {
            strcpy(results_output_fname, &argv[++g][0]);
            resultFile = 1;
            }
          }
        if (strcmp(argv[g], "--matrix_data_type")==0) {
          if (g+1 < argc) {
            strcpy(matrix_data_type, &argv[++g][0]);
            dataType = 1;
          }
        }
        if (strncmp(argv[g], "--stdHash",9)==0) {
        	isStdHash = 1;
      	}
      	if (strncmp(argv[g], "--data_structure",16)==0) {
      		strcpy(data_structure, &argv[++g][0]);
      		structure_spec = 1;
      	}
      	if (strncmp(argv[g], "--use_quadratic_probe",21)==0) {
      		use_quadratic_probe = 1;
      	}
      	if (strncmp(argv[g], "--skipUsage",11)==0) {
      		skipUsage = 1;
      	}
    }
    if (structure_spec == 0) {
    	strcpy(data_structure,"hashtable");
    }
	cout << data_structure << " is data_structure.\n";
	if (skipUsage == 0) {
		printUsage();
		cout << endl << endl;				
	}


		if (strncmp(data_structure,"graph",5)==0) {
			cout << "Running graph!\n";
			graph tspGraph;
			struct tsp_instance* instance;
			
			/*
			instance = read_tsp_instance("tsp/straight_line/straight_line_constant_10_1_1_1.tsp");
			*/
			instance = read_tsp_instance(operation_input_fname);
			
			cout << "Name: " << instance->name << endl;
			cout << "Num points: " << instance->num_points << endl;
	vector<edge> pEdges;
  for(g=0; g<instance->num_points; g++){
    //cout << instance->x[g] << " " << instance->y[g] << endl;
    tspGraph.vertices.push_back(g+'0');
    //We only need coordinates once. Use it here to make the appropriate edge.
    for (int h=1; h < instance->num_points; h++) {
    	if (g == h) { continue; }
    	//cout << instance->y[g] << " " << instance->y[h] << endl;
    	//cout << instance->x[g] << " " << instance->x[h] << endl;
  		float y = instance->y[g] - instance->y[h];
  		float x = instance->x[g] - instance->x[h];
  		float w = sqrt(pow(y,2) + pow(x,2));
  		//cout << "weight is " << w << endl;
			edge temp;
			temp.v1 = g;
			temp.v2 = h;
			temp.weight = w;
			tspGraph.edges.push_back(temp);
    }
  }
  
  
  
	/*By now the graph data structure should be complete.*/
	/*
	for (int i = 0; i < tspGraph.edges.size(); i++) {
		cout << tspGraph.edges[i].v1 << " " << tspGraph.edges[i].v2 << " w" << tspGraph.edges[i].weight << ", ";
	}
	cout << "vertices: size " << tspGraph.vertices.size() << "\n";
	
	for (int i = 0; i < tspGraph.vertices.size(); i++) {
		cout << tspGraph.vertices[i] << ", ";
		cout << "test ";
	}
	*/
	edge* temp = &(tspGraph.edges[0]);
	int tempSize = tspGraph.edges.size();
	mergeSort(temp, 0, tempSize-1);
	
	
	
	/*
	vector<edge> tet; tet.push_back(tspGraph.edges[0]);
	tet.push_back(tspGraph.edges[1]);tet.push_back(tspGraph.edges[2]);
	tspGraph.edges = tet;
	*/
	/*
	cout << "\n\nEdges sorted.\n\n";
	for (int i = 0; i < tspGraph.edges.size(); i++) {
		cout << tspGraph.edges[i].v1 << " " << tspGraph.edges[i].v2 << ", ";
	}
	*/
	vector<edge> fastestPath = tspGraph.christofideMAGIC();
	cout << fastestPath.size() << " edges for MST:\n";
	
	if (resultFile == 1) {
		ofstream file;
		file.open(results_output_fname);
		for (int i = 0; i < fastestPath.size(); i++) {
			file << "(" << instance->x[fastestPath[i].v1] << "," << instance->y[fastestPath[i].v1] << ")" << "->" << "(" << instance->x[fastestPath[i].v2] << "," << instance->y[fastestPath[i].v2] << ")" << endl;
		}
	}
	else {
		for (int i = 0; i < fastestPath.size(); i++) {
			cout << "(" << instance->x[fastestPath[i].v1] << "," << instance->y[fastestPath[i].v1] << ")" << "->" << "(" << instance->x[fastestPath[i].v2] << "," << instance->y[fastestPath[i].v2] << ")" << endl;
		}
	}
  
}    
      
 if (operation == 1 && strncmp(data_structure,"hashtable",9)==0 && use_quadratic_probe == 0 && isStdHash == 0) {
        os = read_operation_sequence(operation_input_fname);
        lHash.setCapacity(os->capacity);
        lHash.setMaxLoad(os->max_load);

        lHash.setProbing(LINEAR);
        
        
        
        for(g=0; g<os->num_operations; g++){
             switch(os->operation[g]){
                 case 0:
                 		 if (lHash.readHash(os->key[g])) {
                     //cout << "READ " << os->key[g] << " " << os->expected_result[g] << endl;
                      //put the call to read from your ADT here
                     //cout << "read true\n"; 
                     } else { 
                     //cout << "read false\n"; 
                     }
                     //qHash.readHash(os->key[g]);
                     break;
                 case 1:
                     //cout << "WRITE " << os->key[g] << " " << os->expected_result[g] <<  endl;
                      //put the call to write to your ADT here
                     if (lHash.writeHash(os->key[g])) { 
                     //cout << "write true\n"; 
                     } else { 
                     //cout << "write false\n"; 
                     }
                     //qHash.writeHash(os->key[g]);
                     break;
                 case 2:
                     //cout << "DELETE " << os->key[g] << " " << os->expected_result[g] << endl;
                      //put the call to delete from your ADT here
                     if (lHash.deleteHash(os->key[g])) { 
                     //cout << "delete true\n"; 
                     } else { 
                     //cout << "delete false\n"; 
                     }
                     //qHash.deleteHash(os->key[g]);
                     break;
                 default:
                     cout << "Invalid operation: " << os->operation[g] << endl;
             }
        }
        cout << "Linear Probing:\n";
        cout << lHash.probes << " is the number of probes.\n";
        cout << lHash.reads << " is the number of reads.\n";
        cout << lHash.writes << " is the number of writes.\n";
        cout << lHash.deletes << " is the number of deletes.\n";
        float total = lHash.reads + lHash.writes + lHash.deletes;
        cout << total << " is the total\n";
        cout << lHash.probes/total << " is fraction.\n";
        cout << endl;
      }



if (operation == 1 && strncmp(data_structure,"hashtable",9)==0 && use_quadratic_probe == 1) {
        os = read_operation_sequence(operation_input_fname);
        qHash.setCapacity(os->capacity);
        qHash.setMaxLoad(os->max_load);

        qHash.setProbing(QUAD);
        
        for(g=0; g<os->num_operations; g++){
             switch(os->operation[g]){
                 case 0:
                 		 if (qHash.readHash(os->key[g])) {
                     //cout << "read true\n"; 
                     } else { 
                     //cout << "read false\n"; 
                     }
                     break;
                 case 1:
                     if (qHash.writeHash(os->key[g])) { 
                     //cout << "write true\n"; 
                     } else { 
                     //cout << "write false\n"; 
                     }
                     break;
                 case 2:
                     if (qHash.deleteHash(os->key[g])) { 
                     //cout << "delete true\n"; 
                     } else { 
                     //cout << "delete false\n"; 
                     }
                     break;
                 default:
                     cout << "Invalid operation: " << os->operation[g] << endl;
             }
        }
        cout << "Quadratic Probing:\n";
        cout << qHash.probes << " is the number of probes.\n";
        cout << qHash.reads << " is the number of reads.\n";
        cout << qHash.writes << " is the number of writes.\n";
        cout << qHash.deletes << " is the number of deletes.\n";
        float total = qHash.reads + qHash.writes + qHash.deletes;
        cout << total << " is the total\n";
        cout << qHash.probes/total << " is fraction.\n";
     		//GHash.outputHash();
      }

if (operation == 1 && strncmp(data_structure,"hashtable",9) && isStdHash == 1) {
        os = read_operation_sequence(operation_input_fname);

        for(g=0; g<os->num_operations; g++){
             switch(os->operation[g]){
                 case 0:
                     if(sHash[os->key[g]]) {
                       cout << sHash[os->key[g]] << endl;
                     }
                     break;
                 case 1:
                     sHash[os->key[g]] = g;
                     break;
                 case 2:
                 {
                     std::map<uint64_t, uint64_t>::iterator it = sHash.begin();
                     while (it != sHash.end()) {
                       if (it->second == os->key[g]) {
                         it = sHash.erase(it);
                       }
                       it++;
                     }
                     break;
                 }
                 default:
                     cout << "Invalid operation: " << os->operation[g] << endl;
             }
        }
      }

      if (operation == 1 && strncmp(data_structure,"binary_tree",11)==0) {
        os = read_operation_sequence(operation_input_fname);
        BTree.setCapacity(os->capacity);

        for(g=0; g<os->num_operations; g++){
             switch(os->operation[g]){
                 case 0:
                     if (BTree.readTree(os->key[g])) { 
                     //cout << "read true\n"; 
                     } else { 
                     //cout << "read false\n"; 
                     }
                     break;
                 case 1:
                     if (BTree.writeTree(os->key[g])) { 
                     //cout << "write true\n"; 
                     } else { 
                     //cout << "write false\n"; 
                     }
                     break;
                 case 2:
                     if (BTree.deleteTree(os->key[g])) { 
                     //cout << "delete true\n"; 
                     } else { 
                     //cout << "delete false\n"; 
                     }
                     break;
                 default:
                     cout << "Invalid operation: " << os->operation[g] << endl;
             }
        }
        if (resultFile == 1) {
        	std::ofstream file;
        	file.open(results_output_fname);
        	BTree.outputTree(file);
        	cout << "Results in " << results_output_fname <<".\n";
        	double logBaseTwo = log(BTree.getSize() + 2)/log(2);
  			float maxTheoreticalHeight = 1.44 * logBaseTwo - 1.328;
  			file << maxTheoreticalHeight << " theoretical max height vs the actual height, " << BTree.totalHeight << std::endl;
  			file << "------------------------------\n";
        } else {
  				BTree.outputTree(); //Just output to terminal.
  				std::cout << "The binary tree's total height is " << BTree.totalHeight << "\n";
        double logBaseTwo = log(BTree.getSize() + 2)/log(2);
  			float maxTheoreticalHeight = 1.44 * logBaseTwo - 1.328;
  			std::cout << maxTheoreticalHeight << " theoretical max height vs the actual height, " << BTree.totalHeight << std::endl;
  			std::cout << "------------------------------\n";
  			}
        
        
      }
      
      
       if (operation == 1 && strncmp(data_structure,"avl_tree",8)==0) {
        os = read_operation_sequence(operation_input_fname);
        GTree.setCapacity(os->capacity);

        for(g=0; g<os->num_operations; g++){
             switch(os->operation[g]){
                 case 0:
                     if (GTree.readTree(os->key[g])) { 
                     //cout << "read true\n"; 
                     } else { 
                     //cout << "read false\n"; 
                     }
                     //BTree.readTree(os->key[g]);
                     break;
                 case 1:
                     if (GTree.writeTree(os->key[g])) { 
                     //cout << "write true\n"; 
                     } else { 
                     //cout << "write false\n"; 
                     }
                     break;
                 case 2:
                     if (GTree.deleteTree(os->key[g])) { 
                     //cout << "delete true\n"; 
                     } else { 
                     //cout << "delete false\n"; 
                     }
                     break;
                 default:
                     cout << "Invalid operation: " << os->operation[g] << endl;
             }
        }
        
        if (resultFile == 1) {
        	std::ofstream file;
        	file.open(results_output_fname);
        	std::cout << "results in " << results_output_fname << std::endl;
        	GTree.outputTree(file);
        	file << "The AVL tree's total height is " << 			GTree.totalHeight << "\n";
        	double logBaseTwo = log(GTree.getSize() + 2)/log(2);
  				float maxTheoreticalHeight = 1.44 * logBaseTwo - 1.328;
  				file << maxTheoreticalHeight << " theoretical max height vs the actual height, " << GTree.totalHeight << std::endl;
  				file << "------------------------------\n";

        } else {
        	GTree.outputTree();
        	std::cout << "The AVL tree's total height is " << 			GTree.totalHeight << "\n";
        	double logBaseTwo = log(GTree.getSize() + 2)/log(2);
  				float maxTheoreticalHeight = 1.44 * logBaseTwo - 1.328;
  				std::cout << maxTheoreticalHeight << " theoretical max height vs the actual height, " << GTree.totalHeight << std::endl;
  				std::cout << "------------------------------\n";
  			}
        
    }
      
      
      
      
      
      
        //Check to see if all options are filled out.
        int error = 0;
        if (multiplication == 1) {
         if (resultFile == 0) {
            cout << "--results_output_fname <new file name>\n";
            error++;
          }
          if (dataType == 0) {
            cout << "--matrix_data_type <type>\n";
            error++;
          }
        }
     
        //If any of the following if statements run, then exit.
        if (error != 0) { exit(1);}
        
    if (multiplication == 1) {
      //Use whatever type user specified.
      if (strcmp(matrix_data_type,"int")==0) {
        UsmaanSahak::MatrixOperator<int> Op(argc,argv);
        readMatrixSequence(argc, argv, Op);
      } else if(strcmp(matrix_data_type,"int32_t")==0) {
        UsmaanSahak::MatrixOperator<int32_t> Op(argc,argv);
        readMatrixSequence(argc,argv, Op);
      }
      else if(strcmp(matrix_data_type,"int64_t")==0) {
        UsmaanSahak::MatrixOperator<int64_t> Op(argc,argv);
        readMatrixSequence(argc,argv, Op);
      }
      else if(strcmp(matrix_data_type,"float")==0) {
        UsmaanSahak::MatrixOperator<float> Op(argc,argv);
        readMatrixSequence(argc, argv, Op);
      }
      else if(strcmp(matrix_data_type,"double")==0) {
        UsmaanSahak::MatrixOperator<double> Op(argc,argv);
        readMatrixSequence(argc,argv, Op);
      }
      else if(strcmp(matrix_data_type,"long")==0) {
        UsmaanSahak::MatrixOperator<long> Op(argc,argv);
        readMatrixSequence(argc,argv, Op);
      }
      else if(strcmp(matrix_data_type,"short")==0) {
        UsmaanSahak::MatrixOperator<short> Op(argc,argv);
        readMatrixSequence(argc, argv, Op);
      }
      else { cout << matrix_data_type << "matrix_data_type not recognized. (int, long, double, float, int64_t, etc)\n"; exit(1); }
    
    }
    
    //Add the new function of the program, operation.
    if (operation == 1) {
      readOperationSequence();
    }
  }

  bool OperationBatchTester::readOperationSequence() {
  
    int64_t deletions_enabled = 0;
    int64_t max_key = 0;
    int64_t capacity = 0;
    int64_t max_load = 0;
    int64_t num_operations = 0;
    ifstream fin;
    fin.open(operation_input_fname);
    if (fin.fail()) { 
      cout << "Operation input file failed to open.\n";
      exit(1);
    }
    std::string buf;
    int64_t num;
    
    fin >> buf; fin >> buf; //has feedback
    fin >> buf; fin >> buf; //has indexes (indicies?)
    fin >> buf;
    fin >> deletions_enabled;
    fin >> buf;
    fin >> max_key;
    fin >> buf;
    fin >> capacity;
    fin >> buf;
    fin >> max_load;
    fin >> buf;
    fin >> num_operations;
    
    //first is the operation
    //second is the value
    //third is whether it was success or failure
    
    
    
    fin >> num;
    /*
    if (num == 1) {
    
    //Add next value to binary tree.
    //write/readTree functions that use num on GTree.
      if (writeTree(num, GTree)) { cout << "WRITTEN\n"; }
      else { cout << "NO WRITE!!!!!!@$\n"; }
      cout << "write HOOOO" << std::endl;
    } else if (num == 0) {
      fin >> num;
      if (readTree(num, GTree)) { cout << "PRESENT\n"; }
      else { cout << "ABSENT\n"; }
    }
    else { cout << "No\n"; }
    //FILL ME
    //noder = stuf
   */  
   
   //Maybe should be filling and OperationSequence first.
  }
  
    
    
    
    
    
   
    
    
    
    
    
    
    
    
    
    
    
    template<class T>
    bool OperationBatchTester::readMatrixSequence(int argc,char** argv, MatrixOperator<T> theOp) {
    
     //Manipulate all three options 
     ofstream fout;
     fout.open(results_output_fname);
        if (fout.fail()) { std::cout << "results output file failed to open.\n"; exit(1);}   
        
      int64_t g;
      ifstream fin;
      char buf[200];
      fin.open(matrix_input_fname);
      if (fin.fail()) {
        cout << "Matrix input file failed to open.\n";
        exit(1);
      }
      //Keep going until NUM_MATRICES shows up.

      while (!num_matrices) {
        if (strcmp(buf, "NUM_MATRICES")==0) {
            fin >> num_matrices;
        } else { 
          fin >> buf;
        }
      }

      //Keep going until buf picks up a skipped line.
      while (fin >> buf) {
        if (strcmp(buf, "NUM_ROWS")==0 || strcmp(buf, "NUM_COLUMNS")==0) {

          if (strcmp(buf, "NUM_ROWS")==0) {
            fin >> num_rows;
            fin >> buf;
            fin >> num_columns;

          }
          else if (strcmp(buf, "NUM_COLUMNS")==0) {
            fin >> num_columns;
            fin >> buf;
            fin >> num_rows;

          }

          UsmaanSahak::Matrix<T> m(num_rows,num_columns);
          for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_columns; j++) {
              T a;
              fin >> a;
              m.addElement(a,i,j);
            }
          }
          theOp.matrices.push_back(m);
        }
        } //EOF
        fin.close();
        //Put the multiplicant of 0 and 1 into 0.

        theOp.matrices[0] = theOp.multiply(theOp.matrices[0], theOp.matrices[1]);
        fout << theOp.matrices[0];
        fout.close();
        cout << "results in " << results_output_fname << ".\n";
        if (theOp.matrices.size() >= 3) {
          if (theOp.matrices[0].equals(theOp.matrices[2])) {
            std::cout << "equals() returns true.\n";
          } else { std::cout << "equals() returns false.\n"; }
        } else { std::cout << "No third matrix.\n"; }
        
        
        for (int i = 0; i < theOp.matrices.size(); i++) {
          theOp.matrices[i].delMatrix();
        }
        
        return true;
      
    }
		//Debugging
		void OperationBatchTester::merge(edge arr[], int l, int m, int r)
		{
		    int i, j, k;
		    int n1 = m - l + 1;
		    int n2 =  r - m;
 
    /* create temp arrays */
    edge L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].weight <= R[j].weight)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
		    while (j < n2)
		    {
		        arr[k] = R[j];
		        j++;
		        k++;
		    }
		}
 
		/* l is for left index and r is right index of the
		   sub-array of arr to be sorted */
		void OperationBatchTester::mergeSort(edge arr[], int l, int r)
		{
		    if (l < r)
		    {
		        // Same as (l+r)/2, but avoids overflow for
		        // large l and h
		        int m = l+(r-l)/2;
		 
		        // Sort first and second halves
		        mergeSort(arr, l, m);
		        mergeSort(arr, m+1, r);
		 
		        merge(arr, l, m, r);
		    }
		}
}













