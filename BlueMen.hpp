
#include "Creature.hpp"
#ifndef BlueMen_hpp
#define BlueMen_hpp

class BlueMen : public Creature
{
    friend class Universe;
public:
    BlueMen(string inputName);
    
    ~BlueMen();
    int getAttack(Creature &opponant);
    int getDefense(Creature &, int atk);
    int getDmg(int atk, int def, Creature &);
    int getStrength();
    string getName();
    int getArmor();
    
};

#endif /* BlueMen_hpp */
