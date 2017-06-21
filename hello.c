#include <stdio.h>
2 #include <stdlib.h>
3 #include <string.h>
4
5 int main()
6 {
7 char message[80];
8
9 printf( "Type in a message , and I'll display it five times.\n" );
10 printf( "Message: " );
11 gets( message );
12
13 for ( int n = 1 ; n <= 5 ; n = n+1 )
14 {
15 printf( "%d. %s\n", n, message );
16 }
17
18 return EXIT_SUCCESS;
19 }