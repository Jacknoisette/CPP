MODE="Group"

I=5
N=3
READ=0
ARG="";

animate_text() {
	text=$1
    length=$(expr length "$text")  # Obtenez la longueur de la chaîne
    for i in $(seq 0 $((length - 1))); do
        char=$(echo "$text" | cut -c $((i + 1)))  # Extraire le i-ème caractère
        echo -n "$char"
        sleep 0.05
    done
    ARG=""
    if [ "$READ" = "1" ]; then
    	echo -n " "
    	read ARG
	else
		echo
    fi
    if [ "$ARG" != "" ]; then
    	echo
    fi
}

execute() {
	echo "\033[32m""_________ CPP0$I EX0$N __________ ""\033[0m"
	cd CPP0$I/ex0$N
	make -s re
	make -s clean
	exec=$(find . -type f ! -name "*.replace" ! -name "*.log" ! -name "*.cpp" ! -name "*.hpp" ! -name "Makefile" ! -name "*_shrubbery" ! -name "*.tpp" ! -name "*.csv" ! -name "*.txt")
	animate_text $exec
	if [ -x "$exec" ]; then
		eval valgrind --leak-check=full --track-origins=yes --quiet ./$exec "$ARG"
	else
		echo No exec file in CPP0$I ex0$N
	fi
	make -s fclean
	echo "\033[32m""_________________________________""\033[0m"
	cd ../../
}

if [ "$MODE" = "Single" ]; then
	execute
elif [ "$MODE" = "Group" ]; then
	while [ -d "CPP0$I/ex0$N" ]; do
		execute
		N=$((N + 1)) 
	done
elif [ "$MODE" = "All" ]; then
	I=0
	while [ -d "CPP0$I" ]; do
		N=0
		while [ -d "CPP0$I/ex0$N" ]; do
			execute
			N=$((N + 1)) 
		done
		I=$((I + 1)) 
	done
fi

echo "\033[34m""FINISHED""\033[0m"
