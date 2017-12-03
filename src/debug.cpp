/*  Copyright 2003-2009 Santi Ontanon <santi.ontanon@terra.es>
    Work continued by 2017 Carlos Donizete Froes [a.k.a coringao]

    This file is part of Road Fighter Remake.

    Road Fighter Remake is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Road Fighter Remake is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Road Fighter Remake; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifdef _WIN32
#include "windows.h"
#endif

#include <stdio.h>

#include <stdarg.h>

#include "filehandling.h"

#ifdef KITSCHY_DEBUG_MEMORY
#include "debug_memorymanager.h"
#endif

FILE *fp = 0;

void output_debug_message(const char *fmt, ...)
{
    char text[256];
    va_list ap;

    if (fmt == 0)
        return ;

    va_start(ap, fmt);
    vsprintf(text, fmt, ap);
    va_end(ap);

    if (fp == 0)
		fp = f1open("roadfighter.dbg", "w", USERDATA);

    fprintf(fp, fmt, text);
    fflush(fp);
} /* glprintf */




void close_debug_messages(void)
{
    fclose(fp);
    fp = 0;
} /* close_debug_messages */
