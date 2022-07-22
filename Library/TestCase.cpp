#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "TestCase.h"

void TestCase::log(const std::string &what) {

    outputWriterFunction(what, 0);
}

void TestCase::log(const std::string &what, int priority) {

    outputWriterFunction(what, priority);
}

int TestCase::getTestCaseTypeId() const {

    return testCaseTypeId;
}

void TestCase::waitFor(int millis) const { std::this_thread::sleep_for(std::chrono::milliseconds(millis)); }