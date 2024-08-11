mkdir -p temp
rm -rf temp/*

git clone --depth 1 --branch v2_k6 https://github.com/INTI-CMNB/KiBot.git temp/KiBot
docker build --no-cache --pull -t assembly_kibot temp/KiBot
