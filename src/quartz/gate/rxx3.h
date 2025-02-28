#pragma once

#include "../math/matrix.h"
#include "gate.h"

#include <assert.h>

namespace quartz {
class RXX3Gate : public Gate {
 public:
  RXX3Gate()
      : Gate(GateType::rxx3, 2 /*num_qubits*/, 0 /*num_parameters*/),
        mat({{ComplexType(-1 / std::sqrt(2)), ComplexType(0), ComplexType(0),
              ComplexType(-1.0i / std::sqrt(2))},
             {ComplexType(0), ComplexType(-1 / std::sqrt(2)),
              ComplexType(-1.0i / std::sqrt(2)), ComplexType(1)},
             {ComplexType(0), ComplexType(-1.0i / std::sqrt(2)),
              ComplexType(-1 / std::sqrt(2)), ComplexType(0)},
             {ComplexType(-1.0i / std::sqrt(2)), ComplexType(0), ComplexType(0),
              ComplexType(-1 / std::sqrt(2))}}) {}
  MatrixBase *get_matrix() override { return &mat; }
  Matrix<4> mat;
};

}  // namespace quartz
