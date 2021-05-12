#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "fifo.h"

struct pipes
{
    FILE *fifo_in;
    FILE *fifo_out;
    int isA;
};

int fileno(FILE *file);
void show_error(char *message);
static FILE *open_out_pipe(char *name);
static FILE *open_in_pipe(char *name);

void close_pipes(pipes_pointer pipes)
{
    fclose(pipes->fifo_in);
    fclose(pipes->fifo_out);
    free(pipes);
}

pipes_pointer init_pipes(int argc, char *argv[])
{
    if (argc < 2 || (argv[1][0] != 'A' && argv[1][0] != 'B') || argv[1][1] != '\0')
    {
        fprintf(stderr, "\nThis program should be called with the first argument: A or B\n\n");
        mkfifo("AtoB", 0664);
        mkfifo("BtoA", 0664);
        fprintf(stderr, "Fifo queues AtoB and BtoA created\n");
        return NULL;
    }
    pipes_pointer pipes = (pipes_pointer)malloc(sizeof(struct pipes));
    if (pipes == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
    }
    else
    {
        pipes->isA = (argv[1][0] == 'A');
        pipes->fifo_out = open_out_pipe(pipes->isA ? "AtoB" : "BtoA");
        pipes->fifo_in = open_in_pipe(pipes->isA ? "BtoA" : "AtoB");
    }
    return pipes;
}

static FILE *open_out_pipe(char *name)
{
    mkfifo(name, 0664);
    FILE *pipe = fopen(name, "w+");
    if (pipe == NULL)
    {
        show_error("Error in creating output pipe");
        exit(-1);
    }
    return pipe;
}

static FILE *open_in_pipe(char *name)
{
    FILE *pipe = fopen(name, "r+");
    if (pipe == NULL)
    {
        mkfifo(name, 0664);
        pipe = fopen(name, "r+");
    }
    if (pipe == NULL)
    {
        show_error("Error in creating input pipe");
        exit(-1);
    }
    int flags, fd;
    fd = fileno(pipe);
    flags = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    return pipe;
}

void send_string_to_pipe(pipes_pointer pipes, const char *data)
{
    int result = fprintf(pipes->fifo_out, "%s", data); // problem
    fflush(pipes->fifo_out);
    if (result == 0)
        show_error("Failed to send data");
}
bool get_strings_from_pipe(pipes_pointer pipes, char *buffer, size_t size)
{
    char = fgets(buffer, (int)size, pipes->fifo_in)
}
bool get_string_from_pipe(pipes_pointer pipes, char *buffer, size_t size)
{
    char *result = fgets(buffer, (int)size, pipes->fifo_in);
    fflush(pipes->fifo_in);
    return result != NULL;
}
