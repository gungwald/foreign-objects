/*
 * String.h
 *
 *  Created on: Nov 25, 2015
 *      Author: bill
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

#include <ForeignObjects/Class.h>

struct String {
	Class cls;
	wchar_t *characters;
    size_t length;
};

typedef
	struct String *
	String;

extern String new_String(const wchar_t *s);
extern size_t sLength(const String s);
extern String sConcat(const String s, const String t);
extern String sConcatCharArray(const String s, const wchar_t *t);
extern bool sEquals(const String s, const String t);
extern bool sEqualsIgnoreCase(const String s, const String t);
extern int sCompareTo(const String s, const String t);
extern wchar_t sCharAt(const String s, size_t idx);
extern size_t sIndexOf(const String s, const wchar_t *search);
extern wchar_t *sToCharArray(const String s);
extern String sToLowerCase(const String s);
extern String sToUpperCase(const String s);

#ifdef FO_SHORT_NAMES
#define news(s) new_String(s);
#define slen(s) sLength(s);
#define scat(s,t) sConcat(s,t)
#define sat(s,idx) sCharAt(s,idx)
#define sidx(s,cp) sIndexOf(s,cp)
#define scptr(s) sGetCharArray(s)

#define new(s) new_String(s);
#define len(s) sLength(s);
#define cat(s,t) sConcat(s,t)
#define at(s,idx) sCharAt(s,idx)
#define idx(s,cp) sIndexOf(s,cp)
#define cptr(s) sGetCharArray(s)

#define length(s) sLength(s);
#define concat(s,t) sConcat(s,t)
#define charAt(s,idx) sCharAt(s,idx)
#define indexOf(s,cp) sIndexOf(s,cp)
#define toCharArray(s) sToCharArray(s)
#endif

#endif /* STRING_H_ */
