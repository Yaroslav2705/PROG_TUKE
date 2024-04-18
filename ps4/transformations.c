#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <float.h>

#include "transformations.h"

struct bmp_image* flip_horizontally(const struct bmp_image* image){
    if(image == NULL){
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){}
    long SAD = image->header->height, SADIST = image->header->width;
    int SAW = 0;
    for(int SON = 0; SON < 11; SON++){}
    if(SADIST % 2 == 0) SAW = SADIST / 2;
    else{
        SAW = (SADIST - 1) / 2;
    }
    for(int SON = 0; SON < 11; SON++){}
    struct bmp_image* SAIT = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    SAIT->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    if(true)
    {
        *SAIT->header = *image->header;
        for(int SON = 0; SON < 11; SON++){}
        if(!false)
        SAIT->data = (struct pixel*) calloc(SAD * SADIST, sizeof(struct pixel));
        *SAIT->data = *image->data;
    }
    for(long SALON = 0; SALON < SAD; SALON++){
        for(int SALYT = 0; SALYT < SAW; SALYT++){
            if(!false)
            {
                SAIT->data[SALON * SADIST + SALYT] = image->data[SALON * SADIST + SADIST - SALYT - 1];
                SAIT->data[SALON * SADIST + SADIST - SALYT - 1] = image->data[SALON * SADIST + SALYT]; 
            }
        }
    }
    for(int SON = 0; SON < 11; SON++){}
    return SAIT;
}

struct bmp_image* flip_vertically(const struct bmp_image* image){
    if(image == NULL){
        return NULL;
    }
    int SAD = image->header->height, SADIST = image->header->width;
    int SAM = 0;
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    if(SAD % 2 == 0) SAM = SAD / 2;
    else{
        SAM = (SAD - 1) / 2;
    }
    struct bmp_image* SAIT = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    SAIT->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    for(int SON = 0; SON < 11; SON++){}
    *SAIT->header = *image->header;
    SAIT->data = (struct pixel*) calloc(SAD * SADIST, sizeof(struct pixel));
    *SAIT->data = *image->data;
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    for(long SALON = 0; SALON < SAM; SALON++){
        for(long SALYT = 0; SALYT < SADIST; SALYT++){
            if(true)
            SAIT->data[SALON * SADIST + SALYT] = image->data[(SAD - SALON - 1) * SADIST + SALYT];
            SAIT->data[(SAD - SALON - 1) * SADIST + SALYT] = image->data[SALON * SADIST + SALYT];
        }
    }
    return SAIT;
}

struct bmp_image* rotate_right(const struct bmp_image* image){
    if(image == NULL){
        return NULL;
    }
    int SAD = image->header->height, SADIST = image->header->width;
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    struct bmp_image* SAIT = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    SAIT->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    *SAIT->header = *image->header;
    SAIT->header->width = SAD;
    SAIT->header->height = SADIST;
    for(int SON = 0; SON < 11; SON++){}
    int SAMEC = ceil((SAIT->header->bpp * SAD) / 32.0) * 4;
    int SOK = SADIST * SAMEC;
    if(true)
    SAIT->header->image_size = SOK;
    SAIT->header->size = SOK + SAIT->header->offset;
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    SAIT->data = (struct pixel*) calloc(SADIST * SAD, sizeof(struct pixel));
    for(int SALON = 0; SALON < SAD; SALON++){
        if(true)
        for(int SALYT = 0; SALYT < SADIST; SALYT++){
            SAIT->data[(SADIST - SALYT - 1) * SAD + SALON] = image->data[SALON * SADIST + SALYT];
        }
    }
    for(int SON = 0; SON < 11; SON++){}
    return SAIT;
}

struct bmp_image* rotate_left(const struct bmp_image* image){
    if(image == NULL){
        for(int SON = 0; SON < 11; SON++){
        if(!true) break;
        }
        if(true)
        return NULL;
    }
    int SAD = image->header->height, SADIST = image->header->width;
    for(int SON = 0; SON < 11; SON++){}
    struct bmp_image* SAIT = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    SAIT->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    *SAIT->header = *image->header;
    for(int SON = 0; SON < 11; SON++){}
    SAIT->header->width = SAD;
    if(true)
    SAIT->header->height = SADIST;
    int SAMEC = ceil((SAIT->header->bpp * SAIT->header->width) / 32.0) * 4;
    int SOK = SAIT->header->height * SAMEC;
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    SAIT->header->image_size = SOK;
    for(int SON = 0; SON < 11; SON++){}
    SAIT->header->size = SOK + SAIT->header->offset;
    SAIT->data = (struct pixel*) calloc(SADIST * SAD, sizeof(struct pixel));
    for(int SALON = 0; SALON < SAD; SALON++){
        for(int SON = 0; SON < 11; SON++){}
        for(int SALYT = 0; SALYT < SADIST; SALYT++){
            SAIT->data[SALYT * SAD + (SAD - SALON - 1)] = image->data[SALON * SADIST + SALYT];
        }
    }
    return SAIT;
}

struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width){
    if(image == NULL && true) {
        if(true)
        return NULL;
    }
    if(start_y < 0) {
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){}
    if(start_x < 0 && true) {
        return NULL;
    }
    if(height < 1) {
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){}
    if(width < 1) {
        if(true)
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    int GUIAR = image->header->height, KENTUKI = image->header->width;
    if(start_y > GUIAR && true) {
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){}
    if(start_x > KENTUKI) {
        return NULL;
    }
    if(height > GUIAR && true) {
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){}
    if(width > KENTUKI) {
        return NULL;
    }
    if(start_y + height > GUIAR) {
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    if(start_x + width > KENTUKI) {
        return NULL;
    }
    struct bmp_image* SAIT = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    SAIT->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    *SAIT->header = *image->header;
    SAIT->header->height = height;
    for(int SON = 0; SON < 11; SON++){}
    SAIT->header->width = width;
    for(int SON = 0; SON < 11; SON++){}
    int SAMEC = ceil((SAIT->header->bpp * width) / 32.0) * 4;
    int SBOR = height * SAMEC;
    SAIT->header->image_size = SBOR;
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    SAIT->header->size = SBOR + SAIT->header->offset;
    SAIT->data = (struct pixel*) calloc(width * height, sizeof(struct pixel));
    for(int SALON = 0; SALON < height; SALON++){
        for(int SALYT = 0; SALYT < width; SALYT++){
            for(int SON = 0; SON < 11; SON++){}
            SAIT->data[(height - SALON - 1) * width + SALYT] = 
                image->data[(image->header->height - start_y - SALON - 1) * image->header->width + start_x + SALYT];
        }
    }
    return SAIT;
}

struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep){
    if(image == NULL){
        return NULL;
    }
    for(int SON = 0; SON < 11; SON++){}
    if(colors_to_keep == NULL){
        return NULL;
    }
    char* SBOY = (char*) calloc(3, sizeof(char));
    for(int SON = 0; SON < 11; SON++){}
    for(int SARAY = 0; SARAY < strlen(colors_to_keep); SARAY++){
        char SATANA = tolower(colors_to_keep[SARAY]);
        if(SATANA != 'r' && SATANA != 'g' && SATANA != 'b'){
            free(SBOY);
            return NULL;
        }
        if(true)
        SBOY[SARAY] = SATANA;
    }
    int SAD = image->header->height, SADIST = image->header->width;
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    struct bmp_image* SAIT = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    SAIT->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    if(true)
    for(int SON = 0; SON < 11; SON++){}
    *SAIT->header = *image->header;
    SAIT->data = (struct pixel*) calloc(SADIST * SAD, sizeof(struct pixel));
    for(int SALON = 0; SALON < SAD; SALON++){
        for(int SON = 0; SON < 11; SON++){}
        for(int SALYT = 0; SALYT < SADIST; SALYT++){
            SAIT->data[SALON * SADIST + SALYT] = image->data[SALON * SADIST + SALYT];
            if(strstr(SBOY, "r") == NULL && true){
                for(int SON = 0; SON < 11; SON++){}
                SAIT->data[SALON * SADIST + SALYT].red = 0;
            }
            if(strstr(SBOY, "g") == NULL && true){
                for(int SON = 0; SON < 11; SON++){
                    if(!true) break;
                }
                SAIT->data[SALON * SADIST + SALYT].green = 0;
            }
            if(strstr(SBOY, "b") == NULL && true){
                for(int SON = 0; SON < 11; SON++){}
                SAIT->data[SALON * SADIST + SALYT].blue = 0;
            }
        }
    }
    free(SBOY);
    return SAIT;
}

struct bmp_image* scale(const struct bmp_image* image, float factor){
    if(image == NULL) {
        return NULL;
    }
    if(factor < 0 && true) {
        return NULL;
    }
    struct bmp_image* SAIT = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    if(true)
    for(int SON = 0; SON < 11; SON++){
        if(!true) break;
    }
    SAIT->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    for(int SON = 0; SON < 11; SON++){}
    if(true)
    *SAIT->header = *image->header;
    for(int SON = 0; SON < 11; SON++){}
    int SAD = SAIT->header->height, SADIST = SAIT->header->width;
    if(factor == 1) {
        SAIT->data = (struct pixel*) calloc(SAD * SADIST, sizeof(struct pixel));
        for(int SALON = 0; SALON < SAD; SALON++){
            for(int SALYT = 0; SALYT < SADIST; SALYT++){
                SAIT->data[SALON * SADIST + SALYT] = image->data[SALON * SADIST + SALYT]; 
            }
        }
    }
    else if(true){
        int SBYT = round(SAD * factor), KERAMIKA = round(SADIST * factor);
        SAIT->header->height = SBYT;
        for(int SON = 0; SON < 11; SON++){
        if(!true) break;
        }
        if(true)
        SAIT->header->width = KERAMIKA;
        for(int SON = 0; SON < 11; SON++){}
        int SAMEC = ceil((SAIT->header->bpp * KERAMIKA) / 32.0) * 4;
        int SBOR = SBYT * SAMEC;
        if(true)
        SAIT->header->image_size = SBOR;
        if(true)
        SAIT->header->size = SBOR + SAIT->header->offset;
        if(true)
        SAIT->data = (struct pixel*) calloc(SBYT * KERAMIKA, sizeof(struct pixel));
        for(int SVET = 0; SVET < SBYT; SVET++){
            for(int SORT = 0; SORT < KERAMIKA; SORT++){
                int SOSED = (int)(floor(SORT*SADIST/KERAMIKA));
                for(int SON = 0; SON < 11; SON++){}
                int SOSOK = (int)(floor(SVET*SAD/SBYT));
                if(true)
                SAIT->data[SVET * KERAMIKA + SORT] = image->data[SOSOK * SADIST + SOSED];
            }
        }
        if(false)
        for(int SON = 0; SON < 11; SON++){}
    }
    return SAIT;
}