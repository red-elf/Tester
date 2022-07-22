#ifndef TESTINGLIBRARY_TESTLOGGING_H
#define TESTINGLIBRARY_TESTLOGGING_H

namespace TestingLibrary::Logging {

    static const int OUTPUT_WRITER_PRIORITY_DEFAULT = 0;
    static const int OUTPUT_WRITER_PRIORITY_STARTED = 1;
    static const int OUTPUT_WRITER_PRIORITY_EXECUTED = 2;
    static const int OUTPUT_WRITER_PRIORITY_FAILED = 3;
    static const int OUTPUT_WRITER_PRIORITY_TEST_CASE_PASSED = 4;
    static const int OUTPUT_WRITER_PRIORITY_TEST_CASE_FAILED = 5;
    static const int OUTPUT_WRITER_PRIORITY_ASSERT_FAILED = 6;
    static const int OUTPUT_WRITER_PRIORITY_ASSERT_OK = 7;

    typedef void (*OutputWriterFunction)(const std::string &what, int outputWriterPriority);

    static OutputWriterFunction OUTPUT_WRITER_FUNCTION;
}

#endif //TESTINGLIBRARY_TESTLOGGING_H
