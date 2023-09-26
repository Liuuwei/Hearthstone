//
// Created by Liuwei on 2023/9/24.
//

#ifndef LUSHI_GHOUL_H
#define LUSHI_GHOUL_H

#include "Card.h"

class Ghoul : public Card {
public:
    Ghoul();
    ~Ghoul() override = default;
public:
    void BattlecryFunction(std::shared_ptr<BattleGround>& battleGround) override;
    void DeathrattleFunction(std::shared_ptr<BattleGround>& battleGround) override;
    void EveryAttackFunction(std::shared_ptr<BattleGround>& battleGround) override;
    void EveryBeAttackFunction(std::shared_ptr<BattleGround>& battleGround) override;
private:
    std::string name_ = "Ghoul";
    int power_ = 3;
    int hp_ = 5;
    Util::Special special_ = Util::Special::Non;
};

#endif //LUSHI_GHOUL_H
