#ifndef TESTINGLIBRARY_TESTCASE_H
#define TESTINGLIBRARY_TESTCASE_H

#include <iostream>
#include <string>

#include "ExecutionTime.h"
#include "TestAssert.h"

class TestCase : public TestAssert, public ExecutionTime {

public:
    TestCase() : TestAssert() {};

    virtual bool execute() = 0;

    void log(const std::string &what);

    void log(const std::string &what, int priority);

    [[nodiscard]] int getTestCaseTypeId() const;

    void waitFor(int millis) const;

protected:

    int testCaseTypeId = 0;
};

#endif
