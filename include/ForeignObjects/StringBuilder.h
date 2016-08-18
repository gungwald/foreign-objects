/*
 * String.h
 *
 *  Created on: Nov 25, 2015
 *      Author: bill
 */

#ifndef FOREIGN_OBJECTS_STRINGBUILDER_H
#define FOREIGN_OBJECTS_STRINGBUILDER_H

#include <ForeignObjects/Character.h>

struct _StringBuilder {
	FO_CHAR *characters;
	size_t capacity;
	size_t length;
};

typedef
	struct _StringBuilder
	StringBuilder;

extern StringBuilder *new_StringBuilder(size_t initialCapacity);
extern size_t sbLength(StringBuilder *s);
extern StringBuilder *sbAppend(StringBuilder *s, FO_CHAR *t);
extern FO_CHAR sbCharAt(StringBuilder *s, size_t idx);

#endif
