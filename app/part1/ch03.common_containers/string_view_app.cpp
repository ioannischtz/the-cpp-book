#include <iostream>
#include <string>
#include <string_view>

int main() {
  std::string text = "C++ Programming";

  std::string_view view{text};

  auto sub = view.substr(0, 3);
  std::cout << "Substring: " << sub << std::endl;

  text[0] = 'P';
  std::cout << "Modified text: " << text << std::endl;

  std::cout << "Updated view: " << view << std::endl;

  return 0;
}
