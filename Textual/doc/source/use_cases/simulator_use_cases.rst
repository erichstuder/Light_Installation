Use Cases for Simulator
=======================

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

.. actor:: User
    :id: A_001
    :association: UC_001, UC_002, UC_003, UC_004, UC_005, UC_006


.. needflow::
   :filter: is_need
   :link_types: includes, association
   :show_link_names:
   :config: lefttoright
