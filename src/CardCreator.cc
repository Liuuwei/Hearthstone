//
// Created by Liuwei on 2023/9/25.
//

#include "CardCreator.h"
#include "Ghoul.h"

std::shared_ptr<Card> CardCreator::CardCreate(Util::CardsName cardName) {
    return std::make_shared<Ghoul>();
}