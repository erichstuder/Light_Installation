docker run --rm --volume $(pwd)/../..:/home/project --workdir /home/project/Shared/electronics/cross_connector kibot_container \
    '-c cross_connector.kibot.yaml' \
    '-b cross_connector.kicad_pcb' \
    '-e cross_connector.kicad_sch' \
	'-d production_data'

docker run --rm --volume $(pwd)/../..:/home/project --workdir /home/project/Shared/electronics/led_connector kibot_container \
    '-c led_connector.kibot.yaml' \
    '-b led_connector.kicad_pcb' \
    '-e led_connector.kicad_sch' \
	'-d production_data'

# openscad -o ${SCRIPT_DIR}/temp/3d_models/clamp.stl ../clamp/clamp.scad
