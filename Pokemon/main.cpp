#include <iostream>
#include "Element.h"

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



    return 0;
}
