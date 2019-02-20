#bin/bash

make

if [ $? -eq 0 ];then
  echo "compile success, now run "
  ./test
else
  #do nothing
  echo "compile failed"
fi
