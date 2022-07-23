#ifndef TESTINGLIBRARY_DUMMYTEST_H
#define TESTINGLIBRARY_DUMMYTEST_H

#include <string>

#include "Test.h"

class DummyTest : public Test {

public:
    DummyTest() : Test() {

    }

    void execute() override;

    std::string name() override;
};


#endif //TESTINGLIBRARY_DUMMYTEST_H
