//
// Created by User on 04.01.2022.
//

#include "PokemonBase.h"
#include <iostream>
PokemonBase::PokemonBase(std::string name, int strength, int agility, int health, int expForWin, int expForEvolve, int roundsToSpecialAction, const Element &element) :
                        name(name), strength(strength), agility(agility), health(health), expForWin(expForWin), expForEvolve(expForEvolve),
                        roundsToSpecialAction(roundsToSpecialAction), element(element){
    specialActionCounter = roundsToSpecialAction;
}

void PokemonBase::attack(const PokemonBase& opponent) const {

}

void PokemonBase::getAttacked(const PokemonBase& opponent, int value) {
    std::cout<<opponent.name+" took "+name+" "<<1<<" HP.";
    health -= value;

    if(health < 0)
        std::cout<<name+" is dead!";
}

bool PokemonBase::trySpecialAction(const PokemonBase& opponent){
    if(specialActionCounter <= 0)
    {
        specialActionCounter = roundsToSpecialAction;
        pokemonSpecialAction(opponent);
        return true;
    }

    return false;
}

void PokemonBase::getDesc() {
    std::cout<<"Name: "+name;
}
