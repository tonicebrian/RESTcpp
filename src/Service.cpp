#include "Service.hpp"
#include <boost/asio.hpp>
#include <pion/net/WebServer.hpp>
#include "ShutdownManager.hpp"


using namespace restcpp;
using namespace pion::net;

/**
 * Constructor
 */
Service::Service(int port=8080) : port(port) {}

/**
 * Run the server
 */
bool
Service::run(){

    boost::asio::ip::tcp::endpoint cfg_endpoint(boost::asio::ip::tcp::v4(), port);
    WebServer web_server(cfg_endpoint);

    try {
        web_server.start();
        main_shutdown_manager.wait();
    } catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return true;
}
