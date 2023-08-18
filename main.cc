#include "absl/strings/numbers.h"
#include <iostream>
#include <stdlib.h>

int main() {
  const char *env = getenv("SAMPLE_ENV");
  int temp;
  std::cout << "is env nullptr? " << (env == nullptr) << std::endl;

  absl::string_view env_view(env);
  std::cout << "converting env to string_view" << std::endl;

  bool result = absl::SimpleAtoi(env_view, &temp);
  std::cout << "env: " << temp << std::endl;
}
