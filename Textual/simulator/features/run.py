# You must run this script without sudo. To run docker without sudo do the following:
# sudo groupadd docker
# sudo gpasswd -a $USER docker

import argparse
import subprocess
import datetime
import pathlib
import os

def parse_arguments():
    parser = argparse.ArgumentParser(description='Execute common cucumber tasks')

    parser.add_argument('-t', '--test',
                        action='store_true',
                        help='Build and run features.')

    parser.add_argument('-r', '--report',
                        action='store_true',
                        help='Create an html report.')

    parser.add_argument('-p', '--pseudo_tty_off',
                        action='store_true',
                        help='Disable colorfull output.')

    parser.add_argument('-k', '--keep_open',
                        action='store_true',
                        help='Enter the command line of the container.')

    parser.add_argument('-v', '--verbose',
                        action='store_true',
                        help='Verbose output.')

    global arguments
    arguments = parser.parse_args()


def build_container(container_tag, work_dir):
    args = ['docker', 'build',
        '--tag', container_tag]

    if not arguments.verbose:
        args.append('--quiet')
        stdout = subprocess.DEVNULL
    else:
        stdout = None

    args.append(work_dir)

    print('    building container... please wait')
    return subprocess.run(args, stdout=stdout)


def run_container(container_tag, work_dir):

    current_time = datetime.datetime.now().strftime('%Hh_%Mm_%Ss')

    docker_volume_dir = '/usr/project'

    work_dir_commands = 'set -e \n '

    if not arguments.verbose:
        build_commands = 'cmake -S . -B build >/dev/null '
        build_commands += '&& cmake --build build >/dev/null '
        build_commands += '&& (build/simulator_steps &) '
    else:
        build_commands = 'cmake -S . -B build --log-level=VERBOSE '
        build_commands += '&& cmake --build build '
        build_commands += '&& (build/simulator_steps -v &) '

    if arguments.keep_open:
        commands = 'bash'
    elif arguments.test:
        commands = work_dir_commands
        commands += build_commands

        commands += '&& cucumber --require cucumber.wire '
        if arguments.verbose:
            commands += '--verbose '
        if arguments.report:
            commands += '--format html > build/simulator_cucumber_report.html '
        commands += '*.feature '
    else:
        return

    args = ['docker', 'run',
        '--rm',
        '--name', 'cucumber_' + current_time,
        '--volume', work_dir + '/../../..:' + docker_volume_dir,
        '--workdir', docker_volume_dir + '/Textual/simulator/features']

    if arguments.pseudo_tty_off:
        args.append('-i')
    else:
        args.append('-it')

    args.extend([container_tag, 'bash', '-c', commands])

    return subprocess.run(args)


def assert_result(result):
    if result is not None and result.returncode != 0:
        if arguments.verbose:
            print(result)
        exit(result.returncode)


def main():
    parse_arguments()

    work_dir = str(pathlib.Path(__file__).parent.resolve())
    container_tag = work_dir[1:].lower().replace('/_', '/')

    if arguments.verbose:
        print('Container Tag: ' + container_tag)

    result = build_container(container_tag, work_dir)
    assert_result(result)

    result = run_container(container_tag, work_dir)
    assert_result(result)


if __name__ == "__main__":
    main()
