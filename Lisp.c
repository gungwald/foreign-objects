/*
 * lisp.lang.List.c
 *
 *  Created on: Jun 10, 2016
 *      Author: bill
 */

#include <gc.h>

#include <ForeignObjects/LispList.h>

ConsCell cons(Object first, Object rest)
{
	ConsCell consCell;

	consCell = (ConsCell) GC_MALLOC(sizeof(struct ConsCell));
    if (consCell) {
    	consCell->cls = CLS_CONSCELL;
        consCell->first = first;
        consCell->rest = rest;
    }
    return consCell;
}

Object first(ConsCell list)
{
	return list->first;
}

Object rest(ConsCell list)
{
	return list->rest;
}

bool atom(Object o)
{
	return o->cls != CLS_CONSCELL;
}



