
#include "Barbarian.hpp"
#include <ctime>
#include <limits>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;



/********************************
 Description: Constructor will take a name as an argument and start the barbarian with 0 armor and 12 
 strength.
 ********************************/
Barbarian::Barbarian(string inputName) : Creature(inputName)
{
    name = inputName;
    armor = 0;
    strength = 12;
}



/********************************
 Description: The barbarian will make 2 die rolls between 1-6 and return the sum, display to the user
 the attack rolled.
 ********************************/
int Barbarian::getAttack(Creature &opponant)
{
    int sumAtk = 0;
    int atk = 0;
    
    
    sumAtk += getRandomNumber(1, 6);
    sumAtk += getRandomNumber(1, 6);
    atk = sumAtk;
    cout << "Attack roll for " << getName() << " " << atk << endl; //for testing;
    return atk;
    
}


/********************************
 Description: Barbarian will make 2 die rolls between 1-6 and return the sum. It will also display the
 defense rolled to the user
 ********************************/
int Barbarian::getDefense(Creature &opponant, int atk)
{
    int def = 0;
    int tempDef = 0;
    
    tempDef += getRandomNumber(1, 6);
    tempDef += getRandomNumber(1, 6);
    def = tempDef;
    cout << "Defense roll for: " << getName() << " " << def << endl; //for testing
    return def;
}

/********************************
 Description: Will return the strength of the creature.
 ********************************/
int Barbarian::getStrength()
{
    
    return strength;
}


/********************************
 Description: Return the name of the creature.
 ********************************/
string Barbarian::getName()
{
    
    return name;
}

/********************************
 Description: Returns the armor of the creature.
 ********************************/
int Barbarian::getArmor()
{
    return armor;
}


/********************************
 Description: Will return the damage, taking the attack and defense as arguments. Also takes the opponant
 it is fighting against to get the value of their armor.
 ********************************/
int Barbarian::getDmg(int atk, int def, Creature &opponant) //will return atk - def - armor = dmg
{
    
		cout << "Attack: " << atk << endl;
		cout << "Defense: " << def << endl;
        cout << opponant.getName() << " armor absorbed: " << opponant.getArmor() << " points of damage" << endl;
        cout << getName() << " does " << atk - def - opponant.getArmor() << " points of damage" << endl;
    return atk - def - opponant.getArmor();
}
