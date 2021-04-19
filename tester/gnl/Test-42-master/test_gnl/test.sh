gcc -Wall -Wextra -Werror -D BUFFER_SIZE=64 -I. ../../get_next_line.c ../../get_next_line_utils.c test.c -o get_next_line
./get_next_line < test/simple > result

rm -f get_next_line

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=64 -I. ../../get_next_line_bonus.c ../../get_next_line_utils_bonus.c test_bonus.c -o get_next_line
./get_next_line < test/simple > result_bonus

rm -f get_next_line

echo "diff classic :"
echo "==================================="

diff result test/expected_result

echo "==================================="

echo "diff bonus sans multi fd :"
echo "==================================="

diff result_bonus test/expected_result

echo "==================================="

rm -f result
rm -f result_bonus
