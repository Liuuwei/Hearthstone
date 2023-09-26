//
// Created by Liuwei on 2023/9/24.
//
#include <iostream>

#include "Card/Ghoul.h"
#include "BattleGround.h"

Ghoul::Ghoul() {
    Card::setName("Ghoul");
    Card::setHp(hp_);
    Card::setPower(power_);
}

void Ghoul::BattlecryFunction(std::shared_ptr<BattleGround>& battleGround) {
    auto& enemy = battleGround->enemy();
    enemy->subHp(5);
}

void Ghoul::DeathrattleFunction(std::shared_ptr<BattleGround>& battleGround) {
    std::cout << "DeathrattleFunction" << std::endl;
}

void Ghoul::EveryAttackFunction(std::shared_ptr<BattleGround>& battleGround) {
    std::cout << "EveryAttackFunction" << std::endl;
}

void Ghoul::EveryBeAttackFunction(std::shared_ptr<BattleGround>& battleGround) {
    std::cout << "EveryBeAttackFunction" << std::endl;
}