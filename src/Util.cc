//
// Created by Liuwei on 2023/9/24.
//
#include "Util.h"

std::unordered_map<Util::State, std::string> Util::Message {
        {State::Success, "Success."},
        {State::HandIsFull, "Hand is already full."},
        {State::DeckIsEmpty, "Deck is already empty."},
        {State::InvalidIndex, "Index is invalid."},
        {State::InvalidOperation, "Operation is invalid."}
};