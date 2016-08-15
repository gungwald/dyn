/*
 * stringconcat.h
 *
 *  Created on: Aug 8, 2016
 *      Author: Bill.Chatfield
 */

#ifndef STRINGCONCAT_H_
#define STRINGCONCAT_H_

#include <stdint.h>	/* uint32_t */
#include <wchar.h>	/* wchar_t */

extern wchar_t *wconcat2(const wchar_t *s, const wchar_t *t);
extern wchar_t *wconcat3(const wchar_t *s, const wchar_t *t, const wchar_t *u);
extern wchar_t *wconcatv(const wchar_t *s, ...);
extern wchar_t *wconcatn(size_t argCount, ...);
extern wchar_t *wconcatUInt32(const wchar_t *s, uint32_t n);


#endif /* STRINGCONCAT_H_ */
