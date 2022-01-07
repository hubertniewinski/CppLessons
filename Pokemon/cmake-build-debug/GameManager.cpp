//
// Created by User on 06.01.2022.
//

#include "GameManager.h"
#include <iostream>

void GameManager::startGame(const Player& player, const PokemonBase* allPokemons, int sizeOfPokemons) const {
    if(player.pokemons == nullptr){
        if(sizeOfPokemons < 7){
            std::cout<<"Something went wrong!"<<std::endl;
            return;
        }

        std::cout<<"Choose pokemons, type number and then enter."<<std::endl;
        PokemonBase playerPokemons[6];

        int i = 0;

        for(int i=0;i<6;i++){
            std::cout<<"Avalible pokemons: "<<std::endl;
            for(int k=0;k<sizeOfPokemons;k++){
                std::cout<<k+1+"."+allPokemons[k].name<<std::endl;
            }

            std::cout<<"Chosen pokemons: "<<i+1<<"/6"<<std::endl;

            int num;
            std::cin>>num;
            if(num > 0 && num < sizeOfPokemons -1){
                std::cout<<"You choose: "+allPokemons[num].name<<std::endl;
                playerPokemons[i] = allPokemons[num];
            }
            else{
                std::cout<<"You picked a wrong number!"<<std::endl;
                i--;
            }
        }
    }
}

void GameManager::startRound() {
    
}