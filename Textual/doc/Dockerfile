FROM python:latest
# Note: Can't use official sphinx image because drawio can't be installed from apt-get which causes problems.

WORKDIR /usr/drawio
RUN apt-get update && apt-get install -y wget libasound2 plantuml && \
    wget https://github.com/jgraph/drawio-desktop/releases/download/v24.7.5/drawio-amd64-24.7.5.deb && \
    apt-get install -y ./drawio-amd64-24.7.5.deb

RUN apt-get update && apt-get install -y xvfb tree
RUN python3 -m pip install sphinx sphinx-autobuild sphinxcontrib-drawio sphinx-rtd-theme \
                           sphinxcontrib-programoutput sphinxcontrib-plantuml sphinx-needs==4.0.0 pillow \
                           sphinx-gherkindoc setuptools
