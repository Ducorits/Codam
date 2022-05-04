make
./push_swap 1 2 3 4 5 6 7 | grep "Error" | wc -l | awk '{if ($1 > 0) printf("Error on input: 1 2 3 4 5 6 7 8 9 10\n")};'
./push_swap 1 a 3 4 5 6 7 | grep "Error" | wc -l | awk '{if ($1 < 1) printf("No Error on input: 1 a 3 4 5 6 7 8 9 10 (Should be error)\n")};'
./push_swap abcdefghijklmnop | grep "Error" | wc -l | awk '{if ($1 < 1) printf("No Error on input: abcdefghijklmnop (Should be error)\n")};'
./push_swap | grep "Error" | wc -l | awk '{if ($1 > 0) printf("Error on no input. (Should not print anything)\n")};'
./push_swap 1 1 55 55 6 6 77 77 | grep "Error" | wc -l | awk '{if ($1 < 1) printf("No Error on input: 1 1 55 55 6 6 77 77. (Should be an error)\n")};'