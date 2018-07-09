//
// Created by forall on 14.05.18.
//

#ifndef PROJECT_QUEUEEXCEPTION_H
#define PROJECT_QUEUEEXCEPTION_H

#include <string>

class QueueException {
public:
    QueueException(int errorCode);
    std::string toString() const;
private:
    int code;
};


#endif //PROJECT_QUEUEEXCEPTION_H
