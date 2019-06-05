#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <cmath>

namespace py = pybind11;

double euc_speed(py::array_t<double> first, py::array_t<double> second){
    auto uncheckedFirst = first.unchecked<1>();
    auto uncheckedSecond = second.unchecked<1>();

    double eucPart = std::sqrt(std::pow(uncheckedFirst(0) - uncheckedSecond(0), 2) + std::pow(uncheckedFirst(1) - uncheckedSecond(2), 2));
    double speedPart = std::abs(uncheckedFirst(2) - uncheckedSecond(2));
    return speedPart * 0.5 + eucPart;
}

double euc_speed2(py::array_t<double> first, py::array_t<double> second) {
    auto uncheckedFirst = first.data();
    auto uncheckedSecond = second.data();

    double eucPart = std::sqrt(std::pow(uncheckedFirst[0] - uncheckedSecond[0], 2) + std::pow(uncheckedFirst[1] - uncheckedSecond[1], 2));
    double speedPart = std::abs(uncheckedFirst[2] - uncheckedSecond[2]);
    return speedPart * 0.5 + eucPart;
}


PYBIND11_MODULE(similarity_measure, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("euc_speed", &euc_speed, py::arg().noconvert(), py::arg().noconvert());
}