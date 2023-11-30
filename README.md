# RayTracing

Ray tracing in a weekend

## How to Build It
RayTracing is a `c++ 23` project and currently it supports only Windows.

In order to be able to compile it, you need to first set up your workspace as follow:
* RayTracing is currently built and tested using `CMake` as build system. 
  You can download the latest version of Cmake from the official [CMake website](https://cmake.org/).
* The official supported compiler is `Visual Studio 17 2022`. 
  You can download the latest Visual Studio 2022 from the [Micorsoft website](https://visualstudio.microsoft.com/vs/).
  Alternative, it is also possible to compile using the `Clang++` compiler. You can downlod the latest `LLVM` suit from
  it's [official website](https://github.com/llvm/llvm-project/releases).
* If you choose to compile using Clang, you additionally need to install `Ninja`, that is used as CMake generator.
  You can download the [latest release](https://github.com/ninja-build/ninja/releases) and make sure to add the 
  installation directory to the system path.
* RayTracing uses `vcpkg` as package managers. 
  You can install vcpkg with the following operations on the command line on Windows:
  ```powershell
  cd C:
  git clone https://github.com/microsoft/vcpkg.git
  cd vcpkg
  .\bootstrap-vcpkg.bat
  .\vcpkg integrate install
  set VCPKG_ROOT
  ```
  Open environmental variables and verify that VCPKG_ROOT variable has been set correctly. 
  Otherwise set it manually to the vcpkg installation directory.

When the workspace is ready, RayTracing can be compiled either in Debug or Release mode, via command line
* Clone the repository
  ```powershell
  git clone https://github.com/nicoladallago/RayTracing.git
  cd RayTracing
  ```

* Compile in debug mode
  ```powershell
  cmake --preset=Debug
  cmake --build .\build\debug --config Debug
  ```

* Compile in release mode
  ```powershell
  cmake --preset=Release
  cmake --build .\build\release --config Release
  ```

* Experimentally, you can also compile in release using Clang as compiler.
  ```powershell
  cmake --preset=Release-Win64-Clang
  cmake --build .\build\release-clang --config Release
  ```