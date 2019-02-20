#bin/bash

function log
{
    echo ''
    echo ============= ${1} ===============
}

log "make"
make
if ! [ $? -eq 0 ]; then
    return 2>/dev/null || exit -1
fi

log "run "
./main

log "test finish"
