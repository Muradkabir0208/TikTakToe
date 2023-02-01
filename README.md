# Tic Tac Toe

A multiplayer Tic Tac Toe game which can be played in a local network.

Compile using CMake or by opening the Project in CLion.

Dependencies:

- C++ 17
- SFML 2.5

## Ubuntu

- Install dependencies:

```console
sudo apt-get -y install cmake git g++ libsfml-dev
```

## Fedora

- Install dependencies:

```console
  doas dnf install SFML SFML-devel
```

## Build:

```console
mkdir build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

_also can be run using build.sh_
