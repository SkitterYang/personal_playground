#!bin/bash

ROOTDIR="/Users/yangwenyu"
DOCUMENTDIR="/Documents/MyDoc/ywyDoc"

if [ -z $1 ]; then
    echo "no param entered"
    return 2>/dev/null || exit
fi

if [ $1 == "blog" ]; then
    destinyDir=${ROOTDIR}${DOCUMENTDIR}"/Md/LearningBlog"
    echo "goto ${destinyDir}"
    cd ${destinyDir}
    return 2>/dev/null || exit
fi

if [ $1 == "code" ]; then
    destinyDir=${ROOTDIR}${DOCUMENTDIR}"/code"
    echo "goto ${destinyDir}"
    cd ${destinyDir}
    return 2>/dev/null || exit
fi
