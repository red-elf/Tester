#ifndef TESTER_TESTER_H
#define TESTER_TESTER_H

#include <list>
#include <string>

#include "TestRunner.h"
#include "TesterConfig.h"

namespace TestingLibrary::Info {

    static const std::string getVersion() {
        std::string majorVersion = std::to_string(TESTER_VERSION_MAJOR);
        std::string minorVersion = std::to_string(TESTER_VERSION_MINOR);
        return majorVersion + "." + minorVersion;
    }
}

namespace TestingLibrary::Testing {

    static std::list<Test *> TESTS;

    static void REGISTER_TEST(Test *test) {

        TESTS.emplace_back(test);
    }

    static int RUN_TESTS() {

        TestRunner runner;
        runner.setOutputWriterFunction(OUTPUT_WRITER_FUNCTION);
        for (Test *test : TESTS) {
            runner.add(test);
        }
        if (runner.run()) {
            return 0;
        }
        return 1;
    }
}

#endif
