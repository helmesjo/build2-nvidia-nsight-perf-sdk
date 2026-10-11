# nvidia-nsight-perf-sdk - <SUMMARY>

This is a `build2` package repository for [`nvidia-nsight-perf-sdk`](https://<UPSTREAM-URL>),
a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`nvidia-nsight-perf-sdk` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](<PACKAGE>/PACKAGE-README.md) file.

The development setup for `nvidia-nsight-perf-sdk` uses the standard `bdep`-based workflow.
For example:

```
git clone .../nvidia-nsight-perf-sdk.git
cd nvidia-nsight-perf-sdk

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
