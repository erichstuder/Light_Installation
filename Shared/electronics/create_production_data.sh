SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
echo $SCRIPT_DIR
echo $(pwd)



mkdir -p temp/production_data
rm -rf temp/production_data/*

docker run --rm --volume $(pwd)/../..:/home/project --workdir /home/project kibot_container \
    '-c Shared/electronics/cross_connector/cross_connector.kibot.yaml' \
    '-b Shared/electronics/cross_connector/cross_connector.kicad_pcb' \
    '-e Shared/electronics/cross_connector/cross_connector.kicad_sch'


exit 0

docker run --rm --volume ${SCRIPT_DIR}/../..:/home/project --workdir /home kibot_container \
    '-c project/mechanics/assembly/assembly.kibot.yaml' \
    '-b project/electronics/cross_connector/cross_connector.kicad_pcb'

openscad -o ${SCRIPT_DIR}/temp/3d_models/clamp.stl ../clamp/clamp.scad
