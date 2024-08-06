#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

#define MAX_LINE_LENGTH 1000

void setup(int argc, char *argv[]);
void test_linkedlist();

int main(int argc, char *argv[])
{
    setup(argc, argv);

    return 1;
}

void setup(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    FILE *in, *out;

    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }

    out = fopen(argv[2], "w");
    if (out == NULL)
    {
        printf("Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Count the number of lines in the input file
    while (fgets(line, MAX_LINE_LENGTH, in))
    {
        count++;
    }

    // Reset pointer
    fclose(in);
    in = fopen(argv[1], "r");

    // Parse input file into array
    char op[count][MAX_LINE_LENGTH];
    int index = 0;
    while (fgets(line, MAX_LINE_LENGTH, in))
    {
        strcpy(op[index++], line);
        printf("%d: %s", index, op[index - 1]);
    }

    fclose(in);
    fclose(out);
}

void test_linkedlist()
{
    LinkedList list;
    init_linkedlist(&list);
    print(&list);

    printf("---------------------------\n");
    insert_at_head(&list, 3);
    insert_at_head(&list, 2);
    insert_at_head(&list, 1);
    insert_at_head(&list, 0);
    print(&list);

    printf("---------------------------\n");
    insert_at_tail(&list, 7);
    insert_at_tail(&list, 8);
    insert_at_tail(&list, 9);
    print(&list);

    printf("---------------------------\n");
    insert_at_index(&list, 4, 6);
    insert_at_index(&list, 4, 5);
    insert_at_index(&list, 4, 4);
    print(&list);

    printf("---------------------------\n");
    printf("At Index %d: %d\n", 3, get_at_index(&list, 3));
    printf("At Head: %d\n", get_at_head(&list));
    printf("At Tail: %d\n", get_at_tail(&list));

    printf("---------------------------\n");
    delete_at_head(&list);
    print(&list);
    delete_at_tail(&list);
    print(&list);

    printf("---------------------------\n");
    delete_at_index(&list, 5);
    print(&list);
    delete_at_index(&list, 5);
    print(&list);
    delete_at_index(&list, 5);
    print(&list);

    free_linkedlist(&list);
}