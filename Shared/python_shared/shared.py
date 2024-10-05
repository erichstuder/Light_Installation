import argparse
import subprocess
import inspect
import os
import sys


class Dispatcher:
    def __init__(self, scripts, description=None):
        if description is None:
            description = 'Execute common tasks (building, testing, ...)'
        self.scripts = scripts
        self.parser = argparse.ArgumentParser(description=description)
        self.group = self.parser.add_mutually_exclusive_group(required=True)
        for key, value in self.scripts.items():
            self.group.add_argument('--'+key,
                                    nargs=argparse.REMAINDER,
                                    help='Pass the remaining arguments to ' + value + '.')
        self.group.add_argument('--ha', '--help_all', dest='help_all',
                                action='store_true',
                                help='Show help for this and all direct subscripts.')


    def parse_args(self):
        self.arguments = self.parser.parse_args()
        work_dir = self._get_caller_path()

        if self.arguments.help_all:
            run_command(['python3', work_dir + '/run.py', '--help'])
            print('\n\n*** below are the help messages of the subscripts ***')
            for _, value in self.scripts.items():
                print('\n\n*** ' + value + ' ***')
                sys.stdout.flush()
                run_command(['python3', work_dir + '/' + value, '--help'])

        else:
            for key in self.scripts:
                script_args = getattr(self.arguments, key)
                if script_args is not None:
                    run_command(['python3', work_dir + '/' + self.scripts[key]] + script_args)
                    break

        return work_dir


    def _get_caller_path(self):
        current_file = os.path.abspath(__file__)
        for frame in inspect.stack():
            caller_file = os.path.abspath(frame.filename)
            if caller_file != current_file:
                return os.path.dirname(caller_file)
        return os.path.dirname(current_file)


def get_dispatcher(scripts, description=None):
    return Dispatcher(scripts, description)


def run_dispatcher(scripts, description=None):
    dispatcher = get_dispatcher(scripts, description)
    dispatcher.parse_args()
    exit(0)


def run_command(command):
    # result = subprocess.run(command, capture_output=True, text=True)
    result = subprocess.run(command)
    if result.returncode != 0:
        raise RuntimeError(f"Failed with result: {result}")
