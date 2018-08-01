#ifndef CREATURE_HPP
#define CREATURE_HPP

#pragma once
#include <string>
using std::string;

#define LOSE -1
#define WIN 1
#define TIE 0

class Creature
{
    friend class Universe;
private:

protected:
    string name;
	int attack;
	int defense;
	int armor;
	int strength;

public:
	Creature(string userName);
	~Creature();
	virtual int getAttack(Creature &);
	virtual int getDefense(Creature &, int atk);
    virtual string getName();
    
    virtual int getStrength();
    virtual int getArmor();
    virtual int getDmg(int atk, int def, Creature &);
    void setArmor(Creature &);
	void setAttack(int atk);
	void setDefense(int def);
	int fight (Creature &);
    int getRandomNumber(int min, int max);

};
#endif
