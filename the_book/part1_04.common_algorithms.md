# Common Algorithms in the STL

The C++ Standard Libray (STL) offers a wide range of powerful algorithms to
manipulate sequences and collections of data. These algorithms are versatile and
efficient, enabling you to perform commong operations on data structures.

## Sequence Modification

### `std::fill`

- **Description:** Fills a range with a specified value.

```cpp
#include <algorithm>
#include <vector>

int main() {
    auto numbers = std::vector<int>(5);
    std::fill(numbers.begin(), numbers.end(), 42);
    // Now, all five elements of numbers, contain the int 42.
}
```

### `std::all_of` , `std::any_of` , `std::none_of`

- **Description:** Check if all, any, or none of the elements in a range meet a
  specified condition.

```cpp
#include <algorithm>
#include <vector>

bool isNegative(int x) {
    return x < 0;
}

int main() {
    auto numbers = std::vector<int> {-1, 0, 1};
    bool all_negative = std::all_of(numbers.begin(), numbers.end(), isNegative);
    bool any_negative = std::any_of(numbers.begin(), numbers.end(), isNegative);
    bool none_negative = std::none_of(numbers.begin(), numbers.end(), isNegative);

    // 'all_negative': false, 'any_negative': true, 'none_negative': false
    return 0;
}
```

### `std::remove` , `remove_if`

- **Description:** Removes elements from a squence based on a value or a
  predicate.

> cppreference: Removing is done by shifting the elements that are not to be
> removed to appear in the begining of the range. A call to remove is typically
> followed by a call to a container's erase member function, which erases the
> unspecified values and reduces the _physical_ size of the container to match
> its new logical size. This constitues the `Erase-remove idiom`.

```cpp
#include <algorithm>
#include <vector>

int main() {
    auto numbers = std::vector<int> {1, 2, 3, 4, 5, 3};
    numbers.erase(std::remove(numbers.beigin(), numbers.end(), 3), numbers.end());
    // 'numbers' now contains {1, 2, 4, 5}
    return 0;
}
```

### `std::replace` , `std::replace_if`

- **Description:** Replaces occurances of a value or elements satisfying a
  predicate in a range.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 3};
    std::replace(numbers.begin(), numbers.end(), 3, 42);

    // 'numbers' now contains {1, 2, 42, 4, 42}.
    return 0;
}
```

### `std::reverse`

- **Description:** reverse the order of elements in a range.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::reverse(numbers.begin(), numbers.end());

    // 'numbers' now contains {5, 4, 3, 2, 1}.
    return 0;
}
```

### `std::shuffle`

- **Description:** Randomly shuffles the elements within a range.

```cpp
#include <algorithm>
#include <vector>
#include <random>

int main() {
    auto numbers = std::vector<int> {1, 2, 3, 4, 5};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);

    // 'numbers' is now shuffled randomly
    return 0;
}
```

### `std::sample`

- **Description:** Randomly samples elements from a range and stores them in
  another sequence.

```cpp
#include <algorithm>
#include <vector>
#include <random>
#include <iterator>

int main() {
    std::vector<int> population = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> sample(3);
    std::random_device rd;
    std::mt19937 g(rd());
    std::sample(population.begin(), population.end(), sample.begin(), 3, g);

    // 'sample' contains a random sample of 3 elements from 'population'.
    return 0;
}
```

### `std::unique`

- **Description:** Removes consecutive duplicate elements deom a range,
  retaining only unique values.

```cpp
#include <algorithm>
#include <vector>

int main() {
    auto numbers = std::vector<int> {1, 1, 2, 3, 3, 3, 4, 4};
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    // 'numbers' now contains {1, 2, 3, 4}
    return 0;
}
```

### `std::sort` , `std::is_sorted` , `std::partial_sort` , `std::stable_sort`

- **Description:** Sorts a range in ascending order. Additional variants offer
  partial sorting and dtability.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 1, 4, 2, 3};
    std::sort(numbers.begin(), numbers.end());

    // 'numbers' is now sorted in ascending order: {1, 2, 3, 4, 5}.
    return 0;
}
```

## Searching and Merging

### `std::binary_search`

- **Descriptio:** Checks if a specific value exists in a sorted range.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    bool found = std::binary_search(numbers.begin(), numbers.end(), 3);

    // 'found' is true.
    return 0;
}
```

### `std::find` , `std::find_if`

- **Description:** Searches for the first occurance of a value or an element
  satisfying a predicate.

```cpp
#include <algorithm>
#include <vector>

bool isEven(int x) { return x % 2 == 0; }

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto found = std::find(numbers.begin(), numbers.end(), 3);
    auto found_if = std::find_if(numbers.begin(), numbers.end(), isEven);

    // 'found' is an iterator to 3, 'found_if' is an iterator to 2.
    return 0;
}
```

### `std::merge` , `std::inplace_merge`

- **Description:** Merges two sorted ranges into a single sorted range.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> first = {1, 3, 5};
    std::vector<int> second = {2, 4, 6};
    std::vector<int> merged(6);

    std::merge(first.begin(), first.end(), second.begin(), second.end(), merged.begin());
    // 'merged' contains {1, 2, 3, 4, 5, 6}.

    std::vector<int> numbers = {5, 3, 1, 4, 2};
    std::inplace_merge(numbers.begin(), numbers.begin() + 3, numbers.end());
    // 'numbers' is sorted within the range [0, 3]: {1, 3, 5, 4, 2}.

    return 0;
}
```

### `std::includes`

- **Description:** Checks if one range includes another, assuming both are
  sorted.

```cpp
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers1 = {1, 2, 3, 4, 5};
    std::vector<int> numbers2 = {2, 4};

    bool included = std::includes(numbers1.begin(), numbers1.end(), numbers2.begin(), numbers2.end());

    // 'included' is true; numbers2 is included in numbers1.
    return 0;
}
```

## Extrema

### `std::min` , `std::max`

- **Description:** finds the minimum/maximum value between two inputs.

```cpp
```

### `std::min_element` , `std::max_element`

- **Description:** Locates the minimum/maximum elements in a range.

```cpp
```

### `std::minmax` , `std::minmax_element`

- **Description:** Finds both the minimum and maximum values / their
  corresponding iterators in a range.

### `std::clamp`

- **Description:** Restricts a value to a specified range.

```cpp
#include <algorithms>

int main() {
    int value = 42;
    int result = std::clamp(value, 10, 30);

    // 'result' is 30, clamped within the range [10, 30].
    return 0;
}
```

## Numeric operations

### `std::iota`

- **Description:** Fills a range with a sequence of icrementing values.

```cpp
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers(5);
    std::iota(numbers.begin(), numbers.end(), 1);

    // 'numbers' contains {1, 2, 3, 4, 5}
    return 0;
}
```

### `std::partial_sum`

- **Description:** Computes the partial sum of elements in a given range and
  stores the results in another range.

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> partial_sums(numbers.size());

    // Compute the partial sums and store them in 'partialSums'.
    std::partial_sum(numbers.begin(), numbers.end(), partial_sums.begin());

    // Display the original numbers and their partial sums.
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < partial_sums.size(); i++) {
        std::cout << partial_sums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### `std::inner_product`

-**Description:** Computes the inner product of two sequences.

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers1 = {1, 2, 3, 4, 5};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50};

    int result = std::inner_product(numbers1.begin(), numbers1.end(), numbers2.begin(), 0);

    std::cout << "Inner Product: " << result << std::endl;

    return 0;
}
```
