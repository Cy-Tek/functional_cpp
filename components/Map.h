//
// Created by hanna on 10/17/2022.
//

#ifndef FUNCTIONAL_CPP_COMPONENTS_MAP_H_
#define FUNCTIONAL_CPP_COMPONENTS_MAP_H_

#include <optional>
#include <functional>
#include "Iterator.h"

namespace iter {

template<class I, class O>
class Map : public Iterator<O> {
 public:
  explicit Map(Iterator<I> *iter, const std::function<std::optional<O>(I)> pred) : internal{iter},
																				 predicate{pred} {}

  std::optional<O> next() override {
	auto next = internal->next();
	if (!next) {
	  return {};
	}

	return predicate(*next);
  }

 private:
  Iterator<I> *internal;
  std::function<std::optional<O>(I)> predicate;
};

}

#endif //FUNCTIONAL_CPP_COMPONENTS_MAP_H_
