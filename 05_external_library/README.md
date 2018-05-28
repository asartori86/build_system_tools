## Find and use an external library

We change the main such that it can read command line options exploiting the library `program_options` of `boost`  as follows

```bash
$ ./exe -h
Allowed options:
  --radius arg (=0)     radius of the circle.
  --distance arg (=1)   distance between the charges.
  -h [ --help ]         print this message.

$ ./exe --help
Allowed options:
  --radius arg (=0)     radius of the circle.
  --distance arg (=1)   distance between the charges.
  -h [ --help ]         print this message.

$ ./exe 
area of a circle 0
perimeter of a circle 0
Coulomb's force 2.30656e-28

$ ./exe --radius 1.1
area of a circle 3.80133
perimeter of a circle 6.9115
Coulomb's force 2.30656e-28

$ ./exe --alberto
unrecognised option '--alberto'
Allowed options:
  --radius arg (=0)     radius of the circle.
  --distance arg (=1)   distance between the charges.
  -h [ --help ]         print this message.
```

To do so, we need to find the library `program_options` and link against it.

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands
- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)
- Run `cmake /path/to/CMakeLists.txt` (e.g. `cmake ..`) 
- Compile with `make`

##### CMake useful commands

```cmake
# FindBoost.cmake is known
find_package(Boost COMPONENTS program_options REQUIRED)
```

If `FindBoost.cmake` were not known you would proceed as follows

```cmake
find_path(BOOST_INCLUDE_DIR program_options.hpp
  PATH_SUFFIXES boost
  /usr/include
  /usr/local/include
  /whatever/path/you/should/look
  )

find_library(BOOST_LIBRARY
  NAMES boost_program_options
  PATHS /usr/lib64 /usr /non/standard/paths
  )
 
target_link_libraries(target_name ${BOOST_LIBRARY})
target_include_directories(target_name PRIVATE ${BOOST_INCLUDE_DIR})
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
boost_dep = dependency('boost', modules : 'program_options')
```

If `meson` didn't know how to find a library, you have two scenarios.

1. The library you are looking for is shipped with a `.pc` file (`pkg-config` files)

```bash
# make sure you have the path of where .pc files are located in PKG_CONFIG_PATH
$ export PKG_CONFIG_PATH=/path/to/pkgconfig/dir:$PKG_CONFIG_PATH
```

and then you can simply use `dependency` in your `meson.build` file.

2.  It is a plain collection of headers and `libname.so`. You follow an approach similar to `cmake` but with different functions

```cmake
cxx = meson.get_compiler('cpp')
boost_dep = cxx.find_library('boost_program_options', dirs: ['/wherever'])

if not cxx.has_header('boost/program_options.hpp')
  found = false
  foreach _i : ['/usr/local/include', '/usr/include','/whatever/']
    _iarg = '-I'+_i
    if not found and cxx.has_header('boost/program_options.hpp', args: [_iarg])
      add_global_arguments(_iarg, language: 'cpp')
      found = true
    endif
  endforeach
endif

```





