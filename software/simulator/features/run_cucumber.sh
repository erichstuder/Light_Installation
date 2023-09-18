#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]')
WORKDIR=/usr/src/cucumber-cpp
docker build -t $TAG .
docker run \
	--rm \
	--name cucumber \
	--workdir ${WORKDIR} \
	-it $TAG \
	bash

	#--volume "${PWD}/..":${WORKDIR} \
