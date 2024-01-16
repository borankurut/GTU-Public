#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;

namespace KurutRpg{
    class Creature
    {
    public:

        Creature();
        Creature(int theStrength, int theHitpoints);
        virtual int getDamage() const;
        // Returns amount of damage this creature
        // inflicts in one round of combat

        int getStrength() const;
        int getHitpoints() const;

        void setStrength(int newStrength);
        void setHitpoints(int newHitpoints);

        virtual string getSpecies() const = 0;

        void attack(Creature& enemy) const;

        friend ostream& operator <<(ostream& output, const Creature& cr);

    private:
        int strength; // How much damage we can inflict
        int hitpoints; // How much damage we can sustain
    };
}

#endif