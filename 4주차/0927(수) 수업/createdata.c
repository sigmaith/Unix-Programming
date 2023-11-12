#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *name[] = {
        "David Hutchison", //15바이트
        "Takeo Kanade",
        "Josef Kittler",
        "John M. Kleinberg",
        "Friedemann Mattern",
        "John C. Mitchell",
        "Moni Naor",
        "Oscar Nierstrasz",
        "C. Pandu Rangan",
        "Bernhard Steffern",
        "Madhu Sudan",
        "Demetri Tygar",
        NULL
};

int
main() {

        int i, out;
        char wbuf[64];

        memset(wbuf, 0, sizeof(wbuf));

        if ((out = open("residents", O_CREAT|O_RDWR, 0644)) < 0) {
                perror("no testdata");
                exit(1);
        }

        for (i=0; name[i]!=NULL; i++) {
                memcpy(wbuf, name[i], sizeof(wbuf));
                write(out, wbuf, sizeof(wbuf));
                printf(" %s %d %s\n", wbuf, i+1, name[i]);
                memset(wbuf, 0, sizeof(wbuf));
        }

        close (out);

}

//포인터 32비트에선 4고 64에선 8이다