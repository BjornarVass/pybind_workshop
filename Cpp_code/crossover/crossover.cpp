#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <vector>
#include <cstdlib>


namespace py = pybind11;

std::vector<double> simple_crossover(py::array_t<double> parent1, py::array_t<double> parent2) {
  auto p1 = parent1.unchecked<1>();
  auto p2 = parent2.unchecked<1>();


  int n = p1.shape(0);
  std::vector<double> child = std::vector<double>();
  child.reserve(n);

  for (int i = 0; i < n; i++) {
    if (((double)rand() / RAND_MAX) < 0.5)
      child.push_back(p1(i));
    else
      child.push_back(p2(i));
  }
  return child;
}

void inplace_crossover(py::array_t<double> parent1, py::array_t<double> parent2) {
  auto p1 = parent1.mutable_unchecked<1>();
  auto p2 = parent2.mutable_unchecked<1>();


  int n = p1.shape(0);
  double temp;
  for (int i = 0; i < n; i++) {
    if (((double)rand() / RAND_MAX) < 0.5) {
      temp = p1(i);
      p1(i) = p2(i);
      p2(i) = temp;
    }
  }
}

void inplace_comparison_crossover(py::array_t<double> parent1, py::array_t<double> parent2) {
  auto p1 = parent1.mutable_unchecked<1>();
  auto p2 = parent2.mutable_unchecked<1>();


  int n = p1.shape(0);
  double temp;
  for (int i = 0; i < n; i++) {
    if (std::abs(p1(i)-p2(i)) > 5.0 && ((double)rand() / RAND_MAX) < 0.5) {
      temp = p1(i);
      p1(i) = p2(i);
      p2(i) = temp;
    }
  }
}



PYBIND11_MODULE(crossover, m) {
  m.def("simple_crossover", &simple_crossover);
  m.def("inplace_crossover", &inplace_crossover, py::arg().noconvert(), py::arg().noconvert());
  m.def("inplace_comparison_crossover", &inplace_comparison_crossover, py::arg().noconvert(), py::arg().noconvert());
}