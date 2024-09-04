Use Cases for Device
====================

.. needflow::
   :filter: docname.endswith('device_use_cases')
   :link_types: includes, association
   :show_link_names:
   :config: lefttoright

.. actor:: User
    :id: A_101
    :association: UC_101, UC_102, UC_103, UC_104

.. usecase:: Start Device
    :id: UC_101

.. usecase:: Load LED pattern
    :id: UC_102

.. usecase:: Show LED pattern
    :id: UC_103
    :links: R_001, R_002, R_003, R_004

.. usecase:: Power down Device
    :id: UC_104
