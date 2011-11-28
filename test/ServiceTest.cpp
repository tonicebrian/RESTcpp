#include <cppunit/extensions/HelperMacros.h>
#include "Service.hpp"

class ServiceTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(ServiceTest);
    CPPUNIT_TEST(testService);
    CPPUNIT_TEST_SUITE_END();

    public:

    void setUp(){
    }

    void tearDown(){
    }

    void testService(){
        HTTPServer server;
        restcpp::Service service(server);
        service
            .path("root");

        CPPUNIT_ASSERT_EQUAL(1,0);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(ServiceTest);




