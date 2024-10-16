FROM python:latest
# Note: Can't use official sphinx image because drawio can't be installed from apt which causes problems.

RUN apt-get update && apt-get install -y tree
RUN python3 -m pip install sphinx sphinx-autobuild sphinx-rtd-theme sphinxcontrib-programoutput

WORKDIR /usr/project
