class regular_expression {
private:
    bool inf = false;        // whether language contains a word with infinite suffix of x-es
    bool is_1 = false;       // whether regex is a 1
    bool has_full = false;   // whether language contains a word from of x-es only
    int full_length = 0;     // in case previous is true, equals maximum length of such a word
    int max_prefix = 0;      // prefix of x-es only maximum length
    int max_suffix = 0;      // suffix of x-es only maximum length
    int max_postfix = 0;     // postfix of x-es only maximum length
public:
    regular_expression() = default;

    regular_expression(const regular_expression &copy) = default;

    regular_expression &operator=(const regular_expression &other) = default;

    ~regular_expression() = default;

    regular_expression(char y, char x);  // letter and x

    regular_expression(regular_expression &reg1, regular_expression &reg2, char y);   // 2 regex-s and operation(+ or .)

    regular_expression(regular_expression &reg1, char y);   // regex and operation(*)

    bool is1() const;        // returns is_1 value

    bool has_inf() const;    // returns inf value

    int get_max() const;     // returns max_suffix value
};
