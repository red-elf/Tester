#include <iostream>
#include <string>

#include "TestCase.h"
#include "DummyTestCase.h"

bool DummyTestCase::execute() {

    int x = 0;
    int y = 0;

    bool success = ASSERT_EQUAL(x, y);
    return success;
}
