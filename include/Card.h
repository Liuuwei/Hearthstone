//
// Created by Liuwei on 2023/9/24.
//

#ifndef LUSHI_CARD_H
#define LUSHI_CARD_H

#include <vector>
#include <string>
#include <memory>

#include "Util.h"

class BattleGround;

class Card {
private:
        static int CardLine_;
        static int CardCols_;
        static int NameLine_;
        static int NameCols_;
        static int PowerLine_;
        static int PowerCols_;
        static int HpLine_;
        static int HpCols_;
public:
    static int CardLine();
    static int CardCols();
    static int NameLine();
    static int NameCols();
    static int PowerLine();
    static int PowerCols();
    static int HpLine();
    static int HpCols();
public:
    Card() = default;
    virtual ~Card() = 0;

    void attack(Card& target);

    [[nodiscard]] std::string name() const {
        return name_;
    }

    [[nodiscard]] int power() const {
        return power_;
    }

    [[nodiscard]] std::string powerToString() const {
        return std::to_string(power_);
    }

    [[nodiscard]] int hp() const {
        return hp_;
    }

    [[nodiscard]] std::string hpToString() const {
        return std::to_string(hp_);
    }

    [[nodiscard]] Util::Special special() const {
        return special_;
    }

    void setName(const std::string& name) {
        name_ = name;
    }

    void setPower(int power) {
        power_ = power;
    }

    void setHp(int hp) {
        hp_ = hp;
    }

    [[nodiscard]] bool firstCome() const {
        return firstCom_;
    }

    void notFirst() {
        firstCom_ = false;
    }

    std::string String();

public:
    virtual void BattlecryFunction(std::shared_ptr<BattleGround>& battleGround) = 0;
    virtual void DeathrattleFunction(std::shared_ptr<BattleGround>& battleGround) = 0;
    virtual void EveryAttackFunction(std::shared_ptr<BattleGround>& battleGround) = 0;
    virtual void EveryBeAttackFunction(std::shared_ptr<BattleGround>& battleGround) = 0;
private:
    std::string name_;
    int power_ = 0;
    int hp_ = 0;
    bool firstCom_ = true;
    Util::Special special_ = Util::Special::Non;
};


#endif //LUSHI_CARD_H
