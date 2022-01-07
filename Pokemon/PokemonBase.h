//
// Created by User on 04.01.2022.
//

#ifndef POKEMON_POKEMONBASE_H
#define POKEMON_POKEMONBASE_H

#include <functional>
#include "Element.h"
#include <string>

class PokemonBase {
    int roundsToSpecialAction;
    int expForWin;

    virtual void pokemonSpecialAction(const PokemonBase& opponent);
public:
    int strength;
    int agility;
    int health;
    int specialActionCounter;
    int currentExp;
    bool canEvolve;
    int expForEvolve;

    struct SpecialActionCounter{
        int activeForRounds;
        std::function<void(PokemonBase)> specialAction;
    };

    SpecialActionCounter pokemonSpecialActionCounter = {0, nullptr};
    Element element;
    std::string name;

    PokemonBase();
    PokemonBase(std::string name, int strength, int agility, int health, int expForWin, int expForEvolve, int roundsToSpecialAction, const Element& element);

    void getDesc();

    void attack(const PokemonBase& opponent) const;

    void getAttacked(const PokemonBase& opponent, int value);

    bool trySpecialAction(const PokemonBase& opponent);

    virtual void evolve(bool strength, bool agility, bool health);
};


#endif //POKEMON_POKEMONBASE_H
