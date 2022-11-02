#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stack.h"

typedef enum
{
    false = 0,
    true = 1
} bool;

/**
 * Zásobník pro ukládání změn
*/
struct stack do_history = {NULL};

/**
 * Zásobník pro ukládání provedených undo operací
*/
struct stack undo_history = {NULL};

/**
 * Pomocná funkce pro kontrolu, jestli je index v rozsahu stringu
*/
bool is_in_bounds(char *string, int position)
{
    if (position < 1) return false;
    if (position > sizeof(string) - 1) return false;

    return true;
}

/**
 * Funkce pro změnu znaku ve stringu na konkrétní pozici
 * @param string Pointer na pole znaků reprezentující string
 * @param c Znak, který má být náhradou
 * @param position Na kolikáté pozici bude změněn znak (1. znak => position = 1)
 * @returns Status kód, jestli operace byla provedena bez chyb
 */
int edit(char *string, char c, int position)
{
    // Kontrola, jestli je pozice v rámci stringu
    //-1 se odečítá proto, aby nám nějakej jouda nepřepsal termination znak stringu.
    if (!is_in_bounds(string, position))
        return 1;

    // Posunutí pointeru o pozici (-1 pro vychýlení na indexování od 0)
    *(string + position - 1) = c;

    return 0;
}

/**
 * Funkce pro změnu rozsahu stringu jiným stringem
 * @param string Pointer na string, ve kterém bude provedena změna
 * @param c Substring, který bude vložen do parametru string
 * @param from Od kolikátého znaku se má začít substring vkládat
 */
int edit_sub(char *string, char* c, int from)
{
    int string_length = strlen(string);
    int c_length = strlen(c);
    int min = string_length > c_length ? c_length : string_length;

    for (size_t i = 0; i < min; i++)
    {
        *(string + from + i) = *(c + i);
    }
    
    return 0;
}

/**
 * Funkce pro naplnění stringu "náhodnými" znaky
 * @param string Pointer na alokované pole charů
 * @param size Délka pole charů (včetně termination znaku \0)
*/
void fill_string(char *string, int size)
{
    // Zajištění seedování pseudonáhodného generátoru čísel
    // Jinak by funkce rand() generovala jednu a tu samou sekvenci
    srand(time(NULL));

    for (size_t i = 0; i < size - 1; i++)
    {
        char randomletter = (rand() % (90 - 65)) + 65;
        *(string + i) = randomletter;
    }

    // Přidání znaku označující konec stringu
    *(string + size - 1) = '\0';
}

int main()
{
    char *string;
    int size = 6; // Velikost stringu (+ 1 pro koncový znak)

    // Inicializace stringu pomocí malloc();
    // size + 1 pro \0 symbol
    string = (char *)malloc(sizeof(char) * (size));

    // Protože je proměnná "string" už pointerem
    // nemusíme při volání funkcí psát &string (což implicitně vytváří pointer)
    fill_string(string, size);
    printf("%s\n", string);

    edit(string, ' ', 3);
    printf("%s\n", string);

    char substring[] = "LOL";
    char *ptr = substring;

    edit_sub(string, ptr, 1);
    printf("%s\n", string);

    //cleanup:
    //free();
}