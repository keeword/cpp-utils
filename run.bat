@echo off

mkdir build
cd build

cmake -G "Visual Studio 15 2017" ..
cmake --build . --config Debug
ctest -C Debug -T test --output-on-failure
