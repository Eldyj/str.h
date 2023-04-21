#ifndef _STRVEC_H_
#	define _STRVEC_H_
#	include "str.h"
#	include "strdef.h"

typedef struct {
	str_t **ptr;
	unsigned long length;
} strvec_t;

#	ifndef _STRVEC_C_
#		define _STRVEC_EXTERN_ extern
#	else
#		define _STRVEC_EXTERN_ STRDEF
#	endif /* !_STRVEC_C_ */

_STRVEC_EXTERN_ void strvec_push(strvec_t *, const str_t *const);
_STRVEC_EXTERN_ void strvec_pushf(strvec_t *, str_t *);
_STRVEC_EXTERN_ void strvec_prepend(strvec_t *, const str_t *const);
_STRVEC_EXTERN_ void strvec_prependf(strvec_t *, str_t *);
_STRVEC_EXTERN_ str_t *strvec_pop(strvec_t *);
_STRVEC_EXTERN_ str_t *strvec_get(const strvec_t *const, const unsigned long);
_STRVEC_EXTERN_ str_t *strvec_last(const strvec_t *const);
_STRVEC_EXTERN_ str_t *strvec_first(const strvec_t *const);
_STRVEC_EXTERN_ void strvec_set(strvec_t *, const str_t *const, const unsigned long);
_STRVEC_EXTERN_ void strvec_setf(strvec_t *, str_t *, const unsigned long);
_STRVEC_EXTERN_ strvec_t *strvec(const str_t *const);
_STRVEC_EXTERN_ strvec_t *strvecf(str_t *);
_STRVEC_EXTERN_ void strvec_reverse(strvec_t *);
_STRVEC_EXTERN_ void strvec_free(strvec_t *);
#endif /* !_STRVEC_H_ */
