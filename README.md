# nvidia-nsight-perf-sdk - NVIDIA Nsight Perf SDK

This is a `build2` package repository for the
[`NVIDIA Nsight Perf SDK`](https://developer.nvidia.com/nsight-perf-sdk),
a graphics profiling toolbox for DirectX, Vulkan, and OpenGL that collects
GPU performance metrics directly from an application. The package does not
contain any upstream files. Instead, it downloads the pre-built SDK that
NVIDIA provides for the target platform (Windows and Linux, x86_64), which is
also why CI builds are disabled for it.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libnvperf` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libnvperf/PACKAGE-README.md) file.

The development setup for `nvidia-nsight-perf-sdk` uses the standard `bdep`-based workflow.
For example:

```
git clone https://github.com/build2-packaging/nvidia-nsight-perf-sdk.git
cd nvidia-nsight-perf-sdk

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```

See [`README-DEV.md`](README-DEV.md) for how the SDK is downloaded and how
to update to a new SDK release.
