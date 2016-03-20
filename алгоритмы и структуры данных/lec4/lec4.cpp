#include <assert.h>
#include <stdio.h>

struct RV
{
	int result;
	int error;
};

RV do_t(int x, int y){
	RV rv;
	if (x >= y)
	{
		rv.result = x - y;
	}
	else
		rv.error = 1;
	return rv;
}

int main(void)
{
	return do_t(10, 20).error;
}