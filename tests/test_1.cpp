#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(MyTests, SimpleRegex_1) {
    EXPECT_EQ(1, solution("abc.+", 'a'));
}

TEST(MyTests, SimpleRegex_2) {
    EXPECT_EQ(-2, solution("1a.*", 'a'));
}

TEST(MyTests, ErrorCases_1) {
    EXPECT_EQ(-1, solution("*", 'a'));
}

TEST(MyTests, ErrorCases_2) {
    EXPECT_EQ(-1, solution("abc+", 'a'));
}

TEST(GivenTests, Regex_1) {
    EXPECT_EQ(2, solution("ab+c.aba.*.bac.+.+*", 'a'));
}

TEST(GivenTests, Regex_2) {
    EXPECT_EQ(2, solution("acb..bab.c.*.ab.ba.+.+*a.", 'a'));
}




