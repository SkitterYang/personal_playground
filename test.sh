#bin/bash

function log
{
    echo ''
    echo ============= ${1} ===============
}

log "make"
make
if ! [ $? -eq 0 ]; then
    exit -1
fi

log "run "
./main
