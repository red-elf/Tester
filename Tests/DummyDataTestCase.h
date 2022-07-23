#ifndef TESTINGLIBRARY_DUMMYDATATESTCASE_H
#define TESTINGLIBRARY_DUMMYDATATESTCASE_H

#include "TestCaseData.h"
#include "TestCase.h"
#include "DataTestCase.h"

class DummyDataTestCase : public DataTestCase {

public:
    explicit DummyDataTestCase(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {

    };

    bool execute() override;
};


#endif //TESTINGLIBRARY_DUMMYTEST_H
