#include <iostream>
#include "regex.h"

regular_expression::regular_expression(char letter, char x_given) : regular_expression() {
    is_1 = (letter == '1');
    if (letter == x_given) {
        has_full = true;
        full_length = 1;
        max_prefix = 1;
        max_suffix = 1;
        max_postfix = 1;
    }
}

regular_expression regular_expression::from_dot(regular_expression &reg1, regular_expression &reg2) {
    inf = reg1.inf || reg2.inf;
    is_1 = false;
    has_full = reg1.has_full && reg2.has_full;
    full_length = reg1.full_length + reg2.full_length;
    max_prefix = reg1.max_prefix;
    if (reg1.has_full && reg1.full_length + reg2.max_prefix > max_prefix)
        max_prefix = reg1.full_length + reg2.max_prefix;
    max_suffix = std::max(reg1.max_postfix + reg2.max_prefix, std::max(reg1.max_suffix, reg2.max_suffix));
    max_postfix = reg1.max_postfix;
    if (reg2.has_full && reg1.max_postfix + reg2.full_length > max_postfix)
        max_postfix = reg1.max_postfix + reg2.full_length;
    return *this;
}

regular_expression regular_expression::from_plus(regular_expression &reg1, regular_expression &reg2) {
    inf = reg1.inf || reg2.inf;
    is_1 = false;
    has_full = reg1.has_full || reg2.has_full;
    full_length = std::max(reg1.full_length, reg2.full_length);
    max_prefix = std::max(reg1.max_prefix, reg2.max_prefix);
    max_suffix = std::max(reg1.max_suffix, reg2.max_suffix);
    max_postfix = std::max(reg1.max_postfix, reg2.max_postfix);
    return *this;
}

regular_expression::regular_expression(regular_expression &reg1, char) : regular_expression(reg1) {
    if (has_full) inf = true;
    max_suffix = std::max(reg1.max_prefix + reg1.max_postfix, reg1.max_suffix);
}

bool regular_expression::is1() const {
    return is_1;
}

bool regular_expression::has_inf() const {
    return inf;
}

int regular_expression::get_max() const {
    return max_suffix;
}
