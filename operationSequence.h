#ifndef OPERATIONSEQUENCE_H
#define OPERATIONSEQUENCE_H

namespace UsmaanSahak {
  class OperationSequence {
    bool feedback_enabled;
    int64_t capacity;
    int64_t max_load;
    int64_t num_operations;
    int64_t max_key;
    //Dynamic arrays
    int64_t *operation;
    int64_t *key;
    int64_t *expected_results;
    //~OperationSequence;
  };
}


#endif
