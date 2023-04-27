#include <ctest.h>
#include "circle.h"
#include <stdio.h>
#include <math.h>

CTEST(INPUT_CHECK, LEFT_BRACKET_INDEX)
{
    char str[] = "circle(0 0, 1.5)";
    int expec = 0;
    int real = left_bracket(str);
    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, RIGHT_BRACKET_INDEX)
{
    char str[] = "circle(0 0, 1.5)";
    int expec = 0;
    int real = right_bracket(str);
    ASSERT_EQUAL(expec, real);
}

CTEST(VALUES_ERRORS, CHECK_STRING)
{
    char str[] = "circle(0 0, 1.5)";
    int expec = 0;
    int real = is_arguments(str);
    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, CHECK_ENDING_SYMBOL)
{
    char str[] = "circle(0 0, 1.5)";
    int expec = 0;
    int real = is_end(str);
    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, SHAPE_NAME_CHECK)
{
    char str[] = "circle(0 0, 1.5)";
    int expec = 0;
    int real = is_object(str);
    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, ERROR_CHECKING)
{
    char str[] = "circle(0 0, 1.5)";
    int expec = 0;
    int real = print_errors(str, 1);
    ASSERT_EQUAL(expec, real);
}
