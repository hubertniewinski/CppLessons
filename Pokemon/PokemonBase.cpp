//
// Created by User on 04.01.2022.
//

#include "PokemonBase.h"
#include <iostream>

PokemonBase::PokemonBase() : element(element){

}

PokemonBase::PokemonBase(std::string name, int strength, int agility, int health, int expForWin, int expForEvolve, int roundsToSpecialAction, const Element &element) :
        name(name), strength(strength), agility(agility), health(health), expForWin(expForWin), expForEvolve(expForEvolve),
        roundsToSpecialAction(roundsToSpecialAction), element(element){
    specialActionCounter = roundsToSpecialAction;
}

void PokemonBase::pokemonSpecialAction(const PokemonBase &opponent, SpecialActionCounter specialActionCounter) {
    if(specialActionCounters == nullptr){
        specialActionCounters->data = specialActionCounter;
    }
    else{
        Node<SpecialActionCounter>* head = specialActionCounters;

        while(head){
            head = head->next;
        }

        head->data = specialActionCounter;
    }

    specialActionCounter.apply();
    specialActionCounter.activeForRounds -=1;
}

bool isNotFinished(const SpecialActionCounter& specialActionCounter) {
    return specialActionCounter.activeForRounds > 0;
}

void PokemonBase::resetRound() {
    Node<SpecialActionCounter>* head = specialActionCounters;

    while(head){
        if(head->data.activeForRounds > 0)
            head->data.apply();
        else
            head->data.reset();

        head->data.activeForRounds -= 1;
    }
    specialActionCounters = extract(specialActionCounters, isNotFinished);

    roundsToSpecialAction-=1;
}

void PokemonBase::evolve(bool strength, bool agility, bool health) {
    std::cout<<"Pokemon evolved!"<<std::endl;

    if(strength)
        strength += 5;
    else if(agility)
        agility += 5;
    else
        health += 5;

    resetRound();
}

void PokemonBase::attack(PokemonBase opponent){
    float multiplier = element.calculateAttackMultiplier(opponent.element.element);

    opponent.getAttacked(this, strength * multiplier);
    resetRound();
}

void PokemonBase::getAttacked(PokemonBase* opponent, int value) {
    srand((unsigned) time(0));
    int randomNumber = (rand() % 100);

    if(randomNumber < agility){
        std::cout<<"Pokemon dodged attack!";
    }
    else{
        std::cout<<opponent->name+" took "+name+" "<<1<<" HP.";
        health -= value;

        if(health < 0)
            std::cout<<name+" is dead!";
    }
}

bool PokemonBase::trySpecialAction(const PokemonBase& opponent){
    if(specialActionCounter <= 0)
    {
        specialActionCounter = roundsToSpecialAction;
        pokemonSpecialAction(opponent);
        resetRound();
        return true;
    }

    return false;
}

void PokemonBase::getDesc() {
    std::cout<<"Name: "+name;
}

template <typename T, typename Pred>
Node <T>* PokemonBase::extract(Node<T>*& head, Pred pred) {
    Node<T>* headTruePred = nullptr;

    Node<T>* lastTruePred = nullptr;
    Node<T>* lastFalsePred = nullptr;

    Node<T>* currentNode = head;

    while(currentNode){
        if(pred(currentNode->data)){
            if(!lastTruePred)
                lastTruePred = headTruePred = currentNode;
            else{
                lastTruePred = lastTruePred->next = currentNode;
                lastFalsePred->next = nullptr;
            }
        }
        else{
            if(!lastFalsePred)
                lastFalsePred = head = currentNode;
            else{
                lastFalsePred = lastFalsePred->next = currentNode;
                lastTruePred->next = nullptr;
            }
        }

        currentNode = currentNode->next;
    }

    return headTruePred;
}
