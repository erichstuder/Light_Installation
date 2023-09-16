#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]')
WORKDIR=/home
docker build -t $TAG .
docker run \
	--rm \
	--name firmware_tests \
	--volume "${PWD}/..":${WORKDIR} \
	--workdir ${WORKDIR} \
	-it $TAG \
	make -C firmware_tests CPPUTEST_USE_GCOV=Y gcov
