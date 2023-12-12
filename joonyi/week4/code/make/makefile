CC = gcc

main.exe : main.o \
1/fn_sort.o 1/fn_swap.o 1/is_negative.o 1/multiple_pointer.o \
2/fn_strcat.o 2/fn_strcmp.o 2/fn_strcpy.o 2/fn_strstr.o 2/memcpy.o
	gcc -o main.exe main.o \
	1/fn_sort.o 1/fn_swap.o 1/is_negative.o 1/multiple_pointer.o \
	2/fn_strcat.o 2/fn_strcmp.o 2/fn_strcpy.o 2/fn_strstr.o 2/memcpy.o 


main.o : main.c
	gcc -c main.c

fn_sort.o : 1/fn_sort.c
	gcc -c 1/fn_sort.c

fn_swap.o : 1/fn_swap.c
	gcc -c 1/fn_swap.c

is_negative.o : 1/is_negative.c
	gcc -c 1/is_negative.c

multiple_pointer.o : 1/multiple_pointer.c
	gcc -c 1/multiple_pointer.c

fn_strcat.o : 2/fn_strcat.c
	gcc -c 2/fn_strcat.c

fn_strcmp.o : 2/fn_strcmp.c
	gcc -c 2/fn_strcmp.c

fn_strcpy.o : 2/fn_strcpy.c
	gcc -c 2/fn_strcpy.c

fn_strstr.o : 2/fn_strstr.c
	gcc -c 2/fn_strstr.c

memcpy.o : 2/memcpy.c
	gcc -c 2/memcpy.c



# 2/fn_strcat.o 2/fn_strcmp.o 2/fn_strcpy.o 2/fn_strstr.o 2/fn_memcpy.o 2/strcapitalize.o


# test.exe : head.o test.o
# 	gcc -o test.exe test.o head.o

# test.o : test.c
# 	gcc -c test.c

# head.o : head.c
# 	gcc -c head.c

clean :
	ls -al
	rm *.o 1/*.o 2/*.o main.exe