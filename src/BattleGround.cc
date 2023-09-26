//
// Created by Liuwei on 2023/9/24.
//

#include "BattleGround.h"

BattleGround::BattleGround(EventLoop* loop, const std::string& ip, int port) : loop_(loop), tcpClient(loop, ip, port),
                                                                               me_(std::make_shared<Player>(23, 108, 23, 0)), enemy_(std::make_shared<Player>(23, 108, 0, 0)),
                                                                               statusBar_(std::make_shared<Window>(46, 108, 0, 108)) {

}

void BattleGround::show() {

}

void BattleGround::onConnection(const std::shared_ptr<TcpConnection> &conn, Buffer *buffer) {
    while (buffer->FindEnd()) {
        std::string command = buffer->retriveSome(buffer->FindEnd() - buffer->readIndex());

    }
}

void BattleGround::onMessage(const std::shared_ptr<TcpConnection> &conn, Buffer *buffer) {

}

void BattleGround::parseCommand(const std::string &command) {

}