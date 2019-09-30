#pragma once

#include <string>

namespace qpdf {

class string {
public:
    string();
    string(const std::string& str);

    bool empty() const;
    const std::string& value() const;
private:
    std::string normalize(const std::string& value) const;
private:
    std::string data;
};

}
