//
// Created by User on 06.01.2022.
//

#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager(Player player) : player(player){}

void GameManager::startGame(const PokemonBase* allPokemons) {
    if(player.pokemons == nullptr){
        std::cout<<"Choose pokemons, type number and then enter."<<std::endl;
        PokemonBase playerPokemons[6];

        int i = 0;

        for(int i=0;i<6;i++){
            std::cout<<"Avalible pokemons: "<<std::endl;
            for(int k=0;k<player.sizeOfPokemons;k++){
                std::cout<<k+1<<"."<<allPokemons[k].name<<std::endl;
            }

            std::cout<<"Chosen pokemons: "<<i<<"/6"<<std::endl;

            std::cout<<"Choose pokemon (pick a number): "<<std::endl;
            int num;
            std::cin>>num;
            if(num > 0 && num < player.sizeOfPokemons+1){
                std::cout<<"You choose: "+allPokemons[num-1].name<<std::endl;
                playerPokemons[i] = allPokemons[num-1];
            }
            else{
                std::cout<<"You picked a wrong number!"<<std::endl;
                i--;
            }
        }
    }
}

PokemonBase GameManager::generateOpponent() {
    PokemonBase opponent;
    return opponent;
}

void GameManager::nextRound() {
    if(currentRound.opponentNumber < 4){
        std::cout<<"Next opponent!"<<std::endl;
        currentRound.opponentNumber+=1;
    }
    else{
        if(currentRound.numberRound == 4 && currentRound.opponentNumber == 4){
            std::cout<<"Congratulations! You win!"<<std::endl;
        }
        else{
            std::cout<<"Next round!"<<std::endl;
            currentRound.numberRound+=1;
            currentRound.opponentNumber=0;
        }
    }
}

void GameManager::fight(PokemonBase& opponent) {
    while(opponent.health > 0 || player.getAlivePokemons() != nullptr){
        player.MakeMove(opponent);

        srand((unsigned) time(0));
        int randomNumber = (rand() % 2);

        if(randomNumber == 0)
            opponent.attack(player.currentPokemon);
        else
            opponent.trySpecialAction(player.currentPokemon);
    }

    if(opponent.health > 0){
        std::cout<<"You lose.";
    }
    else{
        std::cout<<"You win!"<<std::endl;
        nextRound();
    }
}