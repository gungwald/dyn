/*
 * StringBuilder.c
 *
 *  Created on: Aug 14, 2016
 *      Author: Bill
 */

#include <string.h>
#include <malloc.h>
#include <stddef.h>	/* NULL */
#include <dyn/StringBuilder.h>

StringBuilder *new_StringBuilder(size_t initialCapacity)
{
	StringBuilder *s;

	s = (StringBuilder *) malloc(sizeof(struct _StringBuilder));
	if (s == NULL) {
		_wperror("new_StringBuilder");
	}
	else {
		s->length = 0;
		s->capacity = initialCapacity;
		s->chars = (wchar_t *) malloc(s->capacity * sizeof(wchar_t));
		if (s->chars == NULL) {
			_wperror("new_StringBuilder");
			free(s);
			s = NULL;
		}
	}
	return s;
}

void init_StringBuilder(StringBuilder *s, size_t initialCapacity)
{
	if (s != NULL) {
		s->length = 0;
		s->capacity = initialCapacity;
		s->chars = (wchar_t *) malloc(s->capacity * sizeof(wchar_t));
		if (s->chars == NULL) {
			_wperror("init_StringBuilder");
			free(s);
			s = NULL;
		}
	}
}

void delete_StringBuilder(StringBuilder *s)
{
	if (s != NULL) {
		free(s->chars);
		free(s);
	}
}


StringBuilder *sbAppend(StringBuilder *s, const wchar_t *suffix)
{
	size_t combinedLength;

	combinedLength = s->length + wcslen(suffix);
	return s;
}
StringBuilder *sbAppendInt(StringBuilder *sb, int i) {

}
StringBuilder *sbAppendStringBuilder(StringBuilder *sb, StringBuilder *suffix) {

}
size_t sbLength(StringBuilder *sb) {

}
size_t sbSetLength(StringBuilder *sb) {

}
wchar_t sbCharAt(StringBuilder *sb, size_t index) {

}
StringBuilder *deleteCharAt(StringBuilder *sb, size_t index) {

}

