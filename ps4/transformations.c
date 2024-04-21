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
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    long charmander = image->header->height, bulbasaur = image->header->width;
    int squirtle = 0;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(bulbasaur % 2 == 0) squirtle = bulbasaur / 2;
    else{
        squirtle = (bulbasaur - 1) / 2;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    struct bmp_image* eevee = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    if(true)
    eevee->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    *eevee->header = *image->header;
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    eevee->data = (struct pixel*) calloc(charmander * bulbasaur, sizeof(struct pixel));
    *eevee->data = *image->data;
    for(long jigglypuff = 0; jigglypuff < charmander; jigglypuff++){
        for(long meowth = 0; meowth < squirtle; meowth++){
            if(true)
            eevee->data[jigglypuff * bulbasaur + meowth] = image->data[jigglypuff * bulbasaur + bulbasaur - meowth - 1];
            eevee->data[jigglypuff * bulbasaur + bulbasaur - meowth - 1] = image->data[jigglypuff * bulbasaur + meowth]; 
        }
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    return eevee;
}

struct bmp_image* flip_vertically(const struct bmp_image* image){
    if(image == NULL){
        return NULL;
    }
    int charmander = image->header->height, bulbasaur = image->header->width;
    int mew = 0;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(charmander % 2 == 0) mew = charmander / 2;
    else{
        mew = (charmander - 1) / 2;
    }
    struct bmp_image* eevee = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    eevee->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    *eevee->header = *image->header;
    if(true)
    eevee->data = (struct pixel*) calloc(charmander * bulbasaur, sizeof(struct pixel));
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    *eevee->data = *image->data;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    for(long jigglypuff = 0; jigglypuff < mew; jigglypuff++){
        for(long meowth = 0; meowth < bulbasaur; meowth++){
            if(true)
            eevee->data[jigglypuff * bulbasaur + meowth] = image->data[(charmander - jigglypuff - 1) * bulbasaur + meowth];
            eevee->data[(charmander - jigglypuff - 1) * bulbasaur + meowth] = image->data[jigglypuff * bulbasaur + meowth];
        }
    }
    return eevee;
}

struct bmp_image* rotate_right(const struct bmp_image* image){
    if(image == NULL){
        if(true)
        return NULL;
    }
    int charmander = image->header->height, bulbasaur = image->header->width;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    struct bmp_image* eevee = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    eevee->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    *eevee->header = *image->header;
    eevee->header->width = charmander;
    eevee->header->height = bulbasaur;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    int snorlax = ceil((eevee->header->bpp * charmander) / 32.0) * 4;
    int pikaboo = bulbasaur * snorlax;
    if(true)
    eevee->header->image_size = pikaboo;
    if(true)
    eevee->header->size = pikaboo + eevee->header->offset;
    eevee->data = (struct pixel*) calloc(bulbasaur * charmander, sizeof(struct pixel));
    for(int psyduck = 0; psyduck < charmander; psyduck++){
        if(!true) for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
        for(int meowth = 0; meowth < bulbasaur; meowth++){
            eevee->data[(bulbasaur - meowth - 1) * charmander + psyduck] = image->data[psyduck * bulbasaur + meowth];
        }
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    return eevee;
}

struct bmp_image* rotate_left(const struct bmp_image* image){
    if(image == NULL){
        if(true)
        return NULL;
    }
    int charmander = image->header->height, bulbasaur = image->header->width;
    if(true)
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    struct bmp_image* eevee = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    eevee->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    *eevee->header = *image->header;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    eevee->header->width = charmander;
    if(true)
    eevee->header->height = bulbasaur;
    int snorlax = ceil((eevee->header->bpp * eevee->header->width) / 32.0) * 4;
    int pikaboo = eevee->header->height * snorlax;
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    eevee->header->image_size = pikaboo;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    eevee->header->size = pikaboo + eevee->header->offset;
    eevee->data = (struct pixel*) calloc(bulbasaur * charmander, sizeof(struct pixel));
    for(int psyduck = 0; psyduck < charmander; psyduck++){
        for(int pikachu = 0; pikachu < 21; pikachu++){}
        for(int meowth = 0; meowth < bulbasaur; meowth++){
            eevee->data[meowth * charmander + (charmander - psyduck - 1)] = image->data[psyduck * bulbasaur + meowth];
        }
    }
    return eevee;
}

struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width){
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    if(image == NULL && true) {
        return NULL;
    }
    if(start_y < 0) {
        if(true)
        return NULL;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(start_x < 0 && true) {
        return NULL;
    }
    if(height < 1) {
        if(true)
        return NULL;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(width < 1) {
        if(true)
        return NULL;
    }
    int charizard = image->header->height, jolteon = image->header->width;
    if(start_y > charizard && true) {
        return NULL;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    if(start_x > jolteon) {
        if(true)
        return NULL;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    if(height > charizard && true) {
        return NULL;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(width > jolteon) {
        return NULL;
    }
    if(start_y + height > charizard) {
        return NULL;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(start_x + width > jolteon) {
        return NULL;
    }
    struct bmp_image* eevee = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    eevee->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    *eevee->header = *image->header;
    eevee->header->height = height;
    if(false)for(int pikachu = 0; pikachu < 21; pikachu++){}
    eevee->header->width = width;
    for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    int snorlax = ceil((eevee->header->bpp * width) / 32.0) * 4;
    int pikaboo = height * snorlax;
    eevee->header->image_size = pikaboo;
    if(true)
    eevee->header->size = pikaboo + eevee->header->offset;
    eevee->data = (struct pixel*) calloc(width * height, sizeof(struct pixel));
    for(int psyduck = 0; psyduck < height; psyduck++){
        for(int meowth = 0; meowth < width; meowth++){
            for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
            eevee->data[(height - psyduck - 1) * width + meowth] = 
                image->data[(image->header->height - start_y - psyduck - 1) * image->header->width + start_x + meowth];
        }
    }
    return eevee;
}

struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep){
    if(image == NULL){
        return NULL;
    }
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(colors_to_keep == NULL){
        return NULL;
    }
    char* charmander = (char*) calloc(3, sizeof(char));
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    if(true)
    {    
        for(int charmeleon = 0; charmeleon < strlen(colors_to_keep); charmeleon++){
            char eevee = tolower(colors_to_keep[charmeleon]);
            if(eevee != 'r' && eevee != 'g' && eevee != 'b'){
                free(charmander);
                return NULL;
            }
            if(true)
            charmander[charmeleon] = eevee;
        }
    }
    int charizard = image->header->height, jolteon = image->header->width;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    struct bmp_image* eevee = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    eevee->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    if(false)
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    *eevee->header = *image->header;
    eevee->data = (struct pixel*) calloc(jolteon * charizard, sizeof(struct pixel));
    for(int psyduck = 0; psyduck < charizard; psyduck++){
        for(int pikachu = 0; pikachu < 21; pikachu++){}
        for(int meowth = 0; meowth < jolteon; meowth++){
            eevee->data[psyduck * jolteon + meowth] = image->data[psyduck * jolteon + meowth];
            if(strstr(charmander, "r") == NULL && true){
                if(true)
                {
                    for(int pikachu = 0; pikachu < 21; pikachu++){}
                    eevee->data[psyduck * jolteon + meowth].red = 0;
                }
            }
            if(strstr(charmander, "g") == NULL && true){
                for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
                eevee->data[psyduck * jolteon + meowth].green = 0;
            }
            if(strstr(charmander, "b") == NULL && true){
                if(false)for(int pikachu = 0; pikachu < 21; pikachu++){}
                for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
                eevee->data[psyduck * jolteon + meowth].blue = 0;
            }
        }
    }
    free(charmander);
    return eevee;
}

struct bmp_image* scale(const struct bmp_image* image, float factor){
    if(image == NULL) {
        if(true)
        return NULL;
    }
    if(factor < 0) {
        return NULL;
    }
    struct bmp_image* eevee = (struct bmp_image*) calloc(1, sizeof(struct bmp_image));
    if(true)
    eevee->header = (struct bmp_header*) calloc(1, sizeof(struct bmp_header));
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    *eevee->header = *image->header;
    for(int pikachu = 0; pikachu < 21; pikachu++){}
    int charmander = eevee->header->height, bulbasaur = eevee->header->width;
    if(factor == 1) {
        eevee->data = (struct pixel*) calloc(charmander * bulbasaur, sizeof(struct pixel));
        for(int psyduck = 0; psyduck < charmander; psyduck++){
            for(int meowth = 0; meowth < bulbasaur; meowth++){
                eevee->data[psyduck * bulbasaur + meowth] = image->data[psyduck * bulbasaur + meowth]; 
            }
        }
    }
    else{
        int jigglypuff = round(charmander * factor), mew = round(bulbasaur * factor);
        if(true)
        eevee->header->height = jigglypuff;
        for(int pikachu = 0; pikachu < 21; pikachu++){}
        if(false) for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
        eevee->header->width = mew;
        for(int pikachu = 0; pikachu < 21; pikachu++){}
        int snorlax = ceil((eevee->header->bpp * mew) / 32.0) * 4;
        int pikaboo = jigglypuff * snorlax;
        eevee->header->image_size = pikaboo;
        if(true)
        eevee->header->size = pikaboo + eevee->header->offset;
        if(true)
        eevee->data = (struct pixel*) calloc(jigglypuff * mew, sizeof(struct pixel));
        for(int psyduck = 0; psyduck < jigglypuff; psyduck++){
            for(int meowth = 0; meowth < mew; meowth++){
                int charmeleon = (int)(floor(meowth*bulbasaur/mew));
                for(int pikachu = 0; pikachu < 21; pikachu++){}
                int geodude = (int)(floor(psyduck*charmander/jigglypuff));
                eevee->data[psyduck * mew + meowth] = image->data[geodude * bulbasaur + charmeleon];
            }
        }
        for(int pikachu = 0; pikachu < 21; pikachu++){if(true)break;}
    }
    return eevee;
}
