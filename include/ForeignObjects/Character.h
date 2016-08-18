/*
 * Character.h
 *
 *  Created on: Aug 17, 2016
 *      Author: bill
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#ifdef FO_USE_WIDE_CHAR
#define FO_CHAR wchar_t
#define STRCAT(s,t) wcscat(s,t)
#else
#define FO_CHAR char
#define STRCAT(s,t) strcat(s,t)
#endif

#endif /* CHARACTER_H_ */
