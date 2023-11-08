#include "STD_TYPES.h"
#include "BIT_UTILS.h"
#include "GPIO.h"
#include "GPIO_prv.h"
#include "GPIO_cfg.h"

//  void Gpio_FInit(void){
//                                         /********************* FOR PERIFIERAL GPIOA */
//     MGPIO_PORTA_REG->MODER  = CONC_B(GET_BIT(GPIO_PIN_PA15,7),GET_BIT(GPIO_PIN_PA15,6),GET_BIT(GPIO_PIN_PA14,7),GET_BIT(GPIO_PIN_PA14,6),
//                                      GET_BIT(GPIO_PIN_PA13,7),GET_BIT(GPIO_PIN_PA13,6),GET_BIT(GPIO_PIN_PA12,7),GET_BIT(GPIO_PIN_PA12,6),
//                                      GET_BIT(GPIO_PIN_PA11,7),GET_BIT(GPIO_PIN_PA11,6),GET_BIT(GPIO_PIN_PA10,7),GET_BIT(GPIO_PIN_PA10,6),
//                                      GET_BIT(GPIO_PIN_PA09,7),GET_BIT(GPIO_PIN_PA09,6),GET_BIT(GPIO_PIN_PA08,7),GET_BIT(GPIO_PIN_PA08,6),
//                                      GET_BIT(GPIO_PIN_PA07,7),GET_BIT(GPIO_PIN_PA07,6),GET_BIT(GPIO_PIN_PA06,7),GET_BIT(GPIO_PIN_PA06,6),
//                                      GET_BIT(GPIO_PIN_PA05,7),GET_BIT(GPIO_PIN_PA05,6),GET_BIT(GPIO_PIN_PA04,7),GET_BIT(GPIO_PIN_PA04,6),
//                                      GET_BIT(GPIO_PIN_PA03,7),GET_BIT(GPIO_PIN_PA03,6),GET_BIT(GPIO_PIN_PA02,7),GET_BIT(GPIO_PIN_PA02,6),
//                                      GET_BIT(GPIO_PIN_PA01,7),GET_BIT(GPIO_PIN_PA01,6),GET_BIT(GPIO_PIN_PA00,7),GET_BIT(GPIO_PIN_PA00,6));
//    MGPIO_PORTA_REG->OTYPER  = CONC_B(GET_BIT(GPIO_PIN_PA15,3),GET_BIT(GPIO_PIN_PA15,3),GET_BIT(GPIO_PIN_PA14,3),GET_BIT(GPIO_PIN_PA14,3),
//                                      GET_BIT(GPIO_PIN_PA13,3),GET_BIT(GPIO_PIN_PA13,3),GET_BIT(GPIO_PIN_PA12,3),GET_BIT(GPIO_PIN_PA12,3),
//                                      GET_BIT(GPIO_PIN_PA11,3),GET_BIT(GPIO_PIN_PA11,3),GET_BIT(GPIO_PIN_PA10,3),GET_BIT(GPIO_PIN_PA10,3),
//                                      GET_BIT(GPIO_PIN_PA09,3),GET_BIT(GPIO_PIN_PA09,3),GET_BIT(GPIO_PIN_PA08,3),GET_BIT(GPIO_PIN_PA08,3),
//                                      GET_BIT(GPIO_PIN_PA07,2),GET_BIT(GPIO_PIN_PA07,2),GET_BIT(GPIO_PIN_PA06,2),GET_BIT(GPIO_PIN_PA06,2),
//                                      GET_BIT(GPIO_PIN_PA05,2),GET_BIT(GPIO_PIN_PA05,2),GET_BIT(GPIO_PIN_PA04,2),GET_BIT(GPIO_PIN_PA04,2),
//                                      GET_BIT(GPIO_PIN_PA03,2),GET_BIT(GPIO_PIN_PA03,2),GET_BIT(GPIO_PIN_PA02,2),GET_BIT(GPIO_PIN_PA02,2),
//                                      GET_BIT(GPIO_PIN_PA01,2),GET_BIT(GPIO_PIN_PA01,2),GET_BIT(GPIO_PIN_PA00,2),GET_BIT(GPIO_PIN_PA00,2));
//   MGPIO_PORTA_REG->OSPEEDR  = CONC_B(GET_BIT(GPIO_PIN_PA15,5),GET_BIT(GPIO_PIN_PA15,4),GET_BIT(GPIO_PIN_PA14,5),GET_BIT(GPIO_PIN_PA14,4),
//                                      GET_BIT(GPIO_PIN_PA13,5),GET_BIT(GPIO_PIN_PA13,4),GET_BIT(GPIO_PIN_PA12,5),GET_BIT(GPIO_PIN_PA12,4),
//                                      GET_BIT(GPIO_PIN_PA11,5),GET_BIT(GPIO_PIN_PA11,4),GET_BIT(GPIO_PIN_PA10,5),GET_BIT(GPIO_PIN_PA10,4),
//                                      GET_BIT(GPIO_PIN_PA09,5),GET_BIT(GPIO_PIN_PA09,4),GET_BIT(GPIO_PIN_PA08,5),GET_BIT(GPIO_PIN_PA08,4),
//                                      GET_BIT(GPIO_PIN_PA07,5),GET_BIT(GPIO_PIN_PA07,4),GET_BIT(GPIO_PIN_PA06,5),GET_BIT(GPIO_PIN_PA06,4),
//                                      GET_BIT(GPIO_PIN_PA05,5),GET_BIT(GPIO_PIN_PA05,4),GET_BIT(GPIO_PIN_PA04,5),GET_BIT(GPIO_PIN_PA04,4),
//                                      GET_BIT(GPIO_PIN_PA03,5),GET_BIT(GPIO_PIN_PA03,4),GET_BIT(GPIO_PIN_PA02,5),GET_BIT(GPIO_PIN_PA02,4),
//                                      GET_BIT(GPIO_PIN_PA01,5),GET_BIT(GPIO_PIN_PA01,4),GET_BIT(GPIO_PIN_PA00,5),GET_BIT(GPIO_PIN_PA00,4));
//     MGPIO_PORTA_REG->PUPDR  = CONC_B(GET_BIT(GPIO_PIN_PA15,1),GET_BIT(GPIO_PIN_PA15,0),GET_BIT(GPIO_PIN_PA14,1),GET_BIT(GPIO_PIN_PA14,0),
//                                      GET_BIT(GPIO_PIN_PA13,1),GET_BIT(GPIO_PIN_PA13,0),GET_BIT(GPIO_PIN_PA12,1),GET_BIT(GPIO_PIN_PA12,0),
//                                      GET_BIT(GPIO_PIN_PA11,1),GET_BIT(GPIO_PIN_PA11,0),GET_BIT(GPIO_PIN_PA10,1),GET_BIT(GPIO_PIN_PA10,0),
//                                      GET_BIT(GPIO_PIN_PA09,1),GET_BIT(GPIO_PIN_PA09,0),GET_BIT(GPIO_PIN_PA08,1),GET_BIT(GPIO_PIN_PA08,0),
//                                      GET_BIT(GPIO_PIN_PA07,1),GET_BIT(GPIO_PIN_PA07,0),GET_BIT(GPIO_PIN_PA06,1),GET_BIT(GPIO_PIN_PA06,0),
//                                      GET_BIT(GPIO_PIN_PA05,1),GET_BIT(GPIO_PIN_PA05,0),GET_BIT(GPIO_PIN_PA04,1),GET_BIT(GPIO_PIN_PA04,0),
//                                      GET_BIT(GPIO_PIN_PA03,1),GET_BIT(GPIO_PIN_PA03,0),GET_BIT(GPIO_PIN_PA02,1),GET_BIT(GPIO_PIN_PA02,0),
//                                      GET_BIT(GPIO_PIN_PA01,1),GET_BIT(GPIO_PIN_PA01,0),GET_BIT(GPIO_PIN_PA00,1),GET_BIT(GPIO_PIN_PA00,0));
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         /********************* FOR PERIFIERAL GPIOB */
//     MGPIO_PORTB_REG->MODER  = CONC_B(GET_BIT(GPIO_PIN_PB15,7),GET_BIT(GPIO_PIN_PB15,6),GET_BIT(GPIO_PIN_PB14,7),GET_BIT(GPIO_PIN_PB14,6),
//                                      GET_BIT(GPIO_PIN_PB13,7),GET_BIT(GPIO_PIN_PB13,6),GET_BIT(GPIO_PIN_PB12,7),GET_BIT(GPIO_PIN_PB12,6),
//                                      GET_BIT(GPIO_PIN_PB11,7),GET_BIT(GPIO_PIN_PB11,6),GET_BIT(GPIO_PIN_PB10,7),GET_BIT(GPIO_PIN_PB10,6),
//                                      GET_BIT(GPIO_PIN_PB09,7),GET_BIT(GPIO_PIN_PB09,6),GET_BIT(GPIO_PIN_PB08,7),GET_BIT(GPIO_PIN_PB08,6),
//                                      GET_BIT(GPIO_PIN_PB07,7),GET_BIT(GPIO_PIN_PB07,6),GET_BIT(GPIO_PIN_PB06,7),GET_BIT(GPIO_PIN_PB06,6),
//                                      GET_BIT(GPIO_PIN_PB05,7),GET_BIT(GPIO_PIN_PB05,6),GET_BIT(GPIO_PIN_PB04,7),GET_BIT(GPIO_PIN_PB04,6),
//                                      GET_BIT(GPIO_PIN_PB03,7),GET_BIT(GPIO_PIN_PB03,6),GET_BIT(GPIO_PIN_PB02,7),GET_BIT(GPIO_PIN_PB02,6),
//                                      GET_BIT(GPIO_PIN_PB01,7),GET_BIT(GPIO_PIN_PB01,6),GET_BIT(GPIO_PIN_PB00,7),GET_BIT(GPIO_PIN_PB00,6));
//    MGPIO_PORTB_REG->OTYPER  = CONC_B(GET_BIT(GPIO_PIN_PB15,3),GET_BIT(GPIO_PIN_PB15,3),GET_BIT(GPIO_PIN_PB14,3),GET_BIT(GPIO_PIN_PB14,3),
//                                      GET_BIT(GPIO_PIN_PB13,3),GET_BIT(GPIO_PIN_PB13,3),GET_BIT(GPIO_PIN_PB12,3),GET_BIT(GPIO_PIN_PB12,3),
//                                      GET_BIT(GPIO_PIN_PB11,3),GET_BIT(GPIO_PIN_PB11,3),GET_BIT(GPIO_PIN_PB10,3),GET_BIT(GPIO_PIN_PB10,3),
//                                      GET_BIT(GPIO_PIN_PB09,3),GET_BIT(GPIO_PIN_PB09,3),GET_BIT(GPIO_PIN_PB08,3),GET_BIT(GPIO_PIN_PB08,3),
//                                      GET_BIT(GPIO_PIN_PB07,2),GET_BIT(GPIO_PIN_PB07,2),GET_BIT(GPIO_PIN_PB06,2),GET_BIT(GPIO_PIN_PB06,2),
//                                      GET_BIT(GPIO_PIN_PB05,2),GET_BIT(GPIO_PIN_PB05,2),GET_BIT(GPIO_PIN_PB04,2),GET_BIT(GPIO_PIN_PB04,2),
//                                      GET_BIT(GPIO_PIN_PB03,2),GET_BIT(GPIO_PIN_PB03,2),GET_BIT(GPIO_PIN_PB02,2),GET_BIT(GPIO_PIN_PB02,2),
//                                      GET_BIT(GPIO_PIN_PB01,2),GET_BIT(GPIO_PIN_PB01,2),GET_BIT(GPIO_PIN_PB00,2),GET_BIT(GPIO_PIN_PB00,2));
//   MGPIO_PORTB_REG->OSPEEDR  = CONC_B(GET_BIT(GPIO_PIN_PB15,5),GET_BIT(GPIO_PIN_PB15,4),GET_BIT(GPIO_PIN_PB14,5),GET_BIT(GPIO_PIN_PB14,4),
//                                      GET_BIT(GPIO_PIN_PB13,5),GET_BIT(GPIO_PIN_PB13,4),GET_BIT(GPIO_PIN_PB12,5),GET_BIT(GPIO_PIN_PB12,4),
//                                      GET_BIT(GPIO_PIN_PB11,5),GET_BIT(GPIO_PIN_PB11,4),GET_BIT(GPIO_PIN_PB10,5),GET_BIT(GPIO_PIN_PB10,4),
//                                      GET_BIT(GPIO_PIN_PB09,5),GET_BIT(GPIO_PIN_PB09,4),GET_BIT(GPIO_PIN_PB08,5),GET_BIT(GPIO_PIN_PB08,4),
//                                      GET_BIT(GPIO_PIN_PB07,5),GET_BIT(GPIO_PIN_PB07,4),GET_BIT(GPIO_PIN_PB06,5),GET_BIT(GPIO_PIN_PB06,4),
//                                      GET_BIT(GPIO_PIN_PB05,5),GET_BIT(GPIO_PIN_PB05,4),GET_BIT(GPIO_PIN_PB04,5),GET_BIT(GPIO_PIN_PB04,4),
//                                      GET_BIT(GPIO_PIN_PB03,5),GET_BIT(GPIO_PIN_PB03,4),GET_BIT(GPIO_PIN_PB02,5),GET_BIT(GPIO_PIN_PB02,4),
//                                      GET_BIT(GPIO_PIN_PB01,5),GET_BIT(GPIO_PIN_PB01,4),GET_BIT(GPIO_PIN_PB00,5),GET_BIT(GPIO_PIN_PB00,4));
//     MGPIO_PORTB_REG->PUPDR  = CONC_B(GET_BIT(GPIO_PIN_PB15,1),GET_BIT(GPIO_PIN_PB15,0),GET_BIT(GPIO_PIN_PB14,1),GET_BIT(GPIO_PIN_PB14,0),
//                                      GET_BIT(GPIO_PIN_PB13,1),GET_BIT(GPIO_PIN_PB13,0),GET_BIT(GPIO_PIN_PB12,1),GET_BIT(GPIO_PIN_PB12,0),
//                                      GET_BIT(GPIO_PIN_PB11,1),GET_BIT(GPIO_PIN_PB11,0),GET_BIT(GPIO_PIN_PB10,1),GET_BIT(GPIO_PIN_PB10,0),
//                                      GET_BIT(GPIO_PIN_PB09,1),GET_BIT(GPIO_PIN_PB09,0),GET_BIT(GPIO_PIN_PB08,1),GET_BIT(GPIO_PIN_PB08,0),
//                                      GET_BIT(GPIO_PIN_PB07,1),GET_BIT(GPIO_PIN_PB07,0),GET_BIT(GPIO_PIN_PB06,1),GET_BIT(GPIO_PIN_PB06,0),
//                                      GET_BIT(GPIO_PIN_PB05,1),GET_BIT(GPIO_PIN_PB05,0),GET_BIT(GPIO_PIN_PB04,1),GET_BIT(GPIO_PIN_PB04,0),
//                                      GET_BIT(GPIO_PIN_PB03,1),GET_BIT(GPIO_PIN_PB03,0),GET_BIT(GPIO_PIN_PB02,1),GET_BIT(GPIO_PIN_PB02,0),
//                                      GET_BIT(GPIO_PIN_PB01,1),GET_BIT(GPIO_PIN_PB01,0),GET_BIT(GPIO_PIN_PB00,1),GET_BIT(GPIO_PIN_PB00,0));
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         /********************* FOR PERIFIERAL GPIOC */
//     MGPIO_PORTC_REG->MODER  = CONC_B(GET_BIT(GPIO_PIN_PC15,7),GET_BIT(GPIO_PIN_PC15,6),GET_BIT(GPIO_PIN_PC14,7),GET_BIT(GPIO_PIN_PC14,6),
//                                      GET_BIT(GPIO_PIN_PC13,7),GET_BIT(GPIO_PIN_PC13,6),GET_BIT(GPIO_PIN_PC12,7),GET_BIT(GPIO_PIN_PC12,6),
//                                      GET_BIT(GPIO_PIN_PC11,7),GET_BIT(GPIO_PIN_PC11,6),GET_BIT(GPIO_PIN_PC10,7),GET_BIT(GPIO_PIN_PC10,6),
//                                      GET_BIT(GPIO_PIN_PC09,7),GET_BIT(GPIO_PIN_PC09,6),GET_BIT(GPIO_PIN_PC08,7),GET_BIT(GPIO_PIN_PC08,6),
//                                      GET_BIT(GPIO_PIN_PC07,7),GET_BIT(GPIO_PIN_PC07,6),GET_BIT(GPIO_PIN_PC06,7),GET_BIT(GPIO_PIN_PC06,6),
//                                      GET_BIT(GPIO_PIN_PC05,7),GET_BIT(GPIO_PIN_PC05,6),GET_BIT(GPIO_PIN_PC04,7),GET_BIT(GPIO_PIN_PC04,6),
//                                      GET_BIT(GPIO_PIN_PC03,7),GET_BIT(GPIO_PIN_PC03,6),GET_BIT(GPIO_PIN_PC02,7),GET_BIT(GPIO_PIN_PC02,6),
//                                      GET_BIT(GPIO_PIN_PC01,7),GET_BIT(GPIO_PIN_PC01,6),GET_BIT(GPIO_PIN_PC00,7),GET_BIT(GPIO_PIN_PC00,6));
//    MGPIO_PORTC_REG->OTYPER  = CONC_B(GET_BIT(GPIO_PIN_PC15,3),GET_BIT(GPIO_PIN_PC15,3),GET_BIT(GPIO_PIN_PC14,3),GET_BIT(GPIO_PIN_PC14,3),
//                                      GET_BIT(GPIO_PIN_PC13,3),GET_BIT(GPIO_PIN_PC13,3),GET_BIT(GPIO_PIN_PC12,3),GET_BIT(GPIO_PIN_PC12,3),
//                                      GET_BIT(GPIO_PIN_PC11,3),GET_BIT(GPIO_PIN_PC11,3),GET_BIT(GPIO_PIN_PC10,3),GET_BIT(GPIO_PIN_PC10,3),
//                                      GET_BIT(GPIO_PIN_PC09,3),GET_BIT(GPIO_PIN_PC09,3),GET_BIT(GPIO_PIN_PC08,3),GET_BIT(GPIO_PIN_PC08,3),
//                                      GET_BIT(GPIO_PIN_PC07,2),GET_BIT(GPIO_PIN_PC07,2),GET_BIT(GPIO_PIN_PC06,2),GET_BIT(GPIO_PIN_PC06,2),
//                                      GET_BIT(GPIO_PIN_PC05,2),GET_BIT(GPIO_PIN_PC05,2),GET_BIT(GPIO_PIN_PC04,2),GET_BIT(GPIO_PIN_PC04,2),
//                                      GET_BIT(GPIO_PIN_PC03,2),GET_BIT(GPIO_PIN_PC03,2),GET_BIT(GPIO_PIN_PC02,2),GET_BIT(GPIO_PIN_PC02,2),
//                                      GET_BIT(GPIO_PIN_PC01,2),GET_BIT(GPIO_PIN_PC01,2),GET_BIT(GPIO_PIN_PC00,2),GET_BIT(GPIO_PIN_PC00,2));
//   MGPIO_PORTC_REG->OSPEEDR  = CONC_B(GET_BIT(GPIO_PIN_PC15,5),GET_BIT(GPIO_PIN_PC15,4),GET_BIT(GPIO_PIN_PC14,5),GET_BIT(GPIO_PIN_PC14,4),
//                                      GET_BIT(GPIO_PIN_PC13,5),GET_BIT(GPIO_PIN_PC13,4),GET_BIT(GPIO_PIN_PC12,5),GET_BIT(GPIO_PIN_PC12,4),
//                                      GET_BIT(GPIO_PIN_PC11,5),GET_BIT(GPIO_PIN_PC11,4),GET_BIT(GPIO_PIN_PC10,5),GET_BIT(GPIO_PIN_PC10,4),
//                                      GET_BIT(GPIO_PIN_PC09,5),GET_BIT(GPIO_PIN_PC09,4),GET_BIT(GPIO_PIN_PC08,5),GET_BIT(GPIO_PIN_PC08,4),
//                                      GET_BIT(GPIO_PIN_PC07,5),GET_BIT(GPIO_PIN_PC07,4),GET_BIT(GPIO_PIN_PC06,5),GET_BIT(GPIO_PIN_PC06,4),
//                                      GET_BIT(GPIO_PIN_PC05,5),GET_BIT(GPIO_PIN_PC05,4),GET_BIT(GPIO_PIN_PC04,5),GET_BIT(GPIO_PIN_PC04,4),
//                                      GET_BIT(GPIO_PIN_PC03,5),GET_BIT(GPIO_PIN_PC03,4),GET_BIT(GPIO_PIN_PC02,5),GET_BIT(GPIO_PIN_PC02,4),
//                                      GET_BIT(GPIO_PIN_PC01,5),GET_BIT(GPIO_PIN_PC01,4),GET_BIT(GPIO_PIN_PC00,5),GET_BIT(GPIO_PIN_PC00,4));
//     MGPIO_PORTC_REG->PUPDR  = CONC_B(GET_BIT(GPIO_PIN_PC15,1),GET_BIT(GPIO_PIN_PC15,0),GET_BIT(GPIO_PIN_PC14,1),GET_BIT(GPIO_PIN_PC14,0),
//                                      GET_BIT(GPIO_PIN_PC13,1),GET_BIT(GPIO_PIN_PC13,0),GET_BIT(GPIO_PIN_PC12,1),GET_BIT(GPIO_PIN_PC12,0),
//                                      GET_BIT(GPIO_PIN_PC11,1),GET_BIT(GPIO_PIN_PC11,0),GET_BIT(GPIO_PIN_PC10,1),GET_BIT(GPIO_PIN_PC10,0),
//                                      GET_BIT(GPIO_PIN_PC09,1),GET_BIT(GPIO_PIN_PC09,0),GET_BIT(GPIO_PIN_PC08,1),GET_BIT(GPIO_PIN_PC08,0),
//                                      GET_BIT(GPIO_PIN_PC07,1),GET_BIT(GPIO_PIN_PC07,0),GET_BIT(GPIO_PIN_PC06,1),GET_BIT(GPIO_PIN_PC06,0),
//                                      GET_BIT(GPIO_PIN_PC05,1),GET_BIT(GPIO_PIN_PC05,0),GET_BIT(GPIO_PIN_PC04,1),GET_BIT(GPIO_PIN_PC04,0),
//                                      GET_BIT(GPIO_PIN_PC03,1),GET_BIT(GPIO_PIN_PC03,0),GET_BIT(GPIO_PIN_PC02,1),GET_BIT(GPIO_PIN_PC02,0),
//                                      GET_BIT(GPIO_PIN_PC01,1),GET_BIT(GPIO_PIN_PC01,0),GET_BIT(GPIO_PIN_PC00,1),GET_BIT(GPIO_PIN_PC00,0));
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         /********************* FOR PERIFIERAL GPIOD */
//     MGPIO_PORTD_REG->MODER  = CONC_B(GET_BIT(GPIO_PIN_PD15,7),GET_BIT(GPIO_PIN_PD15,6),GET_BIT(GPIO_PIN_PD14,7),GET_BIT(GPIO_PIN_PD14,6),
//                                      GET_BIT(GPIO_PIN_PD13,7),GET_BIT(GPIO_PIN_PD13,6),GET_BIT(GPIO_PIN_PD12,7),GET_BIT(GPIO_PIN_PD12,6),
//                                      GET_BIT(GPIO_PIN_PD11,7),GET_BIT(GPIO_PIN_PD11,6),GET_BIT(GPIO_PIN_PD10,7),GET_BIT(GPIO_PIN_PD10,6),
//                                      GET_BIT(GPIO_PIN_PD09,7),GET_BIT(GPIO_PIN_PD09,6),GET_BIT(GPIO_PIN_PD08,7),GET_BIT(GPIO_PIN_PD08,6),
//                                      GET_BIT(GPIO_PIN_PD07,7),GET_BIT(GPIO_PIN_PD07,6),GET_BIT(GPIO_PIN_PD06,7),GET_BIT(GPIO_PIN_PD06,6),
//                                      GET_BIT(GPIO_PIN_PD05,7),GET_BIT(GPIO_PIN_PD05,6),GET_BIT(GPIO_PIN_PD04,7),GET_BIT(GPIO_PIN_PD04,6),
//                                      GET_BIT(GPIO_PIN_PD03,7),GET_BIT(GPIO_PIN_PD03,6),GET_BIT(GPIO_PIN_PD02,7),GET_BIT(GPIO_PIN_PD02,6),
//                                      GET_BIT(GPIO_PIN_PD01,7),GET_BIT(GPIO_PIN_PD01,6),GET_BIT(GPIO_PIN_PD00,7),GET_BIT(GPIO_PIN_PD00,6));
//    MGPIO_PORTD_REG->OTYPER  = CONC_B(GET_BIT(GPIO_PIN_PD15,3),GET_BIT(GPIO_PIN_PD15,3),GET_BIT(GPIO_PIN_PD14,3),GET_BIT(GPIO_PIN_PD14,3),
//                                      GET_BIT(GPIO_PIN_PD13,3),GET_BIT(GPIO_PIN_PD13,3),GET_BIT(GPIO_PIN_PD12,3),GET_BIT(GPIO_PIN_PD12,3),
//                                      GET_BIT(GPIO_PIN_PD11,3),GET_BIT(GPIO_PIN_PD11,3),GET_BIT(GPIO_PIN_PD10,3),GET_BIT(GPIO_PIN_PD10,3),
//                                      GET_BIT(GPIO_PIN_PD09,3),GET_BIT(GPIO_PIN_PD09,3),GET_BIT(GPIO_PIN_PD08,3),GET_BIT(GPIO_PIN_PD08,3),
//                                      GET_BIT(GPIO_PIN_PD07,2),GET_BIT(GPIO_PIN_PD07,2),GET_BIT(GPIO_PIN_PD06,2),GET_BIT(GPIO_PIN_PD06,2),
//                                      GET_BIT(GPIO_PIN_PD05,2),GET_BIT(GPIO_PIN_PD05,2),GET_BIT(GPIO_PIN_PD04,2),GET_BIT(GPIO_PIN_PD04,2),
//                                      GET_BIT(GPIO_PIN_PD03,2),GET_BIT(GPIO_PIN_PD03,2),GET_BIT(GPIO_PIN_PD02,2),GET_BIT(GPIO_PIN_PD02,2),
//                                      GET_BIT(GPIO_PIN_PD01,2),GET_BIT(GPIO_PIN_PD01,2),GET_BIT(GPIO_PIN_PD00,2),GET_BIT(GPIO_PIN_PD00,2));
//   MGPIO_PORTD_REG->OSPEEDR  = CONC_B(GET_BIT(GPIO_PIN_PD15,5),GET_BIT(GPIO_PIN_PD15,4),GET_BIT(GPIO_PIN_PD14,5),GET_BIT(GPIO_PIN_PD14,4),
//                                      GET_BIT(GPIO_PIN_PD13,5),GET_BIT(GPIO_PIN_PD13,4),GET_BIT(GPIO_PIN_PD12,5),GET_BIT(GPIO_PIN_PD12,4),
//                                      GET_BIT(GPIO_PIN_PD11,5),GET_BIT(GPIO_PIN_PD11,4),GET_BIT(GPIO_PIN_PD10,5),GET_BIT(GPIO_PIN_PD10,4),
//                                      GET_BIT(GPIO_PIN_PD09,5),GET_BIT(GPIO_PIN_PD09,4),GET_BIT(GPIO_PIN_PD08,5),GET_BIT(GPIO_PIN_PD08,4),
//                                      GET_BIT(GPIO_PIN_PD07,5),GET_BIT(GPIO_PIN_PD07,4),GET_BIT(GPIO_PIN_PD06,5),GET_BIT(GPIO_PIN_PD06,4),
//                                      GET_BIT(GPIO_PIN_PD05,5),GET_BIT(GPIO_PIN_PD05,4),GET_BIT(GPIO_PIN_PD04,5),GET_BIT(GPIO_PIN_PD04,4),
//                                      GET_BIT(GPIO_PIN_PD03,5),GET_BIT(GPIO_PIN_PD03,4),GET_BIT(GPIO_PIN_PD02,5),GET_BIT(GPIO_PIN_PD02,4),
//                                      GET_BIT(GPIO_PIN_PD01,5),GET_BIT(GPIO_PIN_PD01,4),GET_BIT(GPIO_PIN_PD00,5),GET_BIT(GPIO_PIN_PD00,4));
//     MGPIO_PORTD_REG->PUPDR  = CONC_B(GET_BIT(GPIO_PIN_PD15,1),GET_BIT(GPIO_PIN_PD15,0),GET_BIT(GPIO_PIN_PD14,1),GET_BIT(GPIO_PIN_PD14,0),
//                                      GET_BIT(GPIO_PIN_PD13,1),GET_BIT(GPIO_PIN_PD13,0),GET_BIT(GPIO_PIN_PD12,1),GET_BIT(GPIO_PIN_PD12,0),
//                                      GET_BIT(GPIO_PIN_PD11,1),GET_BIT(GPIO_PIN_PD11,0),GET_BIT(GPIO_PIN_PD10,1),GET_BIT(GPIO_PIN_PD10,0),
//                                      GET_BIT(GPIO_PIN_PD09,1),GET_BIT(GPIO_PIN_PD09,0),GET_BIT(GPIO_PIN_PD08,1),GET_BIT(GPIO_PIN_PD08,0),
//                                      GET_BIT(GPIO_PIN_PD07,1),GET_BIT(GPIO_PIN_PD07,0),GET_BIT(GPIO_PIN_PD06,1),GET_BIT(GPIO_PIN_PD06,0),
//                                      GET_BIT(GPIO_PIN_PD05,1),GET_BIT(GPIO_PIN_PD05,0),GET_BIT(GPIO_PIN_PD04,1),GET_BIT(GPIO_PIN_PD04,0),
//                                      GET_BIT(GPIO_PIN_PD03,1),GET_BIT(GPIO_PIN_PD03,0),GET_BIT(GPIO_PIN_PD02,1),GET_BIT(GPIO_PIN_PD02,0),
//                                      GET_BIT(GPIO_PIN_PD01,1),GET_BIT(GPIO_PIN_PD01,0),GET_BIT(GPIO_PIN_PD00,1),GET_BIT(GPIO_PIN_PD00,0));
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         /********************* FOR PERIFIERAL GPIOE */
//     MGPIO_PORTE_REG->MODER  = CONC_B(GET_BIT(GPIO_PIN_PE15,7),GET_BIT(GPIO_PIN_PE15,6),GET_BIT(GPIO_PIN_PE14,7),GET_BIT(GPIO_PIN_PE14,6),
//                                      GET_BIT(GPIO_PIN_PE13,7),GET_BIT(GPIO_PIN_PE13,6),GET_BIT(GPIO_PIN_PE12,7),GET_BIT(GPIO_PIN_PE12,6),
//                                      GET_BIT(GPIO_PIN_PE11,7),GET_BIT(GPIO_PIN_PE11,6),GET_BIT(GPIO_PIN_PE10,7),GET_BIT(GPIO_PIN_PE10,6),
//                                      GET_BIT(GPIO_PIN_PE09,7),GET_BIT(GPIO_PIN_PE09,6),GET_BIT(GPIO_PIN_PE08,7),GET_BIT(GPIO_PIN_PE08,6),
//                                      GET_BIT(GPIO_PIN_PE07,7),GET_BIT(GPIO_PIN_PE07,6),GET_BIT(GPIO_PIN_PE06,7),GET_BIT(GPIO_PIN_PE06,6),
//                                      GET_BIT(GPIO_PIN_PE05,7),GET_BIT(GPIO_PIN_PE05,6),GET_BIT(GPIO_PIN_PE04,7),GET_BIT(GPIO_PIN_PE04,6),
//                                      GET_BIT(GPIO_PIN_PE03,7),GET_BIT(GPIO_PIN_PE03,6),GET_BIT(GPIO_PIN_PE02,7),GET_BIT(GPIO_PIN_PE02,6),
//                                      GET_BIT(GPIO_PIN_PE01,7),GET_BIT(GPIO_PIN_PE01,6),GET_BIT(GPIO_PIN_PE00,7),GET_BIT(GPIO_PIN_PE00,6));
//    MGPIO_PORTE_REG->OTYPER  = CONC_B(GET_BIT(GPIO_PIN_PE15,3),GET_BIT(GPIO_PIN_PE15,3),GET_BIT(GPIO_PIN_PE14,3),GET_BIT(GPIO_PIN_PE14,3),
//                                      GET_BIT(GPIO_PIN_PE13,3),GET_BIT(GPIO_PIN_PE13,3),GET_BIT(GPIO_PIN_PE12,3),GET_BIT(GPIO_PIN_PE12,3),
//                                      GET_BIT(GPIO_PIN_PE11,3),GET_BIT(GPIO_PIN_PE11,3),GET_BIT(GPIO_PIN_PE10,3),GET_BIT(GPIO_PIN_PE10,3),
//                                      GET_BIT(GPIO_PIN_PE09,3),GET_BIT(GPIO_PIN_PE09,3),GET_BIT(GPIO_PIN_PE08,3),GET_BIT(GPIO_PIN_PE08,3),
//                                      GET_BIT(GPIO_PIN_PE07,2),GET_BIT(GPIO_PIN_PE07,2),GET_BIT(GPIO_PIN_PE06,2),GET_BIT(GPIO_PIN_PE06,2),
//                                      GET_BIT(GPIO_PIN_PE05,2),GET_BIT(GPIO_PIN_PE05,2),GET_BIT(GPIO_PIN_PE04,2),GET_BIT(GPIO_PIN_PE04,2),
//                                      GET_BIT(GPIO_PIN_PE03,2),GET_BIT(GPIO_PIN_PE03,2),GET_BIT(GPIO_PIN_PE02,2),GET_BIT(GPIO_PIN_PE02,2),
//                                      GET_BIT(GPIO_PIN_PE01,2),GET_BIT(GPIO_PIN_PE01,2),GET_BIT(GPIO_PIN_PE00,2),GET_BIT(GPIO_PIN_PE00,2));
//   MGPIO_PORTE_REG->OSPEEDR  = CONC_B(GET_BIT(GPIO_PIN_PE15,5),GET_BIT(GPIO_PIN_PE15,4),GET_BIT(GPIO_PIN_PE14,5),GET_BIT(GPIO_PIN_PE14,4),
//                                      GET_BIT(GPIO_PIN_PE13,5),GET_BIT(GPIO_PIN_PE13,4),GET_BIT(GPIO_PIN_PE12,5),GET_BIT(GPIO_PIN_PE12,4),
//                                      GET_BIT(GPIO_PIN_PE11,5),GET_BIT(GPIO_PIN_PE11,4),GET_BIT(GPIO_PIN_PE10,5),GET_BIT(GPIO_PIN_PE10,4),
//                                      GET_BIT(GPIO_PIN_PE09,5),GET_BIT(GPIO_PIN_PE09,4),GET_BIT(GPIO_PIN_PE08,5),GET_BIT(GPIO_PIN_PE08,4),
//                                      GET_BIT(GPIO_PIN_PE07,5),GET_BIT(GPIO_PIN_PE07,4),GET_BIT(GPIO_PIN_PE06,5),GET_BIT(GPIO_PIN_PE06,4),
//                                      GET_BIT(GPIO_PIN_PE05,5),GET_BIT(GPIO_PIN_PE05,4),GET_BIT(GPIO_PIN_PE04,5),GET_BIT(GPIO_PIN_PE04,4),
//                                      GET_BIT(GPIO_PIN_PE03,5),GET_BIT(GPIO_PIN_PE03,4),GET_BIT(GPIO_PIN_PE02,5),GET_BIT(GPIO_PIN_PE02,4),
//                                      GET_BIT(GPIO_PIN_PE01,5),GET_BIT(GPIO_PIN_PE01,4),GET_BIT(GPIO_PIN_PE00,5),GET_BIT(GPIO_PIN_PE00,4));
//     MGPIO_PORTE_REG->PUPDR  = CONC_B(GET_BIT(GPIO_PIN_PE15,1),GET_BIT(GPIO_PIN_PE15,0),GET_BIT(GPIO_PIN_PE14,1),GET_BIT(GPIO_PIN_PE14,0),
//                                      GET_BIT(GPIO_PIN_PE13,1),GET_BIT(GPIO_PIN_PE13,0),GET_BIT(GPIO_PIN_PE12,1),GET_BIT(GPIO_PIN_PE12,0),
//                                      GET_BIT(GPIO_PIN_PE11,1),GET_BIT(GPIO_PIN_PE11,0),GET_BIT(GPIO_PIN_PE10,1),GET_BIT(GPIO_PIN_PE10,0),
//                                      GET_BIT(GPIO_PIN_PE09,1),GET_BIT(GPIO_PIN_PE09,0),GET_BIT(GPIO_PIN_PE08,1),GET_BIT(GPIO_PIN_PE08,0),
//                                      GET_BIT(GPIO_PIN_PE07,1),GET_BIT(GPIO_PIN_PE07,0),GET_BIT(GPIO_PIN_PE06,1),GET_BIT(GPIO_PIN_PE06,0),
//                                      GET_BIT(GPIO_PIN_PE05,1),GET_BIT(GPIO_PIN_PE05,0),GET_BIT(GPIO_PIN_PE04,1),GET_BIT(GPIO_PIN_PE04,0),
//                                      GET_BIT(GPIO_PIN_PE03,1),GET_BIT(GPIO_PIN_PE03,0),GET_BIT(GPIO_PIN_PE02,1),GET_BIT(GPIO_PIN_PE02,0),
//                                      GET_BIT(GPIO_PIN_PE01,1),GET_BIT(GPIO_PIN_PE01,0),GET_BIT(GPIO_PIN_PE00,1),GET_BIT(GPIO_PIN_PE00,0));
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         /********************* FOR PERIFIERAL GPIOH */
//      MGPIO_PORTH_REG->MODER  = CONC_B(GET_BIT(GPIO_PIN_PH15,7),GET_BIT(GPIO_PIN_PH15,6),GET_BIT(GPIO_PIN_PH14,7),GET_BIT(GPIO_PIN_PH14,6),
//                                       GET_BIT(GPIO_PIN_PH13,7),GET_BIT(GPIO_PIN_PH13,6),GET_BIT(GPIO_PIN_PH12,7),GET_BIT(GPIO_PIN_PH12,6),
//                                       GET_BIT(GPIO_PIN_PH11,7),GET_BIT(GPIO_PIN_PH11,6),GET_BIT(GPIO_PIN_PH10,7),GET_BIT(GPIO_PIN_PH10,6),
//                                       GET_BIT(GPIO_PIN_PH09,7),GET_BIT(GPIO_PIN_PH09,6),GET_BIT(GPIO_PIN_PH08,7),GET_BIT(GPIO_PIN_PH08,6),
//                                       GET_BIT(GPIO_PIN_PH07,7),GET_BIT(GPIO_PIN_PH07,6),GET_BIT(GPIO_PIN_PH06,7),GET_BIT(GPIO_PIN_PH06,6),
//                                       GET_BIT(GPIO_PIN_PH05,7),GET_BIT(GPIO_PIN_PH05,6),GET_BIT(GPIO_PIN_PH04,7),GET_BIT(GPIO_PIN_PH04,6),
//                                       GET_BIT(GPIO_PIN_PH03,7),GET_BIT(GPIO_PIN_PH03,6),GET_BIT(GPIO_PIN_PH02,7),GET_BIT(GPIO_PIN_PH02,6),
//                                       GET_BIT(GPIO_PIN_PH01,7),GET_BIT(GPIO_PIN_PH01,6),GET_BIT(GPIO_PIN_PH00,7),GET_BIT(GPIO_PIN_PH00,6));
//     MGPIO_PORTH_REG->OTYPER  = CONC_B(GET_BIT(GPIO_PIN_PH15,3),GET_BIT(GPIO_PIN_PH15,3),GET_BIT(GPIO_PIN_PH14,3),GET_BIT(GPIO_PIN_PH14,3),
//                                       GET_BIT(GPIO_PIN_PH13,3),GET_BIT(GPIO_PIN_PH13,3),GET_BIT(GPIO_PIN_PH12,3),GET_BIT(GPIO_PIN_PH12,3),
//                                       GET_BIT(GPIO_PIN_PH11,3),GET_BIT(GPIO_PIN_PH11,3),GET_BIT(GPIO_PIN_PH10,3),GET_BIT(GPIO_PIN_PH10,3),
//                                       GET_BIT(GPIO_PIN_PH09,3),GET_BIT(GPIO_PIN_PH09,3),GET_BIT(GPIO_PIN_PH08,3),GET_BIT(GPIO_PIN_PH08,3),
//                                       GET_BIT(GPIO_PIN_PH07,2),GET_BIT(GPIO_PIN_PH07,2),GET_BIT(GPIO_PIN_PH06,2),GET_BIT(GPIO_PIN_PH06,2),
//                                       GET_BIT(GPIO_PIN_PH05,2),GET_BIT(GPIO_PIN_PH05,2),GET_BIT(GPIO_PIN_PH04,2),GET_BIT(GPIO_PIN_PH04,2),
//                                       GET_BIT(GPIO_PIN_PH03,2),GET_BIT(GPIO_PIN_PH03,2),GET_BIT(GPIO_PIN_PH02,2),GET_BIT(GPIO_PIN_PH02,2),
//                                       GET_BIT(GPIO_PIN_PH01,2),GET_BIT(GPIO_PIN_PH01,2),GET_BIT(GPIO_PIN_PH00,2),GET_BIT(GPIO_PIN_PH00,2));
//    MGPIO_PORTH_REG->OSPEEDR  = CONC_B(GET_BIT(GPIO_PIN_PH15,5),GET_BIT(GPIO_PIN_PH15,4),GET_BIT(GPIO_PIN_PH14,5),GET_BIT(GPIO_PIN_PH14,4),
//                                       GET_BIT(GPIO_PIN_PH13,5),GET_BIT(GPIO_PIN_PH13,4),GET_BIT(GPIO_PIN_PH12,5),GET_BIT(GPIO_PIN_PH12,4),
//                                       GET_BIT(GPIO_PIN_PH11,5),GET_BIT(GPIO_PIN_PH11,4),GET_BIT(GPIO_PIN_PH10,5),GET_BIT(GPIO_PIN_PH10,4),
//                                       GET_BIT(GPIO_PIN_PH09,5),GET_BIT(GPIO_PIN_PH09,4),GET_BIT(GPIO_PIN_PH08,5),GET_BIT(GPIO_PIN_PH08,4),
//                                       GET_BIT(GPIO_PIN_PH07,5),GET_BIT(GPIO_PIN_PH07,4),GET_BIT(GPIO_PIN_PH06,5),GET_BIT(GPIO_PIN_PH06,4),
//                                       GET_BIT(GPIO_PIN_PH05,5),GET_BIT(GPIO_PIN_PH05,4),GET_BIT(GPIO_PIN_PH04,5),GET_BIT(GPIO_PIN_PH04,4),
//                                       GET_BIT(GPIO_PIN_PH03,5),GET_BIT(GPIO_PIN_PH03,4),GET_BIT(GPIO_PIN_PH02,5),GET_BIT(GPIO_PIN_PH02,4),
//                                       GET_BIT(GPIO_PIN_PH01,5),GET_BIT(GPIO_PIN_PH01,4),GET_BIT(GPIO_PIN_PH00,5),GET_BIT(GPIO_PIN_PH00,4));
//      MGPIO_PORTH_REG->PUPDR  = CONC_B(GET_BIT(GPIO_PIN_PH15,1),GET_BIT(GPIO_PIN_PH15,0),GET_BIT(GPIO_PIN_PH14,1),GET_BIT(GPIO_PIN_PH14,0),
//                                       GET_BIT(GPIO_PIN_PH13,1),GET_BIT(GPIO_PIN_PH13,0),GET_BIT(GPIO_PIN_PH12,1),GET_BIT(GPIO_PIN_PH12,0),
//                                       GET_BIT(GPIO_PIN_PH11,1),GET_BIT(GPIO_PIN_PH11,0),GET_BIT(GPIO_PIN_PH10,1),GET_BIT(GPIO_PIN_PH10,0),
//                                       GET_BIT(GPIO_PIN_PH09,1),GET_BIT(GPIO_PIN_PH09,0),GET_BIT(GPIO_PIN_PH08,1),GET_BIT(GPIO_PIN_PH08,0),
//                                       GET_BIT(GPIO_PIN_PH07,1),GET_BIT(GPIO_PIN_PH07,0),GET_BIT(GPIO_PIN_PH06,1),GET_BIT(GPIO_PIN_PH06,0),
//                                       GET_BIT(GPIO_PIN_PH05,1),GET_BIT(GPIO_PIN_PH05,0),GET_BIT(GPIO_PIN_PH04,1),GET_BIT(GPIO_PIN_PH04,0),
//                                       GET_BIT(GPIO_PIN_PH03,1),GET_BIT(GPIO_PIN_PH03,0),GET_BIT(GPIO_PIN_PH02,1),GET_BIT(GPIO_PIN_PH02,0),
//                                       GET_BIT(GPIO_PIN_PH01,1),GET_BIT(GPIO_PIN_PH01,0),GET_BIT(GPIO_PIN_PH00,1),GET_BIT(GPIO_PIN_PH00,0));
// }
Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t *Add_CnfgStruct) {
    Gpio_tenuErrorStatus Loc_enuStatus = Gpio_enuOk;

 
    if (Add_CnfgStruct != NULL) {
        if (Add_CnfgStruct->gpio_port_x < 6 && Add_CnfgStruct->gpio_pin_x < 16) {
            GPIOx_t *GPIO_Arr[6] = {MGPIO_PORTA_REG, MGPIO_PORTB_REG, MGPIO_PORTC_REG, MGPIO_PORTD_REG, MGPIO_PORTE_REG, MGPIO_PORTH_REG};
            u8 PORT_ID = Add_CnfgStruct->gpio_port_x;
            u8 PIN_ID = Add_CnfgStruct->gpio_pin_x;

            if (Add_CnfgStruct->gpio_mode_x <= GPIO_MODE_u64_ANALOG) {
                switch (Add_CnfgStruct->gpio_mode_x) {
                    case GPIO_MODE_u64_OUTPUT_PP:
                        GPIO_Arr[PORT_ID]->MODER &= ~(GPIO_MODE_u64_OUTPUT_PP << (PIN_ID * 2));
                        GPIO_Arr[PORT_ID]->MODER |= (GPIO_MODE_u64_OUTPUT_PP << (PIN_ID * 2));
                        break;
                    case GPIO_MODE_u64_OUTPUT_OD:
                        GPIO_Arr[PORT_ID]->MODER &= ~(GPIO_MODE_u64_OUTPUT_OD << (PIN_ID * 2));
                        GPIO_Arr[PORT_ID]->MODER |= (GPIO_MODE_u64_OUTPUT_OD << (PIN_ID * 2));
                        break;
                    case GPIO_MODE_u64_INPUT:
                        GPIO_Arr[PORT_ID]->MODER &= ~(GPIO_MODE_u64_INPUT << (PIN_ID * 2));
                        GPIO_Arr[PORT_ID]->MODER |= (GPIO_MODE_u64_INPUT << (PIN_ID * 2));
                        break;
                    case GPIO_MODE_u64_AF_PP:
                        GPIO_Arr[PORT_ID]->MODER &= ~(GPIO_MODE_u64_AF_PP << (PIN_ID * 4));
                        GPIO_Arr[PORT_ID]->MODER |= (GPIO_MODE_u64_AF_PP << (PIN_ID * 4));
                        break;
                    case GPIO_MODE_u64_AF_OD:
                        GPIO_Arr[PORT_ID]->MODER &= ~(GPIO_MODE_u64_AF_OD << (PIN_ID * 4));
                        GPIO_Arr[PORT_ID]->MODER |= (GPIO_MODE_u64_AF_OD << (PIN_ID * 4));
                        break;
                    case GPIO_MODE_u64_ANALOG:
                        break;
                    default:
                        Loc_enuStatus = Gpio_WrongModeError;
                        break;
                }

                if (Add_CnfgStruct->gpio_Pull_x <= 2) {
                    GPIO_Arr[PORT_ID]->OTYPER &= ~(Add_CnfgStruct->gpio_Pull_x << PIN_ID);
                    GPIO_Arr[PORT_ID]->OTYPER |= (Add_CnfgStruct->gpio_Pull_x << PIN_ID);
                    if (Add_CnfgStruct->gpio_speed_x <= 3) {
                        GPIO_Arr[PORT_ID]->OSPEEDR &= ~(Add_CnfgStruct->gpio_speed_x << PIN_ID);
                        GPIO_Arr[PORT_ID]->OSPEEDR |= (Add_CnfgStruct->gpio_speed_x << PIN_ID);
                    } else {
                        Loc_enuStatus = Gpio_WrongSpeedError;
                    }
                } else {
                    Loc_enuStatus = Gpio_WrongPuPdError;
                }
            } else {
                Loc_enuStatus = Gpio_WrongModeError;
            }
        } else {
            Loc_enuStatus = Gpio_WrongPinNumError;
        }
    } else {
        Loc_enuStatus = Gpio_enuNULLPTR;
    }

    return Loc_enuStatus;
}

Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t *Add_pu8CnfgStatus, u8 Copyu8PinValue) {
    if (Add_pu8CnfgStatus == NULL) {
        return Gpio_enuNULLPTR;
    }

    if (Add_pu8CnfgStatus->gpio_mode_x == GPIO_MODE_u64_OUTPUT_PP || Add_pu8CnfgStatus->gpio_mode_x == GPIO_MODE_u64_OUTPUT_OD) {
        if (Add_pu8CnfgStatus->gpio_port_x < 6 && Add_pu8CnfgStatus->gpio_pin_x < 16) {
            GPIOx_t *GPIO_Arr[6] = {MGPIO_PORTA_REG, MGPIO_PORTB_REG, MGPIO_PORTC_REG, MGPIO_PORTD_REG, MGPIO_PORTE_REG, MGPIO_PORTH_REG};
            u8 PORT_ID = Add_pu8CnfgStatus->gpio_port_x;
            u8 PIN_ID = Add_pu8CnfgStatus->gpio_pin_x;
            GPIO_Arr[PORT_ID]->ODR &= ~(Copyu8PinValue << PIN_ID);
            GPIO_Arr[PORT_ID]->ODR |= (Copyu8PinValue << PIN_ID);
            return Gpio_enuOk;
        } else {
            return Gpio_WrongPinNumError;
        }
    } else {
        return Gpio_WrongModeError;
    }
}

