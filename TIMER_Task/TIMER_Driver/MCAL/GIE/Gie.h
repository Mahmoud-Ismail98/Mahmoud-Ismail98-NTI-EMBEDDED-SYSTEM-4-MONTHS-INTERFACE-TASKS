/*
 * Gie.h
 *
 * Created: 10/22/2023 10:01:05 AM
 *  Author: sharb
 */ 


#ifndef GIE_H_
#define GIE_H_


typedef enum
{
	GIE_OKAY,
	GIE_ERROR
}GIE_ERROR_t;


typedef enum
{
	GIE_ENABLE,
	GIE_DISABLE,
	GIE_STATUS_ERROR
}GIE_STATUS_t;



GIE_ERROR_t GIE_status(GIE_STATUS_t arg_enu_GIE_status);


#endif /* GIE_H_ */