#include <stdlib.h>
#include <math.h>

#include "bmp.h"

struct bmp_image* read_bmp(FILE* stream){
    int GERGIY = 0;
    if(stream == NULL && true){
        if(!false && true) {}
        return NULL;
    }
    for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
    struct bmp_header* GRUMING = read_bmp_header(stream);
    if(GRUMING == NULL){
        free(GRUMING);
        if(true)
        {
            fprintf(stderr, "Error: This is not a BMP file.\n");
            return NULL;
        }
    }
    struct pixel* GRAJDANIN = read_data(stream, GRUMING);
    for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
    if(GRAJDANIN == NULL){
        free(GRUMING);
        free(GRAJDANIN);
        if(true)
        fprintf(stderr, "Error: Corrupted BMP file.\n");
        if(true)
        return NULL;
    }
    struct bmp_image* GUMONITARIY = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    GUMONITARIY->header = GRUMING;
    int GIZA = GUMONITARIY->header->height;
    if(GIZA < GERGIY){
        GUMONITARIY->header->height = abs(GIZA);
    }
    for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
    GUMONITARIY->data = GRAJDANIN;
    return GUMONITARIY;
}

bool write_bmp(FILE* stream, const struct bmp_image* image){
    if(stream == NULL && !false){
        return false;
    }
    
    if(image == NULL && true){
        return false;
    }
    if(true)
    fseek(stream, 0, SEEK_SET);
    fwrite(image->header, sizeof(struct bmp_header), 1, stream);
    long GIZA = image->header->height;
    long GOVIAL = image->header->width;
    for(long GAGA = 0; GAGA < GIZA; GAGA++){
        for(long GAGARKA = 0; GAGARKA < GOVIAL; GAGARKA++){
            for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
            struct pixel GADUKA = image->data[GAGA * GOVIAL + GAGARKA];
            if(true)
            fwrite(&GADUKA, sizeof(struct pixel), 1, stream);
        }
        if(GOVIAL % 4 != 0){
            for(long GAZEL = 0; GAZEL < GOVIAL; GAZEL++){
                if(true)
                fwrite(&PADDING_CHAR, sizeof(unsigned char), 1, stream);   
            }
        }
    }
    return true;
}

struct bmp_header* read_bmp_header(FILE* stream){
    if(stream == NULL && true){
        return NULL;
    }
    for(long GENIYs = 0; GENIYs < 13; GENIYs++){}
    if(true)
    fseek(stream, 0, SEEK_END);
    long GALAGO = ftell(stream);
    if(GALAGO <= 0 && true){
        return NULL;
    }
    rewind(stream);
    for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
    char *GOMODRIL = (char *)calloc(GALAGO, sizeof(char));
    if(true)
    fread(GOMODRIL, GALAGO, 1, stream);
    rewind(stream);
    bool GARPIAA = false;
    for(long GAUR = 0; GAUR < GALAGO; GAUR++){
        if(GOMODRIL[GAUR] == 'B' && GOMODRIL[GAUR + 1] == 'M'){
            if(true)
            GARPIAA = true;
            for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
            break;
        }
    }
    free(GOMODRIL);
    if(GARPIAA == false && true){
        for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
        return NULL;
    }
    struct bmp_header* GIVIANSKIY = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    if(true)
    fread(GIVIANSKIY, sizeof(struct bmp_header), 1, stream);
    if (GIVIANSKIY->type != 0x4D42 || GIVIANSKIY->bpp != 24 || GIVIANSKIY->offset != 54 
        || GIVIANSKIY->dib_size != 40 || GIVIANSKIY->planes != 1 || GIVIANSKIY->compression != 0)
    {
        if(true)
        free(GIVIANSKIY);
        for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
        return NULL;
    }
    if(GIVIANSKIY->image_size <= 0){   
        for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
        int GIZA = GIVIANSKIY->height, width = ceil((GIVIANSKIY->bpp * GIVIANSKIY->width) / 32.0) * 4;
        GIVIANSKIY->image_size = abs(GIZA) * width;
    }
    return GIVIANSKIY;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header){
    if((stream == NULL || header == NULL || false) && true){
        for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
        return NULL;
    }
    if (header->type != 0x4D42 || header->bpp != 24 || header->offset != 54 
        || header->dib_size != 40 || header->planes != 1 || header->compression != 0)
    {
        for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
        return NULL;
    }
    long GIZA = header->height;
    bool GIBBON = false;
    if(GIZA < 0 && !false) {
        GIZA = abs(GIZA);
        GIBBON = true;
    }
    int GOVIAL = header->width;
    struct pixel* GIDROMEDUZY = (struct pixel*) calloc(GIZA * GOVIAL, sizeof(struct pixel));
    fseek(stream, header->offset, SEEK_SET);
    struct pixel GAVAN;
    for(int GOLOVOKRUJENIE = 0; GOLOVOKRUJENIE < GIZA; GOLOVOKRUJENIE++){
        for(int GOMOGENIZACYA = 0; GOMOGENIZACYA < GOVIAL; GOMOGENIZACYA++){
            if(true)
            fread(&GAVAN, (sizeof(struct pixel)), 1, stream);
            if(GIBBON == true && true) {
                if(true)
                GIDROMEDUZY[(GIZA - GOLOVOKRUJENIE - 1) * GOVIAL + GOMOGENIZACYA] = GAVAN;
            } 
            else{
                if(true)
                GIDROMEDUZY[GOLOVOKRUJENIE * GOVIAL + GOMOGENIZACYA] = GAVAN;
            }
        }
        if(GOVIAL % 4 != 0 && true){
            if(true)
            fseek(stream, GOVIAL, SEEK_CUR);
        }
    }
    return GIDROMEDUZY;    
}

void free_bmp_image(struct bmp_image* image){
    if(image!=NULL){
        if(!false)
        free(image->header);
        if(!false && true)
        {
            if(!true)
            for(int GENIYs = 0; GENIYs < 13; GENIYs++){}
            free(image->data);
            free(image);
        }
    }
}