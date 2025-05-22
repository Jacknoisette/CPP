if !( pgrep -x "code" > /dev/null ); then
    code .
fi

error_message() {
	echo " Welcome to exec.sh"
	echo " This shell file compile CPP"
	echo " Here is the list of Mode you can use :"
	echo "	- No arg"
	echo "		- All CPP are executed"
	echo "	- One arg"
	echo "		- Execute the CPP of the first parameter"
	echo "	- Two arg"
	echo "		- Execute the exercice of the second parameter"
	echo "		  in the CPP of the first parameter"
	echo ""
	echo " Entering more than two arg or number below 0 and above 9"
	echo "  will not be accepted"
	echo " Thanks you"
}

test_variable() {
	arg=$1
	test=0
	for i in $(seq 0 9); do
		if [ "$arg" = "$i" ]; then
			test=1
		fi
	done
	if [ "$test" = 0 ]; then
		error_message
		return 0
	fi
	return 1
}

MODE=""
I=""
N=""
ARG=""

if [ "$#" = 0 ]; then
	MODE="All"
	I=0
	N=0
elif [ "$#" = 1 ]; then
	MODE="Group"
	I=$1
	if test_variable "$I" ; then
		return
	fi
	N=0
elif [ "$#" = 2 ]; then
	MODE="Single"
	I=$1
	if test_variable "$I" ; then
		return
	fi
	N=$2
	if test_variable "$N" ; then
		return
	fi
else
	error_message
	return
fi


animate_text() {
	text=$1
    length=$(expr length "$text")
    for i in $(seq 0 $((length - 1))); do
        char=$(echo "$text" | cut -c $((i + 1)))
        echo -n "$char"
        sleep 0.05
    done
    ARG=""
	if grep -q "argv" main.cpp ; then
		echo -n " \033[31m"
    	read ARG
		echo -n "\033[0m"
	else
		echo
    fi
	echo
}

execute() {
	echo "\033[32;1m""_________ CPP0$I EX0$N __________ ""\033[0m"
	cd CPP0$I/ex0$N
	make -s -j re
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
