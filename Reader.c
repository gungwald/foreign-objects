/*
 * Reader.c
 *
 *  Created on: Dec 22, 2016
 *      Author: bill
 */

#include <ForeignObjects/Reader.h>
#include <ForeignObjects/StringBuilder.h>

StringBuilder *readLine(FILE *f)
{
	StringBuilder *s = new_StringBuilder(256);
    return s;
}

