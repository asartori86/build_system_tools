## How to generate an executable from several source files organized in subfolders



```bash
$ tree -P "*.h|*.cc"
.
├── include
│   ├── constants.h
│   ├── mathematics.h
│   └── physics.h
├── main.cc
└── src
    ├── mathematics.cc
    └── physics.cc
```

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake /path/to/CMakeLists.txt` (e.g. `cmake ..`) 
- Compile with `make`

##### CMake useful commands

```cmake
cmake_minimum_required(VERSION 2.8) # mandatory

add_executable(exe_name source/file1.cc other/suource/file.cc)

include_directories(path/to/folder/with/headers)

add_definitions("-std=c++11")
```

By default `CMake` thinks a project is built in both `C` and `C++` languages. You can set the language of your project calling `project`

```cmake
project(project_name CXX)
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

```python
project('project_name', 'cpp',
         default_options : ['cpp_std=c++11']) # mandatory as first statement

inc = include_directories('path/to/folder/with/headers')

executable('exe_name', 
           ['source/file1.cc', 'other/suource/file.cc'], 
           include_directories: inc)
```



