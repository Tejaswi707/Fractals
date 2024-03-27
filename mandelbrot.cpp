#include <iostream>
#include <graphics.h>

const int WIDTH = 800;
const int HEIGHT = 800;
const int MAX_ITERATIONS = 1000;

// Function to check if a complex number is in the Mandelbrot set
int mandelbrot(double cr, double ci) {
    double zr = 0, zi = 0, zr_temp;
    int iterations = 0;
    while (zr * zr + zi * zi <= 4 && iterations < MAX_ITERATIONS) {
        zr_temp = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = zr_temp;
        iterations++;
    }
    return iterations;
}

// Function to map pixel coordinates to complex plane coordinates with centering and scaling
void mapToComplex(double& cr, double& ci, int x, int y) {
    cr = (3.0 * (x - WIDTH / 2)) / (0.5 * WIDTH);
    ci = (2.0 * (y - HEIGHT / 2)) / (0.5 * HEIGHT);
}

// Function to draw the Mandelbrot set in grayscale
void drawMandelbrot() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double cr, ci;
            mapToComplex(cr, ci, x, y);
            int iterations = mandelbrot(cr, ci);
            // Map the number of iterations to a grayscale value
            int intensity = 255 - (255 * iterations) / MAX_ITERATIONS;
            putpixel(x, y, intensity);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawMandelbrot();

    getch();
    closegraph();
    return 0;
}
