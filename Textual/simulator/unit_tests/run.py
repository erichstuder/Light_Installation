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
            'help': 'Build and run unit-tests.'
        },
        {
            'flag': '-r',
            'name': '--report',
            'help': 'Create an html report.'
        }
    ]

    ex = Executor(additional_arguments, description='Execute unit-tests')

    ex.docker_args.extend([
        '--volume', ex.work_dir + '/../../..:' + ex.docker_volume_dir,
        '--workdir', ex.docker_volume_dir + '/Textual/simulator/unit_tests'])

    work_dir_commands = 'set -e \n'

    if ex.arguments.test:
        commands = work_dir_commands + ' mkdir -p build && cd build && cmake ..'
        commands += ' && make'
        commands += ' && ./unit_tests --gtest_output=xml:execution_report.xml'

        if ex.arguments.report:
            commands += ' && lcov --capture --directory . --output-file coverage.info'
            if not ex.arguments.verbose:
                commands += ' > /dev/null 2>&1'

            commands += ' && lcov --remove coverage.info '
            commands += ' "/usr/include/*" "*gtest*" "*gmock*" "*gnuplot-iostream*" "*unit_tests*"'
            commands += ' --output-file filtered_coverage.info'
            if not ex.arguments.verbose:
                commands += ' > /dev/null 2>&1'

            commands += ' && genhtml filtered_coverage.info --prefix ' + ex.docker_volume_dir
            commands += ' --output-directory coverage_report'
            if not ex.arguments.verbose:
                commands += ' > /dev/null 2>&1'
    else:
        commands = None

    ex.run(commands)
