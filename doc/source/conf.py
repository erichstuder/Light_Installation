# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import subprocess
from sphinx.application import Sphinx
import os
import shutil
import warnings

project = 'Light Installation'
copyright = '2024, erichstuder'
author = 'erichstuder'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    # 'sphinxcontrib.drawio',
    # 'sphinxcontrib.plantuml',
    # 'sphinx_toolbox.collapse',
    'sphinxcontrib.programoutput',
    # 'sphinxcontrib_rust',
]

templates_path = ['_templates']

exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']

# drawio_no_sandbox = True

def pre_build_copy_textual_documentation(app):
    src = os.path.join(app.srcdir, '../../Textual/doc/build')
    dest = os.path.join(app.srcdir, '_static/auto_copied/Textual/build')
    if os.path.exists(src):
        if os.path.exists(dest):
            shutil.rmtree(dest)
        shutil.copytree(src, dest)
        print(f"Copied Textual documentation from {src} to {dest}")
    else:
        warnings.warn(f"No Textual documentation to copy.")

def setup(app):
    app.connect('builder-inited', pre_build_copy_textual_documentation)
