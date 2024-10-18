FROM python:latest
# Note: Can't use official sphinx image because drawio can't be installed from apt which causes problems.

WORKDIR /usr/drawio
RUN apt update && apt install -y wget libasound2 && \
    wget https://github.com/jgraph/drawio-desktop/releases/download/v24.7.5/drawio-amd64-24.7.5.deb && \
    apt install -y ./drawio-amd64-24.7.5.deb

RUN apt update && apt install -y xvfb tree
RUN python3 -m pip install sphinx sphinx-autobuild sphinxcontrib-drawio sphinx-rtd-theme \
                           sphinxcontrib-programoutput

WORKDIR /usr/project
