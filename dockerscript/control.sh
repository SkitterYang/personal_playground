#!bin/bash

DOCKER_BIN='docker'
IMAGE_NAME='nginx'
APP_NAME='mynginx'

ROOT_DIR=`pwd`

LOCAL_HTML_DIR=${ROOT_DIR}'/www'
HTML_DIR='/usr/share/nginx/html'

LOCAL_CONF_DIR=${ROOT_DIR}'/conf/nginx.conf'
CONF_DIR='/etc/nginx/nginx.conf'

LOCAL_LOG_DIR=${ROOT_DIR}'/log'
LOG_DIR='/var/log/nginx/'

PORT=8090

if [ $1 == "run" ]; then
    $DOCKER_BIN stop $APP_NAME
    $DOCKER_BIN rm $APP_NAME
    $DOCKER_BIN run \
        -p $PORT:80 \
        --name $APP_NAME \
        -v ${LOCAL_HTML_DIR}:${HTML_DIR}:ro \
        -v ${LOCAL_CONF_DIR}:${CONF_DIR}:ro \
        -v ${LOCAL_LOG_DIR}:${LOG_DIR} \
        $IMAGE_NAME &
fi

if [ $1 == "start" ]; then
    $DOCKER_BIN start $APP_NAME
fi

if [ $1 == "stop" ]; then
    $DOCKER_BIN stop $APP_NAME
fi

if [ $1 == "rm" ]; then
    $DOCKER_BIN stop $APP_NAME
    $DOCKER_BIN rm $APP_NAME
fi
