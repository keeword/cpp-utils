@echo off

mkdir build
cd build

cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Debug
ctest -C Debug -T test --output-on-failure
