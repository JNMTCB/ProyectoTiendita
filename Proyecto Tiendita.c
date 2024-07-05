//Cardos Becerra Juan Mateo Proyecto: Tiendita
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100

// Estructura para un producto
typedef struct {
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

// Estructura para una venta
typedef struct {
    Producto producto;
    int cantidad;
} Venta;

Producto inventario[MAX_PRODUCTOS];  // Arreglo para almacenar el inventario de productos
int numProductos = 0;  // Contador de la cantidad actual de productos en inventario

// Prototipos de funciones
void mostrarMenu();
void agregarProducto();
void mostrarInventario();
void modificarProducto();
void eliminarProducto();
void realizarVenta();

int main() {
    int opcion;

    do {
        mostrarMenu();  // Mostrar el menú de opciones
        scanf("%d", &opcion);  // Leer la opción elegida por el usuario
        fflush(stdin);  // Limpiar el buffer del teclado

        switch (opcion) {
            case 1:
                agregarProducto();  // Opción para agregar un producto al inventario
                break;
            case 2:
                mostrarInventario();  // Opción para mostrar el inventario de productos
                break;
            case 3:
                modificarProducto();  // Opción para modificar un producto del inventario
                break;
            case 4:
                eliminarProducto();  // Opción para eliminar un producto del inventario
                break;
            case 5:
                realizarVenta();  // Opción para realizar una venta
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);  // Continuar el ciclo hasta que el usuario elija salir

    return 0;
}

void mostrarMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Agregar producto al inventario\n");
    printf("2. Mostrar inventario\n");
    printf("3. Modificar producto del inventario\n");
    printf("4. Eliminar producto del inventario\n");
    printf("5. Realizar venta\n");
    printf("6. Salir\n");
    printf("Ingrese la opción deseada: ");
}

void agregarProducto() {
    if (numProductos >= MAX_PRODUCTOS) {  // Verificar si el inventario está lleno
        printf("No es posible agregar más productos. Inventario lleno.\n");
        return;
    }

    Producto nuevoProducto;
    printf("Ingrese el nombre del producto: ");
    fgets(nuevoProducto.nombre, 50, stdin);  // Leer el nombre del producto
    nuevoProducto.nombre[strcspn(nuevoProducto.nombre, "\n")] = '\0';  // Eliminar el salto de línea

    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevoProducto.precio);  // Leer el precio del producto

    printf("Ingrese la cantidad inicial en inventario: ");
    scanf("%d", &nuevoProducto.cantidad);  // Leer la cantidad inicial en inventario

    inventario[numProductos] = nuevoProducto;  // Agregar el nuevo producto al inventario
    numProductos++;  // Incrementar el contador de productos en inventario

    printf("Producto agregado al inventario correctamente.\n");
}

void mostrarInventario() {
    if (numProductos == 0) {  // Verificar si el inventario está vacío
        printf("El inventario está vacío.\n");
        return;
    }

    printf("\n--- Inventario de la Tienda ---\n");
    printf("%-30s %-10s %-10s\n", "Nombre", "Precio", "Cantidad");
    for (int i = 0; i < numProductos; i++) {
        printf("%-30s %-10.2f %-10d\n", inventario[i].nombre, inventario[i].precio, inventario[i].cantidad);  // Mostrar cada producto en el inventario
    }
}

void modificarProducto() {
    if (numProductos == 0) {  // Verificar si el inventario está vacío
        printf("El inventario está vacío. No hay productos para modificar.\n");
        return;
    }

    char nombreBuscar[50];
    printf("Ingrese el nombre del producto que desea modificar: ");
    fgets(nombreBuscar, 50, stdin);  // Leer el nombre del producto a modificar
    nombreBuscar[strcspn(nombreBuscar, "\n")] = '\0';  // Eliminar el salto de línea

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].nombre, nombreBuscar) == 0) {  // Buscar el producto por su nombre
            printf("Ingrese el nuevo precio para %s: ", inventario[i].nombre);
            scanf("%f", &inventario[i].precio);  // Actualizar el precio del producto

            printf("Ingrese la nueva cantidad en inventario para %s: ", inventario[i].nombre);
            scanf("%d", &inventario[i].cantidad);  // Actualizar la cantidad en inventario del producto

            printf("Producto modificado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado en el inventario.\n");
    }
}

void eliminarProducto() {
    if (numProductos == 0) {  // Verificar si el inventario está vacío
        printf("El inventario está vacío. No hay productos para eliminar.\n");
        return;
    }

    char nombreEliminar[50];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    fgets(nombreEliminar, 50, stdin);  // Leer el nombre del producto a eliminar
    nombreEliminar[strcspn(nombreEliminar, "\n")] = '\0';  // Eliminar el salto de línea

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].nombre, nombreEliminar) == 0) {  // Buscar el producto por su nombre
            for (int j = i; j < numProductos - 1; j++) {
                inventario[j] = inventario[j + 1];  // Eliminar el producto moviendo los siguientes hacia atrás
            }
            numProductos--;  // Decrementar la cantidad de productos en inventario
            printf("Producto eliminado del inventario correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado en el inventario.\n");
    }
}

void realizarVenta() {
    if (numProductos == 0) {  // Verificar si el inventario está vacío
        printf("El inventario está vacío. No se pueden realizar ventas.\n");
        return;
    }

    float totalVenta = 0.0;
    Venta venta;
    int continuar = 1;

    printf("Ingrese el nombre del producto a vender: ");
    fgets(venta.producto.nombre, 50, stdin);  // Leer el nombre del producto a vender
    venta.producto.nombre[strcspn(venta.producto.nombre, "\n")] = '\0';  // Eliminar el salto de línea

    printf("Ingrese la cantidad a vender: ");
    scanf("%d", &venta.cantidad);  // Leer la cantidad a vender

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(inventario[i].nombre, venta.producto.nombre) == 0) {  // Buscar el producto por su nombre
            if (inventario[i].cantidad >= venta.cantidad) {  // Verificar si hay suficiente cantidad en inventario
                totalVenta = venta.cantidad * inventario[i].precio;  // Calcular el total de la venta
                inventario[i].cantidad -= venta.cantidad;  // Actualizar la cantidad en inventario
                printf("Venta realizada correctamente.\n");
            } else {
                printf("No hay suficiente cantidad en inventario para realizar la venta.\n");
            }
            continuar = 0;
            break;
        }
    }

    if (continuar) {
        printf("Producto no encontrado en el inventario.\n");
    }

    printf("Total de la venta: %.2f\n", totalVenta);  // Mostrar el total de la venta realizada
}
