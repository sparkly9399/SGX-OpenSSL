#!/bin/bash
perl Configure -g linux-x86_64 -fPIC no-ui no-idea no-mdc2 no-rc5 no-rc4 no-ec2m no-camellia no-cast no-srp no-hw no-dso no-shared no-stdio no-afalgeng -D_FORTIFY_SOURCE=2 -DGETPID_IS_MEANINGLESS
sed -i 's/build_all: build_libs build_apps build_tests/build_all: build_libs/g' Makefile
