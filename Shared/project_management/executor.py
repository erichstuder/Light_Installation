import argparse
import subprocess
import datetime
import sys
import pathlib

sys.path.append(str(pathlib.Path(__file__).parent))
import common

class Executor:
    def __init__(self, additional_arguments, description):
        self._parse_arguments(additional_arguments, description)

        self.work_dir = common.get_caller_path()
        self.container_tag = self.work_dir[1:].lower().replace('/_', '/')
        self.docker_volume_dir = '/usr/project'

        if self.arguments.verbose:
            print('Container Tag: ' + self.container_tag)

        self._build_container(self.container_tag, self.work_dir)

        self.docker_args = self._get_base_docker_args(self.work_dir)


    def _parse_arguments(self, additional_arguments, description):
        parser = argparse.ArgumentParser(description)

        for argument in additional_arguments:
            parser.add_argument(argument['flag'], argument['name'],
                                action='store_true',
                                help=argument['help'])

        parser.add_argument('-v', '--verbose',
                            action='store_true',
                            help='Verbose output.')

        parser.add_argument('-k', '--keep_open',
                            action='store_true',
                            help='Enter the command line of the container.')

        parser.add_argument('-p', '--pseudo_tty_off',
                            action='store_true',
                            help='Disable colorfull output.')

        self.arguments = parser.parse_args()


    def _build_container(self, container_tag, work_dir):
        args = ['docker', 'build', '--tag', container_tag]

        if not self.arguments.verbose:
            args.append('--quiet')
            stdout = subprocess.DEVNULL
        else:
            stdout = None

        args.append(work_dir)

        result = subprocess.run(args, stdout=stdout)
        if result.returncode != 0:
            raise RuntimeError(f"Failed with result: {result}")


    def _get_base_docker_args(self, work_dir):
        current_time = datetime.datetime.now().strftime('%Hh_%Mm_%Ss')
        return ['docker', 'run', '--rm', '--name', 'doc_' + current_time]


    def run(self, commands):
        if self.arguments.keep_open:
            commands = 'bash'

        if self.arguments.pseudo_tty_off:
            self.docker_args.append('-i')
        else:
            self.docker_args.append('-it')

        self.docker_args.extend([self.container_tag, 'bash', '-c', commands])

        result = subprocess.run(self.docker_args)
        if result.returncode != 0:
            raise RuntimeError(f"Failed with result: {result}")
