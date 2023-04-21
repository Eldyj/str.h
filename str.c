#ifndef _STR_C_
#	define _STR_C_

#	include "str.h"
#	include "strdef.h"
#	include <malloc.h>

STRDEF
char
*cstr_alloc(l)
	unsigned long l;
{
	return malloc(sizeof(char)*(l+1));
}

STRDEF
void
cstr_free(s)
	char *s;
{
	free(s);
}

STRDEF
unsigned long
cstr_length(s)
	const char *const s;
{
	if (!*s)
		return 0;
		
	char *p = (char*)s;

	while(*p++)
	/* VOID */;

	return (p-s) - 1;
}

STRDEF
unsigned short
cstr_eql(s1, s2, l)
	const char *const s1, *const s2;
	const unsigned long l;
{
	for (unsigned long i = 0; i < l; ++i)
		if (s1[i] != s2[i])
			return 0;

	return 1;
}

STRDEF
unsigned short
cstr_eq(s1, s2)
	const char *const s1, *const s2;
{
	if (s1 == s2)
		return 1;

	unsigned long s1l = cstr_length(s1);
	unsigned long s2l = cstr_length(s2);

	if (s1l != s2l)
		return 0;

	return cstr_eql(s1, s2, s1l);
}

STRDEF
unsigned short
str_eql(s1, s2, l)
	const str_t *const s1, *const s2;
	unsigned long l;
{
	return cstr_eql(s1->cstr, s2->cstr, l);
}

STRDEF
unsigned short
str_eq(s1, s2)
	const str_t *const s1, *const s2;
{
	if (s1->length != s2->length)
		return 0;

	return str_eql(s1, s2, s1->length);
}

STRDEF
void
copy(target, what, l)
	char *target;
	const char* const what;
	const unsigned long l;
{
	for (unsigned long i = 0; i < l; ++i)
		target[i] = what[i];
}

STRDEF
void
str_set(ts, cstr)
	str_t *ts;
	const char *const cstr;
{
	unsigned long l = cstr_length(cstr);

	char *s = cstr_alloc(l);
	copy(s,cstr,l);
	ts->length = l;

	if (ts->cstr != NULL)
		cstr_free(ts->cstr);

	ts->cstr = s;
}

STRDEF
void
str_copy(target, what)
	str_t *target;
	const str_t *const what;
{
	str_set(target, what->cstr);
}

STRDEF
void
str_copyf(target, what)
	str_t *target, *what;
{
	str_copy(target, what);
	str_free(what);
}

STRDEF
str_t
*str_dup(target)
	const str_t *const target;
{
	str_t *result = str("");
	str_copy(result, target);
	return result;
}

STRDEF
str_t
*str(cs)
	const char *const cs;
{
	str_t *r = malloc(sizeof(str_t)*1);
	r->cstr = cstr_alloc(0);
	str_set(r,cs);
	return r;
}

STRDEF
void
str_free(s)
	str_t *s;
{
	cstr_free(s->cstr);
	free(s);
}

STRDEF
char
str_get(s, i)
	const str_t *const s;
	const unsigned long i;
{
	return ((char[2]){0, s->cstr[i]})[i < s->length];
}

STRDEF
void
str_chadd(s, ch)
	str_t *s;
	const char ch;
{
	if (ch == 0)
		return;

	s->length += 1;
	s->cstr = realloc(s->cstr, s->length+1);
	s->cstr[s->length - 1] = ch;
	s->cstr[s->length] = 0;
}

/*STRDEF
void
str_cadd(s, cs)
	str_t *s;
	const char *const cs;
{
	unsigned long l = cstr_length(cs);
	s->length += l;
	s->cstr = realloc(s->cstr, sizeof(char)*(s->length+1));

	for (unsigned long i = s->length-l-1; i < s->length; ++i) {
		s->cstr[i] = cs[i - (s->length-l-1)];
	}
	// copy(s->cstr + s->length-l-1, cs, l);
	//char *p = cstr_alloc(s->length+l-2);
	//copy(p,s->cstr,s->length);
	//copy(p+s->length,cs,l);
	//str_set(s,p);
	//cstr_free(p);
}*/
/*
STRDEF
void
str_cadd(s, cstr)
	str_t *s;
	const char *const cstr;
{
	if (s == NULL || cstr == NULL)
		return;

	unsigned long len1 = s->length;
	unsigned long len2 = cstr_length(cstr);

	char *new_cstr = realloc(s->cstr, len1 + len2 + 1);

	if (new_cstr == NULL)
		return;

	s->cstr = new_cstr;

	copy(s->cstr + len1, cstr, len2);
	s->length = len1 + len2;
	s->cstr[s->length] = '\0';
}*/

STRDEF
void
str_cadd(s, cstr)
	str_t *s;
	const char *const cstr;
{
	unsigned long l = cstr_length(cstr);
	for (unsigned long i = 0;i < l; ++i) {
		if (cstr[i] == 0)
			return;
		str_chadd(s, cstr[i]);
	}
}


STRDEF
void
str_add(s1, s2)
	str_t *s1;
	const str_t *const s2;
{
	str_cadd(s1,s2->cstr);
}

STRDEF
void
str_addf(s1, s2)
	str_t *s1, *s2;
{
	str_add(s1, s2);
	str_free(s2);
}

STRDEF
str_t
*str_join(s1, s2)
	const str_t *const s1, *const s2;
{
	str_t *s = str("");
	str_copy(s,s1);
	str_add(s,s2);
	return s;
}

STRDEF
str_t
*str_joinf(s1, s2)
	str_t *s1, *s2;
{
	str_t *r = str_join(s1, s2);
	str_free(s1);
	str_free(s2);
	return r;
}

STRDEF
void
str_prep(s1, s2)
	str_t *s1;
	const str_t *const s2;
{
	str_t *s = str_dup(s1);
	str_add(s,s2);
	str_copy(s1,s);
	str_free(s);
}

STRDEF
void
str_prepf(s1, s2)
	str_t *s1, *s2;
{
	str_prep(s1, s2);
	str_free(s2);
}

STRDEF
str_t
*str_lpad(s, l)
	const str_t *const s;
	const unsigned long l;
{
	return str((s->cstr)+l);
}

STRDEF
str_t
*str_lpadf(s, l)
	str_t *s;
	const unsigned long l;
{
	str_t *r = str_lpad(s,l);
	str_free(s);
	return r;
}

STRDEF
str_t
*str_rpad(s, l)
	const str_t *const s;
	const unsigned long l;
{
	/*unsigned long fl = s->length-l;
	char *t = cstr_alloc(fl);
	copy(t,s->cstr,fl);
	str_t *r = str(t);
	cstr_free(t);
	return r;*/
	str_t *tmp = str_dup(s);
	unsigned fl = tmp->length-l;
	tmp->cstr[fl] = 0;
	str_t *result = str(tmp->cstr);
	result->length = fl+1;
	str_free(tmp);
	return result;
}

STRDEF
str_t
*str_rpadf(s, l)
	str_t *s;
	const unsigned long l;
{
	str_t *r = str_rpad(s,l);
	str_free(s);
	return r;
}

STRDEF
str_t
*str_substr(s, p1, p2)
	const str_t *const s;
	const unsigned long p1, p2;
{
	return str_lpadf(str_rpad(s,s->length-p2),p1);;
}

STRDEF
str_t
*str_substrf(s, p1, p2)
	str_t *s;
	const unsigned long p1, p2;
{
	str_t *r = str_substr(s,p1,p2);
	str_free(s);
	return r;
}

#endif /* !_STR_C_ */
