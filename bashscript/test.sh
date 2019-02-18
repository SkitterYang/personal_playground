#bin/bash

echo "test start"

echo $(dirname "$0")
script_path="$(cd $(dirname "$0"); pwd -P)"
echo ${script_path}

echo "test end"
