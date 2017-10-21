#! /bin/sh

#运行程序的次数命令行传入
arg=0

while [ "$arg" -lt $1 ]
do
	./a.out
	arg=$((arg+1))
done
