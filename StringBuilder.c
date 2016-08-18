/*
 * StringBuilder.c
 *
 *  Created on: Aug 17, 2016
 *      Author: bill
 */

#include <stdio.h>
#include <string.h>
#include <gc.h>
#include <ForeignObjects/StringBuilder.h>

StringBuilder *new_StringBuilder(size_t initialCapacity)
{
	StringBuilder *sb;

	sb = (StringBuilder *) GC_MALLOC(sizeof(struct _StringBuilder));
    if (sb == NULL) {
    	fprintf(stderr, "Failed to allocate memory for StringBuilder\n");
    }
    else {
    	sb->capacity = initialCapacity;
    	sb->length = 0;
    	sb->characters = (FO_CHAR *) GC_MALLOC(initialCapacity * sizeof(FO_CHAR));
        if (sb->characters == NULL) {
        	fprintf(stderr, "Failed to allocate memory for StringBuilder\n");
            GC_FREE(sb);
            sb = NULL;
        }
        else {
        	sb->characters[0] = '\0';
        }
    }
    return sb;
}

size_t sbLength(StringBuilder *s)
{
	return s->length;
}

StringBuilder *sbAppend(StringBuilder *s, FO_CHAR *t)
{
	size_t combinedLength;
    size_t capacity;
    FO_CHAR *buffer;

	combinedLength = s->length + strlen(t);
    capacity = s->capacity;
	while (combinedLength >= capacity) {
		capacity *= 2;
	}
    buffer = (FO_CHAR *) GC_REALLOC(s->characters, capacity);
    if (buffer == NULL) {
    	fprintf(stderr, "Failed to resize allocated memory for StringBuilder\n");
    }
    else {
    	s->characters = buffer;
    	s->length = combinedLength;
    	s->capacity = capacity;
        STRCAT(s->characters, t);
    }
    return s;
}

FO_CHAR sbCharAt(StringBuilder *s, size_t idx)
{
	return s->characters[idx];
}

