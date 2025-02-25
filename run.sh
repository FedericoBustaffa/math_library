#!/bin/bash


if [ $# -eq 0 ]; then
	bt=Debug
else
	bt=$1
fi

cd ./build/
cmake .. -DCMAKE_BUILD_TYPE=$bt

if make; then
	cd ..
	if [ $bt == "Debug" ]; then
		valgrind -s --tool=cachegrind ./build/test $2
	else
		./build/test $2
	fi
else
	echo "compilation failed"
	exit 1
fi
