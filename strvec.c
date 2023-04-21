#ifndef _STRVEC_C_
#	define _STRVEC_C_

#	include "strvec.h"
#	include "strdef.h"
#	include <malloc.h>

STRDEF
void
strvec_push(v, s)
	strvec_t *v;
	const str_t *const s;
{
	v->length += 1;
	v->ptr = realloc(v->ptr, sizeof(str_t *) * v->length);
	v->ptr[v->length-1] = str("");
	str_copy(v->ptr[v->length-1], s);
}

STRDEF
void
strvec_pushf(v, s)
	strvec_t *v;
	str_t *s;
{
	strvec_push(v, s);
	str_free(s);
}

STRDEF
void
strvec_prepend(v, s)
	strvec_t *v;
	const str_t *const s;
{
	if (v == NULL || s == NULL)
		return;
  
	unsigned long i = v->length++;
	v->ptr = realloc(v->ptr, v->length * sizeof(str_t*));
  
	while (i > 0) {
		strvec_set(v, strvec_get(v, i - 1), i);
		i--;
	}
  
	strvec_set(v, s, 0);
}

STRDEF
void
strvec_prependf(v, s)
	strvec_t *v;
	str_t *s;
{
	strvec_prepend(v, s);
	str_free(s);
}

STRDEF
str_t
*strvec_pop(v)
	strvec_t *v;
{
	str_t *tmp = str("");
	
	v->length -= 1;
	str_copy(tmp, v->ptr[v->length]);
	str_free(v->ptr[v->length]);
	v->ptr = realloc(v->ptr, sizeof(str_t *) * v->length);

	return tmp;
}

STRDEF
str_t
*strvec_get(v, i)
	const strvec_t *const v;
	const unsigned long i;
{
	str_t* tmp = str("");
	
	if (i >= v->length)
		return tmp;
		
	str_copy(tmp, v->ptr[i]);
	return tmp;
}

STRDEF
str_t
*strvec_last(v)
	const strvec_t *const v;
{
	return strvec_get(v, v->length - 1);
}

STRDEF
str_t
*strvec_first(v)
	const strvec_t *const v;
{
	return strvec_get(v, 0);
}

STRDEF
void
strvec_set(v,s,i)
	strvec_t *v;
	const str_t *const s;
	const unsigned long i;
{
	if (i >= v->length)
		return;

	str_copy(v->ptr[i], s);
}

STRDEF
void
strvec_setf(v,s,i)
	strvec_t *v;
	str_t *s;
	const unsigned long i;
{
	strvec_set(v,s,i);
	str_free(s);
}

STRDEF
strvec_t
*strvec(init)
	const str_t *const init;
{
	strvec_t *r = malloc(sizeof(strvec_t)*1);
	
	r->ptr = malloc(sizeof(str_t *) * 1);
	r->ptr[0] = str("");
	r->length = 1;
	str_copy(r->ptr[0], init);
	
	return r;
}

STRDEF
strvec_t
*strvecf(init)
	str_t *init;
{
	strvec_t *v = strvec(init);
	str_free(init);
	return v;
}

STRDEF
void
strvec_reverse(v)
	strvec_t* v;
{
	if (v == NULL || !v->length)
		return;
  
	unsigned long i = 0;
	unsigned long j = v->length - 1;
	str_t* s;
  
	while (i < j) {
		s = strvec_get(v, i);
		strvec_set(v, strvec_get(v, j), i++);
		strvec_set(v, s, j--);
	}
}

STRDEF
strvec_t
*strvec_dup(v)
	const strvec_t *const v;
{
	strvec_t *r = strvecf(strvec_first(v));
	
	for (unsigned long i = 1; i < v->length; ++i)
		strvec_push(r, strvec_get(v, i));

	return r;
}

STRDEF
void
strvec_free(v)
	strvec_t *v;
{
	while(v->length)
		str_free(strvec_pop(v));

	free(v);
}

#endif /* !_STRVEC_C_ */
