# redis deom

```bash
./vcpkg install jsoncpp
```


```bash
Computing installation plan...
The following packages will be built and installed:
    jsoncpp:x64-linux@1.9.6
Detecting compiler hash for triplet x64-linux...
Compiler found: /usr/bin/c++
Restored 1 package(s) from /root/.cache/vcpkg/archives in 22.6 ms. Use --debug to see more details.
Installing 1/1 jsoncpp:x64-linux@1.9.6...
Elapsed time to handle jsoncpp:x64-linux: 976 us
jsoncpp:x64-linux package ABI: 5695a66dc34cc8b395817c7cfb6db193eccde386eb6c76660ee149853e2ab51b
Total install time: 1.18 ms
jsoncpp provides CMake targets:

  # this is heuristically generated, and may not be correct
  find_package(jsoncpp CONFIG REQUIRED)
  target_link_libraries(main PRIVATE JsonCpp::JsonCpp)

jsoncpp provides pkg-config modules:

  # A C++ library for interacting with JSON
  jsoncpp


```

```bash
./vcpkg install hiredis
```


```bash
Computing installation plan...
The following packages will be built and installed:
    hiredis:x64-linux@1.2.0
Detecting compiler hash for triplet x64-linux...

Compiler found: /usr/bin/c++
Restored 0 package(s) from /root/.cache/vcpkg/archives in 328 us. Use --debug to see more details.
Installing 1/1 hiredis:x64-linux@1.2.0...
Building hiredis:x64-linux@1.2.0...
Downloading redis-hiredis-v1.2.0.tar.gz
Successfully downloaded redis-hiredis-v1.2.0.tar.gz.
-- Extracting source /root/vcpkg/downloads/redis-hiredis-v1.2.0.tar.gz
-- Applying patch fix-timeval.patch
-- Applying patch fix-ssize_t.patch
-- Applying patch support-static.patch
-- Applying patch fix-cmake-conf-install-dir.patch
-- Using source at /root/vcpkg/buildtrees/hiredis/src/v1.2.0-a20e3254a8.clean
-- Configuring x64-linux
-- Building x64-linux-dbg
-- Building x64-linux-rel
-- Fixing pkgconfig file: /root/vcpkg/packages/hiredis_x64-linux/lib/pkgconfig/hiredis.pc
-- Fixing pkgconfig file: /root/vcpkg/packages/hiredis_x64-linux/debug/lib/pkgconfig/hiredis.pc
-- Installing: /root/vcpkg/packages/hiredis_x64-linux/share/hiredis/copyright
Downloading patchelf-0.14.5-x86_64.tar.gz
Successfully downloaded patchelf-0.14.5-x86_64.tar.gz.
-- Performing post-build validation
Stored binaries in 1 destinations in 21.2 ms.
Elapsed time to handle hiredis:x64-linux: 8.4 s
hiredis:x64-linux package ABI: 135994698453f270725c54ea0f48340326eb736fffac81432bc632b39b015d0b
Total install time: 8.4 s
hiredis provides CMake targets:

  # this is heuristically generated, and may not be correct
  find_package(hiredis CONFIG REQUIRED)
  target_link_libraries(main PRIVATE hiredis::hiredis)

hiredis provides pkg-config modules:

  # Minimalistic C client library for Redis.
  hiredis


```
