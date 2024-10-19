FROM debian:12.7

WORKDIR /usr/

RUN apt-get update && \
    apt-get -y install git cmake build-essential lcov libboost-all-dev

RUN git clone https://github.com/google/googletest.git && \
    cd googletest && \
    git checkout 0953a17a4281fc26831da647ad3fcd5e21e6473b && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make
