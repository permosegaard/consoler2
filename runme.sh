#!/bin/bash

if [[ "$1" == "clean" ]];
	then rm -Rf build dist
else
	ulimit -c unlimited # core dumps
	
	if [[ "$1" == "debug" ]]; then CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Debug --debug-output"
	elif [[ "$1" == "core" ]]; then CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Debug"
	elif [[ "$1" == "valgrind" ]]; then CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Debug"
	else CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Release"
	fi

	BUILDSUCCESS=0

	mkdir build 2>/dev/null; cd build 
	cmake $CMAKE_FLAGS -DCMAKE_PREFIX_PATH="/opt/Qt/5.6/gcc_64/lib/cmake" .. && {
		make -j4 && { BUILDSUCCESS=1; }
	}
	cd ..

	if [ $BUILDSUCCESS -eq 1 ];
	then
		rm -Rf dist && mkdir dist && mkdir dist/plugins

		cp build/consoler2/consoler2 dist/ 2>/dev/null
		cp build/libconsoler2-*/libconsoler2-*.so dist/plugins/ 2>/dev/null
	
		cd dist
		#export LD_LIBRARY_PATH="/opt/Qt/5.6/gcc_64/lib/"
		
		EXECUTABLE="./consoler2"
		if [[ "$1" == "debug" ]]; then gdb $EXECUTABLE
		elif [[ "$1" == "valgrind" ]]; then valgrind $EXECUTABLE
		else $EXECUTABLE
		fi
		
		if [[ "$1" == "core" ]];
			then
				CORE="$( ls --sort=time core.consoler2.* | head -n1 )"
				if [[ "$CORE" == "" ]]; then echo "unable to find core dump"
				else
					gdb $EXECUTABLE $CORE
				fi
		fi

		#unset LD_LIBRARY_PATH
		cd ..
	fi
fi
