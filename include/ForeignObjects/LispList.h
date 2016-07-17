/*
 * lisp.lang.List.h
 *
 *  Created on: Jun 10, 2016
 *      Author: bill
 */

#ifndef LISP_LANG_LIST_H
#define LISP_LANG_LIST_H

#include <stdbool.h>

#include "ForeignObjects/Class.h"
#include "ForeignObjects/Object.h"

struct ConsCell {
	Class cls;
    Object first;	/* car */
    Object rest;	/* cdr */
};

typedef struct ConsCell		*ConsCell;

extern ConsCell cons(Object first, Object rest);
extern Object first(ConsCell list);
extern Object rest(ConsCell list);
extern bool atom(Object o);

#endif /* LISP_LANG_LIST_H_ */
