该示例尝试通过C++/CLI包装spdlog方法

引用spdlog的代码文件需要设置为非托管（否则会编译出错），因为C++/CLI不支持一些C++特性

在运行Console及UI示例时需要将spdlog和fmt的dll文件拷贝到对应项目的运行目录（从vcpkg_installed lib子目录下拷贝）

调试时UI的运行目录如下：
CSharpUI\bin\ARM64\Debug\net8.0-windows10.0.22621.0\win-arm64\AppX

Console的运行目录如下：
CSharpConsole\bin\ARM64\Debug\net8.0-windows10.0.22621.0

根据调试时的错误提示来操作