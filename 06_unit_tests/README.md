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
├── subprojects <--------------------------------
│   └── gtest.wrap <-----------------------------
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
    └── unit_tests <-----------------------------
        ├── CMakeLists.txt
        ├── mathematics_01.cc
        ├── meson.build
        └── physics_01.cc

```

### gtest

You can find very nice documentation in the [repo](https://github.com/google/googletest/tree/master/googletest/docs). A recap of the basic macros is reported here

#### Basic Assertions ####

These assertions do basic true/false condition testing.

| **Fatal assertion**            | **Nonfatal assertion**         | **Verifies**         |
| :----------------------------- | :----------------------------- | :------------------- |
| `ASSERT_TRUE(`_condition_`)`;  | `EXPECT_TRUE(`_condition_`)`;  | _condition_ is true  |
| `ASSERT_FALSE(`_condition_`)`; | `EXPECT_FALSE(`_condition_`)`; | _condition_ is false |

Remember, when they fail, `ASSERT_*` yields a fatal failure and returns from the current function, while `EXPECT_*` yields a nonfatal failure, allowing the function to continue running. In either case, an assertion failure means its containing test fails.

#### Binary Comparison ####

This section describes assertions that compare two values.

| **Fatal assertion**              | **Nonfatal assertion**           | **Verifies**       |
| :------------------------------- | :------------------------------- | :----------------- |
| `ASSERT_EQ(`_val1_`, `_val2_`);` | `EXPECT_EQ(`_val1_`, `_val2_`);` | _val1_ `==` _val2_ |
| `ASSERT_NE(`_val1_`, `_val2_`);` | `EXPECT_NE(`_val1_`, `_val2_`);` | _val1_ `!=` _val2_ |
| `ASSERT_LT(`_val1_`, `_val2_`);` | `EXPECT_LT(`_val1_`, `_val2_`);` | _val1_ `<` _val2_  |
| `ASSERT_LE(`_val1_`, `_val2_`);` | `EXPECT_LE(`_val1_`, `_val2_`);` | _val1_ `<=` _val2_ |
| `ASSERT_GT(`_val1_`, `_val2_`);` | `EXPECT_GT(`_val1_`, `_val2_`);` | _val1_ `>` _val2_  |
| `ASSERT_GE(`_val1_`, `_val2_`);` | `EXPECT_GE(`_val1_`, `_val2_`);` | _val1_ `>=` _val2_ |

In the event of a failure, Google Test prints both _val1_ and _val2_.

#### Exception Assertions ####

These are for verifying that a piece of code throws (or does not throw) an exception of the given type:

| **Fatal assertion**                               | **Nonfatal assertion**                            | **Verifies**                                      |
| :------------------------------------------------ | :------------------------------------------------ | :------------------------------------------------ |
| `ASSERT_THROW(`_statement_, _exception\_type_`);` | `EXPECT_THROW(`_statement_, _exception\_type_`);` | _statement_ throws an exception of the given type |
| `ASSERT_ANY_THROW(`_statement_`);`                | `EXPECT_ANY_THROW(`_statement_`);`                | _statement_ throws an exception of any type       |
| `ASSERT_NO_THROW(`_statement_`);`                 | `EXPECT_NO_THROW(`_statement_`);`                 | _statement_ doesn't throw any exception           |

#### Floating-Point Macros ####

| **Fatal assertion**                 | **Nonfatal assertion**              | **Verifies**                             |
| :---------------------------------- | :---------------------------------- | :--------------------------------------- |
| `ASSERT_FLOAT_EQ(`_val1, val2_`);`  | `EXPECT_FLOAT_EQ(`_val1, val2_`);`  | the two `float` values are almost equal  |
| `ASSERT_DOUBLE_EQ(`_val1, val2_`);` | `EXPECT_DOUBLE_EQ(`_val1, val2_`);` | the two `double` values are almost equal |

By "almost equal", we mean the two values are within 4 ULP's from each other.

The following assertions allow you to choose the acceptable error bound:

| **Fatal assertion**                        | **Nonfatal assertion**                     | **Verifies**                                                 |
| :----------------------------------------- | :----------------------------------------- | :----------------------------------------------------------- |
| `ASSERT_NEAR(`_val1, val2, abs\_error_`);` | `EXPECT_NEAR`_(val1, val2, abs\_error_`);` | the difference between _val1_ and _val2_ doesn't exceed the given absolute error |

#### How to use it in build system tools

- There are different ways to use `gtest` with `CMake` (e.g. see [here](https://github.com/google/googletest/blob/master/googletest/docs/Pkgconfig.md)). I propose one that handle all the details by hand. 
- In `meson` is much easier to use thanks to `meson wrap`.

### CMake

- Create a file `CMakeLists.txt` (case sensitive) with proper commands

- Create a build directory and `cd` in it (e.g. `mkdir build_cmake && cd build_cmake`)

- Run `cmake /path/to/CMakeLists.txt -DVARIABLE_NAME=val` (e.g. 

  ```cmake -DGTEST_DIR=/path/to/gtest/ ..```) 

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
gtest = dependency('gtest',
                   fallback : ['gtest', 'gtest_main_dep'],  # magic of meson wrap
                   required: true)

# remember to add gtest to the depencies of the executable called in the test function
```


