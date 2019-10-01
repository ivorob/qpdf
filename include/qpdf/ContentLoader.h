#pragma once

#include <string>
#include <list>

namespace qpdf {

typedef std::list<std::string> primitives;

class ContentLoader {
public:
    ContentLoader();

    primitives loadFile(const std::string& filename) const;
private:
    primitives parse(const std::string& content) const;
};

}
