#ifndef _SSL_ENCLAVE_TYPES_
#define _SSL_ENCLAVE_TYPES_

#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef unsigned short int sa_family_t;

#define	__SOCKADDR_COMMON(sa_prefix) \
	sa_family_t sa_prefix##family

struct sockaddr
{
	__SOCKADDR_COMMON (sa_);	/* Common data: address family and length.  */
	char sa_data[14];		/* Address data.  */
};

typedef unsigned int pid_t;
typedef unsigned int uid_t;

typedef long int __suseconds_t;

struct timeval
{
	__time_t tv_sec;		/* Seconds.  */
	__suseconds_t tv_usec;	/* Microseconds.  */
};

#define	AF_INET	2

#define htons(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
#define ntohs(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
#define htonl(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))
#define ntohl(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))

typedef uint32_t in_addr_t;
#define	INADDR_ANY		((in_addr_t) 0x00000000)

typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;
struct in_addr
{
	in_addr_t s_addr;
};
#define __SOCKADDR_COMMON_SIZE	(sizeof (unsigned short int))

typedef struct sockaddr_in
{
	__SOCKADDR_COMMON (sin_);
	in_port_t sin_port;			/* Port number.  */
	struct in_addr sin_addr;		/* Internet address.  */

	/* Pad to size of `struct sockaddr'.  */
	unsigned char sin_zero[sizeof (struct sockaddr) -
			   __SOCKADDR_COMMON_SIZE -
			   sizeof (in_port_t) -
			   sizeof (struct in_addr)];
} sockaddr_in;

#define SOCK_STREAM 1
#define SOL_SOCKET	1
#define SO_REUSEADDR 2

typedef int FILE;

#if defined(__cplusplus)
}
#endif

#endif /* !_SSL_ENCLAVE_TYPES_ */



