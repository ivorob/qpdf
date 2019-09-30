#include <gtest/gtest.h>
#include "qpdf/string.h"

TEST(StringTest, emptyTest)
{
    qpdf::string str;
    ASSERT_TRUE(str.empty());

    qpdf::string str1("test");
    ASSERT_FALSE(str1.empty());
}

TEST(StringTest, valueTest)
{
    qpdf::string str;
    ASSERT_EQ("()", str.value());

    qpdf::string str1("test string");
    ASSERT_EQ("(test string)", str1.value());

    qpdf::string str2("test (string)");
    ASSERT_EQ("(test \\(string\\))", str2.value());

    qpdf::string str3("test (string");
    ASSERT_EQ("(test \\(string)", str3.value());

    qpdf::string str4("test )string");
    ASSERT_EQ("(test \\)string)", str4.value());
}
