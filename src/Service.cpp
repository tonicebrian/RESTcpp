#include "Service.hpp"
#include <boost/asio.hpp>
#include "ShutdownManager.hpp"


using namespace restcpp;

/**
 * Constructor
 */
Service::Service(Server& _server) 
    : server(_server) {
}

/**
 * Set the port of the server
 */
Service&
Service::port(int port){
    server.setPort(port);
    return *this;
}

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
