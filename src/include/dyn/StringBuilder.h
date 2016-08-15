/*
 * StringBuilder.h
 *
 *  Created on: Aug 14, 2016
 *      Author: Bill
 */

#ifndef INCLUDE_DYN_STRINGBUILDER_H_
#define INCLUDE_DYN_STRINGBUILDER_H_

#include <wchar.h>

struct _StringBuilder {
	wchar_t *chars;
	size_t capacity;
	size_t length;
};

typedef
		struct _StringBuilder
		StringBuilder;

extern StringBuilder *new_StringBuilder(size_t initialCapacity);
extern void init_StringBuilder(StringBuilder *sb, size_t initialCapacity);
extern void delete_StringBuilder(StringBuilder *sb);
extern StringBuilder *sbAppend(StringBuilder *sb, const wchar_t *suffix);
extern StringBuilder *sbAppendInt(StringBuilder *sb, int i);
extern StringBuilder *sbAppendStringBuilder(StringBuilder *sb, StringBuilder *suffix);
extern size_t sbLength(StringBuilder *sb);
extern size_t sbSetLength(StringBuilder *sb);
extern wchar_t sbCharAt(StringBuilder *sb, size_t index);
extern StringBuilder *deleteCharAt(StringBuilder *sb, size_t index);

#endif /* INCLUDE_DYN_STRINGBUILDER_H_ */