Gpio_tenuErrorStatus Gpio_setPinnValue(u8 Copyu8Port, u8 Copyu8Pin, u8 Copyu8Value) {
    if (Copyu8Port < 6 && Copyu8Pin < 16) {
        GPIOx_t *GPIO_Arr[6] = {MGPIO_PORTA_REG, MGPIO_PORTB_REG, MGPIO_PORTC_REG, MGPIO_PORTD_REG, MGPIO_PORTE_REG, MGPIO_PORTH_REG};
        GPIO_Arr[Copyu8Port]->ODR |= (Copyu8Value << Copyu8Pin);
        return Gpio_enuOk;
    } else {
        return Gpio_WrongPortNumError;
    }
}


Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t *Add_CnfgStruct, pu8 Add_pu8PinValue) {
    if (Add_CnfgStruct != NULL) {
        if ((Add_CnfgStruct->gpio_mode_x == GPIO_MODE_u64_OUTPUT_OD) || (Add_CnfgStruct->gpio_mode_x == GPIO_MODE_u64_INPUT)) {
            GPIOx_t *GPIO_Arr[6] = {MGPIO_PORTA_REG, MGPIO_PORTB_REG, MGPIO_PORTC_REG, MGPIO_PORTD_REG, MGPIO_PORTE_REG, MGPIO_PORTH_REG};
            u8 PORT_ID = Add_CnfgStruct->gpio_port_x;
            u8 PIN_ID = Add_CnfgStruct->gpio_pin_x;
            *Add_pu8PinValue = ((GPIO_Arr[PORT_ID]->IDR >> PIN_ID) & 1);
            return Gpio_enuOk;
        } else {
            return Gpio_WrongModeError;
        }
    } else {
        return Gpio_enuNULLPTR;
    }
}

