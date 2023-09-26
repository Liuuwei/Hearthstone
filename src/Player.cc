//
// Created by Liuwei on 2023/9/24.
//

#include "Player.h"
#include "CardCreator.h"

Player::Player(int line, int col, int x, int y) : battleG_(std::make_shared<Window>(line, col, x, y)) {
    battleG_->box();
    for (int i = 0; i < 6; i++) { // 创建6个卡牌位
        auto son = std::make_shared<Window>(battleG_, Card::CardLine(), Card::CardCols(), 1, 1 + Card::CardCols() * i);
        auto name = std::make_shared<Window>(son, Card::NameLine(), Card::NameCols(), 1, 1); // 卡牌名字
        auto power = std::make_shared<Window>(son, Card::PowerLine(), Card::PowerCols(), 6, 1); // 卡牌攻击力
        auto hp = std::make_shared<Window>(son, Card::HpLine(), Card::HpCols(), 6, 2 + Card::PowerCols()); // 卡牌血量

        son->box();
        name->box();
        power->box();
        hp->box();

        son->sonMap()[Util::Location::Name] = name;
        son->sonMap()[Util::Location::Power] = power;
        son->sonMap()[Util::Location::Hp] = hp;

        battleG_->addSon(son);
    }
}

Util::State Player::Draw() {
    if (Deck_.empty()) {
        return Util::State::DeckIsEmpty;
    }

    auto card = Deck_.front();
    Deck_.pop_front();

    if (handIsFull()) {
        return Util::State::HandIsFull;
    }

    handSize_++;
    Cards_[handSize_] = card;

    return Util::State::Success;
}

Util::State Player::Summon(size_t index) {
    if (index >= Cards_.size()) {
        return Util::State::InvalidIndex;
    }

    if (FightCards_.size() >= 6) {
        return Util::State::FightIsFull;
    }

    auto card = Cards_[index];
    Cards_.erase(index);

    auto newCard = CardCreator::CardCreate(card);
    FightCards_[FightCards_.size()] = newCard;

    return Util::State::Success;
}

void Player::show() {
    for (int i = 0; i < FightCards_.size(); i++) {
        battleG_->sonVector()[i]->sonMap()[Util::Location::Name]->addStr(1, 1, FightCards_[i]->name());
        battleG_->sonVector()[i]->sonMap()[Util::Location::Power]->addStr(6, 1, FightCards_[i]->powerToString());
        battleG_->sonVector()[i]->sonMap()[Util::Location::Hp]->addStr(6, 1 + Card::PowerCols(), FightCards_[i]->hpToString());
    }
    battleG_->sonMap()[Util::Location::Player]->sonMap()[Util::Location::PlayerName]->addStr(1, 1, name_);
    battleG_->sonMap()[Util::Location::Player]->sonMap()[Util::Location::PlayerPower]->addStr(6, 1, powerToString());
    battleG_->sonMap()[Util::Location::Player]->sonMap()[Util::Location::PlayerPower]->addStr(6, 1 + Card::PowerCols(), hpToString());

    battleG_->refresh();
}