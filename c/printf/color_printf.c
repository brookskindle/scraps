/*
  _____          _   _            _____      _                
 |  __ \        | | | |          / ____|    | |               
 | |__) | __ ___| |_| |_ _   _  | |     ___ | | ___  _ __ ___ 
 |  ___/ '__/ _ \ __| __| | | | | |    / _ \| |/ _ \| '__/ __|
 | |   | | |  __/ |_| |_| |_| | | |___| (_) | | (_) | |  \__ \
 |_|   |_|  \___|\__|\__|\__, |  \_____\___/|_|\___/|_|  |___/
                          __/ |                               
                         |___/                                
*/
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main (int argc, char const *argv[]) {

	printf(					  "This text is WHITE (REGULAR)\n"			   );
	printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_GREEN	  "This text is GREEN again!"	"\n");
	printf(					  "This text is probably GREEN again!"	"\n");
	printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");
	printf(					  "This text is WHITE (REGULAR)\n"			   );

	return 0;
}
