## How to configure your project

It is often useful to enable/disable portion (libraries, sub-projects, features, dependencies) of your project. These options are handled by `cmake` or `meson` and stored in a generated header that are included to know the build configuration.  Let us add the following options to the project

- `BUILD_MATHEMATICS` compile the library `mathematics` (**enabled by default**)
- `BUILD_PHYSICS` compile the library `physics` (**enabled by default**)
- `ENABLE_TESTING` enable the tests. For the sake of simplicity, the integration tests are enables if both the `mathematics` and `physics` libraries are compiled (**disabled by default**)

```bash
$ tree -I "*md" 
.
├── CMakeLists.txt
├── include
│   ├── constants.h
│   ├── my_project_config_cmake.h.in <-----------
│   └── my_project_config_meson.h.in <-----------
├── main.cc
├── meson.build
├── meson_options.txt <--------------------------
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
│   └── gtest.wrap
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
    └── unit_tests
        ├── CMakeLists.txt
        ├── mathematics_01.cc
        ├── meson.build
        └── physics_01.cc

```

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands

- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)

- Run `cmake /path/to/CMakeLists.txt -DVARIABLE_NAME=val` (e.g. 

  ```cmake -DGTEST_DIR=/path/to/gtest/ -DENABLE_TESTING=ON ..```) 

- Compile with `make`

- Run the tests with `ctest`

- To change one option afterwards, rerun `cmake` with just the new value of the variable e.g.

  ```cmake -DBUILD_PHYSICS=OFF ..```

##### CMake useful commands

```cmake
set(customization_VERSION_MAJOR 1)
set(customization_VERSION_MINOR 0)


option(ENABLE_TESTING "Enable testing for this project" OFF)
option(BUILD_PHYSICS "Generate and use physics library" ON)

# once all the options are known
configure_file(
  "${PROJECT_SOURCE_DIR}/include/my_project_config_cmake.h.in"
  "${PROJECT_BINARY_DIR}/my_project_config.h"
  )
include_directories(${PROJECT_BINARY_DIR})

# control flow
if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()

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

  - At the **first** call, `meson` has the same syntax of `cmake`

    ``` meson -DENABLE_TESTING=true build_meson```

  - Afterwards, inside the build directory you have to call `meson configure`

    ```meson configure -DBUILD_PHYSICS=false```

- Compile with `ninja`

- Run the tests with `meson test` or `ninja test`

##### Meson useful commands

All the options must be declared in file `meson_options.txt` in the top directory with the following syntax

```cmake
option('BUILD_MATHEMATICS', type: 'boolean', value: true)
option('ENABLE_TESTING', type: 'boolean', value: false,
   description: 'Enable integration tests and unit tests. Integration tests are enabled if and only if both mathematics and phyiscs libraries are compiled.')

```

In `meson.build`

```cmake
if get_option('ENABLE_TESTING')
    subdir('tests')
endif

_cdata = configuration_data()

_cdata.set_quoted('version', meson.project_version() )

_cdata.set('BUILD_PHYSICS', get_option('BUILD_PHYSICS'))
_cdata.set('BUILD_MATHEMATICS', get_option('BUILD_MATHEMATICS'))

configure_file(output: 'my_project_config.h',
               input: 'include/my_project_config_meson.h.in',
               configuration: _cdata)

```


