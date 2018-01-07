#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include "MurmurHash32.h"
using namespace std;

int main() {

 uint32_t seed = 1;
 int len = 8;
 uint32_t* key = (uint32_t*) calloc(8,sizeof(uint32_t));
 int aafds = 13;
 *key = aafds;
 uint32_t h;
 //unsigned long int b = 1;

 cout << MurmurHash32(key,1,1) << endl;
}



//What to give MurmurHash32
//sentiel values
//empty deleted and full

//Avoid Heuristics like the quicksort get middle of 3 samples one

