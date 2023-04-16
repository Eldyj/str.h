#ifndef _STRCONV_C_
#	define _STRCONV_C_

#	include "strconv.h"
#	include "strdef.h"
#	define cstr_alloc(len) cstr_alloc(len+2)

/* STRING TO TYPES CONVERTION */

STRDEF
unsigned long long
str_to_ull(s)
	const str_t *const s;
{
	unsigned long long result = 0;
	
	if (s->length > 20)
		return result;

	unsigned short i = 0;
	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	return result;
}

STRDEF
unsigned long
str_to_ul(s)
	const str_t *const s;
{
	unsigned long result = 0;
	
	if (s->length > 10)
		return result;

	unsigned short i = 0;
	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	return result;
}

STRDEF
unsigned int
str_to_ui(s)
	const str_t *const s;
{
	unsigned int result = 0;
	
	if (s->length > 5)
		return result;

	unsigned short i = 0;
	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	return result;
}

STRDEF
unsigned short
str_to_us(s)
	const str_t *const s;
{
	unsigned short result = 0;
	
	if (s->length > 3)
		return result;

	unsigned short i = 0;
	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	return result;
}

STRDEF
long long
str_to_ll(s)
	const str_t *const s;
{
	long long result = 0;
	
	if (s->length > 20)
		return result;

	unsigned short i = 0;
	unsigned short n = 0;

	if (s->cstr[0] == '-')
		n = i = 1;

	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	if (n)
		result *= -1;

	return result;
}

STRDEF
long
str_to_l(s)
	const str_t *const s;
{
	long result = 0;
	
	if (s->length > 11)
		return result;

	unsigned short i = 0;
	unsigned short n = 0;

	if (s->cstr[0] == '-')
		n = i = 1;

	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	if (n)
		result *= -1;

	return result;
}

STRDEF
int
str_to_i(s)
	const str_t *const s;
{
	long result = 0;
	
	if (s->length > 6)
		return result;

	unsigned short i = 0;
	unsigned short n = 0;

	if (s->cstr[0] == '-')
		n = i = 1;

	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	if (n)
		result *= -1;

	return result;
}

STRDEF
short
str_to_s(s)
	const str_t *const s;
{
	long result = 0;
	
	if (s->length > 4)
		return result;

	unsigned short i = 0;
	unsigned short n = 0;

	if (s->cstr[0] == '-')
		n = i = 1;

	for (; i < s->length; ++i) {
		result *= 10;
		result += s->cstr[i] - '0';
	}

	if (n)
		result *= -1;

	return result;
}

STRDEF
unsigned short
str_to_b(s)
	const str_t *const s;
{
	return str_eq(s, &((str_t){"true",4}))
		|| str_eq(s, &((str_t){"TRUE",4}))
		|| str_eq(s, &((str_t){"True",4}));
}

/* TYPES TO STRING CONVERTION */

STRDEF
str_t
*ull_to_str(ull)
	unsigned long long ull;
{
	unsigned long long ull_copy = ull;
	unsigned short len = 0;
	
	while (ull_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);
	
	while (ull) {
		cs[len] = (ull % 10) + '0';
		ull /= 10;
		--len;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*ul_to_str(ul)
	unsigned long ul;
{
	unsigned long ul_copy = ul;
	unsigned short len = 0;
	
	while (ul_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);
	
	while (ul) {
		cs[len--] = (ul % 10) + '0';
		ul /= 10;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*ui_to_str(ui)
	unsigned int ui;
{
	unsigned int ui_copy = ui;
	unsigned short len = 0;
	
	while (ui_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);
	
	while (ui) {
		cs[len--] = (ui % 10) + '0';
		ui /= 10;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*us_to_str(us)
	unsigned short us;
{
	unsigned short us_copy = us;
	unsigned short len = 0;
	
	while (us_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);
	
	while (us) {
		cs[len--] = (us % 10) + '0';
		us /= 10;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*ll_to_str(ll)
	long long ll;
{
	long long ll_copy = ll;
	unsigned short len = 0;
	
	while (ll_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);

	if (ll < 0) {
		ll *= -1;
		++len;
		cs[0] = '-';
	}
	
	while (ll) {
		cs[len--] = (ll % 10) + '0';
		ll /= 10;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*l_to_str(l)
	long l;
{
	long l_copy = l;
	unsigned short len = 0;
	
	while (l_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);

	if (l < 0) {
		l *= -1;
		++len;
		cs[0] = '-';
	}
	
	while (l) {
		cs[len--] = (l % 10) + '0';
		l /= 10;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*i_to_str(i)
	int i;
{
	int i_copy = i;
	unsigned short len = 0;
	
	while (i_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);

	if (i < 0) {
		i *= -1;
		++len;
		cs[0] = '-';
	}
	
	while (i) {
		cs[len--] = (i % 10) + '0';
		i /= 10;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*s_to_str(s)
	short s;
{
	short s_copy = s;
	unsigned short len = 0;
	
	while (s_copy /= 10)
		++len;
	
	char *cs = cstr_alloc(len);

	if (s < 0) {
		s *= -1;
		++len;
		cs[0] = '-';
	}
	
	while (s) {
		cs[len--] = (s % 10) + '0';
		s /= 10;
	}

	str_t *result = str(cs);
	cstr_free(cs);
	return result;
}

STRDEF
str_t
*b_to_str(b)
	const unsigned short b;
{
	if (b)
		return str("true");

	return str("false");
}

#undef cstr_alloc
#endif /* !_STRCONV_C_ */
