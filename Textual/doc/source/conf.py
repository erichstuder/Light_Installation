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
from sphinx_needs.api import get_needs_view
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


def create_unit_test_execution_reports(app: Sphinx):
    tree = ET.parse('../simulator/unit_tests/build/execution_report.xml')
    root = tree.getroot()

    rst_content = []

    rst_content.append(f"Unit Test Report\n{'=' * len('Unit Test Report')}\n")

    rst_content.append(f"Tests: {root.get('tests')}\n")
    rst_content.append(f"Failures: {root.get('failures')}\n")
    rst_content.append(f"Disabled: {root.get('disabled')}\n")
    rst_content.append(f"Errors: {root.get('errors')}\n")

    for testsuite in root.findall('testsuite'):
        suite_name = testsuite.get('name')
        rst_content.append(f"{suite_name}\n{'^' * len(suite_name)}\n")

        for testcase in testsuite.findall('testcase'):
            case_name = testcase.get('name')
            rst_content.append(f"{case_name}\n{'-' * len(f'Test Case: {case_name}')}\n")

            # Check for links property
            properties = testcase.find('properties')
            if properties is not None:
                for prop in properties.findall('property'):
                    if prop.get('name') == 'links':
                        link_value = prop.get('value')
                        rst_content.append(f"- **Links**: :need:`{link_value}`\n")

            file_path = testcase.get('file')
            rst_content.append(f"- **File**: {file_path}\n")

            rst_content.append("\n")

    output_rst_file = os.path.join(app.srcdir, 'auto_generated/unit_test_reports/simulator_unit_tests_report.rst')
    os.makedirs(os.path.dirname(output_rst_file), exist_ok=True)
    with open(output_rst_file, 'w') as f:
        f.write('\n'.join(rst_content))


def copy_unit_test_coverage_reports(app: Sphinx):
    src = os.path.join(app.srcdir, '../../simulator/unit_tests/build/coverage_report')
    dest = os.path.join(app.srcdir, '_static/auto_copied/coverage_report')
    if os.path.exists(dest):
        shutil.rmtree(dest)
    shutil.copytree(src, dest)
    print(f"Copied {src} to {dest}")


def validate_needs(app, exception):
    if exception is None:
        logger = logging.getLogger(__name__)
        needs_view = get_needs_view(app).to_list_with_parts()
        inspections = needs_view.filter_types(['inspection'])

        for inspection in inspections:
            if inspection['status'] != 'pass':
                logger.warning(f'Inspection "{inspection["id"]}" is not set to "pass".')


def setup(app):
    app.connect("builder-inited", run_gherkindoc)
    app.connect('builder-inited', copy_cucumber_report)
    app.connect('builder-inited', create_unit_test_execution_reports)
    app.connect('builder-inited', copy_unit_test_coverage_reports)
    app.connect('build-finished', validate_needs)
