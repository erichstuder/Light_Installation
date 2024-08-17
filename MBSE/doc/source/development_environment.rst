Development Environment
=======================

This document describes the development environment and tools.

Local Toolchain
---------------
.. drawio-image:: toolchain_local.drawio

Eclipse IDE
^^^^^^^^^^^
Base IDE containing tools like Papyrus, Acceleo and others.

Papyrus
^^^^^^^
Used to create the model.

Acceleo
^^^^^^^
Used to generate code from the model.

Setup
-----
To work on this project on a local machine, the following tools need to be installed:

- VS Code
- Docker
- Python
- Eclipse IDE

Eclipse IDE setup
^^^^^^^^^^^^^^^^^
1. Install Eclipse IDE
    - Download `Eclipse IDE <https://www.eclipse.org/downloads/download.php?file=/oomph/epp/2024-06/R/eclipse-inst-jre-linux64.tar.gz>`_
    - Extract and run installation with ./eclipse-inst
    - Later versions may work, but this is the version used for development as of writing this document.
    - Open Eclipse IDE and select the workspace that contains the projects (see: :doc:`file_structure`).
    - Import all projects of the workspace.

2. Install Papyrus and Acceleo
    - Eclipse IDE -> Help -> Install New Software -> Work with: \--All Available Sites\--
       - Modeling -> select Acceleo and Papyrus for UML
       - Install

       .. image:: select_Acceleo.png

       :

       .. image:: select_Papyrus_for_UML.png

    - Eclipse IDE -> Help -> Eclipse Marketplace -> Fing: papyrus sysml 1.6
       - Install Papyrus SysML 1.6

       .. image:: select_Papyrus_SysML.png

3. Update Eclipse IDE
    Allthough not strictly necessary it is recommended to update Eclipse IDE to the latest version.
    - Eclipse IDE -> Help -> Check for Updates
