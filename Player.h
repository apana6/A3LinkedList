#pragma once
#include <ostream>
#include <iostream>
#include <string>
#include "Card.h"
#include "Stack.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name), hand_(new Stack<Card>()) {}

    ~Player() {
        delete hand_;
    }

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    void addCard(Card* card) {
        hand_->push(card);
    }

    void playCard() {
        Card* card = hand_->pop();

        if (card != nullptr) {
            std::cout << "Player card " << *card << std::endl;
            delete card;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

private:
    int id_;
    std::string name_;
    Stack<Card>* hand_;
};
