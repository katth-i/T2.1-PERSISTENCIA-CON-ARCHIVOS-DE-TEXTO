import java.io.*;
import java.util.Scanner;

public class GestionEstudiantes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("\n--- MENU JAVA ESTUDIANTES ---");
            System.out.println("1. Registrar");
            System.out.println("2. Salir");
            opcion = sc.nextInt();

            if (opcion == 1) {
                try (FileWriter fw = new FileWriter("estudiantes.txt", true);
                     BufferedWriter bw = new BufferedWriter(fw);
                     PrintWriter out = new PrintWriter(bw)) {
                    
                    sc.nextLine(); // Limpiar buffer
                    System.out.print("Nombre: ");
                    String nombre = sc.nextLine();
                    System.out.print("Edad: ");
                    int edad = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Carrera: ");
                    String carrera = sc.nextLine();
                    System.out.print("Promedio: ");
                    double promedio = sc.nextDouble();

                    out.println(nombre + "," + edad + "," + carrera + "," + promedio);
                    System.out.println("Guardado con exito.");
                    
                } catch (IOException e) {
                    System.out.println("Error de archivo: " + e.getMessage());
                }
            }
        } while (opcion != 2);
    }
}