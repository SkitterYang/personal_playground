CC=g++

mainSource = main.cpp
leetcodeSource = leetcode/leetcode.cpp
leetcodeHeader = leetcode/leetcode.h
ywySource = ywy/log.cpp playground/playground.cpp
ywyHeader = ywy/log.h playground/playground.h

flags= -std=c++11

main: ${mainSource} ${leetcodeSource} ${leetcodeHeader} ${ywyHeader} ${ywySource}
	${CC} ${flags} -o main ${mainSource} ${leetcodeSource} ${ywySource}


# evil defender
DEFENDER_DIR = evil_defender
DEFENDER_SOURCE = ${DEFENDER_DIR}/evil_defender.cpp
DEFENDER_HEADER = ${DEFENDER_DIR}/evil_defender.h
evil_defender: ${DEFENDER_SOURCE} ${DEFENDER_HEADER}
	${CC} ${flags} -o evilDefender ${DEFENDER_SOURCE}
