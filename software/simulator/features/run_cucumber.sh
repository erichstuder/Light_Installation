#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]')
WORKDIR=/usr/simulator
docker build -t $TAG .
docker run \
	--rm \
	--name cucumber \
	--volume "${PWD}/..":${WORKDIR} \
	--workdir ${WORKDIR} \
	-it $TAG \
	bash

