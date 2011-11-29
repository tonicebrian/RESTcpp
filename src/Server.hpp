#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <pion/net/HTTPServer.hpp>

/**
 * Adaptor pattern for the HTTPServer class that allows mocking 
 * with the Google Mock infrastructure
 */
namespace restcpp {
    class Server {
        private:
            pion::net::HTTPServer server;

        public:
            virtual void setPort(int port);
            virtual void addResource(const std::string& path);
            virtual void start();

            virtual ~Server(){};
    };
};
#endif
