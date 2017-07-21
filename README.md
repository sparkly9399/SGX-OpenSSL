# SGX-OpenSSL

OpenSSL library for SGX application
<hr/>

### Description
This project contains modified OpenSSL codes and necessary wrapper functions to be used for SGX-enabled applications. <br />
We first ported an OpenSSL library to SGX for the [SGX-Tor project](https://www.usenix.org/system/files/conference/nsdi17/nsdi17-kim-seongmin.pdf) in 2016 and made it public as an open source at Feb 2017. <br />
Then we cleaned up the ported OpenSSL code with the newer version of OpenSSL for other SGX applications. <br />
We also referred to [Intel® SGX SSL project](https://github.com/01org/intel-sgx-ssl) after it was released. <br />
This project uses "md_rand.c" and "rand_unix.c" codes from [Intel® SGX SSL project](https://github.com/01org/intel-sgx-ssl) for generating random number safely in enclave.<br />

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

### References
1. [SGX-Tor](https://github.com/kaist-ina/SGX-Tor): Tor anonymity network in the SGX environment (NSDI'17). 
Paper Link: https://www.usenix.org/system/files/conference/nsdi17/nsdi17-kim-seongmin.pdf.
2. [Intel® SGX SSL](https://github.com/01org/intel-sgx-ssl).

### Contact
Juhyeng Han sparkly9399@gmail.com <br />
Seongmin Kim dallas1004@gmail.com