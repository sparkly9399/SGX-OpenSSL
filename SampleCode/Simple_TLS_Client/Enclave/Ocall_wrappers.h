#ifndef _OCALL_WRAPPERS_H_
#define _OCALL_WRAPPERS_H_

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <assert.h>

#include "sgx_trts.h"
#include "ssl_enclave_types.h"

#include "Enclave_t.h"

#if defined(__cplusplus)
extern "C" {
#endif

long sgx_clock(void); /* For Performance evaluation */
time_t sgx_time(time_t *timep);
struct tm *sgx_localtime(const time_t *timep);
struct tm *sgx_gmtime_r(const time_t *timep, struct tm *tmp);
int sgx_gettimeofday(struct timeval *tv);
int sgx_getsockopt(int s, int level, int optname, char *optval, int* optlen);
int sgx_setsockopt(int s, int level, int optname, const void *optval, int optlen);
int sgx_socket(int af, int type, int protocol);
int sgx_bind(int s, const struct sockaddr *addr, int addrlen);
int sgx_listen(int s, int backlog);
int sgx_connect(int s, const struct sockaddr *addr, int addrlen);
int sgx_accept(int s, struct sockaddr *addr, int *addrlen);
int sgx_shutdown(int fd, int how);
int sgx_read(int fd, void *buf, int n);
int sgx_write(int fd, const void *buf, int n);
int sgx_close(int fd);
char *sgx_getenv(const char *env);
int sgx_printf(const char *fmt, ...);
void sgx_printe(const char *fname, const char *fmt, ...);
void sgx_printl(const char *fname, const char *fmt, ...);
long sgx_rand(void);
void sgx_exit(int exit_status);
int sgx_sscanf(const char *str, const char *format, ...);
int sgxssl_read_rand(unsigned char *rand_buf, int length_in_bytes);
const unsigned short **__ctype_b_loc(void);
const int32_t **__ctype_tolower_loc(void);

#define printf sgx_printf
#define printe(fmt, ...) sgx_printe(__FUNCTION__, fmt, ##__VA_ARGS__)
#define printl(fmt, ...) sgx_printl(__FUNCTION__, fmt, ##__VA_ARGS__)
#define exit sgx_exit

#if defined(__cplusplus)
}
#endif

#endif /* !_OCALL_WRAPPERS_H_ */