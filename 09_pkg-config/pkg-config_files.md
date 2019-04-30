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
 3. **URL:** 
 4. **Version:** 
 5. **Requires** `List of packages that also have a pkg-config file, that are required by this library`
 6. **Requires.private** `List of packages that also have a pkg-config file, that are required by this library BUT ARE NOT EXPOSED TO APPLICATIONS`
 7. **Conflicts**
 8. **Cflags:** `Compilig flags`
 9. **Libs:** `Application and linking flags of required packages that do not have a .pc file`
 10. **Libs.private:** `Application and linking flags of required packages that do not have a .pc file AND ARE NOT EXPOSED TO APPLICATIONS`

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

## Example

In the repo there is an very simple example of two libraries: `libbasic` and `libcool`. This example has two goals: use `pkg-config` files and learn how to create them with `meson` or manually. 

The example is organized in the following way:

├── basic_lib
│   ├── include
│   │   ├── abs.hpp
│   │   ├── dot.hpp
│   │   ├── meson.build
│   │   ├── mult_range.hpp
│   │   └── sum_range.hpp
│   ├── meson.build
│   ├── meson_config.h.in
│   ├── meson_options.txt
│   └── src
│       ├── abs.cpp
│       ├── dot.cpp
│       ├── meson.build
│       ├── mult_range.cpp
│       └── sum_range.cpp
├── cool_lib
│   ├── include
│   │   ├── meson.build
│   │   ├── strange_mult.hpp
│   │   └── strange_sum.hpp
│   ├── meson
│   ├── meson.build
│   ├── meson_config.h.in
│   ├── meson_options.txt
│   └── src
│       ├── meson.build
│       ├── strange_mult.cpp
│       └── strange_sum.cpp
├── main.cpp

Library `libcool` depends on `libbasic` (is "built on top of it"), but the `main.cpp` function does not depend directly on `libbasic`. This way, when using shared libraries, we do not need to explicitly link the main function to the `libbasic` library, we only need the `libcool` library.

For both libraries, we generate with `meson` the pkg-config file, and they go like:

1. `pkg-config` of `libbasic`
```
prefix=<some/path>
libdir=${prefix}/lib
includedir=${prefix}/include

Name: basic
Description: Library for very basic math.
Version: 0.1.0
Libs: -L${libdir} -lbasic
Cflags: -I${includedir}
```

2. `pkg-config` of `libcool`
```
prefix=<some/path>
libdir=${prefix}/lib
includedir=${prefix}/include

other_name=my_lib
author=someone

Name: cool
Description: Library for very cool math.
Version: 0.1.1
Requires.private: basic
Libs: -L${libdir} -lcool
Cflags: -I${includedir} -O3 -Wall
```

What we see here is that `meson` puts the `libbasic` library in the private part of the "requires", and this is done because we declared this library as one of the `dependencies` of `libcool`, and by default, `meson` takes it as private unless stated differently. This makes sense and is in line with what the `requires` is for: to state packages that have a `.cp`file. 