# You must run this script without sudo. To run docker without sudo do the following:
# sudo groupadd docker
# sudo gpasswd -a $USER docker

import pathlib
import os

import sys
import pathlib

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

    ex.docker_args.extend([
        '--volume', ex.work_dir + '/../..:' + ex.docker_volume_dir,
        '--workdir', ex.docker_volume_dir + '/Textual'])

    if ex.arguments.autobuild:
        ex.docker_args.extend([
            '--publish', '8000:8000',
            '--publish', '35729:35729'])

    prebuild_command = 'git config --global --add safe.directory ' + ex.docker_volume_dir
    work_dir_commands = 'set -e \n cd doc \n'

    if ex.arguments.autobuild:
        os.makedirs(ex.work_dir+'/autobuild/html', exist_ok=True)
        commands = work_dir_commands + 'sphinx-autobuild '+ ('' if ex.arguments.verbose else '-q') +' -a --port 8000 --host 0.0.0.0 '
        commands += '--watch ../simulator/features '
        commands += '--re-ignore auto_generated --re-ignore _static/auto_copied source autobuild/html '
        commands += '--pre-build "' + prebuild_command + '"'
    elif ex.arguments.build:
        commands = work_dir_commands + prebuild_command + ' \n make html'
    else:
        commands = None

    ex.run(commands)
