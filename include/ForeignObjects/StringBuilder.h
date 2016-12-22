/*
 * String.h
 *
 *  Created on: Nov 25, 2015
 *      Author: bill
 */

#ifndef FOREIGN_OBJECTS_STRINGBUILDER_H
#define FOREIGN_OBJECTS_STRINGBUILDER_H

#include <ForeignObjects/String.h>

struct StringBuilder_ {
	char *characters;
	size_t capacity;
	size_t length;
};

typedef
	struct StringBuilder_
	StringBuilder;

extern StringBuilder *new_StringBuilder(size_t initialCapacity);
extern size_t sbLength(StringBuilder *s);
extern StringBuilder *sbAppend(StringBuilder *s, char *t);
extern char sbCharAt(StringBuilder *s, size_t index);
extern String *sbToString(StringBuilder *s);
extern char *sbToCharArray(StringBuilder *s);

#endif
