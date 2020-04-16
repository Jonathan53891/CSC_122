#ifndef MENU_HELPER_HEADER_INCLUDED
#define MENU_HELPER_HEADER_INCLUDED

#include "input.h"
#include "strextra.h"

template <typename ProcFnc>
void do_menu(const char menu[], const char allowed[], ProcFnc process)
{
    bool quit;
    char choice;
    do
    {
        choice = get_in_set(allowed, menu);
        quit = process(find(allowed, choice)/3+1);
    } while (!quit);
    return;
}

#endif
