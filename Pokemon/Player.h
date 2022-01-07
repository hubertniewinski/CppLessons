//
// Created by User on 06.01.2022.
//

#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "PokemonBase.h"

template <typename T>
struct Node {
    T data;
    Node* next;
};

class Player {
public:
    enum Move{
        SpecialAttack=1,
        Attack=2,
        ChooseChamp=3,
        Evolve=4
    };

    std::string moves[4] = {"SpecialAttack", "Attack", "ChooseChamp", "Evolve"};

    PokemonBase* pokemons;
    int sizeOfPokemons;

    PokemonBase currentPokemon;

    Player(PokemonBase* pokemons, int sizeOfPokemons);

    void MakeMove(const PokemonBase& opponent);

    void EvolvePokemon(int step);

    template <typename T, typename Pred>
    Node <T>* extract(Node<T>*& head, Pred pred);

    template <typename T>
    Node <T>* arrayToList(const T a[], size_t size);

    Node <PokemonBase>* getAlivePokemons();
};


#endif //POKEMON_PLAYER_H
