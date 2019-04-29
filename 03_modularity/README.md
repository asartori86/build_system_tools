## How to organize the project

Let us organize our project such that each shared library has its own folder to improve the modularity of the code

```bash
$ tree -P "*.h|*.cc"
.
├── include
│   └── constants.h
├── main.cc
└── src
    ├── mathematics
    │   ├── mathematics.cc
    │   └── mathematics.h
    └── physics
        ├── physics.cc
        └── physics.h
```

For each "module" we create a `CMakeLists.txt` and `meson.build`. The
`CMakeLists.txt` and `meson.build` in the top directory will call all
the other `CMakeLists.txt`s and `meson.build`s, respectively.

```bash
$ tree -I "*md"
.
├── CMakeLists.txt 
├── include
│   └── constants.h
├── main.cc
├── meson.build 
└── src
    ├── CMakeLists.txt <-------------------------
    ├── mathematics
    │   ├── CMakeLists.txt <---------------------
    │   ├── mathematics.cc
    │   ├── mathematics.h
    │   └── meson.build <------------------------
    ├── meson.build <----------------------------
    └── physics
        ├── CMakeLists.txt <---------------------
        ├── meson.build <------------------------
        ├── physics.cc
        └── physics.h

```

Remember that both the libraries include the header `constants.h`, so, when you compile them, they need to know where to find it.


### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake /path/to/CMakeLists.txt` (e.g. `cmake ..`) 
- Compile with `make`

##### CMake useful commands

```cmake
add_subdirectory(dir_name)

set_property(TARGET mathematics APPEND PROPERTY
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
```

Since the header of the library `mathematics` are in a non-default path, we tell to everybody who will link against the lib where to find the headers. 

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
subdir('dir_name')

a_dep = declare_dependency(include_directories: inc_dirs,
                          link_with: a_lib)
```
We define a dependency where we set the library and where to find the headers

```cmake
executable('exe_name', 
           ['source/file1.cc', 'other/suource/file.cc'], 
           include_directories: inc,
           dependencies: [a_dep, another_dep])
```
A dependency created by means of the function `declare_dependency`, as well as the external dependencies, are listed with the keyword `dependencies`.



