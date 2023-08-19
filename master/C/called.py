#！/usr/bin/env python
#!coding=utf8
import sys
import time
import os

def sayhi():
	print("hello python!")
	sys.stdout.flush()
	for i in range(10):
		print(i)
		time.sleep(0.5)
	print(os.getcwd())
	print(sys.path)