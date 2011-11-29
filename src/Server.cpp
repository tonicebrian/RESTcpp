#include <Server.hpp>

using namespace restcpp;
using namespace pion::net;

void
Server::setPort(int port){
    server.setPort(port);
}

void
Server::start(){
    server.start();
}
