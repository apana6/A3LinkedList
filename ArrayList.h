//
// Created by adapa on 9/21/2026.
#pragma once

#include <iostream>

#include "List.h"

template <typename T>
class ArrayList : public List<T> {

public:
    ArrayList():size_(0) {}
    // Add to the front
    void addFront(T* item) override{
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }

            for (int i = size_; i > 0; --i) {
                data_[i] = data_[i - 1];
            }

            data_[0] = item;
            ++size_;
        }
    void deleteFront() override{
        if (size_ == 0) {
            std::cout << "ArrayList is empty" << std::endl;
            return;
        }
        delete data_[0];

        for (int i = 0; i < size_ -1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }


    bool search(T* value) const override{
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
            }
        //time complexity - O(n)
        //deleting from the back would be O(1)

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
            }
        std::cout << std::endl;
        }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position >= size_) {
            std::cout << "Not valid" << std::endl;
            return;
        }

        if (size_ >= CAPACITY) {
            std::cout << "Full" << std::endl;
            return;
        }

        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }

        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position > size_) {
            std::cout << "Not valid" << std::endl;
            return;
        }
        delete data_[position];

        for (int i = position; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void reverse() override {
        int left = 0;
        int right = size_ - 1;

        while (left < right) {
            T* temp = data_[left];
            data_[left] = data_[right];
            data_[right] = temp;
            ++left;
            --right;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* otherArrayList = dynamic_cast<ArrayList<T>* >(other);

        if (otherArrayList == nullptr) {
            std::cout << "Not valid" << std::endl;
            return;
        }

        if (size_ + otherArrayList->size_ > CAPACITY) {
            std::cout << "Full" << std::endl;
            return;
        }
        for (int i = 0; i < otherArrayList->size_; ++i) {
            data_[size_ + i] = otherArrayList->data_[i];
        }
        size_ += otherArrayList->size_;
        otherArrayList->size_ = 0;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

    private:
        static const int CAPACITY = 20;
        T* data_[CAPACITY];
        int size_;
    };
