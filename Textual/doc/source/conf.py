# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import subprocess
from sphinx.application import Sphinx

project = 'Light Installation - Textual'
copyright = '2024, erichstuder'
author = 'erichstuder'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'sphinxcontrib.drawio',
    'sphinxcontrib.plantuml',
    # 'sphinx_toolbox.collapse',
    'sphinxcontrib.programoutput',
    'sphinx_needs',
]

templates_path = ['_templates']

exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
# html_static_path = ['_static']

# html_css_files = [
#     'custom.css',
# ]

drawio_no_sandbox = True

needs_types = [
    {"directive": "usecase", "title": "Use Case", "prefix": "UC_", "style": "node", "color": "#BFD8D2"},
]
