#include <iostream>
#include "solution.h"

int solution(const std::string &regex_str, char x_given) {
    bool error = false;
    std::stack<regular_expression> polish_stack;     // stack with information about read part of regex
    for (char symbol: regex_str) {
        switch(symbol) {
            case '*':
                error = asterisk(polish_stack, symbol);     // if Kleene star
                if (error) return -1;
                break;
            case '+':
            case '.':
                error = plus_or_dot(polish_stack, symbol);      // if Kleene plus or concatenation
                if (error) return -1;
                break;
            default:
                polish_stack.push(regular_expression(symbol, x_given));
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
    regular_expression reg;
    if(symbol == '+') polish_stack.push(reg.from_plus(first, second));
    if(symbol == '.') polish_stack.push(reg.from_dot(first, second));
    return false;
}
