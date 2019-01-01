//
// Created by Brett Hartman on 2019-01-01.
//

#include <random>

int roll_dice() {
  std::random_device random_device;
  std::default_random_engine random_engine(random_device());
  std::uniform_int_distribution<int> uniform_int_distribution(1, 6);

  int random_int = uniform_int_distribution(random_engine);

  return random_int;
}

int main() {
  int num_rolls = 20;
  double average = 0.0;

  for (int i = 0; i < num_rolls; i++) {
    int random_int = roll_dice();

    printf("Roll %d of %d was a %d...\n", i + 1, num_rolls, random_int);

    average += (double)random_int;
  }

  average /= num_rolls;

  printf("Your average roll was %f!\n", average);

  return 0;
}
