#include <iostream>
#include <ostream>
#include <vector>

struct Entry {
  std::string title;
  std::string author;
  int year_published;

  friend std::ostream &operator<<(std::ostream &os, const Entry &entry) {
    os << "  { ";
    os << entry.title << ", ";
    os << entry.author << ", ";
    os << entry.year_published;
    os << " },";
    return os;
  }
};

int main() {
  std::vector<int> numbers;

  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);

  auto numbers2 = std::vector<int>{5, 6, 7, 8};

  // Access and print vector elements
  std::cout << "numbers vector \n\n";
  for (const int &num : numbers) {
    std::cout << num << " ";
  }

  std::cout << "\n\nnumbers2 vector \n\n";
  for (auto &num2 : numbers2) {
    std::cout << num2 << " ";
  }
  std::cout << std::endl;

  // Accessing elements using indexing
  int first = numbers[0];
  // Accesing elements using .at() for bounds checking
  int second = numbers.at(1);

  std::cout << "The first element is: " << first << "\n";
  std::cout << "The second element is: " << second << "\n";

  std::cout << "numbers2 capacity: " << numbers2.capacity() << std::endl;

  std::vector<Entry> library = {
      {"A Tour of C++", "Bjarne Stroustrup", 2022},
      {"Applied Acoustics", "Dimitris Scarlatos", 2012}};

  std::vector<Entry> library2 = library;

  std::cout << "\n\n Entry library: \n\n";
  std::cout << "{";
  for (const auto &entry : library) {
    std::cout << "\n" << entry;
  }
  std::cout << "\n}" << std::endl;

  return 0;
}
