#ifndef _REST_SERVICE_HPP_
#define _REST_SERVICE_HPP_

namespace restcpp {
    class Service {
        int port;

        public:
            Service(int port);
            bool run();
    };
}

#endif

