
#include "Creature.hpp"
#ifndef HarryPotter_hpp
#define HarryPotter_hpp

class HarryPotter : public Creature
{
    friend class Universe;
public:
    HarryPotter(string inputName);
    
    ~HarryPotter();
    int getAttack(Creature &opponant);
    int getDefense(Creature &, int atk);
    int getDmg(int atk, int def, Creature &);
    int getStrength();
    string getName();
    int getArmor();
private:
	    bool hogwarts;
    
};

#endif /* HarryPotter_hpp */
