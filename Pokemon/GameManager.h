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
    Player player;

    GameManager(Player player);

    void startGame(const PokemonBase* allPokemons);

    void nextRound();

    void fight(PokemonBase& opponent);

    PokemonBase generateOpponent();
};


#endif //POKEMON_GAMEMANAGER_H
