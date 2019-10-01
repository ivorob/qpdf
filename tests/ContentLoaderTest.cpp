#include <gtest/gtest.h>
#include "qpdf/ContentLoader.h"

TEST(ContentLoaderTest, loadTest)
{
    qpdf::ContentLoader loader;
    qpdf::primitives primitives = loader.loadFile("tests/minimal.pdf");
    ASSERT_FALSE(primitives.empty());

    auto it = primitives.begin();
    ASSERT_EQ("%PDF-1.1", *it);

    auto it1 = it;
    std::advance(it1, 1);
    while (it1 != primitives.end()) {
        ++it;
        std::advance(it1, 1);
    }

    ASSERT_EQ("%%EOF", *it);
}
