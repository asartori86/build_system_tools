## How to use mpi -- external library

`mpi` is a library, so, as for any other library, we need to tell where the headers are, where is the lib and the name of the lib itself. Both `CMake` and `meson` provide a "native" way to find an mpi implementation. Make

### CMake

Take a look at [https://cmake.org/cmake/help/v3.14/module/FindMPI.html](https://cmake.org/cmake/help/v3.14/module/FindMPI.html)

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake /path/to/CMakeLists.txt` (e.g. `cmake ..`) 
- Compile with `make`




##### CMake useful commands

```cmake

find_package(MPI)

```

### Meson

Take a look at [https://mesonbuild.com/Dependencies.html#mpi](https://mesonbuild.com/Dependencies.html#mpi)

- Create a file `meson.build` with proper commands

- Populate the build directory and go there

  - you can ask to meson to create it 

    ```bash
    meson build_meson && cd build_meson
    ```

  - or you create it and call meson from there `mkdir build_meson && cd build_meson`

    ```bash
    mkdir build_meson && cd build_meson && meson ..
    ```

- Compile with `ninja`




##### Meson useful commands

```cmake
mpi = dependency('mpi', language: 'cpp')

```



