//
// Created by User on 04.01.2022.
//

#ifndef POKEMON_POKEMONBASE_H
#define POKEMON_POKEMONBASE_H

#include <functional>
#include "Element.h"
#include <string>
#include "Player.h"

struct SpecialActionCounter{
    int activeForRounds;
    std::function<void(PokemonBase)> apply;
    std::function<void(PokemonBase)> reset;
};

class PokemonBase {
    int roundsToSpecialAction;
    int expForWin;

    virtual void pokemonSpecialAction(const PokemonBase& opponent, SpecialActionCounter specialActionCounter);
public:
    int strength;
    int agility;
    int health;
    int specialActionCounter;
    int currentExp;
    bool canEvolve;
    int expForEvolve;

    Node<SpecialActionCounter>* specialActionCounters = nullptr;
    Element element;
    std::string name;

    PokemonBase();
    PokemonBase(std::string name, int strength, int agility, int health, int expForWin, int expForEvolve, int roundsToSpecialAction, const Element& element);

    void getDesc();

    void attack(PokemonBase opponent);

    void getAttacked(PokemonBase* opponent, int value);

    bool trySpecialAction(const PokemonBase& opponent);

    virtual void evolve(bool strength, bool agility, bool health);

    void resetRound();

    template <typename T, typename Pred>
    Node <T>* extract(Node<T>*& head, Pred pred);
};


#endif //POKEMON_POKEMONBASE_H
