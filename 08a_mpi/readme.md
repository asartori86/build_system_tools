## How to use mpi -- brute force

The brute force approach is to use `mpicxx` as compiler

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake -DCMAKE_CXX_COMPILER=mpicxx /path/to/CMakeLists.txt` (e.g. `cmake .. -DCMAKE_CXX_COMPILER=mpicxx`) 
- Compile with `make`

### Meson

- Create a file `meson.build` with proper commands

- Populate the build directory and go there

  - you can ask to meson to create it 

    ```bash
    CXX=mpicxx meson build_meson && cd build_meson
    ```

  - or you create it and call meson from there `mkdir build_meson && cd build_meson`

    ```bash
    mkdir build_meson && cd build_meson && CXX=mpicxx meson ..
    ```

- Compile with `ninja`

