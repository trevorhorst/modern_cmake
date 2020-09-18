#include <stdio.h>

#include "core/core.h"

namespace Library
{

/**
 * @brief Constructor
 */
Core::Core()
{

}

/**
 * @brief Prints a provided character array
 * @param toPrint Character array to print
 */
void Core::print( const char *toPrint )
{
    printf( "%s\n", toPrint );
}

}
