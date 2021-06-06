#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <pthread.h>

void *hilo (void *arg) {
	char *msg;
	int i;
	msg = (char *) arg;
	for ( i = 0 ; i < strlen (msg) ; i++ ) {
		printf (" %c\n", msg[i]);
		}
}

int  main(int  argc , char *argv []) {
	pthread_t  h1;
	pthread_t  h2;
	pthread_t  h3;
	pthread_t  h4;
	char *h = "1" ,*j = "2",*m = "3",*b ="4";

	pthread_create(&h1, NULL , hilo , (void *) h);
	pthread_create(&h2, NULL , hilo , (void *) j);
	pthread_create(&h3, NULL , hilo , (void *) m);
	pthread_create(&h4, NULL , hilo , (void *) b);
	pthread_join(h1, NULL);
	pthread_join(h2, NULL);
	pthread_join(h3, NULL);
	pthread_join(h4, NULL);
	return 0;
	printf ("Fin\n");

}
