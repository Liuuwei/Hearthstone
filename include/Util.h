//
// Created by Liuwei on 2023/9/24.
//

#ifndef LUSHI_UTIL_H
#define LUSHI_UTIL_H

#include <unordered_map>
#include <string>

const int lines = 23;
const int cols = 36;

class Util {
public:
    enum State {
        Success = 0,
        HandIsFull,
        DeckIsEmpty,
        InvalidIndex,
        InvalidOperation,
        FightIsFull, // 场上已满
    };

    enum Special { // 卡牌特殊效果
        Non = 0,
        Battlecry = 1,
        Deathrattle = 2,
        EveryAttack = 3,
        EveryBeAttack = 4,
    };

    enum Location {
        Name = 0,
        Power,
        Hp,
        Player,
        PlayerName,
        PlayerPower,
        PlayerHp,
    };

    enum CardsName { // 所有卡牌
        Ghoul = 1,
    };

    static std::unordered_map<State, std::string> Message;
public:
    Util() = delete;
private:
};

#endif //LUSHI_UTIL_H
