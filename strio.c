#ifndef _STRIO_C_
#	define _STRIO_C_

#	include <unistd.h>
#	include "strio.h"
#	include "strdef.h"

STRDEF
void
fdprint(fd, s)
	int fd;
	const str_t *const s;
{
	write(fd, s->cstr, s->length);
}

STRDEF
void
print(s)
	const str_t *const s;
{
	fdprint(1, s);
}

STRDEF
void
fdprintln(fd, s)
	int fd;
	const str_t *const s;
{
	fdprint(fd,s);
	fdprint(fd,nl);
}

STRDEF
void
println(s)
	const str_t *const s;
{
	fdprintln(1, s);
}

STRDEF
void
ffdprint(fd, s)
	const int fd;
	str_t *s;
{
	fdprint(fd, s);
	str_free(s);
}

STRDEF
void
fprint(s)
	str_t *s;
{
	ffdprint(1, s);
}

STRDEF
void
ffdprintln(fd, s)
	const int fd;
	str_t *s;
{
	ffdprint(fd, s);
	fdprint(fd, nl);
}

STRDEF
void
fprintln(s)
	str_t *s;
{
	ffdprintln(1, s);
}

STRDEF
str_t
*fdinput(fd, l)
	const int fd;
	const unsigned long l;
{
	char* s = cstr_alloc(l);
	read(fd, s, l);
	str_t *r = str(s);
	cstr_free(s);
	return r;
}

STRDEF
str_t
*input(l)
	const unsigned long l;
{
	return fdinput(1, l);
}

STRDEF
str_t
*prompt(s, l)
	const str_t *const s;
	const unsigned long l;
{
	print(s);
	str_t *s1 = input(l);
	str_t *s2 = str_rpad(s1, 1);
	str_free(s1);
	return s2;
}

STRDEF
str_t
*fprompt(s, l)
	str_t *s;
	const unsigned long l;
{
	str_t *s1 = prompt(s, l);
	str_free(s);
	return s1;
}

#	endif /* _STRIO_C_ */
