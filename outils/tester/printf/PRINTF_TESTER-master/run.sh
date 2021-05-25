
array=(main_string.c main_number.c main_char.c main_unsigned_int.c main_hexa.c main_percent.c main_pointer.c)

array=( "${array[@]/#/src/}" )


for item in ${array[*]}
do
    	printf "%0.s-" {1..30}
	printf "\n"
	printf "|        %-20s|\n" ${item:9}
	printf "|%28c|\n" ' '
    	printf "%0.s-" {1..30}	
	printf "\n\n"
	sleep 0.01
	bash dont_run_me.sh ${item}
done
