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
    subprocess.run(['sphinx-gherkindoc', '--toc-name', 'simulator_features', '--doc-project', 'DOC_PROJECT', '../simulator/features', 'source/auto_generated/features'], check=True)

logger = logging.getLogger(__name__)

def validate_needs(app, exception):
    if exception is None:
        env = app.builder.env
        for need in env.needs_all_needs.values():
            if need['type'] == 'inspection':
                if 'status' not in need or not need['status']:
                    raise SphinxError(f'Inspection "{need["id"]}" is missing the "status" field.')
                elif need['status'] != 'pass':
                    logger.warning(f'Inspection "{need["id"]}" is not set to "pass".')

def setup(app):
    app.connect("builder-inited", run_gherkindoc)
    app.connect('build-finished', validate_needs)
