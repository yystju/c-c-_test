README.md
====

# Description

This is a simple just for fun project in c/c++.

# Generate keys under cert folder...
```shell
openssl req -x509 -newkey rsa:4096 -sha256 -nodes -keyout key.pem -out cert.pem -days 3650
```

[The original Code of client.js and server.js](https://aticleworld.com/ssl-server-client-using-openssl-in-c/)


# Dependencies
1. boost (1.72.0)
2. openssl (1.1.1d)
3. libuv ([https://github.com/libuv/libuv.git])
4. libco ([https://github.com/Tencent/libco.git])

# How to build
```shell
$ rm -rf build
$ mkdir -p build
$ cd build
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
$ make
```

[An example for <Project>Config.cmake file](https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-to-create-a-ProjectConfig.cmake-file)

# How to develop the code under theia-cpp
[An Howto document in simplified Chinese](http://note.youdao.com/noteshare?id=f7ed15927628d72dff4350fa52d6cfe0&sub=2F06DF6168954BC5A475A99408C52CC1)
