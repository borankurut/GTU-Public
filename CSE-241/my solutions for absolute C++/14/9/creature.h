#ifndef CREATURE_H
#define CREATURE_H

#include <string>

using std::string;

namespace KurutRpg{
    class Creature
    {
    public:

        Creature();
        Creature(int theStrength, int theHitpoints);
        int getDamage() const;
        // Returns amount of damage this creature
        // inflicts in one round of combat

        int getType() const;
        int getStrength() const;
        int getHitpoints() const;

        void setType(int newType);
        void setStrength(int newStrength);
        void setHitpoints(int newHitpoints);
        string getSpecies() const; // Returns type of species

    private:
        int strength; // How much damage we can inflict
        int hitpoints; // How much damage we can sustain
    };
}

#endif