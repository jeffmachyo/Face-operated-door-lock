#!/bin/bash
rm -rf out/build CMakelists.txt
cmake -S . -B out/build
make -C out/build

