#ifndef _STRMAP_C_
#	define _STRMAP_C_

#	include "strmap.h"
#	include "strdef.h"
#	include <malloc.h>

STRDEF
unsigned long
strmap_get_index(m, mi)
	const strmap_t *const m;
	const str_t *const mi;
{
	str_t *tmp;

	for (unsigned long i = 0; i < m->indexes->length; ++i) {
		tmp = strvec_get(m->indexes, i);
		
		if (str_eq(mi, tmp)) {
			str_free(tmp);
			return i;
		}
		
		str_free(tmp);
	}
	
	return m->indexes->length + 1;
}

STRDEF
str_t
*strmap_get(m, mi)
	const strmap_t *const m;
	const str_t *const mi;
{
	unsigned long index = strmap_get_index(m, mi);
	
	if (index == m->indexes->length+1)
		return str("");

	return strvec_get(m->values, index);
}

STRDEF
str_t
*strmap_getf(m, i)
	const strmap_t *const m;
	str_t *i;
{
	str_t *s = strmap_get(m, i);
	str_free(i);
	return s;
}

STRDEF
void
strmap_set(m, i, v)
	strmap_t *m;
	const str_t *const i, *const v;
{
	unsigned long index = strmap_get_index(m, i);

	if (index != m->indexes->length+1) {
		strvec_set(m->values, v, index);
		return;
	}

	strvec_push(m->indexes, i);
	strvec_push(m->values, v);
}

STRDEF
void
strmap_setf(m, i, v)
	strmap_t *m;
	str_t *i, *v;
{
	strmap_set(m, i, v);
	str_free(i);
	str_free(v);
}

STRDEF
strmap_t
*strmap(i, v)
	const str_t *const i, *const v;
{
	strmap_t *r = malloc(sizeof(strmap_t) * 1);
	r->indexes = strvec(i);
	r->values  = strvec(v);
	return r;
}

STRDEF
strmap_t
*strmapf(i, v)
	str_t *i, *v;
{
	strmap_t *m = strmap(i, v);
	str_free(i);
	str_free(v);
	return m;
}

STRDEF
void
strmap_free(m)
	strmap_t *m;
{
	strvec_free(m->indexes);
	strvec_free(m->values);
	free(m);
}

#endif /* !_STRMAP_C_ */
