FROM ubuntu:22.04

# Install dependencies
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        wget \
        software-properties-common \
        ca-certificates \
        lsb-release \
        python3 \
        python3-pip \
        python3-setuptools \
        python3-wheel \
        python3-tk \
        python3-dev \
        python3-autopep8 \
        make \
        cmake \
        git \
        g++-12 \
        gdb \
        ccache \
        autoconf \
        automake \
        libtool\
        curl \
        unzip\
        gnupg \
        shellcheck \
        clang-format \
        build-essential \
        libc6 \
        vim \
        nano \
        lcov \
        gcovr \
        plantuml \
        graphviz

RUN add-apt-repository ppa:swi-prolog/stable && \
        add-apt-repository ppa:swi-prolog/stable && \
        apt-get -y install swi-prolog

WORKDIR /opt/workspace


