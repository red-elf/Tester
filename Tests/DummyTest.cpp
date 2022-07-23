#include "DummyTest.h"
#include "DummyTestCase.h"
#include "DummyDataTestCase.h"
#include "DummyTestCaseData.h"
#include "TestCaseData.h"

std::string DummyTest::name() {

    return "Dummy test";
}

void DummyTest::execute() {

    DummyTestCase testCase;
    DummyTestCaseData testCaseData("I am dummy! ;)", 2, 2);
    DummyDataTestCase dataTestCase(&testCaseData);

    EXECUTE_TEST_CASE(&testCase);
    EXECUTE_TEST_CASE(&dataTestCase);

    EXECUTE_TEST_CASE(&testCase, 1);
    EXECUTE_TEST_CASE(&dataTestCase, 1);
}
