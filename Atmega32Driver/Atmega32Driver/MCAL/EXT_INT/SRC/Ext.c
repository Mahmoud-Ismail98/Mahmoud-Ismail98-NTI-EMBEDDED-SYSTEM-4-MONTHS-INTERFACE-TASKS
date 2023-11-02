/*
 * EXT>C
 *
 * Created: 10/21/2023 11:44:23 AM
 *  Author: FADY
 */
#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include "../INC/EXT.h"
#include "../INC/EXT_prv.h"


static void (*EXTINT_SetCallBackExtInt[3])(void)={NULL,NULL,NULL};

EXT_ErorStatus EXT_InterruptPirefralEnable(u8 Copy_u8EXTx,u8 Copy_u8Mode)
{
    EXT_ErorStatus Loc_u8Status =EX_OK;
    if((Copy_u8Mode>3)||(Copy_u8Mode<0)){
        Loc_u8Status = EX_WRONGMODE;
    }
    else if((Copy_u8EXTx>3)||(Copy_u8EXTx<0))
    {
        Loc_u8Status = EX_WRONGNUM;
    }
    else
    {
        switch(Copy_u8EXTx)
        {
            case EXT_0 :
                switch(Copy_u8Mode)
			    {
			        case EXT_ON_CHANGE:
				        CLR_BIT(MCUCR,MCUCR_ISC11);
				        SET_BIT(MCUCR,MCUCR_ISC10);
				    break;
			        case EXT_FALLING_EDGE:
				        SET_BIT(MCUCR,MCUCR_ISC11);
				        CLR_BIT(MCUCR,MCUCR_ISC10);
				    break;
			        case EXT_RISING_EDGE:
				        SET_BIT(MCUCR,MCUCR_ISC11);
				        SET_BIT(MCUCR,MCUCR_ISC10);
				    break;
			        case EXT_LOW_MODE:
				        CLR_BIT(MCUCR,MCUCR_ISC11);
				        CLR_BIT(MCUCR,MCUCR_ISC10);
				    break;
                    default:
                    /*DO NOTHING*/
                    break;
			    }
			    /* Enable Ext Int 1 */
			    SET_BIT(GICR,GICR_INT0);
            break;

            case EXT_1 :
                switch(Copy_u8Mode)
			    {
			        case EXT_ON_CHANGE:
				        CLR_BIT(MCUCR,MCUCR_ISC11);
				        SET_BIT(MCUCR,MCUCR_ISC10);
				    break;
			        case EXT_FALLING_EDGE:
				        SET_BIT(MCUCR,MCUCR_ISC11);
				        CLR_BIT(MCUCR,MCUCR_ISC10);
				    break;
			        case EXT_RISING_EDGE:
				        SET_BIT(MCUCR,MCUCR_ISC11);
				        SET_BIT(MCUCR,MCUCR_ISC10);
				    break;
			        case EXT_LOW_MODE:
				        CLR_BIT(MCUCR,MCUCR_ISC11);
				        CLR_BIT(MCUCR,MCUCR_ISC10);
				    break;
                    default:
                    /*DO NOTHING*/
                    break;
			    }
			    /* Enable Ext Int 1 */
			    SET_BIT(GICR,GICR_INT1);
            break;

            case EXT_2 :
                switch(Copy_u8Mode)
			    {
			        case EXT_FALLING_EDGE:        
				        CLR_BIT(MCUCSR,MCUCSR_ISC2);
				    break;
			        case EXT_RISING_EDGE:
				        SET_BIT(MCUCSR,MCUCSR_ISC2);
				    break;
                    default:
                    /*DO NOTHING*/
                    break;
			    }
			    /* Enable Ext Int 1 */
			    SET_BIT(GICR,GICR_INT2);
            break;

            default:
            break;

        }
    }
    return Loc_u8Status;
}

EXT_ErorStatus EXT_InterruptPirefralDisable(u8 Copy_u8EXTx){
    EXT_ErorStatus Loc_u8Status =EX_OK;
    if((Copy_u8EXTx>3)||(Copy_u8EXTx<0))
    {
        Loc_u8Status = EX_WRONGNUM;
    }
    else
    {
        switch(Copy_u8EXTx)
        {
            case EXT_0:
                CLR_BIT(GICR,GICR_INT0);
            break;
            case EXT_1:
                CLR_BIT(GICR,GICR_INT1);
            break;
            case EXT_2:
                CLR_BIT(GICR,GICR_INT2);
            break;
            default:
            break;
        }
    }
    return Loc_u8Status;
}

void EXTINT_voidSetCallBack(void(*Copy_pfun)(void),u8 Copy_u8ExtIntIndex)
{
	EXTINT_SetCallBackExtInt[Copy_u8ExtIntIndex] = Copy_pfun;
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void){
    if(EXTINT_SetCallBackExtInt[EXT_0]!= NULL)
    {
        EXTINT_SetCallBackExtInt[EXT_0]();
    }
    else
    {
        /*DO NOTHING*/
    }
}

void __vector_2(void)  __attribute__((signal));
void __vector_2(void){
    if(EXTINT_SetCallBackExtInt[EXT_1]!= NULL)
    {
        EXTINT_SetCallBackExtInt[EXT_1]();
    }
    else
    {
        /*DO NOTHING*/
    }
}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void){
    if(EXTINT_SetCallBackExtInt[EXT_2]!= NULL)
    {
        EXTINT_SetCallBackExtInt[EXT_2]();
    }
    else
    {
        /*DO NOTHING*/
    }    
}