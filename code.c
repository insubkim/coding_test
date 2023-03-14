#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int get_lux(const char* wallpaper[], size_t wallpaper_len) {
    int i;
    int j;
    
    i = 0;
    while (i < wallpaper_len) {
        j = 0;
        while (wallpaper[i][j]) {
            if (wallpaper[i][j] == '#')
                return (i);
            j++;
        }
        i++;
    }
    return (0);
}

int get_luy(const char* wallpaper[], size_t wallpaper_len) {
    int i;
    int j;
    
    j = 0;
    while (wallpaper[0][j]) {
        i = 0;
        while (i < wallpaper_len) {
            if (wallpaper[i][j] == '#')
                return (j);
            i++;
        }
        j++;
    }
    return (0);
}

int get_rdx(const char* wallpaper[], size_t wallpaper_len) {
    int i;
    int j;
    
    i = wallpaper_len - 1;
    while (i >= 0) {
        j = 0;
        while (wallpaper[i][j]) {
            if (wallpaper[i][j] == '#')
                return (i);
            j++;
        }
        i--;
    }
    return (0);
}

int get_rdy(const char* wallpaper[], size_t wallpaper_len) {
    int i;
    int j;
    
    j = strlen(wallpaper[0]) - 1;
    while (j >= 0) {
        i = wallpaper_len - 1;
        while (i >= 0) {
            if (wallpaper[i][j] == '#')
                return (j);
            i--;
        }
        j--;
    }
    return (0);
}

int* solution(const char* wallpaper[], size_t wallpaper_len) {
    int* coord;
    
    coord = (int*)malloc(4);
    if (!coord)
        return (NULL);
    coord[0] = get_lux(wallpaper, wallpaper_len);
    coord[1] = get_luy(wallpaper, wallpaper_len);
    coord[2] = get_rdx(wallpaper, wallpaper_len) + 1;
    coord[3] = get_rdy(wallpaper, wallpaper_len) + 1;
    return coord;
}

int main()
{
    const char* wallpaper[] = {".#.", "#..", "..."};
    int* coord;
    
    coord = solution(wallpaper, 3);
    printf("%d %d %d %d", coord[0], coord[1], coord[2], coord[3]);
    return (0);
}
/*
1 ≤ wallpaper의 길이 ≤ 50
1 ≤ wallpaper[i]의 길이 ≤ 50
wallpaper의 모든 원소의 길이는 동일합니다.
wallpaper[i][j]는 바탕화면에서 i + 1행 j + 1열에 해당하는 칸의 상태를 나타냅니다.
wallpaper[i][j]는 "#" 또는 "."의 값만 가집니다.
바탕화면에는 적어도 하나의 파일이 있습니다.
드래그 시작점 (lux, luy)와 끝점 (rdx, rdy)는 lux < rdx, luy < rdy를 만족해야 합니다.
*/