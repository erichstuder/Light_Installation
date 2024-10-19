# You must run this script without sudo. To run docker without sudo do the following:
# sudo groupadd docker
# sudo gpasswd -a $USER docker

import pathlib
import os
import sys

sys.path.append(str(pathlib.Path(__file__).parent.parent.parent / 'Shared' / 'project_management'))
from executor import Executor # type: ignore


if __name__ == "__main__":
    additional_arguments = [
        {
            'flag': '-b',
            'name': '--build',
            'help': 'Build documentation.'
        },
        {
            'flag': '-a',
            'name': '--autobuild',
            'help': 'Start sphinx-autobuild.'
        }
    ]

    ex = Executor(additional_arguments, description='Execute common documentation tasks')

    if ex.arguments.autobuild:
        os.makedirs(ex.work_dir+'/autobuild/html', exist_ok=True)
        commands = 'sphinx-autobuild '+ ('' if ex.arguments.verbose else '-q') +' -a --port 8000 --host 0.0.0.0 '
        commands += '--watch ../../simulator/features '
        commands += '--re-ignore auto_generated --re-ignore _static/auto_copied source autobuild/html '
    elif ex.arguments.build:
        commands = 'make html'
    else:
        commands = None

    ex.run(commands)
