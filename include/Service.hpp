#ifndef _REST_SERVICE_HPP_
#define _REST_SERVICE_HPP_

#include <string>
#include <pion/net/HTTPServer.hpp>

using namespace pion::net;

namespace restcpp {
    static const int DEFAULT_PORT = 8080;

    /**
     * Class implementing the BuilderCommand
     */
    class Service {
        private:
            HTTPServer& server;

        public:
            Service(HTTPServer& server);
            bool run();

            /**
             * Define a new path
             */
            Service& path(const std::string& path);
    };
}

#endif

