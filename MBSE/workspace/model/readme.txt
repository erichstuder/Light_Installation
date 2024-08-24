- It is possible to insert textual code directly into the model. But as these are only text fields (no code-completion, ...) this feature is not used.
  - The solution are user code areas that will be filled in with e.g. vs-code
  - These areas stay untouched by the code generation.
  - The generated code including changes by hand must be commited as well.

- Keep the dependencies close to the client elements (Block, InterfaceBlock, ...)
  - example
    - Package
      - Block1
        - Realization1
        - Dependency1
        :
      - Block2
        - Realization1
        - Realization2
        :
      - block3
        :
  - why?
    - Not every dependency of an element will be shown in a diagram. Unimportant ones will be left away.
    - Dependencies of an element may be not all shown in one diagram, but scattered over multiple diagrams.
    - Keeping the dependencies close to the elements gives a quick overview of the dependencies.
    - Note: Right click on the element and Navigate shows all Target (Supplier) dependencies. This lets you check if all dependencies are close the element.
