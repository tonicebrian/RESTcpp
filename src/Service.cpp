#include "Service.hpp"
#include <boost/asio.hpp>
#include <pion/net/WebServer.hpp>
#include "ShutdownManager.hpp"


using namespace restcpp;
using namespace pion::net;

/**
 * Constructor
 */
template<class Server>
Service<Server>::Service(Server& _server) 
    : server(_server) {
    // Ensure that listens in a valid port
    server.setPort(DEFAULT_PORT);
}

/**
 * Set the port of the server
 */
template<class Server>
Service<Server>&
Service<Server>::port(int port){
    server.setPort(port);
    return *this;
}

/**
 * Adds a new path to be listened to
 */
template<class Server>
Service<Server>&
Service<Server>::path(const std::string& path){
    return *this;
}

/**
 * Run the server
 */
template<class Server>
bool
Service<Server>::run(){

    try {
        server.start();
        main_shutdown_manager.wait();
    } catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return true;
}
