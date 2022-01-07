//
// Created by User on 03.01.2022.
//

#ifndef POKEMON_ELEMENT_H
#define POKEMON_ELEMENT_H

#include <string>
#include "IHelper.h"

class Element : IHelper {
private:
    std::string getElementType(const int elementType) const;

public:
    enum ElementType{
        Water,
        Earth,
        Wind,
        Fire,
        Ice,
        Steel
    };

    ElementType element;

    ElementType* winningElements;
    int sizeOfWinningElements;

    ElementType* losingElements;
    int sizeOfLosingElements;

    Element(ElementType element, ElementType* winningElements, int sizeOfWinningElements, ElementType* losingElements, int sizeOfLosingElements);

    float calculateAttackMultiplier(const Element::ElementType& defenseElement) const;

    void getDesc() override;

    void getHelp() override;
};


#endif //POKEMON_ELEMENT_H
