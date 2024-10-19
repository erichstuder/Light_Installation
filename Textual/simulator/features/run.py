# You must run this script without sudo. To run docker without sudo do the following:
# sudo groupadd docker
# sudo gpasswd -a $USER docker

import pathlib
import sys

sys.path.append(str(pathlib.Path(__file__).parent.parent.parent.parent / 'Shared' / 'project_management'))
from executor import Executor # type: ignore


if __name__ == "__main__":
    additional_arguments = [
        {
            'flag': '-t',
            'name': '--test',
            'help': 'Build and run features.'
        },
        {
            'flag': '-r',
            'name': '--report',
            'help': 'Create an html report.'
        }
    ]

    ex = Executor(additional_arguments, description='Execute feature tests')

    if not ex.arguments.verbose:
        build_commands = 'cmake -S . -B build >/dev/null '
        build_commands += '&& cmake --build build >/dev/null '
        build_commands += '&& (build/simulator_steps &) '
    else:
        build_commands = 'cmake -S . -B build --log-level=VERBOSE '
        build_commands += '&& cmake --build build '
        build_commands += '&& (build/simulator_steps -v &) '

    if ex.arguments.test:
        commands = build_commands

        commands += '&& cucumber --require cucumber.wire '
        if ex.arguments.verbose:
            commands += '--verbose '
        if ex.arguments.report:
            commands += '--format html > build/simulator_cucumber_report.html '
        commands += '*.feature '
    else:
        commands = None

    ex.run(commands)
