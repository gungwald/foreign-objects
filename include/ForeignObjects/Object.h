/*
 * java.lang.Object.h
 *
 *  Created on: Jun 9, 2016
 *      Author: bill
 */

#ifndef FO_JAVA_LANG_OBJECT
#define FO_JAVA_LANG_OBJECT

#include <stdbool.h>

#include <ForeignObjects/Class.h>

struct Object {
	Class cls;
};

typedef
	struct Object *
	Object;

extern Class getClass(Object o);
extern bool instanceof(Object o, Class clazz);

#endif
