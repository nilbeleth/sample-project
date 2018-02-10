# simple-project

![Build Status](https://travis-ci.org/nilbeleth/cleanCppProject.svg?branch=master)

This is a "Hello world!!!" project in C++, which should serve as a cornerstone for any new project.

## Features

 * General direcotry structure common to C++ projects
 * Modern, simple CMake build scripts, divided into several components for readability
 * Sane and simple targets for most basic build actions or more advanced for supplemental code analysis
 * Integration tests via **TODO**
 * Unit tests via **TODO** (Catch, GoogleTests)
 * Coverage???
 * Documentation generation via Doxygen (code + wiki + UML diagrams with Graphciz and PlanUML)
 * Static analysis support (clang-tidy, cppcheck)
 * ...

## How to convert this to you own project

~~~
git clone https://github.com/nilbeleth/simple-demo.git <yourNewProject>
cd <yourNewProject>
mv .git .git-simple-demo
git init
git add .
git commit -a "Initial commit"
~~~

## Building instructions

### Prerequisites

 * CMake 2.8 and newer
 * Compiler with support for C++17
 * [Optional] git - for downloading external sources
 * [Optional] Doxygen
 * [Optional] clang-tools
 * [Optional] cppcheck

### Build on Linux & MacOS

~~~
mkdir build; cd build
cmake -DCMAKE_INSTALL_PREFIX[=path_to_install_dir] ..
make
~~~

### Build on Windows


### Targets

*Note:* Availability of some target depends on availability of certain prerequisites (e.g. clang-format for *format* target)

* Build
    * *all*     -
    * *clean*   -
    * *install* - install binaries into *CMAKE_INSTALL_PREFIX*
    * *run*     - build, install and run the project binary
* Testing
    * *testAll*
* Releases
    * *package*
* Miscellaneous
    * *doc*
    * *format*
* Static analysis
    * *tidy*
    * *cppcheck*
* External
