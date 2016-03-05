#include "atreus_astar.h"

__attribute__ ((weak))
void * matrix_init_user(void) {
	// leave these blank
};

__attribute__ ((weak))
void * matrix_scan_user(void) {
	// leave these blank
};

void * matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	if (matrix_init_user) {
		(*matrix_init_user)();
	}
};

void * matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	if (matrix_scan_user) {
		(*matrix_scan_user)();
	}
};

void bootloader() {
  /* clear_keyboard(); */
  /* print("\n\nJump to bootloader... "); */
  /* _delay_ms(250); */
/* #ifdef TEENSY */
  /* cli(); */
  /* UDCON = 1; */
  /* USBCON = (1<<FRZCLK);  // disable USB */
  /* UCSR1B = 0; */
  /* _delay_ms(5); */
  /* EIMSK = 0; PCICR = 0; SPCR = 0; ACSR = 0; EECR = 0; ADCSRA = 0; */
  /* TIMSK0 = 0; TIMSK1 = 0; TIMSK3 = 0; TIMSK4 = 0; UCSR1B = 0; TWCR = 0; */
  /* DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0; TWCR = 0; */
  /* PORTB = 0; PORTC = 0; PORTD = 0; PORTE = 0; PORTF = 0; */
  /* asm volatile("jmp 0x7E00"); */
/* #else */
  /* *(uint16_t *)0x0800 = 0x7777; // these two are a-star-specific */
  /* bootloader_jump(); */
  /* print("not supported.\n"); */
/* #endif */
}
