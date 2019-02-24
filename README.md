# bosswestfalen::stopwatch
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/bosswestfalen/stopwatch/development/LICENSE.MIT)

`bosswestfalen::stopwatch` is a simple to use time measurement class.

It calculates the time elapsed between construction and destruction.

Depending on what you provided on construction
- the time is stored in a variable or
- a function is executed, with the time being its argument

## Build
`bosswestfalen::stopwatch` is a header only library.

The header in `src` can be used directly.

Nevertheless `cmake` can be used for testing, generating documentation, analysing the code, and installing.

### Tests
CMake flag: `-DBUILD_TESTS=ON (default) or OFF`

Two kinds of tests are generated:
- unit-tests to check correct behaviour
- compilation-tests to ensure correct template meta programming

### Demos
CMake flag: `-DBUILD_DEMOS=OFF (default) or ON`

Build a simple demo application that shows how to use `bosswestfalen::stopwatch`.

### Docs
CMake flag: `-DBUILD_DOCS=OFF (default) or ON`

Generate Doxygen documentation and store at `${CMAKE_BINARY_DIR}/docs`.

**Note:** make sure `doxygen` is installed.

### Analyse Code
CMake flag: `-DBUILD_CODEANALYSIS=OFF (default) or ON`

Analyze the code (header only) with `clang-tidy`.

**Note:** make sure `clang-tidy` is installed.

## Install
Use `cmake --build . --target install` to nstall the header to `${CMAKE_INSTALL_PREFIX}/include/bosswestfalen/stopwatch.hpp`.

## Links
- [bosswestfalen::stopwatch](https://github.com/Bosswestfalen/stopwatch)
- [clang-tidy](https://clang.llvm.org/extra/clang-tidy)
- [CMake](https://cmake.org)
- [Doxygen](http://doxygen.nl)

