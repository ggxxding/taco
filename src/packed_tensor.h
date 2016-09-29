#ifndef TAC_PACKED_TENSOR_H
#define TAC_PACKED_TENSOR_H

#include <vector>
#include <cstdlib>
#include <inttypes.h>

namespace tac {

struct PackedTensor {
  PackedTensor(size_t nnz, void* values,
               const std::vector<std::vector<uint32_t*>>& indices)
      : nnz(nnz), values(values), indices(indices) {}

  ~PackedTensor() {
    free(values);
    for (auto& index : indices) {
      for (auto& indexArray : index) {
        free(indexArray);
      }
    }
  }

  size_t nnz;
  void* values;
  std::vector<std::vector<uint32_t*>> indices;
};

}
#endif