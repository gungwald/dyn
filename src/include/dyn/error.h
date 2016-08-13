/*
 * errors.h
 *
 *  Created on: Aug 8, 2016
 *      Author: Bill.Chatfield
 */

#ifndef DYN_ERROR_H
#define DYN_ERROR_H

#include <wchar.h>

wchar_t *getMessage(unsigned long errorCode);
void printError(const wchar_t *offendingObject, unsigned long errorCode);


#endif
