#ifndef TESTINGLIBRARY_DUMMYTESTCASEDATA_H
#define TESTINGLIBRARY_DUMMYTESTCASEDATA_H

#include "TestCaseData.h"
#include "TestCase.h"
#include "DataTestCase.h"

class DummyTestCaseData : public TestCaseData {

public:
    explicit DummyTestCaseData(const std::string &testCaseName, int xVal, int yVal)
            : TestCaseData(testCaseName) {

        x = xVal;
        y = yVal;
    }

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;

private:

    int x;
    int y;
};


#endif //TESTINGLIBRARY_DUMMYTEST_H
