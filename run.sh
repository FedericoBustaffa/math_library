#!/bin/bash

cd build/
cmake .. -DCMAKE_BUILD_TYPE=Release
make
./test $1
cd ..