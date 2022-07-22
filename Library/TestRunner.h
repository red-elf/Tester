#ifndef TESTINGLIBRARY_TESTRUNNER_H
#define TESTINGLIBRARY_TESTRUNNER_H

#include <list>
#include <string>

#include "Test.h"
#include "TestLogging.h"

using namespace TestingLibrary::Logging;

class TestRunner {

public:

    TestRunner();

    void add(Test *test);

    bool run();

    void setOutputWriterFunction(OutputWriterFunction outWriterFunction);

private:
    OutputWriterFunction outputWriterFunction;

    std::list<Test *> tests;
};


#endif //TESTINGLIBRARY_TESTRUNNER_H
