//
// Created by User on 06.01.2022.
//

#ifndef POKEMON_IHELPER_H
#define POKEMON_IHELPER_H

class IHelper {
public:
    virtual ~IHelper(){};
    virtual void getDesc() = 0;
    virtual void getHelp() = 0;
};


#endif //POKEMON_IHELPER_H
