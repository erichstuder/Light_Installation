import argparse
import subprocess
import pathlib
import sys

scripts = {
    'doc': 'doc/run.py',
    'simulator': 'simulator/run.py',
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
    arguments = parser.parse_args()

    work_dir = str(pathlib.Path(__file__).parent.resolve())
    if arguments.help_all:
        result = subprocess.run(['python3', work_dir + '/run.py', '--help'])
        if result.returncode != 0:
            exit(result.returncode)
        print('\n\n*** below are the help messages of the subscripts ***')
        for _, value in scripts.items():
            print('\n\n*** ' + value + ' ***')
            sys.stdout.flush()
            result = subprocess.run(['python3', work_dir + '/' + value, '--help'])
            if result.returncode != 0:
                exit(result.returncode)
    elif arguments.doc is not None:
        exit(subprocess.run(['python3', work_dir + '/' + scripts['doc']] + arguments.doc).returncode)
    elif arguments.simulator is not None:
        exit(subprocess.run(['python3', work_dir + '/' + scripts['simulator']] + arguments.simulator).returncode)
    else:
        print('Unknown argument')
        exit(2)


if __name__ == "__main__":
    main()
