# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import subprocess
from sphinx.application import Sphinx
from sphinx.errors import SphinxError
from sphinx.util import logging
import os
import sys
import shutil
import xml.etree.ElementTree as ET


project = 'Light Installation - Textual'
copyright = '2024, erichstuder'
author = 'erichstuder'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

sys.path.append(os.path.abspath("./_custom_extensions"))

extensions = [
    'sphinxcontrib.drawio',
    'sphinxcontrib.plantuml',
    # 'sphinx_toolbox.collapse',
    'sphinxcontrib.programoutput',
    'sphinx_needs',
    'checked_file_hashes',
]

templates_path = ['_templates']

exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'

html_static_path = ['_static']

html_css_files = [
    'gherkin.css',
]

drawio_no_sandbox = True

needs_types = [
    {
        "directive": "req",
        "title": "Requirement",
        "prefix": "R_",
        "color": "#BFD8D2",
        "style": "node",
    },
    {
        "directive": "feature",
        "title": "Feature",
        "prefix": "F_",
        "color": "#BFD8D2",
        "style": "node",
    },
    {
        "directive": "inspection",
        "title": "Inspection",
        "prefix": "INSP_",
        "color": "#DCB239",
        "style": "node",
    },
    {
        "directive": "usecase",
        "title": "Use Case",
        "prefix": "UC_",
        "color": "#BFD8D2",
        "style": "usecase",
    },
    {
        "directive": "actor",
        "title": "Actor",
        "prefix": "A_",
        "color": "#BFD8D2",
        "style": "actor",
    },
]

needs_extra_links = [
    {
        "option": "includes",
        "incoming": "is included by",
        "outgoing": "<<include>>",
        "copy": False,
        "style": "#000000",
        "style_part": "#000000",
        "style_start": ".",
        "style_end": "->"
    },
    {
        "option": "association",
        "incoming": "is associated with",
        "outgoing": "",
        "copy": False,
        "style": "#000000",
        "style_part": "#000000",
        "style_start": "-",
        "style_end": "-"
    },
]

def run_gherkindoc(app: Sphinx):
    features_dir = os.path.join(app.srcdir, 'auto_generated/features')
    subprocess.run(['sphinx-gherkindoc', '--raw-descriptions', '--doc-project', 'DOC_PROJECT', '../simulator/features', features_dir], check=True)
    subprocess.run(['rm', os.path.join(features_dir, 'gherkin.rst')], check=True)

    # Remove the '%' character from the beginning of lines in files in the source/auto_generated/features directory
    # This is a workaround for now as the parser removes all whitespaces from the beginning of lines which leads to invalid requirements.
    for root, _, files in os.walk(features_dir):
        for file in files:
            file_path = os.path.join(root, file)
            with open(file_path, 'r') as f:
                lines = f.readlines()
            with open(file_path, 'w') as f:
                for line in lines:
                    if line.startswith('%'):
                        f.write(line[1:])  # Remove the '%' character
                    else:
                        f.write(line)


def copy_cucumber_report(app):
    src = os.path.join(app.srcdir, '../../simulator/features/build/simulator_cucumber_report.html')
    dest = os.path.join(app.srcdir, '_static/auto_copied/')
    os.makedirs(dest, exist_ok=True)
    shutil.copy(src, dest)
    print(f"Copied {src} to {dest}")


def validate_needs(app, exception):
    if exception is None:
        logger = logging.getLogger(__name__)
        env = app.builder.env
        for need in env.needs_all_needs.values():
            if need['type'] == 'inspection':
                if 'status' not in need or not need['status']:
                    raise SphinxError(f'Inspection "{need["id"]}" is missing the "status" field.')
                elif need['status'] != 'pass':
                    logger.warning(f'Inspection "{need["id"]}" is not set to "pass".')


def setup(app):
    app.connect("builder-inited", run_gherkindoc)
    app.connect('builder-inited', copy_cucumber_report)
    app.connect('build-finished', validate_needs)
