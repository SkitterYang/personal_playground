CC=g++

mainSource = main.cpp
leetcodeSource = leetcode/leetcode.cpp
leetcodeHeader = leetcode/leetcode.h
ywySource = ywy/log.cpp
ywyHeader = ywy/log.h

flags= -std=c++11

main: ${mainSource} ${leetcodeSource} ${leetcodeHeader} ${ywyHeader} ${ywySource}
	${CC} ${flags} -o main ${mainSource} ${leetcodeSource} ${ywySource}
