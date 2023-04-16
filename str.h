#ifndef _STR_H_
#	define _STR_H_

typedef struct {
	char *cstr;
	unsigned long length;
} str_t;

#	include "strdef.h"
#	ifndef _STR_C_
//#	warning "externing"
#		define _STR_H_EXTERN_ extern
#	else
//#	warning "skeleton"
#		define _STR_H_EXTERN_ STRDEF
#	endif /* !_STR_C_ */

_STR_H_EXTERN_ char *cstr_alloc(unsigned long);
_STR_H_EXTERN_ void cstr_free(char *);
_STR_H_EXTERN_ unsigned long cstr_length(const char *const);
_STR_H_EXTERN_ unsigned short cstr_eql(const char *const, const char *const, const unsigned long);
_STR_H_EXTERN_ unsigned short cstr_eq(const char *const, const char *const);
_STR_H_EXTERN_ unsigned short str_eql(const str_t *const, const str_t *const, const unsigned long);
_STR_H_EXTERN_ unsigned short str_eq(const str_t *const, const str_t *const);
_STR_H_EXTERN_ void copy(char *, const char *const, const unsigned long);
_STR_H_EXTERN_ void str_set(str_t *, const char *const);
_STR_H_EXTERN_ void str_copy(str_t *, const str_t *const);
_STR_H_EXTERN_ void str_copyf(str_t *, str_t *);
_STR_H_EXTERN_ str_t *str(const char *const);
_STR_H_EXTERN_ void str_free(str_t *);
_STR_H_EXTERN_ void str_cadd(str_t *, const char *const);
_STR_H_EXTERN_ void str_add(str_t *, const str_t *const);
_STR_H_EXTERN_ void str_addf(str_t *, str_t *);
_STR_H_EXTERN_ str_t *str_join(const str_t *const, const str_t *const);
_STR_H_EXTERN_ str_t *str_joinf(str_t *, str_t *);
_STR_H_EXTERN_ void str_prep(str_t *, const str_t *const);
_STR_H_EXTERN_ void str_prepf(str_t *, str_t *);
_STR_H_EXTERN_ str_t *str_lpad(const str_t *const, const unsigned long);
_STR_H_EXTERN_ str_t *str_lpadf(str_t *, const unsigned long);
_STR_H_EXTERN_ str_t *str_rpad(const str_t *const, const unsigned long);
_STR_H_EXTERN_ str_t *str_rpadf(str_t *, const unsigned long);
_STR_H_EXTERN_ str_t *str_substr(const str_t *const, const unsigned long, const unsigned long);
_STR_H_EXTERN_ str_t *str_substrf(str_t *, const unsigned long, const unsigned long);
#endif /* !_STR_H_ */
