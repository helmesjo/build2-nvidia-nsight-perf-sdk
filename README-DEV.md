# NVIDIA Nsight Perf SDK - Packaging Details

This document describes the approach applied to packaging `libnvperf` for
`build2`. In particular, this understanding will be useful when upgrading to
a new upstream version.

## Download

[`redist.build`](redist.build) downloads the SDK archive for the target
platform from `baseUrl` followed by that platform's `relativePath` in
[`manifest.json`](libnvperf/libnvperf/manifest.json). NVIDIA redirects this
URL to a short-lived download link, no developer account login is needed.
Each archive contains the files of all architectures, so the platform's
`exclude` patterns leave out the other architecture when extracting.
[`package.json`](libnvperf/libnvperf/package.json) lists the libraries and
executables that are exported from the extracted files.

## Cache directory

Downloaded archives are placed in `$out_root` by default. They are not
registered as build2 targets, so `bdep clean` leaves them untouched. Set
one of the two `dir_path` variables below to redirect them to a different
location (for example, a directory shared across multiple build
configurations):

  Variable                        Scope
  --------                        -----
  config.nvperf.cache             global: used as the default of the below
  config.libnvperf.cache          per-package

Resolution order (evaluated in `root.build` when the package is first
configured):

  1. `config.libnvperf.cache` if explicitly set, otherwise
  2. `config.nvperf.cache` if explicitly set, otherwise
  3. `$out_root` (the package output directory)

These are package configuration variables, so with `bdep init -C` pass them
after `--`:

  bdep init -C @gcc cc config.cxx=g++ -- \
    "config.nvperf.cache=/path/to/cache-dir"

## Release New Version

1. Find the new version on the
   [Nsight Perf SDK page](https://developer.nvidia.com/nsight-perf-sdk).
2. For each platform, update `relativePath` in
   [`manifest.json`](libnvperf/libnvperf/manifest.json). The archives are
   named `<YYYY_N>/NVIDIA_Nsight_Perf_SDK_<YYYY.N>_Public_Windows.zip` and
   `<YYYY_N>/NVIDIA_Nsight_Perf_SDK_<YYYY.N>_Public_Linux.tar.gz`.
3. Update `version` in [`manifest`](libnvperf/manifest). The full version
   is in the archive's `NvPerf/version.txt`.
4. List the new archives (`bsdtar -tf <archive>`) and update
   [`package.json`](libnvperf/libnvperf/package.json) and the license files
   in [`buildfile`](libnvperf/libnvperf/buildfile) for any renamed or new
   libraries, tools, or license files.
