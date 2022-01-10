#include <iostream>

class Critter {
  public:
    Critter(int Hunger = 0); // constructor prototype
    int getHunger() const; // member function prototype
    void setHunger(int hunger);
  private:
    int m_Hunger;
};

Critter::Critter(int hunger): m_Hunger(hunger) {
  std::cout << "A new critter has been born!" << std::endl;
}

int Critter::getHunger() const { // member function definition
  return m_Hunger;
}

void Critter::setHunger(int hunger) {
  if (hunger < 0) {
    std::cout << "You can't set a critter's hunger to a negative number.\n\n";
  } else {
    m_Hunger = hunger;
  }
}
