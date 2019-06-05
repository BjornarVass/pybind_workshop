#include <pybind11/pybind11.h>

bool is_prime(int x) {
  if (x < 2) {
    return false;
  }
  for (int i = 2; i < x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int next_prime(int x) {
  while (!is_prime(x)) {
    x++;
  }
  return x;
}


PYBIND11_MODULE(prime, m) {
  m.def("next_prime", &next_prime);
}
