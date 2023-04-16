#ifndef _STRIO_H_
#	define _STRIO_H_

#	include "strdef.h"
#	include "str.h"
#	define nl &((str_t) {"\n",1})

#	ifndef _STRIO_C_
//#	warning "externing"
#		define _STRIO_H_EXTERN_ extern
#	else
//#	warning "skeleton"
#		define _STRIO_H_EXTERN_ STRDEF
#	endif /* !_STRIO_C_ */

_STRIO_H_EXTERN_ void fdprint(const int, const str_t *const);
_STRIO_H_EXTERN_ void print(const str_t *const);
_STRIO_H_EXTERN_ void fdprintln(const int, const str_t *const);
_STRIO_H_EXTERN_ void println(const str_t *const);

_STRIO_H_EXTERN_ void ffdprint(const int, str_t *);
_STRIO_H_EXTERN_ void fprint(str_t *);
_STRIO_H_EXTERN_ void ffdprintln(const int, str_t *);
_STRIO_H_EXTERN_ void fprintln(str_t *);

_STRIO_H_EXTERN_ str_t *fdinput(const int, const unsigned long);
_STRIO_H_EXTERN_ str_t *input(const unsigned long);

_STRIO_H_EXTERN_ str_t *prompt(const str_t *const, const unsigned long);
_STRIO_H_EXTERN_ str_t *fprompt(str_t *, const unsigned long);
#endif /* !_STRIO_H_ */
