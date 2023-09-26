//
// Created by Liuwei on 2023/9/25.
//

#ifndef LUSHI_CARDCREATOR_H
#define LUSHI_CARDCREATOR_H

#include <memory>
#include "Util.h"

class Card;

class CardCreator {
public:
    static std::shared_ptr<Card> CardCreate(Util::CardsName cardName);
};


#endif //LUSHI_CARDCREATOR_H
