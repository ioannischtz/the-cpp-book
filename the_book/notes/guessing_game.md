## Random Number Generation

```cpp
auto rd = std::random_device();
auto gen = std::mt19937(rd());
auto distribution = std::uniform_int_distribution<uint32_t>(1, 100);
auto secret_number = uint32_t{distribution(gen)};
```

### Overview

```cpp
auto rd = std::random_device();
```

This line creates a `std::random_device` object named `rd`. It's used to obtain
random numbers suitable for seeding other random number generators.

```
auto gen = std::mt19937(rd());
```

Here, we initialize a Mersenne Twister random number generator (`std::mt19937`)
named `gen`. It's seeded with the value obtained from the `rd()` function call,
ensuring randomness.

```
auto distribution = std::uniform_int_distribution<uint32_t>(1, 100);
```

This line defines a uniform integer distribution
(`std::uniform_int_distribution`) named `distribution`. It's used to generate
random integers between 1 and 100 (inclusive). Each integer in this range has an
equal chance of being generated.

```
auto secret_number = uint32_t{distribution(gen)};
```

Finally, we use the `distribution` to generate a random number within the
desired range (1 to 100) and assign it to the `secret_number` variable. This
ensures that `secret_number` contains a random value for further use.
