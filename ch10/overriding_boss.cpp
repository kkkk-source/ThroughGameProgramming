// Overriding Boss
// Demonstrates calling and overriding base member functions

#include <iostream>

class Enemy {
	public:
		Enemy(int damage = 10);
		void virtual Taunt() const; // made virtual to be overriden
		void virtual Attack() const; // made virtual to be overriden
	private:
		int m_Damage;
};

Enemy::Enemy(int damage): m_Damage(damage) {}

void Enemy::Taunt() const {
	std::cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const {
	std::cout << "Attack! Inflicts " << m_Damage << " damage points.";
}

class Boss : public Enemy {
	public:
		Boss(int damage = 30);
		void virtual Taunt() const; // optional use of keyword virtual
		void virtual Attack() const; // optional use of keyword virtual
};

Boss::Boss(int damage): Enemy(damage) {}

// override base class member
void Boss::Taunt() const {
	std::cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::Attack() const {
	Enemy::Attack();
	std::cout << " And laughs heartily at you.\n";
}

int main() {
	std::cout << "Enemy object:\n";
	Enemy anEnemy;
	anEnemy.Taunt();
	anEnemy.Attack();

	std::cout << "\n\nBoss ojects:\n";
	Boss aBoss;
	aBoss.Taunt();
	aBoss.Attack();

	return 0;
}
