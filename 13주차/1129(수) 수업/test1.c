#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#define HOST_NAME "localhost"

main() {
	struct hostent *hent;

	sethostent(0);

	while ((hent = gethostent()) != NULL)
		printf("Name=%s\n", hent->h_name);

	endhostent();

	if ((hent = gethostbyname(HOST_NAME)) == NULL) {
		perror("%s not exist");
		exit(1);
	}
	printf("gethostbyname %s\n", hent->h_name);
}

