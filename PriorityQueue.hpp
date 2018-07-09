#ifndef PROJECT_PRIORITYQUEUE_H
#define PROJECT_PRIORITYQUEUE_H

#include <string>
#include "PriorityQueueEntry.hpp"

template<typename T>
class PriorityQueue {
public:
    PriorityQueue();

    ~PriorityQueue();

    void insert(T value, float priority);

    T extractMin();

    void decreaseKey(T value, float priority);

    void remove(T value);

    bool isEmpty();

    void printQueue();

    int getSize();

private:
    int size;
    PriorityQueueEntry<T> *head;
    PriorityQueueEntry<T> *tail;

    void connectEntries(PriorityQueueEntry<T> *first, PriorityQueueEntry<T> *second);
};

#include <iostream>
#include "PriorityQueue.hpp"
#include "QueueException.h"

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    size = 0;
    head = NULL;
    tail = NULL;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    for (int i = 0; i < size; i++) {
        extractMin();
    }
}

template<typename T>
void PriorityQueue<T>::insert(T value, float priority) {
    PriorityQueueEntry<T> *newEntry = new PriorityQueueEntry<T>(value, priority);
    newEntry->next = NULL;
    newEntry->prev = NULL;
    newEntry->priority = priority;
    newEntry->value = value;

    if (!head) {
        head = newEntry;
        tail = newEntry;
    } else {
        PriorityQueueEntry<T> *current = head;

        while (current->next) {
            if (current->next->priority >= newEntry->priority)
                break;

            current = current->next;
        }

        if (current == head) {
            if (newEntry->priority > current->priority) {
                connectEntries(newEntry, current->next);
                connectEntries(current, newEntry);
            } else {
                connectEntries(newEntry, current);
                head = newEntry;
            }

            if (!newEntry->next)
                tail = newEntry;
        } else if (current->prev && current->next) {
            connectEntries(newEntry, current->next);
            connectEntries(current, newEntry);
        } else if (current == tail) {
            connectEntries(current, newEntry);
            tail = newEntry;
        }
    }

    size++;
}

template<typename T>
T PriorityQueue<T>::extractMin() {
    T value;
    PriorityQueueEntry<T> *entryToExtract = head;

    if (entryToExtract) {
        value = entryToExtract->value;

        if (entryToExtract == head) {
            head = entryToExtract->next;

            if (head)
                head->prev = NULL;
        } else if (entryToExtract == tail) {
            tail = entryToExtract->prev;

            if (tail)
                tail->next = NULL;
        }

        size--;
        delete entryToExtract;
    } else
        throw QueueException(1);

    return value;
}

template<typename T>
void PriorityQueue<T>::decreaseKey(T value, float priority) {
    PriorityQueueEntry<T> *current = head;

    while (current) {
        if (current->value == value) {
            remove(value);
            insert(value, priority);
            return;
        }

        current = current->next;
    }

    throw QueueException(2);
}

template<typename T>
void PriorityQueue<T>::remove(T value) {
    PriorityQueueEntry<T> *current = head;

    //if (current)
    while (current) {
        if (current->value == value) {
            if (current == head && head->prev != NULL) {
                head = current->next;
                head->prev = NULL;
            } else if (current == tail && tail->next != NULL) {
                tail = current->prev;
                tail->next = NULL;
            } else
                connectEntries(current->prev, current->next);

            size--;
            delete current;
            break;
        }

        current = current->next;
    }
}

template<typename T>
bool PriorityQueue<T>::isEmpty() {
    return size == 0;
}

template<typename T>
void PriorityQueue<T>::connectEntries(PriorityQueueEntry<T> *first, PriorityQueueEntry<T> *second) {
    if (first)
        first->next = second;

    if (second)
        second->prev = first;
}

template<typename T>
void PriorityQueue<T>::printQueue() {
    PriorityQueueEntry<T> *current = head;

    for (int i = 0; i < size; i++) {
        std::cout << "index " << i << ", value: " << current->value << ", priority: " << current->priority << std::endl;
        current = current->next;
    }
}

template<typename T>
int PriorityQueue<T>::getSize() {
    return size;
}

#endif //PROJECT_PRIORITYQUEUE_H
