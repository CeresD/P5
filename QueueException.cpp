//
// Created by forall on 14.05.18.
//

#include <iostream>
#include "QueueException.h"

QueueException::QueueException(int errorCode) {
    code = errorCode;
}

std::string QueueException::toString() const {
    switch (code) {
        case 1:
            return "extractMin not successful: no element to extract";
            break;
        case 2:
            return "decreaseKey not successful: element not found";
            break;
        default:
            return "unknown error occured";
            break;
    }
}