#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global - Structure for use in all functions
* @st_q: Can be stack or queue.
* @actual_li: Posiction actual line
* @arg: Process the second argument of the line.
* @head: Principal head for the liked list.
* @desciptor_file: File descriptor.
* @buffer: Size input.
*/
typedef struct global
{
        int st_q;
        int actual_li;
        char *arg;
        stack_t *head;
        FILE *descriptor_file;
        char *buffer;
        /*instruction_t **ops*/
} Global_t;

extern Global_t glob;

/* mandatory_opcode1.c */
void push_function(stack_t **stack, unsigned int line_number);
void pop_function(stack_t **stack, unsigned int line_number);
void pint_function(stack_t **stack, unsigned int line_number);
void pall_function(stack_t **stack, unsigned int line_number);
void swap_function(stack_t **stack, unsigned int line_number);

/* advance_opcode2.c */
void add_function(stack_t **stack, unsigned int line_number);
void nop_function(stack_t **stack, unsigned int line_number);

/* Helper */
void get_functions(stack_t **stack, char *tok, unsigned int line_number);

void main(int argc, char **argv);
int get_file(char *file, stack_t **head);

#endif /* MONTY_H */
