#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bios.h>
#include <ctype.h>

#define VIDEO_INT 0x10

typedef struct {
    int number;
    int mode_value;
    const char* description;
} ModeInfo;

void display_modes_ui(int is_graphics);
void change_mode(int mode, int is_graphics);
void clear_screen();

void clear_screen() {
    clrscr();
}

void display_modes_ui(int is_graphics) {
    clear_screen();
    
    const ModeInfo* modes;
    int count;
    const char* title;
    
    if (is_graphics) {
        static const ModeInfo graphics_modes[] = {
            {1, 0x04, "1. Mode 0x04: 320x200, 4 colors"},
            {2, 0x06, "2. Mode 0x06: 640x200, 2 colors"},
            {3, 0x10, "3. Mode 0x10: 640x350, 16 colors"},
            {4, 0x13, "4. Mode 0x13: 320x200, 256 colors"},
            {5, 0x12, "5. Mode 0x12: 640x480, 16 colors"},
            {6, 0x07, "6. Mode 0x07: 720x400, monochrome text"},
            {7, 0x102, "7. Mode 0x102: 800x600, 16 colors"},
            {8, 0x105, "8. Mode 0x105: 1024x768, 16 colors"},
            {9, 0x107, "9. Mode 0x107: 1280x1024, 16 colors"}
        };
        modes = graphics_modes;
        count = 9;
        title = "Dos Resolution/Mode Changer Ver 0\nGraphics Modes:";
    } else {
        static const ModeInfo text_modes[] = {
            {1, 0x00, "1. Mode 0x00: 40x25, 16 colors"},
            {2, 0x01, "2. Mode 0x01: 40x25, 16 colors (alt.)"},
            {3, 0x02, "3. Mode 0x02: 80x25, 16 colors"},
            {4, 0x03, "4. Mode 0x03: 80x25, 16 colors (def.)"},
            {5, 0x07, "5. Mode 0x07: 80x25, monochrome"},
            {6, 0x0F, "6. Mode 0x0F: 80x25, monochrome (Vga 720x400)"}
        };
        modes = text_modes;
        count = 6;
        title = "Dos Resolution/Mode Changer Ver 0\nText Modes:";
    }
    
    printf("\n%s\n\n", title);
    for (int i = 0; i < count; i++) {
        printf("%s\n", modes[i].description);
    }
    
    printf("\nPress 1-%d to select, %c for %s, Q to quit: ",
           count, is_graphics ? 'T' : 'G', 
           is_graphics ? "text modes" : "graphics modes");
    
    char choice = toupper(getch());
    if (choice == 'T' && is_graphics) {
        display_modes_ui(0);
    } else if (choice == 'G' && !is_graphics) {
        display_modes_ui(1);
    } else if (choice >= '1' && choice <= '0' + count) {
        change_mode(choice - '0', is_graphics);
    } else if (choice == 'Q') {
        exit(0);
    } else {
        printf("\nInvalid choice!");
        delay(1000);
        display_modes_ui(is_graphics);
    }
}

void change_mode(int mode, int is_graphics) {
    int mode_value;
    const char* mode_str;
    
    if (is_graphics) {
        if (mode < 1 || mode > 9) return;
        static const ModeInfo modes[] = {
            {1,0x04},{2,0x06},{3,0x10},{4,0x13},
            {5,0x12},{6,0x07},{7,0x102},{8,0x105},{9,0x107}
        };
        mode_value = modes[mode-1].mode_value;
        mode_str = "Graphics Mode";
    } else {
        if (mode < 1 || mode > 6) return;
        static const ModeInfo modes[] = {
            {1,0x00},{2,0x01},{3,0x02},
            {4,0x03},{5,0x07},{6,0x0F}
        };
        mode_value = modes[mode-1].mode_value;
        mode_str = "Text Mode";
    }
    
    clear_screen();
    printf("Changing to %s %d...", mode_str, mode);
    
    union REGS regs;
    regs.h.ah = 0x00;
    regs.h.al = mode_value;
    int86(VIDEO_INT, &regs, &regs);
    
    delay(1000);
    display_modes_ui(is_graphics);
}

int main() {
    display_modes_ui(1); // Start with graphics modes
    return 0;
}