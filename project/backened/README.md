说明 — 如何引入 Crow 头文件并构建

概述
- 本仓库示例使用 Crow（C++ micro web framework）。最简单的方式是使用 Crow 的 single-header（`crow_all.h`）。

两种推荐方式

A) 单头文件（最简单，跨平台）
1. 在 `backened/` 下创建 `include` 目录：

   Powershell:
   ```powershell
   New-Item -ItemType Directory -Force .\backened\include
   ```

2. 下载 single-header 到 `backened\include`：

   Powershell:
   ```powershell
   Invoke-WebRequest -Uri "https://raw.githubusercontent.com/CrowCpp/Crow/master/include/crow_all.h" -OutFile ".\backened\include\crow_all.h"
   ```

3. 在 `main.cpp` 中使用：
   #include "crow_all.h"

4. 使用 CMake 构建（PowerShell）：
   ```powershell
   cd backened
   if (-Not (Test-Path build)) { New-Item -ItemType Directory build }
   cd build
   cmake ..
   cmake --build . --config Release
   ```

B) 将 Crow 源码克隆到项目并把 `include` 路径加入到编译器（高级用法）
- git clone https://github.com/CrowCpp/Crow.git
- 在 CMake 中 add_subdirectory 或把 `Crow/include` 加到 include_directories。

注意与依赖
- Crow 使用 C++11/14/17；示例使用 C++17。
- Windows 下可能需要链接 `ws2_32`（CMakeLists 已包含）。
- 在 Linux/macOS 可能需要 pthread（CMakeLists 已处理 Threads::Threads）。

快速验证
- 下载 `crow_all.h` 后，执行上述 CMake 构建步骤。
- 运行生成的可执行文件后，通过浏览器或 curl 访问 `http://localhost:8080/api/data`。

如果需要，我可以：
- 把 `crow_all.h` 自动下载到 `backened/include` 并提交（需你确认）；
- 或者把 CMake 配置改为使用 FetchContent 自动拉取 Crow 源码并构建。
