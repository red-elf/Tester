#ifndef TESTINGLIBRARY_EXECUTIONTIME_H
#define TESTINGLIBRARY_EXECUTIONTIME_H

class ExecutionTime {

public:

    [[nodiscard]] long getExecutionTimeInMilliseconds() const;

    void setExecutionTimeInMilliseconds(long executionTime);

private:

    long executionTimeInMilliseconds = 0;
};

#endif
