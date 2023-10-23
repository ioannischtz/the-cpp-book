#include <charconv>
#include <cstdint>
#include <format>
#include <iostream>
#include <random>
#include <string>
#include <system_error>

int main() {
  auto rd = std::random_device();
  auto gen = std::mt19937(rd());
  auto distribution = std::uniform_int_distribution<int32_t>(1, 100);
  auto secret_number = int32_t{distribution(gen)};

  std::cout << std::format("The secret number is: {}\n", secret_number);

  std::cout << "Guess the number!" << std::endl;

  while (true) {

    std::cout << "Please input your guess." << std::endl;

    auto guess_str = std::string();

    // Read line of input, until user presses `Enter`
    if (!std::getline(std::cin, guess_str)) {
      std::cerr << "Failed to read line" << std::endl;
      return 1;
    }

    auto guess = int32_t{0};
    // convert the string input to an int
    auto [ptr, err_code] = std::from_chars(
        guess_str.data(), guess_str.data() + guess_str.size(), guess);

    if (err_code == std::errc()) {
      std::cout << std::format("You guessed: {}\n", guess);
    } else {
      std::cout << "Error. Invalid input. Please enter a valid number."
                << std::endl;
      continue;
    }

    // Check if the guess is within the valid range
    if (guess < 1 || guess > 100) {
      std::cout << "Error: Please enter a number between 1 and 100."
                << std::endl;
      continue;
    }

    // Compare the guess with the secret number
    if (guess < secret_number) {
      std::cout << "Too small!" << std::endl;
    } else if (guess > secret_number) {
      std::cout << "Too big!" << std::endl;
    } else {
      std::cout << "You win!!" << std::endl;
      break;
    }
  }
  return 0;
}
