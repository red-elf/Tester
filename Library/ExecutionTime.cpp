#include "ExecutionTime.h"

void ExecutionTime::setExecutionTimeInMilliseconds(long executionTime) {

    executionTimeInMilliseconds = executionTime;
}

long ExecutionTime::getExecutionTimeInMilliseconds() const {

    return executionTimeInMilliseconds;
}
