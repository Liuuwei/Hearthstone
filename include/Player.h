//
// Created by Liuwei on 2023/9/24.
//

#ifndef LUSHI_PLAYER_H
#define LUSHI_PLAYER_H

#include <vector>
#include <string>
#include <deque>
#include <memory>
#include <unordered_map>

#include "Card.h"
#include "Util.h"
#include "Window.h"

class Player {
public:
    Player(int line, int col, int x, int y);

    Util::State Draw(); // 抽牌

    Util::State Summon(size_t index);

    void show();

    [[nodiscard]] std::string name() const {
        return name_;
    }

    std::string hpToString() const {
        return std::to_string(hp_);
    }

    [[nodiscard]] int hp() const {
        return hp_;
    }

    void addHp(int value) {
        hp_ += value;
    }

    void subHp(int value) {
        hp_ -= value;
    }

    int power() const {
        return power_;
    }

    std::string powerToString() const {
        return std::to_string(power_);
    }

    void addPower(int value) {
        power_ += value;
    }

    void subPower(int value) {
        power_ -= value;
    }

    [[nodiscard]] size_t handSize() const {
        return handSize_;
    }

    [[nodiscard]] bool handIsFull() const {
        return handSize_ >= maxHandSize_;
    }

    std::unordered_map<size_t, std::shared_ptr<Card>>& FightCards() {
        return FightCards_;
    }

    void setMe(int i) {
        me_ = i;
    }

    int me() const {
        return me_;
    }

private:
    std::string name_;
    int hp_ = 30;
    int power_ = 0;
    size_t handSize_ = 0; // 手牌数量
    size_t maxHandSize_ = 10;
    std::unordered_map<size_t, std::shared_ptr<Card>> FightCards_; // 召唤到场上的卡牌
    std::unordered_map<size_t, Util::CardsName> Cards_; // 手牌
    std::deque<Util::CardsName> Deck_; // 牌库
    int me_ = -1; // 自己窗口

    std::shared_ptr<Window> battleG_;
};


#endif //LUSHI_PLAYER_H
