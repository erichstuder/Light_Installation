git submodule update --init
cmake -S src -B build
cmake --build build
build/simulator
