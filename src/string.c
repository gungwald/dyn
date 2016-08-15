/*
 * dyn/string.c
 *
 *  Created on: Aug 8, 2016
 *      Author: Bill.Chatfield
 */

#include <stdio.h>
#include <stdarg.h>	/* va_arg, va_start */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>	/* _wperror */

#include <dyn/string.h>

/**
 * Concatenates s & t, just like the plus operator in Java. The return
 * value is malloc'd so the caller must free it.
 */
wchar_t *wconcat(const wchar_t *s, const wchar_t *t)
{
    const wchar_t *sNotNull;
    const wchar_t *tNotNull;
    wchar_t *result;
    size_t length;

    if (s == NULL) {
        sNotNull = L"";
    }
    else {
        sNotNull = s;
    }

    if (t == NULL) {
        tNotNull = L"";
    }
    else {
    	tNotNull = t;
    }

    /* Variables s & t are guaranteed to be non-NULL at this point. */
    length = wcslen(sNotNull) + wcslen(tNotNull);

    /* Calculate the exact size of the resulting string when s & t are
       concatenated, plus 1 for the string terminator character. */
    result = (wchar_t *) malloc((length + 1) * sizeof(wchar_t));

    if (result != NULL) {
        /* There is no need for special "secure" string functions because
           the size of result has already been correctly calculated so
           a buffer overrun is NOT POSSIBLE. */
        wcscpy(result, sNotNull);
        wcscat(result, tNotNull);
    }
    else {
        _wperror(L"wconcat");
    }
    return result;
}

wchar_t *wconcatn(size_t argCount, ...)
{
	va_list args;
	wchar_t *s;
	size_t totalLength = 0;
	wchar_t *result;
	size_t i;

	/* Calculate total length of result string. */
	va_start(args, argCount);
	for (i = 0; i < argCount; i++) {
		s = va_arg(args, wchar_t*);
		/* NULL input parameters are treated like an empty string and
		   therefore do not cause an error. */
		if (s != NULL) {
			totalLength += wcslen(s);
		}
	}
	va_end(args);

	result = (wchar_t *)malloc((totalLength + 1) * sizeof(wchar_t));
	if (result != NULL) {
		result[0] = '\0';
		va_start(args, argCount);
		for (i = 0; i < argCount; i++) {
			s = va_arg(args, wchar_t*);
			/* NULL arguments will be treated like empty strings and will
			   not cause an error. */
			if (s != NULL) {
				wcscat(result, s);
			}
		}
		va_end(args);
	}
	else {
		_wperror(L"wconcatn");
	}
	return result;
}

/**
 * Concatenates a list of strings terminated by a NULL character. This
 * inherently cannot differentiate between the NULL at the end and any
 * other argument that was accidentally passed as NULL.
 *
 * @arg first	The first string in the list to be included in the
 * 				resulting concatenated string. If it is NULL, the
 * 				concatenation process ends and a dynamically allocated
 * 				empty string (containing one NULL character) is
 * 				returned.
 * @return	A dynamically allocated string consisting of all arguments
 * 			or NULL if a memory allocation error occurred. The caller
 * 			must free the returned string. So, if the result is a zero
 * 			length (empty) string, it will be a dynamically allocated
 * 			array of one NULL character.
 */
wchar_t *wconcatv(const wchar_t *first, ...)
{
	va_list args;
	wchar_t *s;
	size_t totalLength;
	wchar_t *result;

	if (first == NULL) {
		result = malloc(sizeof(wchar_t));
		if (result != NULL) {
			result[0] = '\0';
		}
		else {
			_wperror(L"wconcatv");
		}
	}
	else {
		/* Calculate total length. */
		totalLength = wcslen(first);
		va_start(args, first);
		while ((s = va_arg(args, wchar_t*)) != NULL) {
			totalLength += wcslen(s);
		}
		va_end(args);

		/* Build concatenated result string. */
		result = (wchar_t *)malloc((totalLength + 1) * sizeof(wchar_t));
		if (result != NULL) {
			va_start(args, first);
			wcscpy(result, first);
			while ((s = va_arg(args, wchar_t*)) != NULL) {
				wcscat(result, s);
			}
			va_end(args);
		}
		else {
			_wperror(L"wconcatn");
		}
	}
	return result;
}

/**
 * Concatenates s & t, just like the plus operator in Java. The return
 * value is malloc'd so the caller must free it.
 */
wchar_t *wconcat3(const wchar_t *s, const wchar_t *t, const wchar_t *u)
{
    const wchar_t *sNotNull;
    const wchar_t *tNotNull;
    const wchar_t *uNotNull;
    wchar_t *result;
    size_t length;

    if (s == NULL) {
        sNotNull = L"";
    }
    else {
        sNotNull = s;
    }

    if (t == NULL) {
        tNotNull = L"";
    }
    else {
    	tNotNull = t;
    }

    if (u == NULL) {
        uNotNull = L"";
    }
    else {
    	uNotNull = t;
    }

    /* Variables s & t are guaranteed to be non-NULL at this point. */
    length = wcslen(sNotNull) + wcslen(tNotNull) + wcslen(uNotNull);

    /* Calculate the exact size of the resulting string when s & t are
       concatenated, plus 1 for the string terminator character. */
    result = (wchar_t *) malloc((length + 1) * sizeof(wchar_t));

    if (result != NULL) {
        /* There is no need for special "secure" string functions because
           the size of result has already been correctly calculated so
           a buffer overrun is NOT POSSIBLE. */
        wcscpy(result, sNotNull);
        wcscat(result, tNotNull);
        wcscat(result, uNotNull);
    }
    else {
        _wperror(L"wconcat3");
    }
    return result;
}

wchar_t *wconcatUInt32(const wchar_t *s, uint32_t n)
{
    wchar_t numbertext[32];

    /* There can be no buffer overrun because a uint32_t cannot
       exceed the number of characters in the buffer. */
    _swprintf(numbertext, L"%u", n);
    return wconcat(s, numbertext);
}
