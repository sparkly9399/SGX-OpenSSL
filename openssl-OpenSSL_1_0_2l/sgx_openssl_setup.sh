#!/bin/bash
SGXSSL_ROOT="`pwd`"
perl Configure linux-x86_64 -fPIC no-ui no-idea no-mdc2 no-rc5 no-rc4 no-bf no-ec2m no-camellia no-cast no-srp no-hw no-dso no-shared no-stdio no-afalgeng -D_FORTIFY_SOURCE=2 -DGETPID_IS_MEANINGLESS -g
#./config no-hw no-engine no-shared no-asm no-stdio no-dso no-ui no-dgram no-srp -fPIC no-threads -DGETPID_IS_MEANINGLESS -include$SGXSSL_ROOT/sgxssl.h -g
sed -i 's/build_all: build_libs build_apps build_tests/build_all: build_libs/g' Makefile
#./config -g no-hw no-engine no-shared no-asm no-stdio no-dso no-ui no-dgram no-srp -fPIC no-threads -DGETPID_IS_MEANINGLESS
