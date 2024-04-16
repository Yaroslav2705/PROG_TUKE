#include <stdio.h>
#include "bmp.h"

int main() {
    // Открываем файл для чтения
    FILE* input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    // Загружаем изображение BMP из файла
    struct bmp_image* image = read_bmp(input_file);
    if (image == NULL) {
        fprintf(stderr, "Error: Failed to load BMP image.\n");
        fclose(input_file);
        return 1;
    }

    // Закрываем файл после чтения
    fclose(input_file);

    // Открываем файл для записи
    FILE* output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Failed to open output file.\n");
        free_bmp_image(image);
        return 1;
    }

    // Сохраняем изображение BMP в файл
    if (!write_bmp(output_file, image)) {
        fprintf(stderr, "Error: Failed to write BMP image.\n");
        fclose(output_file);
        free_bmp_image(image);
        return 1;
    }

    // Закрываем файл после записи
    fclose(output_file);

    // Освобождаем память, выделенную для изображения
    free_bmp_image(image);

    printf("BMP image loaded and saved successfully.\n");

    return 0;
}
