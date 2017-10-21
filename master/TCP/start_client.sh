#! /bin/sh

IP=$(sed -n '/IP/p' config|awk -F ":" '{print $2}')
PORT=$(sed -n '/PORT/p' config|awk -F ":" '{print $2}')

echo $IP
echo $PORT

./client/client  $PORT $PORT

