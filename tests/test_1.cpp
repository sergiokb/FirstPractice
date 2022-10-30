#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(MyTests, SimpleRegex_1) {
    EXPECT_EQ(1, solution("abc.+", 'a'));
}

TEST(MyTests, SimpleRegex_2) {
    EXPECT_EQ(-2, solution("1a.*", 'a'));
}

TEST(MyTests, SimpleRegex_3) {
    EXPECT_EQ(2, solution("c*ba.+aa.+", 'a'));
}

TEST(MyTests, SimpleRegex_4) {
    EXPECT_EQ(2, solution("ab+c+a.", 'a'));
}

TEST(MyTests, ErrorCases_1) {
    EXPECT_EQ(-1, solution("*", 'a'));
}

TEST(MyTests, ErrorCases_2) {
    EXPECT_EQ(-1, solution("abc+", 'a'));
}

TEST(MyTests, ErrorCases_3) {
    EXPECT_EQ(-1, solution("aaaaaa", 'a'));
}

TEST(GivenTests, Regex_1) {
    EXPECT_EQ(2, solution("ab+c.aba.*.bac.+.+*", 'a'));
}

TEST(GivenTests, Regex_2) {
    EXPECT_EQ(2, solution("acb..bab.c.*.ab.ba.+.+*a.", 'a'));
}

TEST(MyTests, AnotherRegex_1) {
    EXPECT_EQ(3, solution("ab+a.a.c+b+c.b*.", 'a'));
}

TEST(MyTests, AnotherRegex_2) {
    EXPECT_EQ(1, solution("ab+c.******b+", 'a'));
}




