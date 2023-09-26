//
// Created by Liuwei on 2023/9/24.
//

#include <iostream>
#include <ncurses.h>
#include <thread>
#include <csignal>
#include <vector>

#include "Window.h"
#include "Card.h"

void en(int) {
    endwin();
    exit(0);
}

int main() {
    signal(SIGINT, en);

    std::shared_ptr<Window> battleG_ = std::make_shared<Window>(23, 106, 0, 0);

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

    battleG_->refresh();

    while (true) {

    }
}