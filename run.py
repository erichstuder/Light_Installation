from Shared.python_shared.shared import run_command, get_dispatcher

def main():
    description='Execute common tasks like building, testing, uploading, ...'

    scripts = {
        'doc': 'doc/run.py',
        'Textual': 'Textual/run.py',
    }

    dispatcher = get_dispatcher(description, scripts)

    dispatcher.group.add_argument(
        '--build_all',
        action='store_true',
        help='Build EVERYTHING: build models, compile source code, run tests, create reports, ..., and documentation).'
    )

    work_dir = dispatcher.parse_args()
    if dispatcher.arguments.build_all:
        run_command(['git', 'submodule', 'update', '--init'])

        run_command(['python3', work_dir +'/run.py', '--Textual', '--simulator', '--unit_tests',
                        '--test', '--report', '--verbose', '--pseudo_tty_off'])

        run_command(['python3', work_dir +'/run.py', '--Textual', '--simulator', '--features',
                        '--test', '--report', '--verbose', '--pseudo_tty_off'])

        run_command(['python3', work_dir +'/run.py', '--Textual', '--doc',
                        '--build', '--verbose', '--pseudo_tty_off'])

        run_command(['python3', work_dir +'/run.py', '--doc',
                        '--build', '--verbose', '--pseudo_tty_off'])
    exit(0)


if __name__ == "__main__":
    main()
