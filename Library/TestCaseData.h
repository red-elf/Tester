#ifndef TESTINGLIBRARY_TESTCASEDATA_H
#define TESTINGLIBRARY_TESTCASEDATA_H

#include <string>

class TestCaseData {

public:

    explicit TestCaseData(const std::string &testCaseName) {

        name = testCaseName;
    };

    [[nodiscard]] const std::string &getName() const;

private:

    std::string name;
};

#endif
