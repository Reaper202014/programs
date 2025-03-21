﻿#include <iostream>
using namespace std;

class BaseEnemy {
public:
    virtual void Damage() = 0;
    virtual void Die() = 0;
    virtual void ChasePlayer() = 0;

    virtual ~BaseEnemy() {}
};

class Goblin : public BaseEnemy {
public:
    void Damage() override {
        cout << "Гоблин наносит урон" << endl;
    }

    void Die() override {
        cout << "Гоблин умирает" << endl;
    }

    void ChasePlayer() override {
        cout << "Гоблин гонится за игроком" << endl;
    }
};

class Ogre : public BaseEnemy {
public:
    void Damage() override {
        cout << "Огр наносит мощный удар" << endl;
    }

    void Die() override {
        cout << "Огр падает на землю" << endl;
    }

    void ChasePlayer() override {
        cout << "Огромный огр медленно идёт к игроку" << endl;
    }
};

int main() {
    BaseEnemy* goblin = new Goblin();
    BaseEnemy* ogre = new Ogre();

    goblin->ChasePlayer();
    goblin->Damage();
    goblin->Die();

    ogre->ChasePlayer();
    ogre->Damage();
    ogre->Die();

    delete goblin;
    delete ogre;

    return 0;
}