#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <cmath>


namespace py = pybind11;

int subtractOrAdd(int x, int y) {
  if (x > y)
    return x - y;
  else
    return x + y;
}

double eucDist(int x, int y) {
  if (x > y)
    return std::sqrt(x * x + y * y);
  else
    return std::sqrt(x * y + x * y);
}


PYBIND11_MODULE(vectorized_funcs, m) {

  m.def("subtract_or_add", py::vectorize(subtractOrAdd));
  m.def("euc_dist", py::vectorize(eucDist));
}