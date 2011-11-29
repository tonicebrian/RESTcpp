#ifndef _REST_SERVICE_HPP_
#define _REST_SERVICE_HPP_

#include <string>
#include <Server.hpp>

namespace restcpp {
    static const int DEFAULT_PORT = 8080;

    /**
     * Class implementing the BuilderCommand
     */
    class Service {
        private:
            Server& server;

        public:
            Service(Server& server);
            bool run();

            /**
             * Define a new path
             */
            Service& path(const std::string& path);

            /**
             * Define the port for listening to
             */
            Service& port(int port);
    };
}

#endif

