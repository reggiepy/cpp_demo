# cpp deom


安装 vcpkg
```bash
git clone https://github.com/microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh
```



### 安装 Linux Developer Tools

在Linux的不同发行版中，您需要安装不同的工具包:

- Debian，Ubuntu，popOS或其他基于 Debian 的发行版:

```sh
$ sudo apt-get update
$ sudo apt-get install build-essential tar curl zip unzip
```

- CentOS

```sh
$ sudo yum install centos-release-scl
$ sudo yum install devtoolset-7
$ scl enable devtoolset-7 bash
```

对于其他的发行版，请确保已安装 g++ 6 或更新的版本。
若您希望添加特定发行版的说明，[请提交一个 PR](https://github.com/microsoft/vcpkg/pulls)!

### 安装 macOS Developer Tools

在 macOS 10.15 中，唯一需要做的是在终端中运行以下命令:

```sh
$ xcode-select --install
```

然后按照出现的窗口中的提示进行操作。

在 macOS 10.14 及先前版本中，您也需要使用 homebrew 安装 g++。
请遵循以下部分中的说明：

#### 在 macOS 10.15 之前版本中安装 GCC

此条只在您的macOS版本低于 10.15 时是必须的。
安装homebrew应当很轻松，请查阅 <brew.sh> 以获取更多信息。
为了更简便，请使用以下命令:

```sh
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```

然后，为了获取最新版本的gcc，请运行以下命令：

```sh
$ brew install gcc
```

此时，您就可以使用 bootstrap.sh 编译vcpkg了。 请参阅 [快速开始](https://blog.csdn.net/sexyluna/article/details/115280121#快速开始-unix)

### 在 CMake 中使用 vcpkg

若您希望在CMake中使用vcpkg，以下内容可能帮助您：

#### Visual Studio Code 中的 CMake Tools

将以下内容添加到您的工作区的 `settings.json` 中将使CMake Tools自动使用vcpkg中的第三方库:

```json
{
  "cmake.configureSettings": {
    "CMAKE_TOOLCHAIN_FILE": "[vcpkg root]/scripts/buildsystems/vcpkg.cmake"
  }
}
```

#### Visual Studio CMake 工程中使用 vcpkg

打开CMake设置选项，将 vcpkg toolchain 文件路径在 `CMake toolchain file` 中：

```
[vcpkg root]/scripts/buildsystems/vcpkg.cmake
```

#### [CLion](https://so.csdn.net/so/search?q=CLion&spm=1001.2101.3001.7020) 中使用 vcpkg

打开 Toolchains 设置
(File > Settings on Windows and Linux, CLion > Preferences on macOS)，
并打开 CMake 设置 (Build, Execution, Deployment > CMake)。
最后在 `CMake options` 中添加以下行:

```
-DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake
```

遗憾的是，您必须手动将此选项加入每个项目配置文件中。

#### 将 vcpkg 作为一个子模块

当您希望将vcpkg作为一个子模块加入到您的工程中时，
您可以在第一个 `project()` 调用之前将以下内容添加到 CMakeLists.txt 中，
而无需将 `CMAKE_TOOLCHAIN_FILE` 传递给cmake调用。

```cmake
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")
```

使用此种方式可无需设置 `CMAKE_TOOLCHAIN_FILE` 即可使用vcpkg，且更容易完成配置工作。

## Tab补全/[自动补全](https://so.csdn.net/so/search?q=自动补全&spm=1001.2101.3001.7020)

`vcpkg` 支持命令，包名称，以及 Powershell 和 Bash 中的选项。
若您需要在指定的 shell 中启用Tab补全功能，请依据您使用的shell运行：

```pwsh
> .\vcpkg integrate powershell
```

或

```sh
$ ./vcpkg integrate bash
```

然后重新启动控制台。

### 示例

请查看 [文档](https://blog.csdn.net/sexyluna/article/details/docs/README.md) 获取具体示例，
其包含 [安装并使用包](https://blog.csdn.net/sexyluna/article/details/docs/examples/installing-and-using-packages.md)，
[使用压缩文件添加包](https://blog.csdn.net/sexyluna/article/details/docs/examples/packaging-zipfiles.md)
和 [从GitHub源中添加一个包](https://blog.csdn.net/sexyluna/article/details/docs/examples/packaging-github-repos.md)。

我们的文档现在也可以从 [ReadTheDocs](https://vcpkg.readthedocs.io/) 在线获取。

观看4分钟 [demo视频](https://www.youtube.com/watch?v=y41WFKbQFTw)。

### 贡献者

Vcpkg是一个开源项目，并通过您的贡献不断发展。
下面是一些您可以贡献的方式:

- [提交一个关于vcpkg或已支持包的新issue](https://github.com/microsoft/vcpkg/issues/new/choose)
- [提交修复PR和创建新包](https://github.com/microsoft/vcpkg/pulls)
