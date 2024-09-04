SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
echo $SCRIPT_DIR

mkdir -p ${SCRIPT_DIR}/temp/3d_models
rm -rf ${SCRIPT_DIR}/temp/3d_models/*

docker run --rm --volume ${SCRIPT_DIR}/../..:/home/project --workdir /home kibot_container \
	'-c project/mechanics/assembly/assembly.kibot.yaml' \
	'-b project/electronics/led_connector/led_connector.kicad_pcb'

docker run --rm --volume ${SCRIPT_DIR}/../..:/home/project --workdir /home kibot_container \
	'-c project/mechanics/assembly/assembly.kibot.yaml' \
	'-b project/electronics/cross_connector/cross_connector.kicad_pcb'

openscad -o ${SCRIPT_DIR}/temp/3d_models/clamp.stl ../clamp/clamp.scad
