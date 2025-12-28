#get_next_line

Description

get_next_line reads and returns one line at a time from a file descriptor.

Prototype

```char    *get_next_line(int fd);```
g read()
	•	Returns one line per call
	•	Uses a static buffer to keep leftover data
	•	Stops at newline (\n) or EOF

Return
	•	Line ending with \n (if present)
	•	NULL on EOF or error

Files
	•	get_next_line.c
	•	get_next_line_utils.c
	•	get_next_line.h

Allowed functions
	•	read
	•	malloc
	•	free

Notes
	•	Caller must free the returned line
	•	Works with any BUFFER_SIZE
	•	Norminette compliant

⸻


 Example Usage
```
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```


Compilation

```cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c```
