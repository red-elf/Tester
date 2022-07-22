#ifndef TESTINGLIBRARY_TESTASSERT_H
#define TESTINGLIBRARY_TESTASSERT_H

#include <string>

#include "TestLogging.h"

using namespace TestingLibrary::Logging;

class TestAssert {

public:
    TestAssert();

    void setOutputWriterFunction(OutputWriterFunction outWriterFunction);

    bool ASSERT_EQUAL(int expected, int actual);

    bool ASSERT_EQUAL(long expected, long actual);

    bool ASSERT_EQUAL(long long expected, long long actual);

    bool ASSERT_EQUAL(float expected, float actual);

    bool ASSERT_EQUAL(double expected, double actual);

    bool ASSERT_EQUAL(char expected, char actual);

    bool ASSERT_EQUAL(const std::string &expected, const std::string &actual);

    bool ASSERT_NOT_EQUAL(int expected, int actual);

    bool ASSERT_NOT_EQUAL(float expected, float actual);

    bool ASSERT_NOT_EQUAL(double expected, double actual);

    bool ASSERT_NOT_EQUAL(char expected, char actual);

    bool ASSERT_NOT_EQUAL(const std::string &expected, const std::string &actual);

    bool ASSERT_TRUE(bool what);

    bool ASSERT_FALSE(bool what);

    bool ASSERT_TIME(long expected, long actual);

    static bool endsWith(const std::string &mainStr, const std::string &toMatch);

    bool ASSERT_ENDS_WITH(const std::string &mainStr, const std::string &toMatch);

protected:

    OutputWriterFunction outputWriterFunction;

private:

    template<class T>
    bool compareEquality(T expected, T actual);

    template<class T>
    bool compareNotEquality(T expected, T actual);

    template<class T>
    bool assertTruthness(T what);

    template<class T>
    bool assertFalseness(T what);
};

#endif
