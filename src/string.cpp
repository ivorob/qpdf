#include "qpdf/string.h"

qpdf::string::string()
{
    data = normalize("");
}

qpdf::string::string(const std::string& str)
    : data(normalize(str))
{
}

bool
qpdf::string::empty() const
{
    return this->data.size() == 2;
}

const std::string&
qpdf::string::value() const
{
    return this->data;
}

std::string
qpdf::string::normalize(const std::string& value) const
{
    size_t count = std::count_if(value.begin(), value.end(), [](const char symbol) {
                return symbol == '(' || symbol == ')';
            });
    if (count == 0) {
        return "(" + value + ")";
    }

    std::string result("(");
    for (const auto symbol : value) {
        if (symbol == '(' || symbol == ')') {
            result.push_back('\\');
        }

        result.push_back(symbol);
    }
    result.push_back(')');

    return result;
}
