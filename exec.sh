MODE="All"

I=4
N=0

if [ "$MODE" = "Single" ]; then
	while [ -d "CPP0$I/ex0$N" ]; do
		echo "\033[32m""_________ CPP0$I EX0$N __________ ""\033[0m"
		echo Search exec in CPP0$I ex0$N
		cd CPP0$I/ex0$N
		make -s re
		make -s clean
		exec=$(find . -type f ! -name "*.cpp" ! -name "*.hpp" ! -name "Makefile")
		if [ -x "$exec" ]; then
			valgrind --leak-check=full --track-origins=yes --quiet ./$exec
		fi
		N=$((N + 1)) 
		echo "\033[32m""_________________________________""\033[0m"
		sleep 1
		cd ../../
	done
elif [ "$MODE" = "All" ]; then
	I=0
	while [ -d "CPP0$I" ]; do
		N=0
		while [ -d "CPP0$I/ex0$N" ]; do
			echo "\033[32m""_________ CPP0$I EX0$N __________ ""\033[0m"
			echo Search exec in CPP0$I ex0$N
			cd CPP0$I/ex0$N
			make -s re
			make -s clean
			exec=$(find . -type f ! -name "*.cpp" ! -name "*.hpp" ! -name "Makefile")
			if [ -x "$exec" ]; then
				valgrind --leak-check=full --track-origins=yes --quiet ./$exec
			fi
			N=$((N + 1)) 
			echo "\033[32m""_________________________________""\033[0m"
			sleep 1
			cd ../../
		done
		I=$((I + 1)) 
	done
fi

echo "\033[34m""FINISH""\033[0m"