#!/bin/bash

BUILD_DIR="build"

if [ -d $BUILD_DIR ]; then
    rm -rf $BUILD_DIR
fi

mkdir $BUILD_DIR

(cd $BUILD_DIR && cmake .. && make && make DESTDIR=/tmp/install install )
