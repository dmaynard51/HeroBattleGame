
#include "Creature.hpp"
#ifndef Medusa_hpp
#define Medusa_hpp

class Medusa : public Creature
{
    friend class Universe;
public:
    Medusa(string inputName);
    
    ~Medusa();
    int getAttack(Creature &opponant);
    int getDefense(Creature &, int atk);
    int getDmg(int atk, int def, Creature &);
    int getStrength();
    string getName();
    int getArmor();
    
    
};

#endif /* Medusa_hpp */
