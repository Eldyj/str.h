#include "strio.h"
#include "strvec.h"
#include "strmap.h"
#include "strconv.h"

int
main()
{
	str_t *hello = str("hello");
	str_t *world = str("world");
	strmap_t *m = strmap(hello, world);
	strmap_set(m, world, hello);
	fprintln(strmap_getf(m, world));
	fprintln(strmap_getf(m, hello));
	strmap_free(m);
}
