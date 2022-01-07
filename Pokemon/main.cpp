#include <iostream>
#include "Element.h"
#include "GameManager.h"

int main() {
    Element::ElementType waterWinning[] = {Element::ElementType::Earth, Element::ElementType::Fire};
    Element::ElementType waterLosing[] = {Element::ElementType::Water};

    Element::ElementType earthWinning[] = {Element::ElementType::Fire, Element::ElementType::Ice, Element::ElementType::Steel};
    Element::ElementType earthLosing[] = {Element::ElementType::Wind};

    Element::ElementType windWinning[] = {Element::ElementType::Ice};
    Element::ElementType windLosing[] = {Element::ElementType::Earth, Element::ElementType::Steel};

    Element::ElementType fireWinning[] = {Element::ElementType::Ice, Element::ElementType::Steel};
    Element::ElementType fireLosing[] = {Element::ElementType::Water, Element::ElementType::Earth};

    Element::ElementType iceWinning[] = {Element::ElementType::Earth};
    Element::ElementType iceLosing[] = {Element::ElementType::Water, Element::ElementType::Fire, Element::ElementType::Ice};

    Element::ElementType steelWinning[] = {Element::ElementType::Water, Element::ElementType::Wind};
    Element::ElementType steelLosing[] = {Element::ElementType::Fire, Element::ElementType::Steel};

    Element elements[6] = {
            Element(Element::ElementType::Water, waterWinning, std::size(waterWinning), waterLosing, std::size(waterLosing)),
            Element(Element::ElementType::Earth, earthWinning, std::size(earthWinning), earthLosing, std::size(earthLosing)),
            Element(Element::ElementType::Wind, windWinning, std::size(windWinning), windLosing, std::size(windLosing)),
            Element(Element::ElementType::Fire, fireWinning, std::size(fireWinning), fireLosing, std::size(fireLosing)),
            Element(Element::ElementType::Ice, iceWinning, std::size(iceWinning), iceLosing, std::size(iceLosing)),
            Element(Element::ElementType::Steel, steelWinning, std::size(steelWinning), steelLosing, std::size(steelLosing)),
    };

    Player player(nullptr, 6);
    GameManager gm(player);

    PokemonBase pokemons[6] = {
            PokemonBase("xx", 1,1,1,1,1,1,elements[0]),
            PokemonBase("aa", 1,1,1,1,1,1,elements[1]),
            PokemonBase("dd", 1,1,1,1,1,1,elements[2]),
            PokemonBase("ee", 1,1,1,1,1,1,elements[3]),
            PokemonBase("gg", 1,1,1,1,1,1,elements[4]),
            PokemonBase("nn", 1,1,1,1,1,1,elements[5]),
    };

    gm.startGame(pokemons);
    player.currentPokemon = player.pokemons[0];
    gm.currentRound.opponentNumber = 1;
    gm.currentRound.numberRound = 1;
    PokemonBase opponent = gm.generateOpponent();
    gm.fight(opponent);

    return 0;
}