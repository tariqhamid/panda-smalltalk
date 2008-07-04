
#include <st-types.h>
#include <st-symbol.h>
#include <st-compiler.h>
#include <st-processor.h>
#include <st-array.h>
#include <st-lexer.h>
#include <st-node.h>
#include <st-universe.h>
#include <st-object.h>
#include <st-float.h>
#include <optparse.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

#define BUF_SIZE 2000

static const char version[] =
PACKAGE_STRING"\n"
"Copyright (C) 2007-2008 Vincent Geddes";

static bool verbose = false;

struct opt_spec options[] = {
    {opt_help, "h", "--help", NULL, "Show help information", NULL},
    {opt_version, "V", "--version", NULL, "Show version information" , (char *) version},
    {opt_store_1, "v", "--verbose", NULL, "Show verbose messages" , &verbose},
    {NULL}
};


static void
compile_input (void)
{
    st_compiler_error error;
    char buffer[BUF_SIZE];
    char *string;
    char c;
    int i = 0;

    while ((c = getchar ()) != EOF && i < (BUF_SIZE - 1))
	buffer[i++] = c;
    buffer[i] = '\0';

    string = st_strconcat ("doIt ^ [", buffer, "] value", NULL);

    if (!st_compile_string (st_undefined_object_class, string, &error)) {
	fprintf (stderr, "test-processor:%i: %s\n",
		 error.line, error.message);
	exit (1);
    }

    st_free (string);
}

static double
get_elapsed_time (struct timeval before, struct timeval after)
{
    return after.tv_sec - before.tv_sec + (after.tv_usec - before.tv_usec) / 1.e6;
}

int
main (int argc, char *argv[])
{
    st_processor processor;
    st_oop value;

    opt_basename(argv[0], '/');
    opt_parse ("usage: %s [options]", options, argv);
    
    st_set_verbosity (verbose);

    st_bootstrap_universe ();
    compile_input ();

    st_processor_initialize (&processor);

    proc = &processor;

    st_processor_main (&processor);
    
    /* inspect the returned value on top of the stack */
    value = ST_STACK_PEEK ((&processor));

    fprintf (stdout, "\n");
    fprintf (stdout, "result: %s\n", st_object_printString (value));

    return 0;
}
