#include <string>
#include <iostream>
#include <chrono>

#include "Test.h"
#include "TestLogging.h"
#include "TestRunner.h"

using namespace TestingLibrary::Logging;

TestRunner::TestRunner() {

    outputWriterFunction = [](const std::string &what, int priority) {

        std::cout << what << '\n';
    };
}

void TestRunner::add(Test *test) {

    test->setOutputWriterFunction(outputWriterFunction);
    tests.emplace_back(test);
}

bool TestRunner::run() {

    bool success = true;
    for (Test *test : tests) {
        outputWriterFunction(
                "Test -> '" + test->name() + "' -> STARTED",
                OUTPUT_WRITER_PRIORITY_STARTED
        );

        auto started = std::chrono::high_resolution_clock::now();
        test->execute();
        auto completed = std::chrono::high_resolution_clock::now();
        auto executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                completed - started
        ).count();
        test->setExecutionTimeInMilliseconds(executionTime);
        auto executedMsg = "Execution time: " + std::to_string(executionTime)
                           + " milliseconds.";

        bool result = test->getExecutionResult();
        if (success) {
            success = result;
        }
        if (result) {

            outputWriterFunction(
                    "Test -> '" + test->name() + "' -> SUCCEEDED. " + executedMsg,
                    OUTPUT_WRITER_PRIORITY_EXECUTED
            );
        } else {

            outputWriterFunction(
                    "Test -> '" + test->name() + "' -> FAILED. " + executedMsg,
                    OUTPUT_WRITER_PRIORITY_FAILED
            );
        }
    }
    return success;
}

void TestRunner::setOutputWriterFunction(OutputWriterFunction outWriterFunction) {

    outputWriterFunction = outWriterFunction;
}
