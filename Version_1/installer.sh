#!/bin/bash
cd ~/Documents/Projects/Face-operated-door-lock/Version_1
rm -rf out/build CMakelists.txt
cmake -S . -B out/build
make -C out/build

