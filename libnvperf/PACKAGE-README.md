# libnvperf - NVIDIA Nsight Perf SDK GPU performance metrics library

This is a `build2` package for the
[`NVIDIA Nsight Perf SDK`](https://developer.nvidia.com/nsight-perf-sdk)
C and C++ library. It provides a graphics profiling toolbox for DirectX,
Vulkan, and OpenGL that collects GPU performance metrics directly from an
application.

This package is not open source and does not contain any upstream files.
Instead, in order to "build" the exported targets it downloads the
(potentially large) SDK archive that NVIDIA provides for the target platform
and extracts the headers, the pre-built host library, and the pre-built tools
from it. Supported platforms are Windows and Linux (x86_64). The SDK is
distributed under the NVIDIA Nsight Perf SDK License and its NvPerfUtility
headers under the Apache License 2.0. Both license texts are installed with
the package.


## Usage

To start using `libnvperf` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnvperf ^2026.3.0
```

Then import the library in your `buildfile`:

```
import libs = libnvperf%lib{nvperf}
```


## Importable targets

This package provides the following importable targets:

```
lib{nvperf}
libs{nvperf_grfx_host}
exe{GpuDiag}
exe{MetricsEnumerator}
exe{Monitoring}
```

`lib{nvperf}` provides the SDK headers (`#include <nvperf_host.h>` and so
on) and the NvPerfUtility C++ headers (`#include <NvPerfInit.h>` and so on).
It is for loading the host library at runtime, which is what upstream
recommends: include the platform's `nvperf_host_impl.h` (also available as
`<windows-desktop-x64/nvperf_host_impl.h>` and
`<linux-desktop-x64/nvperf_host_impl.h>`) in one translation unit. The host
library is then found through the dynamic loader search path or the
directories passed to `NVPW_SetLibraryLoadPaths()`. Some NvPerfUtility
headers also need the headers of the graphics API they target (Direct3D,
Vulkan, OpenGL, or EGL) or of rapidyaml, Dear ImGui, or ImPlot, which this
package does not provide.

`libs{nvperf_grfx_host}` is the pre-built host library for linking against
directly, with the same headers.

`exe{GpuDiag}`, `exe{MetricsEnumerator}`, and `exe{Monitoring}` are the
pre-built SDK tools. On Linux they find `libnvperf_grfx_host.so` through
`LD_LIBRARY_PATH`, as in upstream.


## Configuration variables

This package provides the following configuration variables:

```
[dir_path] config.libnvperf.cache ?= $out_root
```

The directory used to cache the downloaded SDK archive between builds. If
`config.nvperf.cache` is specified when the package is first configured, its
value is used as the default instead.
