#ifndef _STRMAP_H_
#	define _STRMAP_H_

#	include "strvec.h"
#	include "strdef.h"

typedef struct {
	strvec_t *indexes;
	strvec_t *values;
} strmap_t;

#	ifndef _STRMAP_C_
#		define _STRMAP_EXTERN_ extern
#	else
#		define _STRMAP_EXTERN_ STRDEF
#	endif /* !_STRMAP_C_ */

_STRMAP_EXTERN_ unsigned long strmap_get_index(const strmap_t *const, const str_t *const);
_STRMAP_EXTERN_ str_t *strmap_get(const strmap_t *const, const str_t *const);
_STRMAP_EXTERN_ str_t *strmap_getf(const strmap_t *const, str_t *);
_STRMAP_EXTERN_ void strmap_set(strmap_t *, const str_t *const, const str_t *const);
_STRMAP_EXTERN_ void strmap_setf(strmap_t *, str_t *, str_t *);
_STRMAP_EXTERN_ strmap_t *strmap(const str_t *const, const str_t *const);
_STRMAP_EXTERN_ strmap_t *strmapf(str_t *, str_t *);
_STRMAP_EXTERN_ void strmap_free(strmap_t *);

#endif /* !_STRMAP_H_ */
