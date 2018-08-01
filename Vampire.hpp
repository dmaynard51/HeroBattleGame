
#include "Creature.hpp"
#ifndef Vampire_hpp
#define Vampire_hpp

class Vampire : public Creature
{
	friend class Universe;
public:
    Vampire(string inputName);
    
    ~Vampire();
    int getAttack(Creature &opponant);
    int getDefense(Creature &, int atk);
    int getDmg(int atk, int def, Creature &);
    int getStrength();
    string getName();
    int getArmor();
    
};

#endif /* Vampire_hpp */
