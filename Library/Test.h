#ifndef TESTINGLIBRARY_TEST_H
#define TESTINGLIBRARY_TEST_H

#include <string>
#include <iostream>

#include "ExecutionTime.h"
#include "TestAssert.h"
#include "TestCase.h"
#include "DataTestCase.h"
#include "TestCaseData.h"

class Test : public TestAssert, public ExecutionTime {

public:

    Test() : TestAssert() {

        outputWriterFunction = [](const std::string &what, int priority) {

            std::cout << what << '\n';
        };
    };

    virtual void execute() = 0;

    virtual std::string name() = 0;

    void EXECUTE_TEST_CASE(TestCase *testCase);

    void EXECUTE_TEST_CASE(TestCase *testCase, long expectedExecutionTime);

    void log(const std::string &what);

    void log(const std::string &what, int priority);

    bool getExecutionResult();

private:

    bool executionResult = true;

    int testCasesRegistered = 0;
};


#endif //TESTINGLIBRARY_TEST_H
