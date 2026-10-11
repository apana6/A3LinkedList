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
    std::unique_ptr<List<Player>> table = makeList<Player>();
    std::unique_ptr<List<Player>> secondTable = makeList<Player>();
    //three players join the table
    table->addFront(new Player(1, "Fred"));
    table->addFront(new Player(2, "Bruno"));
    table->addFront(new Player(3, "Rihanna"));

// player joins
    table->addAnywhere(1, new Player(4, "Alex"));
    table->print();

    //reverse card
    table->reverse();
    table->print();

    //player leaves from a spot that isn't the front
    table->deleteAnywhere(2);
    table->print();

    //a second table starts
    secondTable->addFront(new Player(5, "Alex"));
    secondTable->addFront(new Player(6, "Bob"));
    secondTable->print();

    //merge the second table into the first table
    table->concat(secondTable.get());
    table->print();
    secondTable->print();


    return 0;
}
