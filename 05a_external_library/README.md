## How to use an external library

Use a **`C` **compiler to compile `hello.c`. Remember to link against the `m` library.

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake /path/to/CMakeLists.txt` (e.g. `cmake ..`) 
- Compile with `make`

##### CMake useful commands

```cmake
target_link_libraries(exe_name m)

```

### Meson

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
compiler = meson.get_compiler('c')
lib_m = compiler.find_library('m')

executable('exe_name', 
			...,
			dependencies: lib_m)

```



