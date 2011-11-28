#include "Service.hpp"
#include <boost/asio.hpp>
#include <pion/net/WebServer.hpp>
#include "ShutdownManager.hpp"


using namespace restcpp;
using namespace pion::net;

/**
 * Constructor
 */
Service::Service(HTTPServer& _server) 
    : server(_server) {}

/**
 * Adds a new path to be listened to
 */
Service&
Service::path(const std::string& path){
    return *this;
}

/**
 * Run the server
 */
bool
Service::run(){

    try {
        server.start();
        main_shutdown_manager.wait();
    } catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return true;
}
