#!/bin/bash


if [ $# -lt 1 ]; then
	echo "USAGE: ./run.sh <BUILD_TYPE>"
	exit 1
fi

if [[ ! -d "build" ]]; then
	mkdir "build"
fi

cd ./build/
cmake .. -DCMAKE_BUILD_TYPE=$1

if make; then
	cd ..
	if [ $1 == "Debug" ]; then
		valgrind -s --tool=cachegrind ./build/test $2
	else
		./build/test $2
	fi
else
	echo "compilation failed"
	exit 1
fi
