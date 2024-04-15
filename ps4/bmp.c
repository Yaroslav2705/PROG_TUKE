#include "bmp.h"
#include <stdlib.h>

struct bmp_image* read_bmp(FILE* stream) {
    // Читаем заголовок
    struct bmp_header* header = read_bmp_header(stream);
    if (header == NULL) {
        return NULL;
    }

    // Читаем данные изображения
    struct pixel* data = read_data(stream, header);
    if (data == NULL) {
        free(header);
        return NULL;
    }

    // Создаем структуру для хранения всего изображения
    struct bmp_image* image = (struct bmp_image*)malloc(sizeof(struct bmp_image));
    if (image == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(header);
        free(data);
        return NULL;
    }

    // Сохраняем заголовок и данные в структуре изображения
    image->header = header;
    image->data = data;

    return image;
}

bool write_bmp(FILE* stream, const struct bmp_image* image) {
    if (stream == NULL || image == NULL || image->header == NULL || image->data == NULL) {
        return false;
    }

    // Записываем заголовок
    fwrite(image->header, sizeof(struct bmp_header), 1, stream);

    // Записываем данные изображения
    fwrite(image->data, sizeof(struct pixel), image->header->width * image->header->height, stream);

    return true;
}

void free_bmp_image(struct bmp_image* image) {
    if (image != NULL) {
        if (image->header != NULL) {
            free(image->header);
        }
        if (image->data != NULL) {
            free(image->data);
        }
        free(image);
    }
}
