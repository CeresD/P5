//
// Created by phorphable on 26.04.18.
//

#ifndef PROJECT_PRIORITYQUEUEENTRY_H
#define PROJECT_PRIORITYQUEUEENTRY_H

#include <string>

template<typename T>
class PriorityQueueEntry {
public:
    PriorityQueueEntry(T value, float priority);

    T value;
    float priority;
    PriorityQueueEntry<T> *next;
    PriorityQueueEntry<T> *prev;
};


template<typename T>
PriorityQueueEntry<T>::PriorityQueueEntry(T value, float priority) {
    this->value = value;
    this->priority = priority;
}

#endif //PROJECT_PRIORITYQUEUEENTRY_H
