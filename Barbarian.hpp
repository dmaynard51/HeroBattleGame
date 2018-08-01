
#include "Creature.hpp"
#ifndef Barbarian_hpp
#define Barbarian_hpp

class Barbarian : public Creature
{
    friend class Universe;
public:
    Barbarian(string inputName);
    
    ~Barbarian();
    int getAttack(Creature &opponant);
    int getDefense(Creature &, int atk);
    int getDmg(int atk, int def, Creature &);
    int getStrength();
    string getName();
    int getArmor();
    
};

#endif /* Barbarian_hpp */
