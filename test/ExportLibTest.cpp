#include "config.hpp"
#include "ExportLib.h"

#include <boost/test/unit_test.hpp>

struct ExportLibFixture {
    ExportLibFixture()
    { 
        BOOST_TEST_MESSAGE("setup fixture"); 
        ::configure(TEST_ASSETS_PATH, TEST_ASSETS_PATH, TEST_ASSETS_PATH);
    }

    ~ExportLibFixture()
    { 
        BOOST_TEST_MESSAGE("teardown fixture"); 
    }
};

BOOST_FIXTURE_TEST_SUITE(ExportLib, ExportLibFixture)

BOOST_AUTO_TEST_CASE(GivenTestData_WhenTileLoad_ThenCallbacksAreCalled)
{
    ::loadTile(0, 0, 1, 
        [](const char* name,
           const double* vertices, int vertexCount,
           const int* triangles, int triCount,
           const int* colors, int colorCount) {
            // TODO basic checks
        }, 
        [](uint64_t id, const char* name,
            const char** tags, int size,
            const double* vertices, int vertexCount) {
            // TODO basic checks
        },
        [](int id)
        {
           // TODO basic checks
        }
    );
}

BOOST_AUTO_TEST_SUITE_END()