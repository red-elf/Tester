#ifndef TESTINGLIBRARY_DATATESTCASE_H
#define TESTINGLIBRARY_DATATESTCASE_H

#include "TestCaseData.h"
#include "TestCase.h"

class DataTestCase : public TestCase {

public:

    explicit DataTestCase(TestCaseData *data) : TestCase() {

        testCaseData = data;
        testCaseTypeId = 1;
    };

    TestCaseData *getTestCaseData();

protected:

    TestCaseData *testCaseData;
};


#endif //TESTINGLIBRARY_DATATESTCASE_H
