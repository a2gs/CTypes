#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <float.h>
#include <sys/types.h>


/* ver tb:
 * getrlimit()
 */

char * endian(void)
{
	union{
		short s;
		char  c[sizeof(short)];
	}un;

	un.s = 0x0102;

	if(sizeof(short) == 2){
		if      (un.c[0] == 1 && un.c[1] == 2) return("big-endian");
		else if (un.c[0] == 2 && un.c[1] == 1) return("little-endian");
		else                                   return("unknown");
	}

	return(NULL);
}

int main(int argc, char *argv[])
{
	/*
	https://en.wikipedia.org/wiki/C_data_types

	Properties of integer types

		CHAR_BIT	size of the char type in bits (at least 8 bits)
		SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN(C99)	minimum possible value of signed integer types: signed char, signed short, signed int, signed long, signed long long
		SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX(C99)	maximum possible value of signed integer types: signed char, signed short, signed int, signed long, signed long long
		UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX(C99)	maximum possible value of unsigned integer types: unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long
		CHAR_MIN	minimum possible value of char
		CHAR_MAX	maximum possible value of char
		MB_LEN_MAX	maximum number of bytes in a multibyte character

	Properties of floating-point types

		FLT_MIN, DBL_MIN, LDBL_MIN	minimum normalized positive value of float, double, long double respectively
		FLT_TRUE_MIN, DBL_TRUE_MIN, LDBL_TRUE_MIN (C11)	minimum positive value of float, double, long double respectively
		FLT_MAX, DBL_MAX, LDBL_MAX	maximum finite value of float, double, long double, respectively
		FLT_ROUNDS	rounding mode for floating-point operations
		FLT_EVAL_METHOD (C99)	evaluation method of expressions involving different floating-point types
		FLT_RADIX	radix of the exponent in the floating-point types
		FLT_DIG, DBL_DIG, LDBL_DIG	number of decimal digits that can be represented without losing precision by float, double, long double, respectively
		FLT_EPSILON, DBL_EPSILON, LDBL_EPSILON	difference between 1.0 and the next representable value of float, double, long double, respectively
		FLT_MANT_DIG, DBL_MANT_DIG, LDBL_MANT_DIG	number of FLT_RADIX-base digits in the floating-point significand for types float, double, long double, respectively
		FLT_MIN_EXP, DBL_MIN_EXP, LDBL_MIN_EXP	minimum negative integer such that FLT_RADIX raised to a power one less than that number is a normalized float, double, long double, respectively
		FLT_MIN_10_EXP, DBL_MIN_10_EXP, LDBL_MIN_10_EXP	minimum negative integer such that 10 raised to that power is a normalized float, double, long double, respectively
		FLT_MAX_EXP, DBL_MAX_EXP, LDBL_MAX_EXP	maximum positive integer such that FLT_RADIX raised to a power one less than that number is a normalized float, double, long double, respectively
		FLT_MAX_10_EXP, DBL_MAX_10_EXP, LDBL_MAX_10_EXP	maximum positive integer such that 10 raised to that power is a normalized float, double, long double, respectively
		DECIMAL_DIG (C99)	minimum number of decimal digits such that any number of the widest supported floating-point type can be represented in decimal with a precision of DECIMAL_DIG digits and read back in the original floating-point type without changing its value. DECIMAL_DIG is at least 10.
	 */

	printf("Machine type: %s. Word size: %d bits\n\n", endian(), __WORDSIZE);

	printf("Pointer size: %ld bytes (intptr_t/uintptr_t: Signed/Unsigned integral type large enough to hold any pointer).\n", sizeof(void *));
	printf("size_t size: %ld bytes.\n\n", sizeof(size_t));

	printf("time_t size: %ld bytes.\n", sizeof(time_t));
	printf("off_t size: %ld bytes.\n\n", sizeof(off_t));

	printf("char size: %ld bytes. Limits: [%d, %d]\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("unsigned char size: %ld bytes. Limits: [0, %u]\n\n", sizeof(unsigned char), UCHAR_MAX);

	printf("int size: %ld bytes. Limits: [%d, %d] (int16_t, int32_t, int64_t)\n", sizeof(int), INT_MIN, INT_MAX);
	printf("unsigned int size: %ld bytes. Limits: [0, %u] (uint16_t, uint32_t, uint64_t)\n\n", sizeof(unsigned int), UINT_MAX);

	printf("short size: %ld bytes. Limits: [%hd, %hd]\n", sizeof(short), SHRT_MIN, SHRT_MAX);
	printf("unsigned short size: %ld bytes. Limits: [0, %hu]\n\n", sizeof(unsigned short), USHRT_MAX);

	printf("long size: %ld bytes. Limits: [%li, %li]\n", sizeof(long), LONG_MIN, LONG_MAX);
	printf("unsigned long size: %ld bytes. Limits: [0, %lu]\n\n", sizeof(unsigned long), ULONG_MAX);

	printf("long long size: %ld bytes. Limits: [%lli, %lli]\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
	printf("unsigned long long size: %ld bytes. Limits: [0, %llu]\n\n", sizeof(unsigned long long), ULLONG_MAX);

	printf("float size: %ld bytes. Limits: [%.20e, %.20e]. Number of digits in the number: [%d]\n\n", sizeof(float), FLT_MIN, FLT_MAX, FLT_MANT_DIG);

	printf("double size: %ld bytes. Limits: [%.20le, %.20le]. Number of digits in the number: [%d]\n\n", sizeof(double), DBL_MIN, DBL_MAX, DBL_MANT_DIG);

	printf("long double size: %ld bytes. Limits: [%.20Le, %.20Le]. Number of digits in the number: [%d]\n\n", sizeof(long double), LDBL_MIN, LDBL_MAX, LDBL_MANT_DIG);

	printf("Default settings compilation (see feature_test_macros(7)):\n");
	
	#ifdef _POSIX_SOURCE
		printf("_POSIX_SOURCE defined\n");
	#endif

	#ifdef _POSIX_C_SOURCE
		printf("_POSIX_C_SOURCE defined: %ldL\n", (long) _POSIX_C_SOURCE);
	#endif

	#ifdef _ISOC99_SOURCE
		printf("_ISOC99_SOURCE defined\n");
	#endif

	#ifdef _ISOC11_SOURCE
		printf("_ISOC11_SOURCE defined\n");
	#endif

	#ifdef _XOPEN_SOURCE
		printf("_XOPEN_SOURCE defined: %d\n", _XOPEN_SOURCE);
	#endif

	#ifdef _XOPEN_SOURCE_EXTENDED
		printf("_XOPEN_SOURCE_EXTENDED defined\n");
	#endif

	#ifdef _LARGEFILE64_SOURCE
		printf("_LARGEFILE64_SOURCE defined\n");
	#endif

	#ifdef _FILE_OFFSET_BITS
		printf("_FILE_OFFSET_BITS defined: %d\n", _FILE_OFFSET_BITS); /* api de LOG !!!!! */
	#endif

	#ifdef _BSD_SOURCE
		printf("_BSD_SOURCE defined\n");
	#endif

	#ifdef _SVID_SOURCE
		printf("_SVID_SOURCE defined\n");
	#endif

	#ifdef _DEFAULT_SOURCE
		printf("_DEFAULT_SOURCE defined\n");
	#endif

	#ifdef _ATFILE_SOURCE
		printf("_ATFILE_SOURCE defined\n");
	#endif

	#ifdef _GNU_SOURCE
		printf("_GNU_SOURCE defined\n");
	#endif

	#ifdef _REENTRANT
		printf("_REENTRANT defined\n");
	#endif

	#ifdef _THREAD_SAFE
		printf("_THREAD_SAFE defined\n");
	#endif

	#ifdef _FORTIFY_SOURCE
		printf("_FORTIFY_SOURCE defined\n");
	#endif
	
	return(0);
}
