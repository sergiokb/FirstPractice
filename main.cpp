#include <iostream>
#include "src/solution.h"

int main() {
    std::string reg;                // given regular expression in reversed polish notation
    char x;                         // given symbol
    std::cin >> reg >> x;
    int ans = solution(reg, x);
    if(ans >= 0) std::cout << ans << '\n';
    if(ans == -1) std::cout << "ERROR" << '\n';
    if(ans == -2) std::cout << "INF" << '\n';
    return 0;
}
