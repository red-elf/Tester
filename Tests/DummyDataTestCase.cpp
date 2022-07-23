#include <iostream>
#include <string>

#include "TestCaseData.h"
#include "TestCase.h"
#include "DummyTestCaseData.h"
#include "DummyDataTestCase.h"

bool DummyDataTestCase::execute() {

    auto data = (DummyTestCaseData *) testCaseData;

    int x = data->getX();
    int y = data->getY();

    bool success = ASSERT_EQUAL(x, y);
    return success;
}
