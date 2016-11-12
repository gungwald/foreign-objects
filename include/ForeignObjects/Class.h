/*
 * Class.h
 *
 *  Created on: Jun 9, 2016
 *      Author: bill
 */

#ifndef FOREIGN_OBJECTS_CLASS_H
#define FOREIGN_OBJECTS_CLASS_H

#include <ForeignObjects/String.h>

enum Class_ {CLS_OBJECT, CLS_STRING, CLS_STRINGBUILDER, CLS_ARRAYLIST, CLS_CONSCELL};

typedef
    enum Class_
    Class;

extern String *clsGetName(Class cls);

#endif
