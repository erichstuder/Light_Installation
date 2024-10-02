import argparse
import pathlib
import sys

from Shared.shared import run_command

scripts = {
    'doc': 'doc/run.py',
    'Textual': 'Textual/run.py',
}


def main():
    parser = argparse.ArgumentParser(description='Execute common tasks like building, testing, uploading, ...')
    group = parser.add_mutually_exclusive_group(required=True)
    for key, value in scripts.items():
        group.add_argument('--'+key,
                           nargs=argparse.REMAINDER,
                           help='Pass the remaining arguments to ' + value + '.')
    group.add_argument('--ha', '--help_all', dest='help_all',
                       action='store_true',
                       help='Show help for this and all direct subscripts.')
    group.add_argument('--build_all',
                       action='store_true',
                       help='Build EVERYTHING: build models, compile source code, run tests, create reports, ..., and documentation).')
    arguments = parser.parse_args()

    work_dir = str(pathlib.Path(__file__).parent.resolve())
    if arguments.help_all:
        run_command(['python3', work_dir + '/run.py', '--help'])
        print('\n\n*** below are the help messages of the subscripts ***')
        for _, value in scripts.items():
            print('\n\n*** ' + value + ' ***')
            sys.stdout.flush()
            run_command(['python3', work_dir + '/' + value, '--help'])

    elif arguments.build_all:
        run_command(['git', 'submodule', 'update', '--init'])

        run_command(['python3', work_dir +'/run.py', '--Textual', '--simulator', '--unit_tests',
                     '--test', '--report', '--verbose', '--pseudo_tty_off'])

        run_command(['python3', work_dir +'/run.py', '--Textual', '--simulator', '--features',
                     '--test', '--report', '--verbose', '--pseudo_tty_off'])

        run_command(['python3', work_dir +'/run.py', '--Textual', '--doc',
                     '--build', '--verbose', '--pseudo_tty_off'])

        run_command(['python3', work_dir +'/run.py', '--doc',
                     '--build', '--verbose', '--pseudo_tty_off'])

    for key in scripts:
        script_args = getattr(arguments, key)
        if script_args is not None:
            run_command(['python3', work_dir + '/' + scripts[key]] + script_args)
            break
    else:
        raise argparse.ArgumentError('Unknown argument')

    exit(0)


if __name__ == "__main__":
    main()
