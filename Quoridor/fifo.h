#include <stdbool.h>

typedef struct pipes *pipes_pointer;

pipes_pointer init_pipes(int argc, char *argv[]);
void send_string_to_pipe(pipes_pointer channel, const char *data);
bool get_string_from_pipe(pipes_pointer channel, char *buffer, size_t size);
void close_pipes(pipes_pointer channel);
