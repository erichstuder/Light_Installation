# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]')
docker build -t $TAG .
docker run -it $TAG
