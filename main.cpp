//
// Created by Brett Hartman on 2019-01-01.
//

#include <iostream>
#include <random>

int roll_dice(const int num_faces) {
  std::random_device random_device;
  std::default_random_engine random_engine(random_device());
  std::uniform_int_distribution<int> uniform_int_distribution(1, num_faces);

  int random_int = uniform_int_distribution(random_engine);

  return random_int;
}

int main() {
  int num_rolls;
  int num_faces;

  std::cout << "Enter the number of faces on the die: ";
  std::cin >> num_faces;
  std::cout << "Enter the number of times to roll: ";
  std::cin >> num_rolls;

  printf("Rolling a %d-sided die %d times...\n", num_faces, num_rolls);

  int sum = 0;
  int min_roll;
  int max_roll;

  for (int i = 0; i < num_rolls; i++) {
    int random_int = roll_dice(num_faces);

    printf("Roll %d of %d was a %d...\n", i + 1, num_rolls, random_int);

    sum += random_int;

    if (i == 0) {
      min_roll = random_int;
      max_roll = random_int;
    } else {
      if (random_int < min_roll) {
        min_roll = random_int;
      }

      if (random_int > max_roll) {
        max_roll = random_int;
      }
    }
  }

  double average = (double)sum / (double)num_rolls;

  printf("Your average roll was %f!\n", average);
  printf("Your maximum roll was %d.\n", max_roll);
  printf("Your minimum roll was %d.\n", min_roll);

  return 0;
}
