FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

# Compila o executavel incluindo a librt (-lrt) para suporte a SHM
RUN gcc -O2 -DRT -DUSE_RTMODEL -DNCSTATES=0 *.c -I. -o microrrede.elf -lm -lrt

CMD ["./microrrede.elf"]
