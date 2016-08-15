/*
 * dyn-unit-tests.c
 *
 *  Created on: Aug 13, 2016
 *      Author: Bill
 */

#include <stdbool.h>
#include <wchar.h>
#include <assert.h>

#include <dyn/string.h>

bool test_wconcatv() {
	assert(wcscmp(wconcatv(L"abcd", L"efgh", L"ijkl", L"mnop", L"qrst", L"uvwx", L"yz", NULL), L"abcdefghijklmnopqrstuvwxyz") == 0);
	assert(wcscmp(wconcatv(L"", L"", L"", L"", NULL), L"") == 0);
	assert(wcscmp(wconcatv(NULL, L"", L"", L"", NULL), L"") == 0);
	return true;
}

int main(void) {
	test_wconcatv();
}

