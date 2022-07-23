#include <iostream>
#include <string>

#include "DummyTest.h"
#include "TestLogging.h"
#include "Tester.h"
#include "LoggerFactory.h"
#include "LogLevel.h"
#include "LoggerSimple.h"

using namespace TestingLibrary::Testing;
using namespace TestingLibrary::Logging;

Logger *obtainLogger() {

    LoggerFactory::initializeDefaultImplementations();
    static auto logger = LoggerFactory::create(
            LoggerFactoryImplementationNames::IMPL_LOGGER_SIMPLE()
    );
    logger->setApplicationId("Example App.");
    logger->setApplicationVersion("0.0");
    return logger;
}

int main() {

    OUTPUT_WRITER_FUNCTION = [](const std::string &what, int priority) {

        auto logger = obtainLogger();
        LogLevel level;
        switch (priority) {
            case OUTPUT_WRITER_PRIORITY_STARTED:
                level = LogLevel::verbose;
                break;
            case OUTPUT_WRITER_PRIORITY_EXECUTED:
                level = LogLevel::debug;
                break;
            case OUTPUT_WRITER_PRIORITY_FAILED:
                level = LogLevel::error;
                break;
            case OUTPUT_WRITER_PRIORITY_TEST_CASE_PASSED:
                level = LogLevel::verbose;
                break;
            case OUTPUT_WRITER_PRIORITY_TEST_CASE_FAILED:
                level = LogLevel::error;
                break;
            case OUTPUT_WRITER_PRIORITY_ASSERT_FAILED:
                level = LogLevel::error;
                break;
            default:
                level = LogLevel::verbose;
        }
        logger->log(level, what);
    };

    DummyTest test;
    REGISTER_TEST(&test);
    return RUN_TESTS();
}
