#include "mHash.h"
#define EMPTY 0
#define FULL 1
#define DELETED 2
namespace UsmaanSahak {
	
	mHash::mHash() {
		probes = 0;
	}
	mHash::mHash(uint64_t newCapacity) {
		capacity = newCapacity;
		probes = 0;
		darr = new hNode*[capacity];
		for (int i = 0; i < capacity; i++) {
			darr[i] = new hNode();
			darr[i]->status = EMPTY;
		}
	}
	bool mHash::readHash(uint64_t v) {
		reads++;
		uint64_t* key = (uint64_t*) calloc(8,sizeof(uint64_t));
		*key = v;
	
		uint64_t h = MurmurHash64A(key,3,1);
		int loc = h % capacity;
		//std:cout << loc << " loc\n";
		probes++;
		int it = 0;
		
		if (probing == LINEAR) {
			while ((darr[loc]->status != EMPTY) && (darr[loc]->data != v) && (it < capacity)) {
				loc++;
				loc = loc % capacity;
				it++;
				//cout << loc << " loc down\n";
				probes++;
			}
		} else { //Do QUAD
			while ((darr[loc]->status != EMPTY) && (darr[loc]->data != v) && (it < capacity)) {
				loc = loc + pow(it,2);
				loc = loc % capacity;
				it++;
				probes++;
			}
		}
			
		if (darr[loc]->data == v) {
			//cout << "Read now output\n";
			//outputHash();
			return true;
		} else { return false; }
	}
	
	bool mHash::writeHash(uint64_t v) {
		writes++;
		if (size >= maxLoad) {
			//cout << "size is " << size << ", no room.\n";
			return false;
		}
		uint64_t* key = (uint64_t*) calloc(8,sizeof(uint64_t));
		*key = v;
		
		uint64_t h = MurmurHash64A(key,3,1);
		int loc = h % capacity;
		//cout << loc << " loc\n";
		probes++;
		int it = 0; //Loop through entire hash.
		
		if (probing == LINEAR) {
			while ((darr[loc]->status == FULL) && (it < capacity)) {
				loc++;
				loc = loc % capacity; //Wrap.
				it++;
				//cout << loc << " loc down\n";
				probes++;
			}
		} else {
			while ((darr[loc]->status == FULL) && (it < capacity)) {
				loc = loc + pow(it,2);
				loc = loc % capacity;
				it++;
				probes++;
			}
		}
		if (darr[loc]->status != FULL) {
			darr[loc]->data = v;
			darr[loc]->status = FULL;
			//cout << "write now output.\n";
			//outputHash();
			size++;
			return true;
		} else {
			//cout << "Capacity filled.\n";
			return false;
		}
	}
	bool mHash::deleteHash(uint64_t v) {
		deletes++;
		uint64_t* key = (uint64_t*) calloc(8,sizeof(uint64_t));
		*key = v;
		uint64_t h = MurmurHash64A(key,3,1);
		int loc = h % capacity;
		//cout << loc << " loc\n";
		probes++;
		int it = 0;
		if (probing == LINEAR) {
			while ((darr[loc]->status != EMPTY) && (darr[loc]->data != v) && (it < capacity)) {
				it++;
				loc++;
				loc = loc % capacity;
				//cout << loc << " loc down\n";
				probes++;
			}
		} else {
			while ((darr[loc]->status != EMPTY) && (darr[loc]->data != v) && (it < capacity)) {
				it++;
				loc = pow(loc,2);
				loc = loc % capacity;
				probes++;
			}
		}
		if (darr[loc]->data == v) {
			darr[loc]->data = 0;
			darr[loc]->status = DELETED;
			//cout << "delete now output\n";
			//outputHash();
			size--;
			return true;
		} else {
			return false;
		}
	}
	void mHash::setCapacity(uint64_t newCapacity) {
		if (capacity != 0) {
			for (int i = 0; i < capacity; i++) {
				delete darr[i];
			}
			delete darr;
		}
		delete [] darr;
		capacity = newCapacity;
		darr = new hNode*[capacity];
		for (int i = 0; i < capacity; i++) {
			darr[i] = new hNode();
		}
	}
	void mHash::outputHash() {
		cout << "capacity: " << capacity << endl;
		cout << "probes: " << probes << endl;
		cout << "operations: " << reads + writes + deletes << endl;
		for (int i = 0; i < capacity; i++) {
			cout << darr[i]->data << endl;
		}
	}
}













