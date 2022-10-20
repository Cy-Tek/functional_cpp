#include <iostream>
#include <string>

#include "components/Iterator.h"
#include "components/Map.h"

namespace iter {
template<class Input, class Output>
class Map;
}

class NumberGenerator : public iter::Iterator<char8_t> {
 public:
  std::optional<char8_t> next() override {
	if (hasCompleted) { return {}; }
	if (current == 255) {
	  hasCompleted = true;
	  return {current};
	}

	return {current++};
  }

 private:
  char8_t current{0};
  bool hasCompleted{false};
};

int main() {
  NumberGenerator generator{};
  auto stringMap = generator
	  .map<size_t>([](auto num) -> size_t { return num * 2; })
	  .map<std::string>([](auto num) -> std::string { return std::to_string(num); });

  for (auto var = stringMap.next(); var; var = stringMap.next()) {
	std::cout << *var << std::endl;
  }
  return 0;
}
