#!/bin/bash

if [[ "$1" == "clean" ]]; then rm -Rf build; exit; fi

ulimit -c unlimited # core dumps

#DEBUG="--debug-output"
if [[ "$1" == "debug" ]]; then TYPE="Debug"
elif [[ "$1" == "core" ]]; then TYPE="Debug"
elif [[ "$1" == "valgrind" ]]; then TYPE="Debug"
else TYPE="Release"
fi

mkdir build 2>/dev/null
cd build 
cmake ${DEBUG} -DCMAKE_BUILD_TYPE=${TYPE} -DCMAKE_PREFIX_PATH="/opt/Qt/5.6/gcc_64/lib/cmake" .. && {
	make -j8 && {
		export LD_LIBRARY_PATH="/opt/Qt/5.6/gcc_64/lib/"

		if [[ "$1" == "debug" ]]; then $PRE gdb src/consoler2
		elif [[ "$1" == "valgrind" ]]; then $PRE valgrind src/consoler2
		else $PRE src/consoler2
		fi

		unset LD_LIBRARY_PATH

		if [[ "$1" == "core" ]];
		then
			filename="$( ls --sort=time core.consoler2.* | head -n1 )"
			if [[ "$filename" == "" ]]; then echo "unable to find core dump"; exit
			else
				gdb src/consoler2 ${filename}
			fi
		fi
	}
}
cd ..
