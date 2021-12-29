[![License](https://img.shields.io/badge/license-%20BSD--3-blue.svg)](../master/LICENSE)

This is a simplified version of [bast's gtest-demo repository]https://github.com/bast/gtest-demo)
with more focus on CMake and GoogleTest, and advanced software engineering features like code coverage and continuous integration removed.

# gtest-demo

C/C++ unit test demo using [Google Test](https://code.google.com/p/googletest).

**Note:** some tests are deliberately failing for the purpose of demonstration!

- Licensed under [BSD-3](../master/LICENSE)


## How to build this demo

```bash
git clone https://github.com/jthies/gtest-demo.git
cd gtest-demo
cmake -S. -Bbuild 
cmake --build build
```


## Running the tests

Either using `ctest` (equivalently type `make test`):
```
$ cd build
$ ctest

```
est project /home/jonas/teaching/oospc++/gtest-demo/build
    Start 1: functions.add
1/9 Test #1: functions.add ...................................   Passed    0.00 sec
    Start 2: functions.subtract
2/9 Test #2: functions.subtract ..............................   Passed    0.00 sec
    Start 3: VectorTest.add_d_d
3/9 Test #3: VectorTest.add_d_d ..............................   Passed    0.00 sec
    Start 4: VectorTest.add_d_d_buggy_test
4/9 Test #4: VectorTest.add_d_d_buggy_test ...................***Failed    0.00 sec
    Start 5: VectorTest.add_i_i
5/9 Test #5: VectorTest.add_i_i ..............................   Passed    0.00 sec
    Start 6: VectorTest.add_throws_on_length_mismatch
6/9 Test #6: VectorTest.add_throws_on_length_mismatch ........   Passed    0.00 sec
    Start 7: VectorTest.subtract_throws_on_length_mismatch
7/9 Test #7: VectorTest.subtract_throws_on_length_mismatch ...***Failed    0.00 sec
    Start 8: VectorTest.add_mixed_d_i
8/9 Test #8: VectorTest.add_mixed_d_i ........................   Passed    0.00 sec
    Start 9: VectorTest.add_mixed_i_d
9/9 Test #9: VectorTest.add_mixed_i_d ........................***Failed    0.00 sec

67% tests passed, 3 tests failed out of 9

Label Time Summary:
unit    =   0.04 sec*proc (9 tests)

Total Test time (real) =   0.04 sec

```

Or directly using `unit_tests`. This allows you to use gtest options.
Use ./bin/unit_tests --gtest_help to see all possible options.
```
$ cd build 
$ ./bin/unit_tests --gtest_filter=*mixed*

Running main() from /home/jonas/teaching/oospc++/gtest-demo/build/_deps/gtest-src/googletest/src/gtest_main.cc
Note: Google Test filter = *mixed*
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from VectorTest
[ RUN      ] VectorTest.add_mixed_d_i
[       OK ] VectorTest.add_mixed_d_i (0 ms)
[ RUN      ] VectorTest.add_mixed_i_d
/home/jonas/teaching/oospc++/gtest-demo/test/vector.cpp:86: Failure
Expected equality of these values:
  result[0]
    Which is: 2
  2.1
    Which is: 2.0999999
[  FAILED  ] VectorTest.add_mixed_i_d (0 ms)
[----------] 2 tests from VectorTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] VectorTest.add_mixed_i_d

 1 FAILED TEST

```


## Acknowledgments

- Container Travis setup thanks to [Joan Massich](https://github.com/massich).
- Clean-up in CMake code thanks to [Claus Klein](https://github.com/ClausKlein).
- Clean-up and GitHub Actions workflow: [Roberto Di Remigio](https://github.com/robertodr).
