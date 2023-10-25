#include "../../services/Bit_utils.h"
#include "../../services/Std_types.h"
#include "../../MCAL/PORT/include/port_private.h"
#include "../../MCAL/DIO/include/DIO.h"
#include "../../MCAL/PORT/include/port.h"
#include "../../HAL/7_segment/seven_segment.h"




	
int main(void)
{
	
init_four_sev_Seg();

while(1)
{	

	sev_seg_stop_watch();
}
}

