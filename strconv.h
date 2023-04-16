#ifndef _STRCONV_H_
#	define _STRCONV_H_

#	include "str.h"
#	include "strdef.h"

#	ifndef _STRCONV_C_
#		define _STRCONV_EXTERN_ extern
#	else
#		define _STRCONV_EXTERN_ STRDEF
#	endif /* !_STRCONV_C_ */

_STRCONV_EXTERN_ unsigned long long str_to_ull(const str_t* const);
_STRCONV_EXTERN_ unsigned long str_to_ul(const str_t* const);
_STRCONV_EXTERN_ unsigned int str_to_ui(const str_t* const);
_STRCONV_EXTERN_ unsigned short str_to_us(const str_t* const);
_STRCONV_EXTERN_ long long str_to_ll(const str_t* const);
_STRCONV_EXTERN_ long str_to_l(const str_t* const);
_STRCONV_EXTERN_ int str_to_i(const str_t* const);
_STRCONV_EXTERN_ short str_to_s(const str_t* const);
_STRCONV_EXTERN_ unsigned short str_to_b(const str_t* const);

_STRCONV_EXTERN_ str_t *ull_to_str(unsigned long long);
_STRCONV_EXTERN_ str_t *ul_to_str(unsigned long);
_STRCONV_EXTERN_ str_t *ui_to_str(unsigned int);
_STRCONV_EXTERN_ str_t *us_to_str(unsigned short);
_STRCONV_EXTERN_ str_t *ll_to_str(long long);
_STRCONV_EXTERN_ str_t *l_to_str(long);
_STRCONV_EXTERN_ str_t *i_to_str(int);
_STRCONV_EXTERN_ str_t *s_to_str(short);
_STRCONV_EXTERN_ str_t *b_to_str(unsigned short);

#endif /* !_STRCONV_H_ */
