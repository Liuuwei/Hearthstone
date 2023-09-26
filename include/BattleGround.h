//
// Created by Liuwei on 2023/9/24.
//

#ifndef LUSHI_BATTLEGROUND_H
#define LUSHI_BATTLEGROUND_H

#include <vector>
#include <ncurses.h>

#include <my/TcpClient.h>

#include "Player.h"
#include "Window.h"

class BattleGround {
public:
    BattleGround(EventLoop* loop, const std::string& ip, int port);

    std::shared_ptr<Player>& me() { return me_; }
    std::shared_ptr<Player>& enemy() { return enemy_; }

    void show();

    void setMe(int i) {
        me_->setMe(i);
        i ^= 1;
        enemy_->setMe(i);
    }

private:
    void onConnection(const std::shared_ptr<TcpConnection>& conn, Buffer* buffer);
    void onMessage(const std::shared_ptr<TcpConnection>& conn, Buffer* buffer);

    void parseCommand(const std::string& command);

private:
    EventLoop* loop_;
    TcpClient  tcpClient;

    std::shared_ptr<Player> me_;
    std::shared_ptr<Player> enemy_;
    std::shared_ptr<Window> statusBar_;
};


#endif //LUSHI_BATTLEGROUND_H
