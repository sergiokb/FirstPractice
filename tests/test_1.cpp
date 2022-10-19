#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(MyTests, SimpleRegex) {
    EXPECT_EQ(1, solution("abc.+", 'a'));
    EXPECT_EQ(-2, solution("1a.*", 'a'));
}

TEST(MyTests, ErrorCases) {
    EXPECT_EQ(-1, solution("*", 'a'));
    EXPECT_EQ(-1, solution("abc+", 'a'));
}

TEST(GivenTests, Regex) {
    EXPECT_EQ(2, solution("ab+c.aba.*.bac.+.+*", 'a'));
    EXPECT_EQ(2, solution("acb..bab.c.*.ab.ba.+.+*a.", 'a'));
}



