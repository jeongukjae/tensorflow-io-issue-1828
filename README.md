this is for reproducing core dump issue.

```sh
$ bazel build //:main
$ sudo sysctl -w kernel.core_pattern=core.%e.%p
$ ./bazel-bin/main
is env nullptr? 1
Segmentation fault (core dumped)
$ gdb bazel-bin/main core.main.xxx
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04.1) 9.2
...
...
Program terminated with signal SIGSEGV, Segmentation fault.
--Type <RET> for more, q to quit, c to continue without paging--
#0  __strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:65
65      ../sysdeps/x86_64/multiarch/strlen-avx2.S: No such file or directory.
(gdb) bt
#0  __strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:65
#1  0x000056338b536dfc in main ()
```
