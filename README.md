# SGX-OpenSSL

OpenSSL library for SGX application
<hr/>

This project contains modified OpenSSL codes and necessary wrapper functions to be used for SGX-enabled applications. <br />

<hr/>

> Modified OpenSSL version: OpenSSL-1.0.2l https://github.com/openssl/openssl/releases/tag/OpenSSL_1_0_2l <br />
> Tested OS: ubuntu 16.04 LTS, 4.4.0 <br />
> Tested SGX SDK version: Intel SGX SDK Linux 1.8 https://github.com/01org/linux-sgx/releases/tag/sgx_1.8 <br />

<hr/>

### Usage:
1. Goto openssl-OpenSSL_1_0_2l/ folder.
2. Run sgx_openssl_setup.sh to configure OpenSSL.
3. Type "make" then you will get "libcrypto.a" and "libssl.a".
4. Include the both library files to your SGX application project.
5. Move the wrapper codes inside of "App" and "Enclave" directory and include them to your project.

<hr/>

Some codes are came from Intel® SGX SSL https://github.com/01org/intel-sgx-ssl (md_rand.c, rand_unix.c).