Gpio_tenuErrorStatus Gpio_SetAlternateFunction(GpioPinCfg_t *Add_CnfgStruct, u8 CopyAF) {
    if (Add_CnfgStruct != NULL) {
        if ((Add_CnfgStruct->gpio_mode_x == GPIO_MODE_u64_AF_PP) || (Add_CnfgStruct->gpio_mode_x == GPIO_MODE_u64_AF_OD)) {
            if (CopyAF > 7) {
                GPIOx_t *GPIO_Arr[6] = {MGPIO_PORTA_REG, MGPIO_PORTB_REG, MGPIO_PORTC_REG, MGPIO_PORTD_REG, MGPIO_PORTE_REG, MGPIO_PORTH_REG};
                u8 PORT_ID = Add_CnfgStruct->gpio_port_x;
                u8 PIN_ID = Add_CnfgStruct->gpio_pin_x;
                GPIO_Arr[PORT_ID]->AFRL &= ~(CopyAF << (4 * PIN_ID));
                GPIO_Arr[PORT_ID]->AFRL |= (CopyAF << (4 * PIN_ID));
            } else {
                GPIOx_t *GPIO_Arr[6] = {MGPIO_PORTA_REG, MGPIO_PORTB_REG, MGPIO_PORTC_REG, MGPIO_PORTD_REG, MGPIO_PORTE_REG, MGPIO_PORTH_REG};
                u8 PORT_ID = Add_CnfgStruct->gpio_port_x;
                u8 PIN_ID = Add_CnfgStruct->gpio_pin_x;
                GPIO_Arr[PORT_ID]->AFRH &= ~(CopyAF << (4 * PIN_ID));
                GPIO_Arr[PORT_ID]->AFRH |= (CopyAF << (4 * PIN_ID));
            }
            return Gpio_enuOk;
        } else {
            return Gpio_WrongModeError;
        }
    } else {
        return Gpio_enuNULLPTR;
    }
}
