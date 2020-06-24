## How to build (and link against to) a shared library

Let us create two shared libraries `libmathematics.so` and `libphysics.so` and link our `main.cc`  against them

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake /path/to/CMakeLists.txt` (e.g. `cmake ..`) 
- Compile with `make`

##### CMake useful commands

```cmake
add_library(name_of_the_lib SHARED src_1.cc src_2.cc)

target_link_libraries(exe name_of_the_lib)
```

In `add_library` omit the prefix `lib` in the name of the library. To define a library named `libmathematics.so` I can write

```cmake
add_libary(mathematics SHARED ...)
```


The call to `target_link_libraries` must be in the same `CMakeLists.txt` where `exe` has been defined.

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
a_lib = library('name_of_the_lib', ['src_1.cc', 'src_2.cc'],
                include_directories : inc_dirs)

executable('exe_name', 
           ['source/file1.cc', 'other/suource/file.cc'], 
           include_directories: inc,
           link_with: [a_lib])
```

`inc_dirs` and `inc` are object returned by the function `include_directories()` 

