## How to handle unit tests

In this example we make the first steps in the [Test-driven Development (TDD)](https://en.wikipedia.org/wiki/Test-driven_development). We use [google tests](https://github.com/google/googletest/) to implement the unit tests. For the sake of simplicity, the code does not use `boost` `program_options` lib.

```bash
$ tree -I "*md" 
.
├── CMakeLists.txt
├── include
│   └── constants.h
├── main.cc
├── meson.build
├── src
│   ├── CMakeLists.txt
│   ├── mathematics
│   │   ├── CMakeLists.txt
│   │   ├── mathematics.cc
│   │   ├── mathematics.h
│   │   └── meson.build
│   ├── meson.build
│   └── physics
│       ├── CMakeLists.txt
│       ├── meson.build
│       ├── physics.cc
│       └── physics.h
├── subprojects
│   └── gtest.wrap <------------------------------------------
└── tests
    ├── CMakeLists.txt
    ├── integration_tests
    │   ├── 01.input
    │   ├── 01.output
    │   ├── 02.input
    │   ├── 02.output
    │   ├── CMakeLists.txt
    │   ├── compare.sh
    │   └── meson.build
    ├── meson.build
    └── unit_tests <------------------------------------------
        ├── CMakeLists.txt
        ├── mathematics_01.cc
        ├── meson.build
        └── physics_01.cc

```

### gtest

You can find very nice documentation in the [repo](https://github.com/google/googletest/tree/master/googletest/docs). 

There are different ways to use `gtest` with `CMake` (e.g. see [here](https://github.com/google/googletest/blob/master/googletest/docs/Pkgconfig.md)). I propose one that handle all the details. by hand. 

In `meson` is much easier to use thanks to `meson wrap`.

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake /path/to/CMakeLists.txt` (e.g. `cmake ..`) 
- Compile with `make`
- Run the tests with `ctest`

##### CMake useful commands

```cmake
set(GTEST_DIR "" CACHE PATH "google test dir")

find_package(Threads REQUIRED) # gtest requires pthread

# remember to link the executable called by the test against the library ${CMAKE_THREAD_LIBS_INIT}
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

- Run the tests with `meson test` or `ninja test`

##### Meson useful commands

```cmake
gtest = dependency('gtest', main: true,
                   fallback : ['gtest', 'gtest_main_dep'],  # magic of meson wrap
                   required: true)

# remember to add gtest to the depencies of the executable called in the test function
```


