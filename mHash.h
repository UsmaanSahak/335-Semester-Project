#ifndef MHASH_H
#define MHASH_H
#include "MurmurHash64A.h"
#include <cmath>
#include <stdint.h>
#include <iostream>
#define LINEAR 0
#define QUAD 1
using std::cout;
using std::endl;

namespace UsmaanSahak {

	struct hNode {
		uint64_t data;
		unsigned char status;
	};
	
	class mHash {
		public:
			mHash();
			mHash(uint64_t newCapacity);
			bool readHash(uint64_t v);
			bool writeHash(uint64_t v);
			bool deleteHash(uint64_t v);
			uint64_t getCapacity() { return capacity; }
			void setCapacity(uint64_t newCapacity);
			uint64_t getMaxLoad() { return maxLoad; }
			void setMaxLoad(uint64_t l) { maxLoad = l; }
			void setProbing(unsigned char v) { probing = v; }
			void outputHash();
			int probes;
			int reads = 0;
			int writes = 0;
			int deletes = 0;
			unsigned char probing;
		private:
			hNode** darr; //Dynamic array, size of capacity on file.
			int64_t capacity;
			int64_t maxLoad;
			int64_t size = 0;
	};
}
#endif


/*
1 - Decide how long the array of hNodes there needs to be.
2 - Fill entries with it, modulo the length of array to decide where it will go.
3 - In writeHash(), make it linear probe.
*/
