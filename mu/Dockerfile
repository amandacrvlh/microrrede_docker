FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Instala dependências de compilação e git
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gcc \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# 1. Baixa a biblioteca libiec61850 v1.5
RUN git clone -b v1.5 https://github.com/mz-automation/libiec61850.git /app/libiec61850

# 2. Compila a biblioteca na raiz dela (gerando o arquivo build/libiec61850.a)
RUN cd /app/libiec61850 && make

# 3. Cria a pasta do projeto exatamente dois níveis abaixo da raiz (para bater com o ../../)
WORKDIR /app/libiec61850/examples/mu_virtual

# 4. Copia os seus arquivos (mu.c, static_model.c, shared_struct.h) para cá
COPY . .

# 5. Executa a compilação exata que o usuário antigo deixou no script, adicionando a biblioteca de tempo real (-lrt)
RUN gcc -g -o mu_virtual mu.c static_model.c \
    -I../../config \
    -I../../hal/inc \
    -I../../src/common/inc \
    -I../../src/mms/inc \
    -I../../src/mms/inc_private \
    -I../../src/mms/asn1 \
    -I../../src/iec61850/inc \
    -I../../src/iec61850/inc_private \
    -I../../src/goose \
    -I../../src/sampled_values \
    -I../../src/logging \
    -I../../src/tls \
    ../../build/libiec61850.a \
    -lpthread -lm -lrt

CMD ["./mu_virtual", "eth0"]
