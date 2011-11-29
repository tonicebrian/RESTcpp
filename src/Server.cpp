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

void 
Server::addResource(const std::string& path){
    server.addResource(path,NULL);
}


