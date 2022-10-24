#include <iostream>
#include "solution.h"

int solution(const std::string &reg, char x) {
    bool error = false;
    std::stack<regular_expression> polish_stack;     // stack with information about read part of regex
    for (char symbol: reg) {
        if (symbol == 'a' || symbol == 'b' || symbol == 'c' || symbol == '1') {
            polish_stack.push(regular_expression(symbol, x));       // if letter/1, put on top of stack
        } else {
            if (symbol == '*') {
                error = asterisk(polish_stack, symbol);     // if Kleene star
                if (error) return -1;
            } else {
                error = plus_or_dot(polish_stack, symbol);      // if Kleene plus or concatenation
                if (error) return -1;
            }
        }
    }

    // In the end stack should contain all regular expression

    if (polish_stack.size() > 1) error = true;
    if (error) return -1;
    else {
        regular_expression ans = polish_stack.top();
        if (ans.has_inf()) return -2;
        else return ans.get_max();
    }
}

bool asterisk(std::stack<regular_expression> &polish_stack, char symbol) {
    if (polish_stack.empty()) return true;
    regular_expression first = polish_stack.top();
    if (first.is1()) return false;
    polish_stack.pop();
    polish_stack.push(regular_expression(first, symbol));
    return false;
}

bool plus_or_dot(std::stack<regular_expression> &polish_stack, char symbol) {
    if (polish_stack.size() < 2) return true;
    regular_expression first = polish_stack.top();
    polish_stack.pop();
    if (first.is1()) return false;
    regular_expression second = polish_stack.top();
    polish_stack.pop();
    if (second.is1()) {
        polish_stack.push(first);
        return false;
    }
    polish_stack.push(regular_expression(first, second, symbol));
    return false;
}
