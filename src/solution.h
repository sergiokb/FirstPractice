#include <stack>
#include "regex.h"

int solution(const std::string &regex_str, char x_given);   // returns answer in case it is integer,
                                                // -2 in case it is infinite, -1 in case there is an error

// Functions below return true, if there are errors, false otherwise

bool asterisk(std::stack<regular_expression> &polish_stack, char symbol);

bool plus_or_dot(std::stack<regular_expression> &polish_stack, char symbol);
