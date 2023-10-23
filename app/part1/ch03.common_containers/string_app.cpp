#include <iostream>
#include <string>

int main() {
  std::string first = "Hello, ";
  std::string second = "world!";

  auto combined = std::string{first + second};

  std::cout << combined << std::endl;

  auto fist_character = char{combined[0]};
  std::cout << "First character: " << fist_character << std::endl;

  combined[7] = 'W';
  std::cout << "Modified string: " << combined << std::endl;

  return 0;
}
