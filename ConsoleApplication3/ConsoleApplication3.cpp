#include <iostream>
#include <string>

class CombatUnit {
private:
    int health;
    int damage;
    std::string unitType;

    static int totalHealth;
    static int totalDamage;

public:
    CombatUnit(int h, int d, std::string type) : health(h), damage(d), unitType(type) {
        totalHealth += health;
        totalDamage += damage;
    }

    ~CombatUnit() {
        totalHealth -= health;
        totalDamage -= damage;
    }

    void setHealth(int h) {
        totalHealth = totalHealth - health + h;
        health = h;
    }

    int getHealth() const {
        return health;
    }

    void setDamage(int d) {
        totalDamage = totalDamage - damage + d;
        damage = d;
    }

    int getDamage() const {
        return damage;
    }

    std::string getUnitType() const {
        return unitType;
    }

    static int getTotalHealth() {
        return totalHealth;
    }

    static int getTotalDamage() {
        return totalDamage;
    }
};

int CombatUnit::totalHealth = 0;
int CombatUnit::totalDamage = 0;

int main() {
    CombatUnit warrior(100, 25, "Воин");
    CombatUnit archer(80, 15, "Лучник");

    std::cout << "Общее здоровье армии: " << CombatUnit::getTotalHealth() << std::endl;
    std::cout << "Общая боевая мощь армии: " << CombatUnit::getTotalDamage() << std::endl;

    warrior.setDamage(30);
    std::cout << "После изменения урона воина:" << std::endl;
    std::cout << "Общее здоровье армии: " << CombatUnit::getTotalHealth() << std::endl;
    std::cout << "Общая боевая мощь армии: " << CombatUnit::getTotalDamage() << std::endl;

    return 0;
}