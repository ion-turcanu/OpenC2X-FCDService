FROM ubuntu:16.04

MAINTAINER Florian Adamsky <florian.adamsky@uni.lu>

RUN apt-get update \
	&& apt-get install -y --no-install-recommends \
		build-essential \
                wget \
                cmake \
                libprotobuf-dev \
                libboost-thread-dev \
                libprotobuf9v5 \
                protobuf-compiler \
                libzmqpp-dev \
                libzmqpp-dev \
                libnl-3-dev \
                libnl-genl-3-dev \
                libgps-dev \
                libsqlite3-dev \
	&& rm -r /var/lib/apt/lists/*

WORKDIR /tmp

COPY . /tmp/OpenC2X

RUN cd OpenC2X \
    && mkdir build \
    && cd build \
    && cmake ../ \
    && make

## Build the original openc2x
#RUN wget http://www.ccs-labs.org/software/openc2x/openc2x-v1.0.tar.gz \
#    && tar xfz openc2x-v1.0.tar.gz \
#    && cd OpenC2X \
#    && mkdir build \
#    && cd build \
#    && cmake ../ \
#    && make

WORKDIR /opt
