gcc -c -fPIC conversions.c bitwise.c 
gcc -shared -o libbitwise_utils.so conversions.o bitwise.o
sudo cp *.h /usr/local/include/
sudo cp libbitwise_utils.so /usr/local/lib
sudo ldconfig 
gcc main.c -lbitwise_utils -o res