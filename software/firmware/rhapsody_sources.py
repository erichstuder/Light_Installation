import os

Import("env")

path = "rhapsody/firmware/Component/Config"

env.BuildSources(
    os.path.join("$BUILD_DIR", path),
    os.path.join("$PROJECT_DIR", path)
)
