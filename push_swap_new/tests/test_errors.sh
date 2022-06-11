make
./push_swap 1 2 3 4 5 6 7 2> >(grep "Error" | wc -l | awk '{if ($1 == 1) printf("Error on valid input: 1 2 3 4 5 6 7 8 9 10\n")};') >1 >(grep "Error" | wc -l | awk '{if ($1 == 1) printf("Error on standard output! (Should be on standard err)\n")};')
./push_swap 1 a 3 4 5 6 7 2> >(grep "Error" | wc -l | awk '{if ($1 == 0) printf("No Error on invalid input: 1 a 3 4 5 6 7 8 9 10 (Should be error)\n")};') >1 >(grep "Error" | wc -l | awk '{if ($1 == 1) printf("Error on standard output! (Should be on standard err)\n")};')
./push_swap abcdefghijklmnop 2> >(grep "Error" | wc -l | awk '{if ($1 == 0) printf("No Error on letter input: abcdefghijklmnop (Should be error)\n")};') >1 >(grep "Error" | wc -l | awk '{if ($1 == 1) printf("Error on standard output! (Should be on standard err)\n")};')
./push_swap 2> >(grep "Error" | wc -l | awk '{if ($1 == 1) printf("Error on no input. (Should not print anything)\n")};') 1> >(grep "Error" | wc -l | awk '{if ($1 == 1) printf("Error on standard output! (Should be on standard err)\n")};')
./push_swap 1 1 55 55 6 6 77 77 2> >(grep "Error" | wc -l | awk '{if ($1 == 0) printf("No Error on duplicate input: 1 1 55 55 6 6 77 77. (Should be an error)\n")};') >1 >(grep "Error" | wc -l | awk '{if ($1 == 1) printf("Error on standard output! (Should be on standard err)\n")};')
