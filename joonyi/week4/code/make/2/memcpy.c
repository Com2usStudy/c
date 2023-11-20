#include <stdio.h>
#include <string.h>

void* fn_memcpy(void* dest, const void* source, size_t num)
{
    char* destination = (char*) dest;
    const char* origin = (const char*) source;

    for (int i = 0; i < num; i++)
    {
        *(destination + i) = *(origin + i);
    }

    return dest;
}