#include "../../../libc/include/stdio.h"
#include "../../../libc/include/string.h"
#include "../../include/kernel/tty.h"

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++)
    {
		for (size_t x = 0; x < VGA_WIDTH; x++)
        {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) 
{
    if(c != '\n')
    {
        terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
        terminal_column++;
    }
    else
    {
        terminal_column=0;
        terminal_row++;
    }

    if(terminal_column == VGA_WIDTH)
    {
        terminal_column = 0;
        if(terminal_row == VGA_HEIGHT)
        {
            for (size_t y = 0; y < VGA_HEIGHT-1; y++)
            {
                for (size_t x = 0; x < VGA_WIDTH; x++)
                    terminal_putentryat(terminal_buffer[(y+1) * VGA_WIDTH + x],terminal_color,x,y);
            }

            for(size_t x = 0; x < VGA_WIDTH; x++)
                terminal_putentryat(' ', terminal_color, x, VGA_HEIGHT-1);

            terminal_row = VGA_HEIGHT-1;
            terminal_column = 0;
        }
        else
        {
            terminal_row++;
            return;
        }
    }
    
    if(terminal_row == VGA_HEIGHT)
    {
        for (size_t y = 0; y < VGA_HEIGHT-1; y++)
        {
            for (size_t x = 0; x < VGA_WIDTH; x++)
                terminal_putentryat(terminal_buffer[(y+1) * VGA_WIDTH + x],terminal_color,x,y);
        }

        for(size_t x = 0; x < VGA_WIDTH; x++)
            terminal_putentryat(' ', terminal_color, x, VGA_HEIGHT-1);

        terminal_row = VGA_HEIGHT-1;
        terminal_column = 0;
    }
}

void terminal_write(const char* data) 
{
	for (size_t i = 0; i < strlen(data); i++)
		terminal_putchar(data[i]);
}
 
