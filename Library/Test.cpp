#include <string>
#include <iostream>
#include <chrono>

#include "Test.h"
#include "TestAssert.h"
#include "TestCase.h"
#include "DataTestCase.h"
#include "TestCaseData.h"

#include "TestLogging.h"
#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

using namespace TestingLibrary::Logging;

void Test::EXECUTE_TEST_CASE(TestCase *testCase) {

    testCase->setOutputWriterFunction(outputWriterFunction);
    ++testCasesRegistered;
    auto started = std::chrono::high_resolution_clock::now();
    bool success = testCase->execute();
    auto completed = std::chrono::high_resolution_clock::now();
    auto executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            completed - started
    ).count();
    testCase->setExecutionTimeInMilliseconds(executionTime);
    auto executedMsg = "Execution time: " + std::to_string(executionTime)
                       + " milliseconds.";
    auto testCaseId = testCase->getTestCaseTypeId();
    if (testCaseId == 0) {

        if (success) {

            log(
                    "Test case " + std::to_string(testCasesRegistered) + " passed. "
                    + executedMsg,
                    OUTPUT_WRITER_PRIORITY_TEST_CASE_PASSED
            );
        } else {

            log(
                    "Test case " + std::to_string(testCasesRegistered) + " failed. "
                    + executedMsg,
                    OUTPUT_WRITER_PRIORITY_TEST_CASE_FAILED
            );
        }
    } else {

        auto dataTestCase = dynamic_cast<DataTestCase *>(testCase);
        TestCaseData *testCaseData = dataTestCase->getTestCaseData();
        if (success) {

            log(
                    "Test case '" + testCaseData->getName() + "'" + " passed. "
                    + executedMsg,
                    OUTPUT_WRITER_PRIORITY_TEST_CASE_PASSED
            );
        } else {

            log(
                    "Test case '" + testCaseData->getName() + "'" + " failed. "
                    + executedMsg,
                    OUTPUT_WRITER_PRIORITY_TEST_CASE_FAILED
            );
        }
    }

    if (executionResult) {
        executionResult = success;
    }
}

void Test::EXECUTE_TEST_CASE(TestCase *testCase, long expectedExecutionTime) {

    EXECUTE_TEST_CASE(testCase);
    if (executionResult) {
        bool success = ASSERT_TIME(
                expectedExecutionTime, testCase->getExecutionTimeInMilliseconds()
        );
        executionResult = success;
    }
}

void Test::log(const std::string &what) {

    outputWriterFunction(what, 0);
}

void Test::log(const std::string &what, int priority) {

    outputWriterFunction(what, priority);
}

bool Test::getExecutionResult() {

    return executionResult;
}
