# syntax=docker/dockerfile:1
#
# VIED (IEC 61850 / GOOSE / SV) em container.
# Construir a partir da raiz: docker build --build-arg APP_DIR=examples/VIED_81 -t vied .

###############################################################################
# Estágio 1 - compila a lib e o VIED integrado via CMake (focado no alvo)
###############################################################################
FROM debian:bookworm-slim AS build

RUN apt-get update \
 && apt-get install -y --no-install-recommends build-essential cmake \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /opt/libiec61850
COPY . .

# Argumento da pasta do app (ex: examples/VIED_81)
ARG APP_DIR=examples/VIED_81

# Valida se os ficheiros existem
RUN test -f "${APP_DIR}/server_example_goose.c" && test -f "${APP_DIR}/static_model.c" \
 || { echo "ERRO: Ficheiros do app nao encontrados em ${APP_DIR}."; exit 1; }

# Substitui o exemplo padrão do repositório pelos seus ficheiros personalizados do VIED_81
RUN cp -f ${APP_DIR}/server_example_goose.c examples/server_example_goose/ \
 && cp -f ${APP_DIR}/static_model.c examples/server_example_goose/ \
 && if [ -f "${APP_DIR}/static_model.h" ]; then cp -f ${APP_DIR}/static_model.h examples/server_example_goose/; fi

# Configura o CMake com os exemplos ativados
RUN cmake -S . -B build \
        -DBUILD_EXAMPLES=ON \
        -DBUILD_TESTS=OFF \
        -DBUILD_PYTHON_BINDINGS=OFF \
        -DWITH_MBEDTLS=OFF \
        -DWITH_MBEDTLS3=OFF

# Compila EXCLUSIVAMENTE o alvo do seu servidor GOOSE (evita os erros dos outros exemplos)
RUN cmake --build build --target server_example_goose --parallel "$(nproc)"

# Copia o binário final gerado para a pasta temporária
RUN cp build/examples/server_example_goose/server_example_goose /tmp/vied

###############################################################################
# Estágio 2 - imagem final
###############################################################################
FROM debian:bookworm-slim AS runtime

ARG APP_DIR=examples/VIED_81

COPY --from=build /tmp/vied /usr/local/bin/vied

# O programa abre "Ajustes_*.txt" pelo diretório ATUAL (/config)
WORKDIR /config
COPY ${APP_DIR}/Ajustes_*.txt /config/

# Servidor MMS
EXPOSE 10102/tcp

STOPSIGNAL SIGINT

ENTRYPOINT ["stdbuf", "-oL", "/usr/local/bin/vied"]
CMD ["enp2s0"]
