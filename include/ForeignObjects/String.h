/*
 * String.h
 *
 *  Created on: Nov 25, 2015
 *      Author: bill
 */

#ifndef FO_STRING_H
#define FO_STRING_H

#include <stdbool.h>
#include <string.h>

#include <ForeignObjects/Class.h>

struct String_ {
    Class cls;
    char *characters;
    size_t length;
};

typedef
	struct String_
	String;

extern String *new_String(const char *s);
extern size_t sLength(const String *s);
extern String *sConcat(const String *s, const String *t);
extern String *sConcatCharArray(const String *s, const char *t);
extern bool sEquals(const String *s, const String *t);
extern bool sEqualsIgnoreCase(const String *s, const String *t);
extern int sCompareTo(const String *s, const String *t);
extern char sCharAt(const String *s, size_t index);
extern size_t sIndexOf(const String *s, const char *search);
extern char *sToCharArray(const String *s);
extern String *sToLowerCase(const String *s);
extern String *sToUpperCase(const String *s);

#ifdef FO_SHORT_NAMES
#define length(s) sLength(s);
#define concat(s,t) sConcat(s,t)
#define charAt(s,idx) sCharAt(s,idx)
#define indexOf(s,cp) sIndexOf(s,cp)
#define toCharArray(s) sToCharArray(s)
#endif

#endif /* STRING_H_ */
