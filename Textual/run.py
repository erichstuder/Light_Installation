import sys
import pathlib

sys.path.append(str(pathlib.Path(__file__).parent.parent / 'Shared' / 'python_shared'))
from shared import run_dispatcher # type: ignore

if __name__ == "__main__":
    scripts = {
        'doc':       'doc/run.py',
        'simulator': 'simulator/run.py',
    }

    run_dispatcher(scripts)
