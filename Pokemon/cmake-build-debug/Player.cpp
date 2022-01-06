//
// Created by User on 06.01.2022.
//

#include "Player.h"
#include <iostream>
#include "NodeHelper.h"


Player::Player(PokemonBase *pokemons, int sizeOfPokemons) : pokemons(pokemons), sizeOfPokemons(sizeOfPokemons){
    if(sizeOfPokemons > 0)
        currentPokemon = pokemons[0];
}

bool isAlive(const PokemonBase& pokemon) {
    return pokemon.health > 0;
}

void Player::EvolvePokemon(int step) {
    std::cout<<"Type what you want to evolve in your champ (pick a number). Skills to give left: "<<step<<std::endl;

    std::cout<<"1.Strength"<<std::endl;
    std::cout<<"2.Agility"<<std::endl;
    std::cout<<"3.Health"<<std::endl;

    int i;
    std::cin>>i;

    switch(i){
        case 1:{
            currentPokemon.evolve(true, false, false);
            break;
        }
        case 2:{
            currentPokemon.evolve(false, true, false);
            break;
        }
        case 3:{
            currentPokemon.evolve(false, false, true);
            break;
        }
        default:{
            std::cout<<"You picked a wrong number. Try again."<<std::endl;
            EvolvePokemon(step);
            break;
        }
    }
}

void Player::MakeMove(const PokemonBase& opponent){
    std::cout<<"Pick an action: (type number)"<<std::endl;
    for ( int fooInt = SpecialAttack; fooInt != Evolve; fooInt++ )
    {
        std::cout<<fooInt<<" "<<moves[fooInt];
    }

    int move;
    std::cin>>move;

    if(move > 0 && move <= Evolve){
        switch(move){
            case Move::Attack:{
                currentPokemon.attack(opponent);
                break;
            }
            case Move::SpecialAttack:{
                if(!currentPokemon.trySpecialAction(opponent));
                {
                    std::cout<<"You can't use special action! Remaining rounds to use: "<<currentPokemon.specialActionCounter;
                    MakeMove(opponent);
                }
                break;
            }
            case Move::ChooseChamp:{
                NodeHelper::Node<PokemonBase>* pokemonArr = NodeHelper::arrayToList(pokemons, sizeOfPokemons);
                NodeHelper::Node<PokemonBase>* filtered = NodeHelper::extract(pokemonArr, isAlive);

                if(filtered != nullptr){
                    std::cout<<"Choose pokemon (pick a number):";

                    NodeHelper::Node<PokemonBase>* next = filtered;
                    int i=1;

                    while(next){
                        std::cout<<i<<" "<<next->data.name;
                        i++;
                        next = next->next;
                    }

                    int input;
                    std::cin>>input;

                    NodeHelper::Node<PokemonBase>* choosed;
                    next = filtered;

                    i=1;

                    while(next){
                        if(i==input){
                            choosed = next;
                            break;
                        }
                        i++;
                        next = next->next;
                    }

                    if(choosed){
                        std::cout<<"You choose: "+choosed->data.name;
                        currentPokemon = choosed->data;
                    }
                    else{
                        std::cout<<"You picked a wrong number! Try again..";
                        MakeMove(opponent);
                    }
                }
                else{
                    std::cout<<"You cannot choose other champ!"<<std::endl;
                    MakeMove(opponent);
                }

                break;
            }
            case Move::Evolve:{
                if(currentPokemon.canEvolve){
                    EvolvePokemon(2);
                    EvolvePokemon(1);
                }
                else
                {
                    std::cout<<"Your pokemon can't evolve. Current EXP: "<<currentPokemon.currentExp<<" "<<currentPokemon.expForEvolve;
                    MakeMove(opponent);
                }
                break;
            }
        }
    }
    else
    {
        std::cout<<"You picked a wrong number. Try again."<<std::endl;
        MakeMove(opponent);
    }
}