gcc -c tm_queue.c -I ../../include/queue/ -I ../../include/singly/ -L ../../lib/ -ltm_singly -o tm_queue.o
ar rcs libtm_queue.a *.o
mv libtm_queue.a ../../lib/
rm -rf *.o
