# Hello World

## Build

```bash
# optional, cleanup the cache
# rm -rf build/

cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build build
```

## Run main

```bash
./build/hello_world
```

## Run tests

```bash
./build/foo_test
```
