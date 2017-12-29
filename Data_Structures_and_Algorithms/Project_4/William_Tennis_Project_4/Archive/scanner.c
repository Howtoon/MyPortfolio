#include <stdio.h>
#include <ctype.h>   /* for isspace */
#include <string.h>  /* for strdup */

#include "scanner.h"
#include "dictionary.h"

/*    Original Author: J.Lusth
 *    readInt(FILE *fp) 
 *      - wrapper for fscanf(fp,"%d")
 *      - returns 0 if end of file, but feof will subsequently return true
 *      - usage example: int x = readInt(stdin);
 *    readString(FILE *fp) 
 *      - safe version of fscanf(fp,"%s")
 *      - returns a malloc'd string
 *        the caller should free the returned string
 *      - returns 0 if end of file; feof will subsequently return true
 *      - usage example: char *x = readToken(stdin);
 *    allocate(size_t size) 
 *      - wrapper for malloc that will generate an out of memory error
 *      - usage example: int *x = (int *) allocate(sizeof(int) * count);
 *    reallocate(void *items,size_t size) 
 *      - wrapper for realloc that will generate an out of memory error
 *      - usage example: x = (int *) reallocate(x,sizeof(int) * count);
 */

static void skipWhiteSpace(FILE *);
static void *allocate(size_t);
static void *reallocate(void *,size_t);

/********** public functions **********************/

int readInt(FILE *fp){
    int x,result;
    result = fscanf(fp,"%d",&x);
    if (result == EOF)
    {
        return 0;
    }
    if (result == 0)
    {
        fprintf(stderr,"SCAN ERROR: attempt to read an integer failed\n");
        fprintf(stderr,"offending character was <%c>\n",fgetc(fp));
        exit(1);
    }
    return x;
}

/* Safe way of reading in strings from a file, avoids buffer overflows
 * starts with an initial buffer of size 80 and reads a character at a time
 * if the size of the string goes beyond the size of the buffer, increases
 * size of the buffer and continues to read
 */ 
char *readString(FILE *fp)
{
    int ch,index;
    char *buffer;
    int size = 80;

    skipWhiteSpace(fp);

    ch = fgetc(fp);
    if (ch == EOF) return 0;

    buffer = allocate(size);

    index = 0;
    while (!isspace(ch))
    {
        if (ch == EOF) break;
        if (index > size - 2)
        {
            ++size;
            buffer = reallocate(buffer,size);
        }
        buffer[index] = ch;
        ++index;
        ch = fgetc(fp);
    }

    /* push back the character that got us out of this loop */

    ungetc(ch,fp);

    if (index > 0)              //there is something in the buffer
        clearerr(fp);           //so force the read to be good

    buffer[index] = '\0';

    return buffer;
}

/********** private functions **********************/
//static keyword restricts visibility of function to file

static void skipWhiteSpace(FILE *fp)
{
    int ch;

    /* read chars until a non-whitespace character is encountered */

    while ((ch = fgetc(fp)) != EOF && isspace(ch))
        continue;

    /* a non-space character got us out of the loop, so push it back */

    ungetc(ch,fp);
}

static void *allocate(size_t size)
{
    char *s;
    s = malloc(size);
    if (s == 0)
        {
        fprintf(stderr,"could not allocate string, out of memory\n");
        exit(3);
        }

    return s;
}

static void *reallocate(void *s,size_t size)
{
    char *t;
    t = realloc(s,size);
    if (t == 0)
    {
        fprintf(stderr,"could not reallocate string, out of memory\n");
        exit(3);
    }

    return t;
}

