from docutils import nodes
from sphinx.util.docutils import SphinxDirective
from sphinx.errors import SphinxError
import subprocess

class CheckedFileHashesError(SphinxError):
    category = 'Checked File Hashes error'


def get_last_commit_hash(file_path):
    try:
        result = subprocess.run(
            ['git', 'log', '-n', '1', '--pretty=format:%h', '--', file_path],
            check=True, capture_output=True, text=True
        )
        return result.stdout.strip()
    except subprocess.CalledProcessError as e:
        raise CheckedFileHashesError(f"Error retrieving hash for {file_path}: {e}\n{e.stderr}")


def create_table(content):
    table = nodes.table()
    tgroup = nodes.tgroup(cols=2)
    table += tgroup
    tgroup += nodes.colspec(colwidth=1)
    tgroup += nodes.colspec(colwidth=1)

    # Create the table header
    thead = nodes.thead()
    tgroup += thead
    row = nodes.row()
    thead += row
    row += nodes.entry('', nodes.paragraph(text='File'))
    row += nodes.entry('', nodes.paragraph(text='Hash'))

    tbody = nodes.tbody()
    tgroup += tbody
    for line in content:
        file_path, expected_hash = line.split()
        row = nodes.row()
        tbody += row
        row += nodes.entry('', nodes.Text(file_path))
        row += nodes.entry('', nodes.Text(expected_hash))
    return table


class CheckedFileHashesDirective(SphinxDirective):
    has_content = True

    def run(self):
        for line in self.content:
            file_path, expected_hash = line.split()
            actual_hash = get_last_commit_hash(file_path)
            if actual_hash != expected_hash:
                raise CheckedFileHashesError(f"Hash mismatch for {file_path}: expected {expected_hash}, got {actual_hash}")

        return [create_table(self.content)]


def setup(app):
    app.add_directive('checked-file-hashes', CheckedFileHashesDirective)
