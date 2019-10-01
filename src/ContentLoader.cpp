#include <fstream>
#include <sstream>
#include "qpdf/ContentLoader.h"

qpdf::ContentLoader::ContentLoader()
{
}

qpdf::primitives
qpdf::ContentLoader::loadFile(const std::string& filename) const
{
    std::ifstream input(filename);
    std::string content((std::istreambuf_iterator<char>(input)),
                         std::istreambuf_iterator<char>());
    return parse(content);
}

qpdf::primitives
qpdf::ContentLoader::parse(const std::string& content) const
{
    qpdf::primitives primitives;
    if (content.empty()) {
        return primitives;
    }

    std::stringstream input(content);

    std::string version;
    input >> version;
    primitives.push_back(version);

    std::string data;
    while (input && data != "%%EOF") {
        input >> data;
    }

    if (data == "%%EOF") {
        primitives.push_back(data);
    }
    return primitives;
}
