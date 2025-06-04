#ifndef FOO_FOO_H
#define FOO_FOO_H

#include <iostream>
#include <vector>

template <typename data_type> class Foo {
public:
  void add(const data_type &value) { data_storage.push_back(value); }
  void print() const {
    for (const auto &item : data_storage) {
      std::cout << item << " ";
    }
  }

private:
  std::vector<data_type> data_storage;
};

#endif // FOO_FOO_H
