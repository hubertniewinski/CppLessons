//
// Created by User on 06.01.2022.
//

#ifndef POKEMON_GAMEMANAGER_H
#define POKEMON_GAMEMANAGER_H

#include "Player.h"

class GameManager {
public:
    struct Round{
        int numberRound=0;
        int opponentNumber=0;
    };

    Round currentRound;

    void startGame(const Player& player, const PokemonBase* pokemonBase, int sizeOfPokemons) const;

    void startRound();
};


#endif //POKEMON_GAMEMANAGER_H
