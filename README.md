# SGX-OpenSSL

### Overview
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
> Tested SGX SDK version: Intel SGX SDK Linux 2.5 https://github.com/01org/linux-sgx/releases/tag/sgx_2.5 <br />

<hr/>

### Usage:
1. Go to OpenSSL_SGX/ folder.
2. Run sgx_openssl_setup.sh to configure OpenSSL.
3. Type "make" then you will get "libcrypto.a" and "libssl.a".
4. Include the both static library files to your SGX application project.
5. Copy and include the wrapper codes in "Wrappers/App" and "Wrappers/Enclave" directory to your own project.
6. Implement your Makefile, EDL file, Linker script, Enclave configure file to build an SGX-enabled binary.

For the detailed usage, you can refer to the [sample codes](#running-sample-codes)

<hr/>

### Running sample codes
This project contains "Simple SSL/TLS server and client" sample codes. <br />
I hope you can get some hints from the sample applications.

1. If you did not build OpenSSL_SGX library, [build the library first](#usage).
2. Go to SampleCode/Simple_TLS_(Client or Server)/.
3. Type "make" to build SGX-enabled TLS server and client.
4. Start the TLS server at SampleCode/Simple_TLS_Server/app.
5. Start the TLS client at SampleCode/Simple_TLS_Client/app.

<hr/>

### References
1. [SGX-Tor](https://github.com/kaist-ina/SGX-Tor): Tor anonymity network in the SGX environment (NSDI'17). <br />
Paper Link: https://www.usenix.org/system/files/conference/nsdi17/nsdi17-kim-seongmin.pdf.
2. [Intel® SGX SSL](https://github.com/01org/intel-sgx-ssl).
3. SGX-Box: Enabling Visibility on Encrypted Traffic using a Secure Middlebox Module (APNet'17) <br />
Paper Link: http://conferences.sigcomm.org/events/apnet2017/papers/sgxbox-han.pdf.

### Contact
Juhyeng Han sparkly9399@gmail.com <br />
Seongmin Kim dallas1004@gmail.com
