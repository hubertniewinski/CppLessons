//
// Created by User on 03.01.2022.
//

#include <iostream>
#include "Element.h"

Element::Element(ElementType element, ElementType* winningElements, int sizeOfWinningElements, ElementType* losingElements, int sizeOfLosingElements)
                                                    : element(element), winningElements(winningElements), sizeOfWinningElements(sizeOfWinningElements),
                                                    losingElements(losingElements), sizeOfLosingElements(sizeOfLosingElements){

}

std::string Element::getElementType(const int elementType) const{
    switch(elementType){
        case 0:
            return "Water";
        case 1:
            return "Earth";
        case 2:
            return "Wind";
        case 3:
            return "Fire";
        case 4:
            return "Ice";
        case 5:
            return "Steel";
    }
}

float Element::calculateAttackMultiplier(const Element::ElementType& defenseElement){
    for(int i=0;i<sizeOfWinningElements;i++){
        if(winningElements[i] == defenseElement)
            return 1.2f;
    }

    for(int i=0;i<sizeOfLosingElements;i++){
        if(losingElements[i] == defenseElement)
            return 0.8f;
    }

    return 1.0f;
}

void Element::getDesc() {

}

void Element::getHelp() {
    std::cout<<getElementType(element)<<" deals a lot of damage to: ";
    for(int i=0;i<sizeOfWinningElements;i++){
        std::cout << getElementType(winningElements[i]);
        if(i<sizeOfWinningElements -1)
            std::cout<<" , ";
        else
            std::cout<<". "<<std::endl;
    }

    std::cout<<getElementType(element)<<" deals little damage to: ";
    for(int i=0;i<sizeOfLosingElements;i++){
        std::cout << getElementType(losingElements[i]);
        if(i<sizeOfLosingElements -1)
            std::cout<<" , ";
        else
            std::cout<<". "<<std::endl;
    }
}