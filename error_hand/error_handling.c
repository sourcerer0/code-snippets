#include <string.h>
#include <errno.h>
#include <stdio.h>

extern int errno;
#define NUM_ERROR 133

void print_errno()
{
    int option = 0;

    printf("Select error message\n\t>> greater than 133 for quit\n\t>> negative to display all possibilities");
    while (option < NUM_ERROR)
    {
        printf("\n>> ");
        scanf("%d", &option);

        if (option < 0)
        {
            for (int x = 0; x < NUM_ERROR; x++)
            {
                printf("%d %s\n\n", x, strerror(x));
            }
        }
        else if (option > NUM_ERROR)
        {
            printf("Goodbye! :)\n");
            return;
        }
        else
        {
            printf("%d %s\n", option, strerror(option));
        }
    }
    return;
}

int main(int argc, char *argv)
{
    /*
    FILE *file;
    file = fopen("something.txt", "a");
    if (errno == 2) {
        printf("%d %s\n", errno, strerror(errno));
    }
    */
    print_errno();

    return 0;
}

/*
PYTHON
--------
staticmethod
classmethod (*static Java)
property
abstract (*abstract Java)

C
---------
static (*private Java && *static C)
const (*final Java)
extern
enum
struct
union
typedef
*
#

JAVA
---------
final (*const C)
abstract (*abstract Python)
static (*classmethod Python)
public (all)
default / none (package)
protected (package and inheritance)
private (class)
*/
