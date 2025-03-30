# Game-Of-Life

Este proyecto es una implementación del famoso **Juego de la Vida** de John Conway en C++ utilizando la biblioteca **SDL2** para renderizar la simulación. El Juego de la Vida es un autómata celular que simula la evolución de un conjunto de celdas vivas en una cuadrícula, siguiendo reglas simples que producen patrones complejos y fascinantes.

## Características

- Simulación del Juego de la Vida con reglas estándar.
- Interfaz gráfica interactiva utilizando **SDL2**.
- Control de la simulación mediante teclado y ratón.
- Opciones para pausar, reiniciar, ajustar la velocidad, hacer zoom y mostrar/ocultar la cuadrícula.

## Controles

| Tecla/Acción         | Función                                                                 |
|-----------------------|-------------------------------------------------------------------------|
| **Espacio**           | Pausar/Reanudar la simulación.                                         |
| **R**                | Reiniciar la simulación (limpiar todas las celdas vivas).              |
| **G**                | Mostrar/Ocultar la cuadrícula.                                         |
| **+ / Teclado numérico +** | Aumentar la velocidad de la simulación (disminuir el intervalo).   |
| **- / Teclado numérico -** | Disminuir la velocidad de la simulación (aumentar el intervalo).   |
| **Rueda del ratón**   | Hacer zoom (acercar/alejar).                                           |
| **Clic izquierdo**    | Activar/Desactivar una celda en la cuadrícula.                         |
| **Clic derecho + arrastrar** | Desplazar la cuadrícula.                                        |

## Tecnologías utilizadas

- **C++20**: Lenguaje de programación utilizado para implementar la lógica del juego.
- **SDL2**: Biblioteca para gráficos y manejo de eventos.
- **SDL2_image**: Extensión de SDL2 para manejar imágenes.
- **SDL2_ttf**: Extensión de SDL2 para manejar fuentes tipográficas.

## Instalación

### Requisitos previos

Asegúrate de tener instaladas las siguientes herramientas y bibliotecas en tu sistema:

1. **Compilador C++** compatible con C++20 (como `g++`).
2. **SDL2** y sus extensiones:
   - `libsdl2-dev`
   - `libsdl2-image-dev`
   - `libsdl2-ttf-dev`

En sistemas basados en Debian/Ubuntu, puedes instalarlas con:

```bash
sudo apt update
sudo apt install g++ make libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

## Clonar Repositorio
Para poder ejecutar este repositorio en tu máquina local usa el siguiente comando:
```bash
git clone git@github.com:hugogonzalezperez/Game-Of-Life.git
cd Game-Of-Life
```

## Compilar y Ejecutar

### Compilación
Compila el proyecto utilizando el archivo makefile incluido:
```bash
make
```
Esto generará el ejecutable en el directorio bin/ con el nombre GameOfLife.

### Ejecución
Ejecuta el programa con:
```bash
./bin/GameOfLife
```

## Uso

1. Al iniciar el programa, se abrirá una ventana con la cuadrícula del Juego de la Vida.
2. Usa los controles mencionados en la tabla anterior para interactuar con la simulación.
3. Puedes pausar la simulación, agregar celdas vivas, ajustar la velocidad, hacer zoom y más.