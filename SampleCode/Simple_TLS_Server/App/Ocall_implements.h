#ifndef _OCALL_IMPLEMENTS_H_
#define _OCALL_IMPLEMENTS_H_

#include <stdio.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif

long ocall_sgx_clock(void); /* For Performance evaluation */
time_t ocall_sgx_time(time_t *timep, int t_len);
struct tm *ocall_sgx_localtime(const time_t *timep, int t_len);
struct tm *ocall_sgx_gmtime_r(const time_t *timep, int t_len, struct tm *tmp, int tmp_len);
int ocall_sgx_gettimeofday(void *tv, int tv_size);
int ocall_sgx_getsockopt(int s, int level, int optname, char *optval, int optval_len, int* optlen);
int ocall_sgx_setsockopt(int s, int level, int optname, const void *optval, int optlen);
int ocall_sgx_socket(int af, int type, int protocol);
int ocall_sgx_bind(int s, const void *addr, int addr_size);
int ocall_sgx_connect(int s, const void *addr, int addrlen);
int ocall_sgx_accept(int s, void *addr, int addr_size, int *addrlen);
int ocall_sgx_shutdown(int fd, int how);
int ocall_sgx_read(int fd, void *buf, int n);
int ocall_sgx_write(int fd, const void *buf, int n);
int ocall_sgx_close(int fd);
int ocall_sgx_getenv(const char *env, int envlen, char *ret_str,int ret_len);
void ocall_print_string(const char *str);

#if defined(__cplusplus)
}
#endif

#endif /* !_OCALL_IMPLEMENTS_H_ */