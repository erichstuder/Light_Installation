Use Cases for Device
====================

.. usecase:: Start Device
    :id: UC_101

.. usecase:: Load LED pattern
    :id: UC_102

.. usecase:: Show LED pattern
    :id: UC_103

.. usecase:: Power down Device
    :id: UC_104

.. actor:: User
    :id: A_101
    :association: UC_101, UC_102, UC_103, UC_104

.. needflow::
   :filter: docname.endswith('device_use_cases')
   :link_types: includes, association
   :show_link_names:
   :config: lefttoright
