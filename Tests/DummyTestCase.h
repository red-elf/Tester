#ifndef TESTINGLIBRARY_DUMMYTESTCASE_H
#define TESTINGLIBRARY_DUMMYTESTCASE_H

#include "Test.h"
#include "TestCase.h"

class DummyTestCase : public TestCase {

public:
    explicit DummyTestCase() : TestCase() {

    };

    bool execute() override;
};


#endif //TESTINGLIBRARY_DUMMYTEST_H
