#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


namespace py = pybind11;

class Counter {
public:
    int counter;

    Counter(){
        counter = 0;
    }

    Counter(int initVal) {
        counter = initVal;
    }

    int getNext()
    {
        counter++;
        return counter;
    }

    std::vector<int> getNextN(int n)
    {
        if (n <= 0)
            return {};
        std::vector<int> outVec = {};
        for (int i = 0; i < n; i++)
        {
            counter++;
            outVec.push_back(counter);
        }
        return outVec;
    }

    std::vector<int> batchIncrement(std::vector<int> jumps)
    {
        std::vector<int> outVec = {};
        for (int i = 0; i < jumps.size(); i++)
        {
            counter += jumps.at(i);
            outVec.push_back(counter);
        }
        return outVec;
    }

    std::string greetCounter(std::string greeting)
    {
        std::cout << greeting << std::endl;
        return std::string("Hello Python");
    }

};


PYBIND11_MODULE(counter_class, m) {
    py::class_<Counter>(m, "Counter")
        .def(py::init<>())
        .def(py::init<int>())
        .def("getNext", &Counter::getNext, "Method for getting the next number of the counter")
        .def("getNextN", &Counter::getNextN)
        .def("batchIncrement", &Counter::batchIncrement)
        .def("greetCounter", &Counter::greetCounter);
}