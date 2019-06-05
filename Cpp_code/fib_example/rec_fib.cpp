#include <pybind11/pybind11.h>


int rec_fib(int nr){
  if (nr == 0)
    return 0;
  if (nr == 1)
    return 1;
  return rec_fib(nr - 1) + rec_fib(nr - 2);
}


PYBIND11_MODULE(fib_example, m) {

  m.def("rec_fib", &rec_fib, "A re(tarded)cursive fibonacci function");
}