#include <iostream>
#include <string>

#include "TestAssert.h"
#include "TestLogging.h"

using namespace TestingLibrary::Logging;

TestAssert::TestAssert() {

    outputWriterFunction = [](const std::string &what, int priority) {

        std::cout << what << '\n';
    };
}

bool TestAssert::ASSERT_EQUAL(int expected, int actual) {

    return compareEquality(expected, actual);
}

bool TestAssert::ASSERT_EQUAL(long expected, long actual) {

    return compareEquality(expected, actual);
}

bool TestAssert::ASSERT_EQUAL(long long expected, long long actual) {

    return compareEquality(expected, actual);
}

bool TestAssert::ASSERT_EQUAL(float expected, float actual) {

    return compareEquality(expected, actual);
}

bool TestAssert::ASSERT_EQUAL(double expected, double actual) {

    return compareEquality(expected, actual);
}

bool TestAssert::ASSERT_EQUAL(char expected, char actual) {

    return compareEquality(expected, actual);
}

bool TestAssert::ASSERT_EQUAL(const std::string &expected, const std::string &actual) {

    return compareEquality(expected, actual);
}

bool TestAssert::ASSERT_NOT_EQUAL(int expected, int actual) {

    return compareNotEquality(expected, actual);
}

bool TestAssert::ASSERT_NOT_EQUAL(float expected, float actual) {

    return compareNotEquality(expected, actual);
}

bool TestAssert::ASSERT_NOT_EQUAL(double expected, double actual) {

    return compareNotEquality(expected, actual);
}

bool TestAssert::ASSERT_NOT_EQUAL(char expected, char actual) {

    return compareNotEquality(expected, actual);
}

bool TestAssert::ASSERT_NOT_EQUAL(const std::string &expected, const std::string &actual) {

    return compareNotEquality(expected, actual);
}

bool TestAssert::ASSERT_TRUE(bool what) {

    return assertTruthness(what);
}

bool TestAssert::ASSERT_FALSE(bool what) {

    return assertFalseness(what);
}

bool TestAssert::ASSERT_TIME(long expected, long actual) {

    bool success = actual <= expected;
    if (success) {

        auto diff = expected - actual;
        outputWriterFunction(
                "Asserting time succeeded. Executed for " + std::to_string(diff) +
                " milliseconds faster than expected. Expected: " +
                std::to_string(expected) + " Actual: " + std::to_string(actual),
                OUTPUT_WRITER_PRIORITY_ASSERT_OK
        );
    } else {

        auto diff = actual - expected;
        outputWriterFunction(
                "Assert time failed. Executed for " + std::to_string(diff) +
                " milliseconds longer than expected. Expected: " +
                std::to_string(expected) + " Actual: " + std::to_string(actual),
                OUTPUT_WRITER_PRIORITY_ASSERT_FAILED
        );
    }
    return success;
}

template<class T>
bool TestAssert::compareEquality(T expected, T actual) {

    bool success = expected == actual;
    if (!success) {
        std::string name(typeid(expected).name());
        outputWriterFunction(
                "Assert equality failed for the type: " + name,
                OUTPUT_WRITER_PRIORITY_ASSERT_FAILED
        );
    }
    return success;
}

template<class T>
bool TestAssert::compareNotEquality(T expected, T actual) {

    bool success = expected != actual;
    if (!success) {
        std::string name(typeid(expected).name());
        outputWriterFunction(
                "Assert inequality failed for the type: " + name,
                OUTPUT_WRITER_PRIORITY_ASSERT_FAILED
        );
    }
    return success;
}

template<class T>
bool TestAssert::assertTruthness(T what) {
    if (!what) {
        outputWriterFunction(
                "Assert truthiness failed.",
                OUTPUT_WRITER_PRIORITY_ASSERT_FAILED
        );
        return false;
    }
    return true;
}

bool TestAssert::ASSERT_ENDS_WITH(const std::string &mainStr, const std::string &toMatch) {

    bool ends = endsWith(mainStr, toMatch);
    if (!ends) {
        outputWriterFunction(
                "Assert string ends with ' " + toMatch + " ' failed.",
                OUTPUT_WRITER_PRIORITY_ASSERT_FAILED
        );
    }
    return ends;
}

bool TestAssert::endsWith(const std::string &mainStr, const std::string &toMatch) {

    return mainStr.size() >= toMatch.size() &&
           mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0;
}

template<class T>
bool TestAssert::assertFalseness(T what) {
    if (what) {
        outputWriterFunction(
                "Assert falseness failed. ",
                OUTPUT_WRITER_PRIORITY_ASSERT_FAILED
        );
        return false;
    }
    return true;
}

void TestAssert::setOutputWriterFunction(OutputWriterFunction outWriterFunction) {

    outputWriterFunction = outWriterFunction;
}
