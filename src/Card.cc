//
// Created by Liuwei on 2023/9/24.
//

#include "Card.h"

void Card::attack(Card &target) {
    this->setHp(hp_ - target.power_);
    target.setHp(target.hp() - this->power());
}

std::string Card::String() {
    std::string ret;
    ret += name_;
    ret += "\n";
    ret += std::to_string(power_);
    ret += "\t";
    ret += std::to_string(hp_);

    return ret;
}

int Card::CardLine_ = 11;
int Card::CardCols_ = 17;

int Card::NameLine_ = 3;
int Card::NameCols_ = 15;

int Card::PowerLine_ = 3;
int Card::PowerCols_ = 7;

int Card::HpLine_ = 3;
int Card::HpCols_ = 7;

int Card::CardLine() { return CardLine_; }
int Card::CardCols() { return CardCols_; }

int Card::NameLine() { return NameLine_; }
int Card::NameCols() { return NameCols_; }

int Card::PowerLine() { return PowerLine_; }
int Card::PowerCols() { return PowerCols_; }

int Card::HpLine() { return HpLine_; }
int Card::HpCols() { return HpCols_; }