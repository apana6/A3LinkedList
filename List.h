//
// Created by adapa on 9/21/2026.
//

#ifndef A3LINKEDLIST_LIST_H
#define A3LINKEDLIST_LIST_H

#endif //A3LINKEDLIST_LIST_H

#pragma one
#include <memory>

template <typename T>
class List {
    public:
    virtual ~List() = default;

    virtual void addFront(T* value) = 0;
    virtual void deleteFront() = 0;
    virtual void search(T* value) const = 0;
    virtual void print() const = 0;
};

#include "Arraylist.h"
#include "LinkedList.h"

template <typename T>
std::unique_ptr<List<T>> makeList() {
    return std::make_unique<LinkedList<T>();
    //return std::make_unique<ArrayList<T>();
}