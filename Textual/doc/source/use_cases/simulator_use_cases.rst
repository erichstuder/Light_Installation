Use Cases for Simulator
=======================

.. needflow::
   :filter: docname.endswith('simulator_use_cases')
   :link_types: includes, association
   :show_link_names:
   :config: lefttoright

.. actor:: User
    :id: A_001
    :association: UC_001, UC_002, UC_003, UC_004, UC_005, UC_006

.. usecase:: Start Simulator
    :id: UC_001
    :includes: UC_002

.. usecase:: Load existing LED pattern
    :id: UC_002

.. usecase:: Create new LED pattern
    :id: UC_003
    :includes: UC_004

.. usecase:: Store LED pattern
    :id: UC_004

.. usecase:: Simulate LED pattern
    :id: UC_005
    :includes: UC_004

.. usecase:: Edit LED pattern
    :id: UC_006
