/***************************STM32 CAN驱动文件****************************/

//外设寄存器基地址
#define CAN1_BASE 0x4000 6400
#define CAN2_BASE 0x4000 6800

typedef strcut
{
	volitile uint32_t TIR;
	volitile uint32_t TDTR;
	volitile uint32_t TDLR;
	volitile uint32_t TDHR;
}CAN_TxMailBox_Typedef;			//发送邮箱封装

typedef struct
{
	volitile uint32_t RIR;
	volitile uint32_t RDTR;
	volitile uint32_t RDLR;
	volitile uint32_t RDHR;
}CAN_FIFOMailBox_TypeDef;		//接收邮箱封装

typedef strcut
{
	volitile uint32_t FR1;
	volitile uint32_t FR2;
}CAN_FilterRegister_Typedef;	//过滤器组封装

//CAN寄存器定义(按照参考手册CAN寄存器映射，需要与内存地址对应)
typedef strcut
{
	volitile uint32_t MCR;		//必须在实际地址中查询内容 因此加volitile(易变得、不稳定的)
	volitile uint32_t MSR;
	volitile uint32_t TSR;
	volitile uint32_t RF0R;
	volitile uint32_t RF1F;
	volitile uint32_t IER;
	volitile uint32_t ESR;
	volitile uint32_t BTR;
	uint32_t RESERVED0[88];		//保留区域
	CAN_TxMailBox_Typedef sTxMailBox[3];		//发送邮箱区域
	CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];	//FIFO邮箱
	uint32_t RESERVED1[12];		//保留区域
	volitile uint32_t FMR;
	volitile uint32_t FM1R;
	uint32_t  RESERVED2;
	volitile uint32_t FS1R;
	uint32_t  RESERVED3;
	volitile uint32_t FFA1R;
	uint32_t  RESERVED4;
	volitile uint32_t FA1R;
	uint32_t  RESERVED5[8];
	CAN_FilterRegister_Typedef sFilterRegister[28];
}CAN_TypeDef;

//以结构体指针形式封装外设
#define CAN1 (CAN_TypeDef *) CAN1_BASE
#define CAN2 (CAN_TypeDef *) CAN2_BASE

