/*
 * String.h
 *
 *  Created on: Nov 25, 2015
 *      Author: bill
 */

#ifndef FOREIGN_OBJECTS_STRINGBUILDER_H
#define FOREIGN_OBJECTS_STRINGBUILDER_H

#define SB_INITIAL_CAPACITY 1024

struct StringBuilder {
	char *characters;
	size_t capacity;
	size_t length;
};

typedef
	struct StringBuilder *
	StringBuilder;

extern StringBuilder new_StringBuilder(const char *s);
extern size_t sbLength(String s);
extern StringBuilder sbAppend(StringBuilder s, String t);
extern char sbCharAt(StringBuilder s, size_t idx);

#endif
