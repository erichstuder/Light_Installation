from Shared.project_management.dispatcher import Dispatcher, run_command

if __name__ == "__main__":
    scripts = {
        'doc': 'doc/run.py',
        'Textual': 'Textual/run.py',
    }

    dispatcher = Dispatcher(scripts)

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
