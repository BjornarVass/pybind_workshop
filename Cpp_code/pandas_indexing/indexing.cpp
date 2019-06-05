#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void simpleFilter(py::array_t<double> vals, py::array_t<bool> chgs, double minChg) {
  auto valInfo = vals.request(),
    chgInfo = chgs.request();

  if (valInfo.ndim != 1 || chgInfo.ndim != 1)
    throw std::runtime_error("Number of dimentions must be one");

  if (valInfo.size != chgInfo.size)
    throw std::runtime_error("Input shapes must match");

  auto valPtr = vals.data();
  auto chgPtr = chgs.mutable_data();

  auto lastVal = valPtr[0];
  chgPtr[0] = true;

  for (size_t idx = 1; idx < valInfo.shape[0]; idx++)
  {
    if (std::abs(valPtr[idx] - lastVal) >= minChg) {
      lastVal = valPtr[idx];
      chgPtr[idx] = true;
    }
  }
}


void simpleFilter2(py::array_t<double> vals, py::array_t<bool> changes, double minChg) {
    auto v = vals.unchecked<1>();
    auto chgs = changes.mutable_unchecked<1>();

    int n = v.shape(0);

    double lastVal = v[0];
    chgs[0] = true;

    for (size_t idx = 1; idx < n; idx++)
    {
        if (std::abs(v[idx] - lastVal) >= minChg) {
            lastVal = v[idx];
            chgs[idx] = true;
        }
    }
}


PYBIND11_MODULE(pandas_indexing, m) {

  m.def("simple_filter", &simpleFilter, "Simple State Filtering");
  m.def("simple_filter2", &simpleFilter2, "Simple State Filtering");
}