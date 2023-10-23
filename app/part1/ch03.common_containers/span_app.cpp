#include <iostream>
#include <span>

void modifyElements(std::span<int> elements) {
  for (auto &element : elements) {
    element *= 2;
  }
}

int main() {
  int array[5] = {1, 2, 3, 4, 5};

  // Create a span from the array
  std::span<int> spanFromArray{array + 1, 3};

  modifyElements(spanFromArray);

  // Elements in the array have been modified
  for (const int &element : spanFromArray) {
    std::cout << element << " ";
  }
  std::cout << std::endl;

  return 0;
}
