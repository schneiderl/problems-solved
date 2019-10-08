#!/bin/bash

repos=(
	"username/repo1"
	"username/repo2"
	"username/repo3"
)

for i in "${repos[@]}"
do
   : 
   curl -XDELETE -H 'Authorization: token XXX' "https://api.github.com/repos/$i ";
done
