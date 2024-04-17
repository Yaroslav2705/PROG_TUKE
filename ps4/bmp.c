#include "bmp.h"
#include <stdlib.h>

struct bmp_image* read_bmp(FILE* stream) {
    // Считываем заголовок
    struct bmp_header* header = read_bmp_header(stream);
    if (header == NULL) {
        return NULL;
    }

    // Считываем данные изображения
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

struct bmp_header* read_bmp_header(FILE* stream) {
    // Проверяем, что поток открыт
    if (stream == NULL) {
        //fprintf(stderr, "Error: Input stream is not open.\n");
        return NULL;
    }

    // Выделяем память под заголовок
    struct bmp_header* header = (struct bmp_header*)malloc(sizeof(struct bmp_header));
    if (header == NULL) {
        //fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Считываем заголовок из потока
    if (fread(header, sizeof(struct bmp_header), 1, stream) != 1) {
        //fprintf(stderr, "Error: Failed to read BMP header.\n");
        free(header);
        return NULL;
    }

    // Проверяем, является ли файл BMP файлом
    if (header->type != 0x4D42) { // BM
        //fprintf(stderr, "Error: This is not a BMP file.\n");
        free(header);
        return NULL;
    }

    return header;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header) {
    // Проверяем, что поток открыт и заголовок предоставлен
    if (stream == NULL || header == NULL) {
        fprintf(stderr, "Error: Input stream or BMP header is invalid.\n");
        return NULL;
    }

    // Переходим к началу данных изображения
    fseek(stream, header->offset, SEEK_SET);

    // Выделяем память под данные изображения
    struct pixel* data = (struct pixel*)malloc(header->width * header->height * sizeof(struct pixel));
    if (data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Считываем данные изображения
    if (fread(data, sizeof(struct pixel), header->width * header->height, stream) != header->width * header->height) {
        fprintf(stderr, "Error: Failed to read image data.\n");
        free(data);
        return NULL;
    }

    return data;
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
