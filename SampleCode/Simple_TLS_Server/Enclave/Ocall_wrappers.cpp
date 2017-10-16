#include "Ocall_wrappers.h"

long sgx_clock(void)
{
	long retv;
	ocall_sgx_clock(&retv);
	return retv;
}

time_t sgx_time(time_t *timep)
{
	time_t retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_time(&retv, timep, sizeof(time_t))) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

struct tm *sgx_localtime(const time_t *timep)
{
	struct tm* retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_localtime(&retv, timep, sizeof(time_t))) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

struct tm *sgx_gmtime_r(const time_t *timep, struct tm *tmp)
{
	struct tm* retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_gmtime_r(&retv, timep, sizeof(time_t), tmp, sizeof(struct tm))) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
    
	return retv;
}

int sgx_gettimeofday(struct timeval *tv)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_gettimeofday(&retv, tv, sizeof(struct timeval))) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_getsockopt(int s, int level, int optname, char *optval, int* optlen)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_getsockopt(&retv, s, level, optname, optval, *optlen, optlen)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_setsockopt(int s, int level, int optname, const void *optval, int optlen)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_setsockopt(&retv, s, level, optname, optval, optlen)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_socket(int af, int type, int protocol)
{
		int retv;
		sgx_status_t sgx_retv;
		if((sgx_retv = ocall_sgx_socket(&retv, af, type, protocol)) != SGX_SUCCESS){
			printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
			sgx_exit(EXIT_FAILURE);
		}
		return retv;
}

int sgx_bind(int s, const struct sockaddr *addr, int addrlen)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_bind(&retv, s, addr, addrlen)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_listen(int s, int backlog)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_listen(&retv, s, backlog)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_connect(int s, const struct sockaddr *addr, int addrlen)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_connect(&retv, s, addr, addrlen)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_accept(int s, struct sockaddr *addr, int *addrlen)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_accept(&retv, s, addr, sizeof(struct sockaddr), addrlen)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	sockaddr_in *addr_in = (sockaddr_in *)addr;
	return retv;
}

int sgx_shutdown(int fd, int how)
{
	int retv;
	ocall_sgx_shutdown(&retv, fd, how);
	return retv;
}

int sgx_read(int fd, void *buf, int n)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv = ocall_sgx_read(&retv, fd, buf, n)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_write(int fd, const void *buf, int n)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv =	ocall_sgx_write(&retv, fd, buf, n)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

int sgx_close(int fd)
{
	int retv;
	sgx_status_t sgx_retv;
	if((sgx_retv =	ocall_sgx_close(&retv, fd)) != SGX_SUCCESS) {
		printf("OCALL FAILED!, Error code = %d\n", sgx_retv);
		sgx_exit(EXIT_FAILURE);
	}
	return retv;
}

char *sgx_getenv(const char *env)
{
	printf("SGXBOX: sgx_getenv: workaround\n");
	return NULL;
}

int sgx_printf(const char *fmt, ...)
{
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    ocall_print_string(buf);
}

void sgx_printe(const char *fname, const char *fmt, ...)
{
    char ebuf[BUFSIZ] = {'\0'};
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    snprintf(ebuf, sizeof(ebuf), "Error: %s failed!: %s\n", fname, buf);
    ocall_print_string(ebuf);
}

void sgx_printl(const char *fname, const char *fmt, ...)
{
    char ebuf[BUFSIZ] = {'\0'};
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    snprintf(ebuf, sizeof(ebuf), "LOG: %s: %s\n", fname, buf);
    ocall_print_string(ebuf);
}

long sgx_rand(void)
{
	long retv;
	sgx_read_rand((unsigned char*)&retv, sizeof(retv));
	return retv;
}

void sgx_exit(int exit_status)
{
	printf("sgx_exit: exit(%d) called!\n",exit_status);
	assert(0); // SGX: just for debug purpose.
	//ocall_sgx_exit(exit_status);
}

int sgx_sscanf(const char *str, const char *format, ...)
{
	int val_cnt = 0;
	va_list args;
	va_start(args, format);
	for ( ; *format != '\0'; format++) {
		if (*format == '%' && format[1] == 'd') {
			int positive;
			int value;
			int *valp;

			if (*str == '-') {
				positive = 0;
				str++;
			} else
				positive = 1;
			if (!isdigit(*str))
				break;
			value = 0;
			do {
				value = (value * 10) - (*str - '0');
				str++;
			} while (isdigit(*str));
			if (positive)
				value = -value;
			valp = va_arg(args, int *);
			val_cnt++;
			*valp = value;
			format++;
		}
		else if (*format == '%' && format[1] == 'c') {
			char value;
			char *valp;

			if (!isalpha(*str))
				break;
			value = *str;
			str++;
			valp = va_arg(args, char *);
			val_cnt++;
			*valp = value;
			format++;
		}
		else if (*format == *str) {
			str++;
		}
		else {
			break;
		}
	}
	va_end(args);
	return val_cnt;
}

int sgxssl_read_rand(unsigned char *rand_buf, int length_in_bytes)
{
	sgx_status_t ret;
	if (rand_buf == NULL ||	length_in_bytes <= 0) {
		return 1;
	}

	ret = sgx_read_rand(rand_buf, length_in_bytes);
	if (ret != SGX_SUCCESS) {
		return 1;
	}
	return 0;
}

#if __BYTE_ORDER == __BIG_ENDIAN
#define X(x) x
#else
#define X(x) (((x)/256 | (x)*256) % 65536)
#endif

static const unsigned short table[] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),
X(0x200),X(0x320),X(0x220),X(0x220),X(0x220),X(0x220),X(0x200),X(0x200),
X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),
X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),X(0x200),
X(0x160),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),
X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),
X(0x8d8),X(0x8d8),X(0x8d8),X(0x8d8),X(0x8d8),X(0x8d8),X(0x8d8),X(0x8d8),
X(0x8d8),X(0x8d8),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),
X(0x4c0),X(0x8d5),X(0x8d5),X(0x8d5),X(0x8d5),X(0x8d5),X(0x8d5),X(0x8c5),
X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),
X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),X(0x8c5),
X(0x8c5),X(0x8c5),X(0x8c5),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),
X(0x4c0),X(0x8d6),X(0x8d6),X(0x8d6),X(0x8d6),X(0x8d6),X(0x8d6),X(0x8c6),
X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),
X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),X(0x8c6),
X(0x8c6),X(0x8c6),X(0x8c6),X(0x4c0),X(0x4c0),X(0x4c0),X(0x4c0),X(0x200),
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

static const unsigned short *const ptable = table+128;

const unsigned short **__ctype_b_loc(void)
{
	return (const unsigned short **)&ptable;
}

static const int32_t table2[] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,
32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,
48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,
64,
'a','b','c','d','e','f','g','h','i','j','k','l','m',
'n','o','p','q','r','s','t','u','v','w','x','y','z',
91,92,93,94,95,96,
'a','b','c','d','e','f','g','h','i','j','k','l','m',
'n','o','p','q','r','s','t','u','v','w','x','y','z',
123,124,125,126,127,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

static const int32_t *const ptable2 = table2+128;

const int32_t **__ctype_tolower_loc(void)
{
    return (const int32_t **)&ptable2;
}