#include "tsp_instance_reader.h"

#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::stol;

const string DIMENSION = "DIMENSION";
const string DIMENSION_ = "DIMENSION:";
const string NAME = "NAME";
const string NAME_ = "NAME:";
const string NODE_COORD_SECTION = "NODE_COORD_SECTION";

struct tsp_instance * read_tsp_instance(string fname){

  struct tsp_instance * instance = new tsp_instance;

  ifstream inStream;
  long int g, j, res;
  string s;

  inStream.open(fname);
  if(inStream.fail()){
    cout << "Could not open file: " << fname << endl;
    exit(1);
  }

  while( inStream >> s ){
    if(s.compare(DIMENSION)==0 || s.compare(DIMENSION_)==0){
      inStream >> s;
      inStream >> s;
      instance->num_points = stol(s);
      instance->x = new double[instance->num_points];
      instance->y = new double[instance->num_points];
    }
    if(s.compare(NAME)==0 || s.compare(NAME_)==0){
    	inStream >> instance->name;
      inStream >> instance->name;
    }

    if(s.compare(NODE_COORD_SECTION)==0){
      g = 0;
      while(g < instance->num_points){
        inStream >> j >> instance->x[g] >> instance->y[g];
        g++;
      }
    }

    
  }

  inStream.close();
  return instance;
}

