

#include <stdint.h>


int main(void)
{
	uint32_t *ptr_RCC_CLKREG	= (uint32_t*)0x40023830;
	uint32_t *ptr_GPIOA_MODREG 	= (uint32_t*)0x40020000;
	uint32_t *ptr_GPIOD_MODREG 	= (uint32_t*)0x40020C00;
	uint32_t *ptr_GPIO_ODR 		= (uint32_t*)0x40020C14;
	uint32_t *ptr_GPIO_IDR 		= (uint32_t*)0x40020010;

	//Enable RCC CLK REG for GPIOA & GPIOD
	*ptr_RCC_CLKREG |= (1 << 0); //GPIOA
	*ptr_RCC_CLKREG |= (1 << 3); //GPIOD


	//CONFIGURE THE MODE OF I/O PIN

	//CONFIGURE PA0 AS INPUT MODE
	*ptr_GPIOA_MODREG &= ~(3 << 0);

	//CLEAR THE MODE REG GPIOD
	*ptr_GPIOD_MODREG &= ~(3 << 24);

	//SET THE MODE REG FOR GPIOD 12 PIN AS OUTPUT MODE
	*ptr_GPIOD_MODREG |= (1 << 24);


    /* Loop forever */
	for(;;)
	{
		uint8_t PA0 = (uint8_t)(*ptr_GPIO_IDR & 0x1); //zero out all other bits

		if(PA0){
		//GREEN LED ON
			*ptr_GPIO_ODR |= (1 << 12);
		}else{
		//GREEN LED OFF
			*ptr_GPIO_ODR &= ~(1 << 12);
		}
	}

}
