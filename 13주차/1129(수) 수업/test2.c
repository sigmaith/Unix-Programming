#include <netdb.h>
#include <stdio.h>

main() {
	struct servent *port;
	int n;

	setservent(0);

	for (n=0; n<5; n++) {
		port = getservent();
		printf("Name=%s, Port=%d\n", port->s_name, port->s_port);
	}

	port = getservbyname("ftp", "tcp");
	printf("getservbyname %s\n", port->s_name);

	endservent();

}

