#include <cppunit/extensions/HelperMacros.h>
#include "Service.hpp"
#include "Service.cpp"
#include "gmock/gmock.h"

using namespace restcpp;

class HTTPServerMock {
    public:
        MOCK_METHOD1(setPort, void(int port));
        MOCK_METHOD0(start, void());
};

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
        // Set the mock object
        HTTPServerMock server;
        EXPECT_CALL(server, setPort(8080))
                  .Times(1);

        // Perform the SUT
        Service<HTTPServerMock> service(server);
        service
            .port(8080)
            .path("root");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(ServiceTest);




