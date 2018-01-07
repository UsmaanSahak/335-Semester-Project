#ifndef TSP_INSTANCE_READER_H
#define TSP_INSTANCE_READER_H

#include<string>

using std::string;

struct tsp_instance {
  string name;
  double * x, * y;
  long int num_points;
};
struct tsp_instance * read_tsp_instance(string fname);

#endif
//Weights are the euclidian distances between each
//Square root of the sum of squares	
