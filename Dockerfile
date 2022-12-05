FROM ubuntu:22.04

ARG GRPC_UPSTREAM=https://github.com/grpc/grpc
ARG GRPC_VERSION=1.50.0
ENV INSTALL_DIR=/usr/local

RUN apt-get update && apt-get -y upgrade && apt-get -y install \
      cmake build-essential python3 autoconf libtool pkg-config \
      git zip unzip wget python-is-python3

RUN git clone --recurse-submodules -b v$GRPC_VERSION --depth=1 --shallow-submodules $GRPC_UPSTREAM
RUN cd grpc && \
    mkdir -p cmake/build && \
    cd cmake/build && \
    cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR ../.. && \
    make -j$(nproc) && \
    make install && \
    cd ../.. && \
    rm -rf /grpc # buildkit

CMD ["/bin/bash", "-s"]