README.md
====

# Generate KEYs
```shell
openssl req -x509 -newkey rsa:4096 -sha256 -nodes -keyout key.pem -out cert.pem -days 3650
```

[Original Code](https://aticleworld.com/ssl-server-client-using-openssl-in-c/)


# How to build
```shell
$ rm -rf build
$ mkdir -p build
$ cd build
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
$ make
```

[An example for <Project>Config.cmake file](https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-to-create-a-ProjectConfig.cmake-file)
