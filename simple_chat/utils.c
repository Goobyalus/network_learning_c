#include <stdio.h>
#include "utils.h"

/*	readline: read a line of console input up to bufsize
 *	arguments:
 *		prompt:  in; string to display when requesting input
 *		buffer: out; where to copy read input
 *		bufsize: in; size of buffer
 *	return value:
 *		return an enum realine_success with result of read
 *	notes:
 * 		It is caller's responsibility to zero buffer before calling.
 */
enum readline_success readline(
	const char* prompt, char *buffer, int bufsize) {
	
	// Print prompt if it exists
	if (prompt) {
		printf("%s", prompt);
		fflush(stdout);
	}
	
	// Read up to bufsize bytes
	if (NULL == fgets(buffer, bufsize, stdin)) {
		return ERROR;
	}
	if ('\n' != buffer[bufsize-1]) {
		// Line did not fit in buffer - throw rest of line out
		while ('\n' != getchar());
		return TOO_LONG
	}
	
	return SUCCESS;
}

