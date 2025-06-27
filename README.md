# carsService
# Sistema de Registro de Clientes y Servicios Vehiculares

Este programa en C++ permite registrar información de clientes, sus vehículos y los servicios solicitados. Está diseñado para un entorno como un taller mecánico o centro de atención vehicular. La información se almacena en un archivo de texto plano llamado `Fichero1.txt`.

---

##  Funcionalidades Principales

- Registro de **clientes** con:
  - Identidad válida (13 dígitos)
  - Nombre (solo letras y espacios)
  - Sexo (M/F)
  - Fecha de nacimiento (día, mes, año)
- Cálculo automático de la **edad** del cliente.
- Registro de **vehículos**:
  - Placa válida (7 caracteres)
  - Marca, modelo, color
  - Año de fabricación (1960–2025)
  - Tipo de vehículo (6 opciones)
- Registro de **servicios solicitados**:
  - Lavado
  - Engrase
  - Parqueo
  - Cambio de aceite
- Validaciones de entradas incorrectas o duplicadas.
- Almacenamiento de datos en `Fichero1.txt`.

---

##  Estructuras Usadas

```cpp
struct cliente { string nombre, ident; char sexo; int fechas[3]; };
struct carro { string placa, marca, modelo, color; int year, tipo; };
struct servicio { int horaentr[2], horasalid[2], servicio[4]; };
struct fact { cliente datosCl; carro datosCar; servicio datosServ; };
```

---

##  Archivo Generado

- `Fichero1.txt`: Contiene los datos ingresados (clientes, carros y servicios), grabados secuencialmente por cliente.

---

##  Validaciones Incluidas

- **Identidad**: 13 dígitos numéricos.
- **Nombre**: Letras y espacios únicamente.
- **Sexo**: 'M' o 'F'.
- **Placa**: 7 caracteres.
- **Año del vehículo**: Entre 1960 y 2025.
- **Tipo de vehículo**: Opción entre 1 y 6.
- **Cantidad y tipo de servicios**: 1 a 4 servicios, sin repetir.

---

##  Cómo usar

1. Ejecuta el programa.
2. Selecciona si deseas agregar un cliente.
3. Ingresa la información que el programa solicita paso a paso.
4. La información será validada.
5. Al finalizar, los datos se almacenan en `Fichero1.txt`.

---

##  Mejoras posibles

- Implementar sistema de menús con múltiples funcionalidades (consulta, eliminación, edición).
- Validación más robusta de fechas.
- Manejo de hora de entrada y salida para servicios.
- Agregar almacenamiento binario o uso de base de datos.
- Dividir el código en múltiples archivos y funciones reutilizables.

---

##  Requisitos

- Compilador de C++ (como g++, MinGW o Visual Studio).
- Sistema con soporte para `ctime`, `fstream` y `algorithm`.

---

##  Autor

Desarrollado como parte de un ejercicio educativo para gestión de clientes y servicios de vehículos.
