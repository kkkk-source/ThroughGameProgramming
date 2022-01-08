#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(
      static_cast<unsigned int>(time(0))); // seed random number generator
  int randomNumber = std::rand();          // generate random number
  int die = (randomNumber % 6) + 1;        // get a number between 1 and  6
  std::cout << "You rolled a " << die << std::endl;

  return 0;
}
