## pkg-config

##### Preliminaries
You can find the software at pkg-config's [page](https://www.freedesktop.org/wiki/Software/pkg-config/), and the available information regarding this topic is in [this](https://people.freedesktop.org/~dbn/pkg-config-guide.html) guide.

#### What is pkg-config's purpose?
In simple words, it is a way to provide necessary details for compiling and linking a program to a library. `pkg-config` tool is able to read specially formatted files and use that information for the compilation and linking. 

#### `pkg-config` files
These files have file extension `.pc` and have two types of statements: metadata keywords and freeform variables. 

There are little number of keywords:

 1. **Name:** `Name of library and the .pc file`
 2. **Description:** `What does the library do?`
 3. **URL** 
 4. **Version** 
 5. **Requires:** `List of packages that also have a pkg-config file, that are required by this library`
 6. **Requires.private:** `List of packages that also have a pkg-config file, that are required by this library BUT ARE NOT EXPOSED TO APPLICATIONS`
 7. **Conflicts**
 8. **Cflags:** `Compiling flags`
 9. **Libs:** `Application and linking flags of required packages that do not have a .pc file`
 10. **Libs.private** `Application and linking flags of required packages that do not have a .pc file AND ARE NOT EXPOSED TO APPLICATIONS`

The most important keywords are **Requires**, **Requires.private**, **Cflags**, **Libs** and **Libs.private**. What does *private* mean in here? If the application you are compiling depends on some library that internally depends on some other library, you don't need to link directly against the later one.

Regarding the freeform variables, they are strings and values separated by an equal sign, and they can be used later in the definition of the keywords. They just make keywords' information more readable.

#### Some commands
There are only a few commands to use with `pkg-config` and they can be seen with `pkg-config --help` or, for a more detailed explanation, `man pkg-config`. Some of the more useful commands are:
1. `--modversion` Version of the package
2. `--cflags` Preprocessor and compile flags (duplicate flags are omitted)
3. `--libs` Linking flags (duplicate flags are omitted)
4. `--exists` Prints 0 if the file is found in the `PKG_CONFIG_PATH`
5. `--static`Libraries for static linking (includes private libraries)

#### How to use it in your code?
```
c++ `pkg-config --cflags --libs PETSc` main.cpp -o main.x
```

### Compiling Recap
In order to produce an executable from some code there are four stages in the compilation procedure:
1. Preprocessing
2.  Compilation proper
3.  Assembly
4. Linking

and there is a difference if the linking is done dynamically or statically. Just in case, let's take a brief look of this. Suppose we have two libraries, one (`libA`) depending on the other (`libB`), and there is a `main.cpp` function that only depends on `libA`.
```
$ g++ -c main.cpp -I{include_dirs} -o main.o --> Construct the object file
```
```
$ g++ main.o -L{libA_dir} -lA -L{libB_dir} -lB -o main.x --> Static linking
```
```
$ export LD_LIBRARY_PATH={libA_dir}:$LD_LIBRARY_PATH
$ g++ main.o -L{libA_dir} -lA -o main.x --> Dynamic linking
``` 
And suppose the case that inside `libA_dir`and `libB_dir` there are two versions of the libraries, a static one and a shared one. In that case, the compiler will try to link with the shared one, unless we use the `-static`flag during linking.
```
$ g++ main.o -static -L{libA_dir} -lA -L{libB_dir} -lB -o main.x --> Static linking
```


## Example

In the repo there is an very simple example of three libraries: `libextra`, `libbasic` and `libcool`. This example has two goals: one, use `pkg-config` files, and two, learn how to create them with `meson` (and/or manually). 

The example is organized in the following way:

root
├── basic_lib
│   ├── include
│   │   ├── abs.hpp
│   │   ├── dot.hpp
│   │   ├── meson.build
│   │   ├── mult_range.hpp
│   │   └── sum_range.hpp
│   ├── meson.build
│   ├── meson_options.txt
│   ├── my_project_config.h.in
│   └── src
│       ├── abs.cpp
│       ├── dot.cpp
│       ├── meson.build
│       ├── mult_range.cpp
│       └── sum_range.cpp
├── cool_lib
│   ├── include
│   │   ├── max_vec.hpp
│   │   ├── meson.build
│   │   ├── min_vec.hpp
│   │   ├── strange_mult.hpp
│   │   └── strange_sum.hpp
│   ├── meson.build
│   └── src
│       ├── max_vec.cpp
│       ├── meson.build
│       ├── min_vec.cpp
│       ├── strange_mult.cpp
│       └── strange_sum.cpp
├── extra_lib
│   ├── include
│   │   ├── max.hpp
│   │   ├── meson.build
│   │   └── min.hpp
│   ├── meson.build
│   └── src
│       ├── max.cpp
│       ├── meson.build
│       └── min.cpp
├── main.cpp
└── pkg-config_files.md

Library `libcool` depends on `libbasic` and on `libextra`, but the `main.cpp` function does not depend directly on the last two. This way, when using shared libraries, we do not need to explicitly link the main function to these libraries, we only need to link against the `libcool` library.

Only the `libcool` and the `libbasic` libraries have a `.pc` file, the `libextra` does no. With this we can exemplify the usage of the `pkg-config` file variables.

##
For two of the libraries, we generate with `meson` the pkg-config file, and they go like:

1. `pkg-config` of `libbasic`
The command to create the library is `build_target` and it can create either a static or a shared library according to a flag passed during configuration. This file is the one obtained when creating a shared library.
```
prefix=/tmp/basic
libdir=${prefix}/lib
includedir=${prefix}/include

Name: basic
Description: Library for very basic math.
Version: 0.1.0
Libs: -L${libdir} -lbasic
Cflags: -I${includedir}
```

2. `pkg-config` of `libcool`
The command used in this case to create the library is `both_libraries`, so it creates a static and a shared version of the library.
```
prefix=/tmp/cool
libdir=${prefix}/lib
includedir=${prefix}/include

other_name=my_lib
author=someone

Name: cool
Description: Library for very cool math.
Version: 0.1.1
Requires.private: basic
Libs: -L${libdir} -lcool
Libs.private: /tmp/extra/lib/libextra.so
Cflags: -I${includedir} -O3 -Wall -I/tmp/extra/include
```

##
What do we observe from these files:
1. `Libs` has the library and the path to the current library
2. `Libs.private` has the library that does not have a `.pc` file
3. `Requires.private` has the `libbasic` library that has a  `.pc` file and that may be only required by the current library and not by another executable --> By default, `meson` takes the `dependencies` as private unless stated differently
4. `Cflags` has also the include directory of the `libextra` library (we had to add them MANUALLY to the `extra_cflags` keyword in the `meson` file)

##
How can we use these files to create an executable from the `main.cpp`code?
```
$ export PKG_CONFIG_PATH=/tmp/cool/lib/pkgconfig/:/tmp/basic/lib/pkgconfig
$ export /tmp/extra/lib/:/tmp/othersss/basic/lib/:/tmp/othersss/cool/lib/
$ g++ -c main.cpp `pkg-config --cflags cool` -o main.o
$ g++ main.o `pkg-config --libs cool` -o main.x
```
If we wanted to link the main function against static libraries, these files are not correct. We need the static version of the `libextra` library. We should modify the `cool.pc` file like
```
Libs.private: -L/tmp/extra/lib/ -lextra
```
and now link it with
```
$ export /tmp/cool/lib/pkgconfig/:/tmp/static_libs/basic/lib/pkgconfig
$ g++ main.o -static `pkg-config --libs --static cool` -o main.x
```