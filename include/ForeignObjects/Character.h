/*
 * Character.h
 *
 *  Created on: Aug 17, 2016
 *      Author: bill
 */

#ifndef CHARACTER_H
#define CHARACTER_H

/* Choosing the character width is best done at compile time
   because there is no elegant way to change function parameter types
   and return types at run time. This should not be too much of a
   problem because Windows uses wchar_t internally and Linux/Mac
   typically use UTF-8 for which a normal char is best. */

#ifdef _WINDOWS
#define FO_CHAR wchar_t
#else
#define FO_CHAR char
#endif

#ifdef FO_WIDE_CHAR
#define FO_CHAR wchar_t
#elif defined(FO_NORMAL_CHAR)
#define FO_CHAR char
#endif

#endif /* CHARACTER_H */

