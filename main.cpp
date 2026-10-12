#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl;
    std::cout << "== Uno Table ==" << std::endl;

    std::unique_ptr<List<Player>> table = makeList<Player>();
    std::unique_ptr<List<Player>> secondTable = makeList<Player>();

    // Create three players
    Player* fred = new Player(1, "Fred");
    Player* bruno = new Player(2, "Bruno");
    Player* rihanna = new Player(3, "Rihanna");

    // Deal cards to players
    fred->addCard(new Card("Red", "7"));
    fred->addCard(new Card("Blue", "Skip"));

    bruno->addCard(new Card("Green", "2"));
    bruno->addCard(new Card("Yellow", "Reverse"));

    rihanna->addCard(new Card("Red", "5"));

    // Players join the first table
    table->addFront(fred);
    table->addFront(bruno);
    table->addFront(rihanna);

    std::cout << "Starting turn order:" << std::endl;
    table->print();

    // A new player joins in the middle
    Player* alex = new Player(4, "Alex");
    alex->addCard(new Card("Blue", "Draw Two"));

    table->addAnywhere(1, alex);

    std::cout << "After Alex joins in the middle:" << std::endl;
    table->print();

    // A player plays a card
    std::cout << "Fred plays a card:" << std::endl;
    fred->playCard();

    // Reverse card
    std::cout << "Before reverse:" << std::endl;
    table->print();

    table->reverse();

    std::cout << "After reverse:" << std::endl;
    table->print();

    // A player leaves from a non-front position
    table->deleteAnywhere(2);

    std::cout << "After a player leaves:" << std::endl;
    table->print();

    // Create a second table
    Player* sofia = new Player(5, "Sofia");
    Player* bob = new Player(6, "Bob");

    secondTable->addFront(sofia);
    secondTable->addFront(bob);

    std::cout << "Second table before merging:" << std::endl;
    secondTable->print();

    std::cout << "First table before merging:" << std::endl;
    table->print();

    // Merge the second table into the first
    table->concat(secondTable.get());

    std::cout << "First table after merging:" << std::endl;
    table->print();

    std::cout << "Second table after merging:" << std::endl;
    secondTable->print();

    return 0;
}
