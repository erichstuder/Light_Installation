#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]')
WORKDIR=/usr/software
docker build -t $TAG .
docker run \
	--rm \
	--name cucumber \
	--volume "${PWD}/../..":${WORKDIR} \
	--workdir ${WORKDIR}/simulator/features \
	-it $TAG \
	bash

