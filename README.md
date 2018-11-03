# cpp-python

Example of a C++ library used in Python as a C++ extension module.

## Generate the shared library (`bitmap.so`) and the C++ application (`app.out`)

```sh
make
```

## Run the C++ application

```sh
make run
```

## C++ code formatting

Use [clang-format](https://clang.llvm.org/docs/ClangFormat.html) for code formatting.

```sh
make format
```

## C++ tests

Use [Catch](https://github.com/catchorg/Catch2) for unit tests.

```sh
make test
```

## Project documentation

Use [Doxygen](https://github.com/doxygen/doxygen) to genrarate the HTML documentation.

```sh
make docs
cd docs/html
python -m http.server
# or
google-chrome index.html
```