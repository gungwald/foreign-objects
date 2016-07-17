/*
 * String.c
 *
 *  Created on: Nov 26, 2015
 *      Author: bill
 */
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <wctype.h>	/* towlower */
#include <gc.h>

#include <ForeignObjects/Class.h>
#include <ForeignObjects/Object.h>
#include <ForeignObjects/String.h>

String new_String(const wchar_t *s)
{
	String n;
    size_t len;
    wchar_t *validatedS;

    if (s == NULL) {
    	validatedS = (wchar_t *) "";
    }
    else {
        validatedS = (wchar_t *) s;
    }

    len = wcslen(validatedS);
    n = (String) GC_MALLOC(sizeof(struct String));
    if (n != NULL) {
        n->cls = CLS_STRING;
        n->length = len;
        n->characters = (wchar_t *) GC_MALLOC(sizeof(wchar_t) * len + 1);
    	if (n->characters != NULL) {
        	wcscpy(n->characters, validatedS);
    	}
    	else {
    		GC_FREE(n);
    		n = NULL;
    	}
    }
	return n;
}

size_t sLength(const String s)
{
    if (s == NULL) {
    	return 0;
    }
    else {
    	return s->length;
    }
}

String sConcat(const String s, const String t)
{
	size_t len;
	String n = NULL;
    wchar_t *p;
    String vs, vt;

    if (s == NULL)
    	vs = new_String(L"");
    else
    	vs = s;

    if (t == NULL)
    	vt = new_String(L"");
    else
    	vt = t;

	len = sLength(vs) + sLength(vt);
	if ((p = (wchar_t *) GC_MALLOC(sizeof(wchar_t) * len + 1)) != NULL) {
		wcscpy(p, vs->characters);
		wcscat(p, vt->characters);
        if ((n = (String) GC_MALLOC(sizeof(struct String))) != NULL) {
        	n->cls = CLS_STRING;
        	n->characters = p;
            n->length = len;
        }
        else {
        	GC_FREE(p);
        }
	}
	return n;
}

String sConcatCharArray(const String s, const wchar_t *t)
{
	size_t len;
	String n = NULL;
    wchar_t *p;
    String validatedS;
    wchar_t *validatedT;

    if (s == NULL) {
        validatedS = new_String(L"");
    }
    else {
    	validatedS = s;
    }

    if (t == NULL) {
    	validatedT = L"";
    }
    else {
    	validatedT = (wchar_t *) t;
    }

	len = sLength(validatedS) + wcslen(validatedT);
	if ((p = (wchar_t *) GC_MALLOC(sizeof(wchar_t) * len + 1)) != NULL) {
		wcscpy(p, validatedS->characters);
		wcscat(p, validatedT);
        if ((n = (String) GC_MALLOC(sizeof(struct String))) != NULL) {
        	n->cls = CLS_STRING;
        	n->characters = p;
            n->length = len;
        }
        else {
        	GC_FREE(p);
        }
	}
	return n;
}

wchar_t *sToCharArray(const String s)
{
    if (s == NULL)
    	return L"";
    else
    	return s->characters;
}

bool sEquals(const String s, const String t)
{
	return wcscmp(s->characters, t->characters) == 0;
}

bool sEqualsIgnoreCase(const String s, const String t)
{
	return sEquals(sToLowerCase(s), sToLowerCase(t));
}

String sToLowerCase(const String s)
{
	size_t i;
    String lowerCased;
    wchar_t *characters;
    size_t len;

    lowerCased = new_String(s->characters);
    characters = lowerCased->characters;
    len = lowerCased->length;

	for (i = 0; i < len; i++) {
		characters[i] = towlower(characters[i]);
	}
    return lowerCased;
}
