Use Cases for Simulator
=======================

.. needflow::
   :filter: docname.endswith('simulator_use_cases')
   :link_types: includes, association
   :show_link_names:
   :config: lefttoright

.. actor:: User
    :id: A_001
    :association: UC_001, UC_003, UC_004, UC_007

.. usecase:: Start Simulator
    :id: UC_001
    :includes: UC_002, UC_005, UC_006

    - When the simulator is started, it is compiled and then run.
    - It is started via a script file.

.. usecase:: Load LED pattern
    :id: UC_002

    - Which LED pattern to show is hard-coded in the code.

.. usecase:: Create new LED pattern
    :id: UC_003

    - LED patterns can be developed with the simulator.
    - They are directly edited in the code.
    - C++ is used as the programming language.

.. usecase:: Store LED pattern
    :id: UC_004

.. usecase:: Simulate LED pattern
    :id: UC_005

    - The simulator shows a 3D model of the Light Installation.
    - The LED pattern is simulated as it would look like on the real Light Installation.

.. usecase:: Rotate 3D model
    :id: UC_006

    - During the simulation the 3D model can be rotated with the mouse.

.. usecase:: Edit LED pattern
    :id: UC_007

    - LED patterns are directly edited in the code.
