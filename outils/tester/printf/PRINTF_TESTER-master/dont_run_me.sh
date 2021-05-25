
REAL_MAIN=${1}

if [ "$REAL_MAIN" == "" ]
then
	echo -e "\n (It needs a src_file to work)\nTry running [ bash dont_run_me.sh src/main_char.c ] for example to test only char \n or simply run [ bash run.sh ] \n"
	exit 1
fi

GREEN='\033[1;32m'
RED='\033[0;31m'
OFF='\033[0m'

main='main_tmp.c'
lib='libftprintf.a'
CC='gcc'
FLAGS='-Wall -Werror -Wextra'
r_printf='results/printf.txt'
r_ft_printf='results/ft_printf.txt'
GET_HEADER=$(find ../ -name "*.h")

#here comptabilite couleur OS
e='-e'


echo -e "Compile error" > ${r_ft_printf}
echo -e "\nCompile error\n\n" > ${r_printf}


cp ${REAL_MAIN}  ${main}
make libftprintf.a -C ../
cp ../libftprintf.a ./




${CC} ${FLAGS} ${main} ${lib}  && ./a.out > ${r_printf}


sed -i -e "s/"printf"/"ft_printf"/g" ${main}


${CC} ${FLAGS} -w -include ${GET_HEADER} ${main} ${lib}  && ./a.out > ${r_ft_printf}

if [ $? -eq 139 ]
then
 	echo -e "${RED}[ Not good, It crashed ! ]"
	echo -e "\nThe tests's results before your crash will still be printed into results/ft_printf.txt"
	echo -e "${OFF}"
else

DIFF=$(diff ${r_printf} ${r_ft_printf})

FIRST_LINE=$(head -n 1 results/ft_printf.txt)

if [ "$FIRST_LINE" == "Compile error" ]
then
                echo -e "Ouch, compile error, maybe from here maybe not"
elif [ "$DIFF" != "" ]
then
	
       ERROR_COUNT=$(diff -U 0 ${r_printf} ${r_ft_printf} | grep ^@ | wc -l)
	echo  -e " \n \n \n \n PRINTF" >> ${r_printf}
	echo  -e "\n\n\n\n FT_PRINTF" >> ${r_ft_printf}
	
	sdiff -s ${r_printf} ${r_ft_printf}

	echo "------------------------------------------------------------------------------------------------------------------------------"


	if [ "$REAL_MAIN" == "src/main_pointer.c" ]
	then
		echo ${e} "${GREEN}"
		echo "[ KO ] But it's ok, it is the pointer test, you have to compare the results by yourself"
	else
		echo ${e} "\n${RED}[ KO ]  ${ERROR_COUNT} errors"
	fi 
	echo ${e} "${OFF}"
else
	echo  -e "\n${GREEN}[ OK ] - All GOOD"
	echo ${e} "${OFF}"
fi

fi

while true
do

	echo -e "Please select: 1, 2, 3, or 4\n\n\n[ next (1) ]  |  [ show diff (2) ]  |  [ show printf results ] (3)  |  [ show ft_printf results ] (4)  |\n"

	read answer
	if [ ${answer} == "1" ]
	then
		break
	elif [ ${answer} == "2" ]
	then
		vim -d ${r_printf} ${r_ft_printf}
	elif [ ${answer} == "3" ]
	then
 		vim ${r_ft_printf}
	elif [ ${answer} == "4" ]
	then
		vim ${r_ft_printf}
	fi
done



rm  ${main} ${lib} a.out 

rm ${r_printf} ${r_ft_printf}

#rm backup file
rm main_tmp.c-e #only for mac

make fclean -C ../ 




#	************************	others	*****************************


#kind of replacing a word by another
#sed -i -e "s/"ft_printf"/"printf"/g" ${main}

#delete first line of a file
#sed -i -e '1d' ${main}


#add text at the beginning of a file
#sed -i -e '1s/^/#include "..\/include\/ft_printf.h"\
#/' ${main}

#not working with -Werror	 don't get that: (2> /dev/null)
#${CC} ${main} i libftprintf.a 2> /dev/null && ./a.out > results/ft_printf.txt
