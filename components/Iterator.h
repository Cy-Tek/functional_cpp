//
// Created by hanna on 10/17/2022.
//

#ifndef FUNCTIONAL_CPP_COMPONENTS_ITERATOR_H_
#define FUNCTIONAL_CPP_COMPONENTS_ITERATOR_H_

#include <optional>
#include <functional>

namespace iter {

template<class Input, class Output>
class Map;

template<class T>
class Iterator {
 public:
  virtual std::optional<T> next() = 0;

  template<typename Output>
  Map<T, Output> map(std::function<std::optional<Output>(T)> fn);
};

template<class T>
template<typename Output>
Map<T, Output> Iterator<T>::map(std::function<std::optional<Output>(T)> fn) {
  return Map<T, Output>{this, fn};
}

} // iter

#endif //FUNCTIONAL_CPP_COMPONENTS_ITERATOR_H_
