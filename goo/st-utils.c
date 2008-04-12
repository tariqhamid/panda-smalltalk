/*
 * st-utils.c
 *
 * Copyright (C) 2008 Vincent Geddes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
*/
 
#include "st-utils.h"
#include "st-array.h"
#include "st-byte-array.h"

#include <stdint.h>

st_oop
st_allocate_object (gsize size)
{
    // all heap objects have at least a header of two st_oops
    g_assert (size >= 2);

    /* no gc fanciness yet ! */
    st_oop object = ST_OOP (g_malloc (size * sizeof (st_oop)));

    return object;
}

void
st_error_set (STError   **error,
	      guint       code,
              const char *message)
{
    if (!error)
	return;

    *error = g_slice_new0 (STError);

    (*error)->code = code;
    (*error)->message = g_strdup (message);

    g_datalist_init (&(*error)->datalist);
}

void
st_error_destroy (STError *error)
{
    if (!error)
	return;

    g_free (error->message);
    g_datalist_clear (&error->datalist);
    g_slice_free (STError, error);
}

gpointer
st_error_get_data (STError     *error,
		   const char  *key)
{
    g_assert (error != NULL);

    g_datalist_get_data (&error->datalist, key);
}

void
st_error_set_data (STError    *error,
		   const char *key,
		   gpointer   data)
{
    g_assert (error != NULL);

    g_datalist_set_data (&error->datalist,
			 key,
			 data);
}
