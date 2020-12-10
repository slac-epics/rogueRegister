// #############################################
// Auto Generated Header File From Rogue
// #############################################
#ifndef __ROGUE_ADDR_MAP_H__
#define __ROGUE_ADDR_MAP_H__

#define ROGUE_ADDR_MAP "Path	TypeStr	Address	Offset	Mode	BitOffset	BitSize	Minimum	Maximum	Enum	OverlapEn	Verify	ModelId	ByteReverse	BitReverse	BinPoint	BulkEn	UpdateNotify	MemBaseName	BlockName	BlockSize	NumValues	ValueBits	ValueStride	RetryCount	Description|"\
     "Top.AxiVersion.FpgaVersion	UInt32	0x0	0x0	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.FpgaVersion	0x4	0	32	32	0	FPGA Firmware Version Number|"\
     "Top.AxiVersion.ScratchPad	UInt32	0x4	0x4	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.ScratchPad	0x4	0	32	32	0	Register to test reads and writes|"\
     "Top.AxiVersion.UpTimeCnt	UInt32	0x8	0x8	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.UpTimeCnt	0x4	0	32	32	0	Number of seconds since last reset|"\
     "Top.AxiVersion.FpgaReloadHalt	UInt1	0x100	0x100	RW	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.FpgaReloadHalt	0x4	0	1	1	0	Used to halt automatic reloads via AxiVersion|"\
     "Top.AxiVersion.FpgaReload	UInt1	0x104	0x104	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.AxiVersion.FpgaReload	0x4	0	1	1	0	Optional Reload the FPGA from the attached PROM|"\
     "Top.AxiVersion.FpgaReloadAddress	UInt32	0x108	0x108	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.FpgaReloadAddress	0x4	0	32	32	0	Reload start address|"\
     "Top.AxiVersion.UserReset	UInt1	0x10c	0x10c	RW	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.UserReset	0x4	0	1	1	0	Optional User Reset|"\
     "Top.AxiVersion.FdSerial	UInt64	0x300	0x300	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.FdSerial	0x8	0	64	64	0	Board ID value read from DS2411 chip|"\
     "Top.AxiVersion.DeviceId	UInt32	0x500	0x500	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.DeviceId	0x4	0	32	32	0	Device Identification  (configued by generic)|"\
     "Top.AxiVersion.GitHash	UInt160	0x600	0x600	RO	[0]	[160]	0	1461501637330902918203684832716283019655932542975	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.GitHash	0x14	0	160	160	0	GIT SHA-1 Hash|"\
     "Top.AxiVersion.DeviceDna	UInt128	0x700	0x700	RO	[0]	[128]	0	340282366920938463463374607431768211455	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AxiVersion.DeviceDna	0x10	0	128	128	0	Xilinx Device DNA value burned into FPGA|"\
     "Top.AxiVersion.BuildStamp	String(256)	0x800	0x800	RO	[0]	[2048]	None	None	None	False	True	5	False	False	0	True	True	Unnamed_5	Top.AxiVersion.BuildStamp	0x100	0	2048	2048	0	Firmware Build String|"\
     "Top.PgpMon[0].CountReset	UInt1	0x2000000	0x0	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.PgpMon[0].CountReset	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].AutoStatus	Bool	0x2000004	0x4	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].AutoStatus	0x4	0	1	1	0	Auto Status Send Enable (PPI)|"\
     "Top.PgpMon[0].Loopback	UInt3	0x2000008	0x8	RO	[0]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].Loopback	0x4	0	3	3	0	GT Loopback Mode|"\
     "Top.PgpMon[0].SkipInterval	UInt32	0x200000c	0xc	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].SkipInterval	0x4	0	32	32	0	|"\
     "Top.PgpMon[0].RxPhyActive	Bool	0x2000010	0x10	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxPhyActive	0x4	0	1	1	0	RX Phy is Ready|"\
     "Top.PgpMon[0].RxLocalLinkReady	Bool	0x2000010	0x10	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxPhyActive	0x4	0	1	1	0	Rx Local Link Ready|"\
     "Top.PgpMon[0].RxRemLinkReady	Bool	0x2000010	0x10	RO	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxPhyActive	0x4	0	1	1	0	Rx Remote Link Ready|"\
     "Top.PgpMon[0].RxRemPause	UInt4	0x2000020	0x20	RO	[16]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemPause	0x4	0	4	4	0	RX Remote Pause Asserted|"\
     "Top.PgpMon[0].RxRemOverflow	UInt4	0x2000020	0x20	RO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemPause	0x4	0	4	4	0	Received remote overflow flag|"\
     "Top.PgpMon[0].RxClockFreqRaw	UInt32	0x200002c	0x2c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxClockFreqRaw	0x4	0	32	32	0	|"\
     "Top.PgpMon[0].RxFrameCount	UInt16	0x2000024	0x24	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxFrameCount	0x4	0	16	16	0	|"\
     "Top.PgpMon[0].RxFrameErrorCount	UInt8	0x2000028	0x28	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxFrameErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxCellErrorCount	UInt8	0x2000014	0x14	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxCellErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxLinkDownCount	UInt8	0x2000018	0x18	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxLinkDownCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxLinkErrorCount	UInt8	0x200001c	0x1c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxLinkErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[0]	UInt8	0x2000040	0x40	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[0]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[1]	UInt8	0x2000044	0x44	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[1]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[2]	UInt8	0x2000048	0x48	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[2]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[3]	UInt8	0x200004c	0x4c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[3]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[4]	UInt8	0x2000050	0x50	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[4]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[5]	UInt8	0x2000054	0x54	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[5]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[6]	UInt8	0x2000058	0x58	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[6]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[7]	UInt8	0x200005c	0x5c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[7]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[8]	UInt8	0x2000060	0x60	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[8]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[9]	UInt8	0x2000064	0x64	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[9]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[10]	UInt8	0x2000068	0x68	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[10]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[11]	UInt8	0x200006c	0x6c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[11]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[12]	UInt8	0x2000070	0x70	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[12]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[13]	UInt8	0x2000074	0x74	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[13]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[14]	UInt8	0x2000078	0x78	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[14]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxRemOverflowCount[15]	UInt8	0x200007c	0x7c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxRemOverflowCount[15]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxOpCodeCount	UInt8	0x2000030	0x30	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxOpCodeCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].RxOpCodeDataLastRaw	UInt56	0x2000034	0x34	RO	[0]	[56]	0	72057594037927935	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxOpCodeDataLastRaw	0x8	0	56	56	0	|"\
     "Top.PgpMon[0].RxOpCodeNumLastRaw	UInt3	0x2000034	0x34	RO	[56]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RxOpCodeDataLastRaw	0x8	0	3	3	0	|"\
     "Top.PgpMon[0].PhyRxValid	UInt1	0x2000108	0x108	RO	[2]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].PhyRxValid	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].PhyRxData	UInt64	0x2000100	0x100	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].PhyRxData	0x8	0	64	64	0	|"\
     "Top.PgpMon[0].PhyRxHeader	UInt2	0x2000108	0x108	RO	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].PhyRxValid	0x4	0	2	2	0	|"\
     "Top.PgpMon[0].EbRxValid	UInt1	0x2000118	0x118	RO	[2]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].EbRxValid	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].EbRxData	UInt64	0x2000110	0x110	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].EbRxData	0x8	0	64	64	0	|"\
     "Top.PgpMon[0].EbRxHeader	UInt2	0x2000118	0x118	RO	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].EbRxValid	0x4	0	2	2	0	|"\
     "Top.PgpMon[0].EbRxStatus	UInt9	0x2000118	0x118	RO	[3]	[9]	0	511	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].EbRxValid	0x4	0	9	9	0	|"\
     "Top.PgpMon[0].EbRxOverflow	UInt1	0x200011c	0x11c	RO	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].EbRxOverflow	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].EbRxOverflowCnt	UInt8	0x200011c	0x11c	RO	[1]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].EbRxOverflow	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].GearboxAligned	UInt1	0x2000120	0x120	RO	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].GearboxAligned	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].GearboxAlignCnt	UInt8	0x2000120	0x120	RO	[8]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].GearboxAligned	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].PhyRxInitCnt	UInt4	0x2000130	0x130	RO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].PhyRxInitCnt	0x4	0	4	4	0	|"\
     "Top.PgpMon[0].RemLinkData	UInt56	0x2000138	0x138	RO	[0]	[56]	0	72057594037927935	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].RemLinkData	0x8	0	56	56	0	|"\
     "Top.PgpMon[0].FlowControlDisable	Bool	0x2000080	0x80	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].FlowControlDisable	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].TxDisable	Bool	0x2000080	0x80	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].FlowControlDisable	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].TxPhyActive	Bool	0x2000084	0x84	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxPhyActive	0x4	0	1	1	0	TX Phy is Ready|"\
     "Top.PgpMon[0].TxLinkReady	Bool	0x2000084	0x84	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxPhyActive	0x4	0	1	1	0	|"\
     "Top.PgpMon[0].TxLocPause	UInt4	0x200008c	0x8c	RO	[16]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocPause	0x4	0	4	4	0	Tx Local Pause Asserted|"\
     "Top.PgpMon[0].TxLocOverflow	UInt4	0x200008c	0x8c	RO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocPause	0x4	0	4	4	0	Received local overflow flag|"\
     "Top.PgpMon[0].TxClockFreqRaw	UInt32	0x200009c	0x9c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxClockFreqRaw	0x4	0	32	32	0	|"\
     "Top.PgpMon[0].TxFrameCount	UInt16	0x2000090	0x90	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxFrameCount	0x4	0	16	16	0	|"\
     "Top.PgpMon[0].TxFrameErrorCount	UInt8	0x2000094	0x94	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxFrameErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[0]	UInt8	0x20000b0	0xb0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[0]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[1]	UInt8	0x20000b4	0xb4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[1]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[2]	UInt8	0x20000b8	0xb8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[2]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[3]	UInt8	0x20000bc	0xbc	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[3]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[4]	UInt8	0x20000c0	0xc0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[4]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[5]	UInt8	0x20000c4	0xc4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[5]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[6]	UInt8	0x20000c8	0xc8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[6]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[7]	UInt8	0x20000cc	0xcc	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[7]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[8]	UInt8	0x20000d0	0xd0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[8]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[9]	UInt8	0x20000d4	0xd4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[9]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[10]	UInt8	0x20000d8	0xd8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[10]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[11]	UInt8	0x20000dc	0xdc	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[11]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[12]	UInt8	0x20000e0	0xe0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[12]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[13]	UInt8	0x20000e4	0xe4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[13]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[14]	UInt8	0x20000e8	0xe8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[14]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxLocOverflowCount[15]	UInt8	0x20000ec	0xec	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxLocOverflowCount[15]	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxOpCodeCount	UInt8	0x20000a0	0xa0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxOpCodeCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[0].TxOpCodeDataLastRaw	UInt56	0x20000a4	0xa4	RO	[0]	[56]	0	72057594037927935	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxOpCodeDataLastRaw	0x8	0	56	56	0	|"\
     "Top.PgpMon[0].TxOpCodeNumLastRaw	UInt3	0x20000a4	0xa4	RO	[56]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[0].TxOpCodeDataLastRaw	0x8	0	3	3	0	|"\
     "Top.PgpMon[1].CountReset	UInt1	0x2002000	0x0	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.PgpMon[1].CountReset	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].AutoStatus	Bool	0x2002004	0x4	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].AutoStatus	0x4	0	1	1	0	Auto Status Send Enable (PPI)|"\
     "Top.PgpMon[1].Loopback	UInt3	0x2002008	0x8	RO	[0]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].Loopback	0x4	0	3	3	0	GT Loopback Mode|"\
     "Top.PgpMon[1].SkipInterval	UInt32	0x200200c	0xc	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].SkipInterval	0x4	0	32	32	0	|"\
     "Top.PgpMon[1].RxPhyActive	Bool	0x2002010	0x10	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxPhyActive	0x4	0	1	1	0	RX Phy is Ready|"\
     "Top.PgpMon[1].RxLocalLinkReady	Bool	0x2002010	0x10	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxPhyActive	0x4	0	1	1	0	Rx Local Link Ready|"\
     "Top.PgpMon[1].RxRemLinkReady	Bool	0x2002010	0x10	RO	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxPhyActive	0x4	0	1	1	0	Rx Remote Link Ready|"\
     "Top.PgpMon[1].RxRemPause	UInt4	0x2002020	0x20	RO	[16]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemPause	0x4	0	4	4	0	RX Remote Pause Asserted|"\
     "Top.PgpMon[1].RxRemOverflow	UInt4	0x2002020	0x20	RO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemPause	0x4	0	4	4	0	Received remote overflow flag|"\
     "Top.PgpMon[1].RxClockFreqRaw	UInt32	0x200202c	0x2c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxClockFreqRaw	0x4	0	32	32	0	|"\
     "Top.PgpMon[1].RxFrameCount	UInt16	0x2002024	0x24	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxFrameCount	0x4	0	16	16	0	|"\
     "Top.PgpMon[1].RxFrameErrorCount	UInt8	0x2002028	0x28	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxFrameErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxCellErrorCount	UInt8	0x2002014	0x14	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxCellErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxLinkDownCount	UInt8	0x2002018	0x18	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxLinkDownCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxLinkErrorCount	UInt8	0x200201c	0x1c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxLinkErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[0]	UInt8	0x2002040	0x40	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[0]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[1]	UInt8	0x2002044	0x44	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[1]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[2]	UInt8	0x2002048	0x48	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[2]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[3]	UInt8	0x200204c	0x4c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[3]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[4]	UInt8	0x2002050	0x50	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[4]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[5]	UInt8	0x2002054	0x54	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[5]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[6]	UInt8	0x2002058	0x58	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[6]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[7]	UInt8	0x200205c	0x5c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[7]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[8]	UInt8	0x2002060	0x60	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[8]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[9]	UInt8	0x2002064	0x64	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[9]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[10]	UInt8	0x2002068	0x68	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[10]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[11]	UInt8	0x200206c	0x6c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[11]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[12]	UInt8	0x2002070	0x70	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[12]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[13]	UInt8	0x2002074	0x74	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[13]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[14]	UInt8	0x2002078	0x78	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[14]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxRemOverflowCount[15]	UInt8	0x200207c	0x7c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxRemOverflowCount[15]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxOpCodeCount	UInt8	0x2002030	0x30	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxOpCodeCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].RxOpCodeDataLastRaw	UInt56	0x2002034	0x34	RO	[0]	[56]	0	72057594037927935	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxOpCodeDataLastRaw	0x8	0	56	56	0	|"\
     "Top.PgpMon[1].RxOpCodeNumLastRaw	UInt3	0x2002034	0x34	RO	[56]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RxOpCodeDataLastRaw	0x8	0	3	3	0	|"\
     "Top.PgpMon[1].PhyRxValid	UInt1	0x2002108	0x108	RO	[2]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].PhyRxValid	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].PhyRxData	UInt64	0x2002100	0x100	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].PhyRxData	0x8	0	64	64	0	|"\
     "Top.PgpMon[1].PhyRxHeader	UInt2	0x2002108	0x108	RO	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].PhyRxValid	0x4	0	2	2	0	|"\
     "Top.PgpMon[1].EbRxValid	UInt1	0x2002118	0x118	RO	[2]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].EbRxValid	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].EbRxData	UInt64	0x2002110	0x110	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].EbRxData	0x8	0	64	64	0	|"\
     "Top.PgpMon[1].EbRxHeader	UInt2	0x2002118	0x118	RO	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].EbRxValid	0x4	0	2	2	0	|"\
     "Top.PgpMon[1].EbRxStatus	UInt9	0x2002118	0x118	RO	[3]	[9]	0	511	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].EbRxValid	0x4	0	9	9	0	|"\
     "Top.PgpMon[1].EbRxOverflow	UInt1	0x200211c	0x11c	RO	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].EbRxOverflow	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].EbRxOverflowCnt	UInt8	0x200211c	0x11c	RO	[1]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].EbRxOverflow	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].GearboxAligned	UInt1	0x2002120	0x120	RO	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].GearboxAligned	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].GearboxAlignCnt	UInt8	0x2002120	0x120	RO	[8]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].GearboxAligned	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].PhyRxInitCnt	UInt4	0x2002130	0x130	RO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].PhyRxInitCnt	0x4	0	4	4	0	|"\
     "Top.PgpMon[1].RemLinkData	UInt56	0x2002138	0x138	RO	[0]	[56]	0	72057594037927935	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].RemLinkData	0x8	0	56	56	0	|"\
     "Top.PgpMon[1].FlowControlDisable	Bool	0x2002080	0x80	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].FlowControlDisable	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].TxDisable	Bool	0x2002080	0x80	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].FlowControlDisable	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].TxPhyActive	Bool	0x2002084	0x84	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxPhyActive	0x4	0	1	1	0	TX Phy is Ready|"\
     "Top.PgpMon[1].TxLinkReady	Bool	0x2002084	0x84	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxPhyActive	0x4	0	1	1	0	|"\
     "Top.PgpMon[1].TxLocPause	UInt4	0x200208c	0x8c	RO	[16]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocPause	0x4	0	4	4	0	Tx Local Pause Asserted|"\
     "Top.PgpMon[1].TxLocOverflow	UInt4	0x200208c	0x8c	RO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocPause	0x4	0	4	4	0	Received local overflow flag|"\
     "Top.PgpMon[1].TxClockFreqRaw	UInt32	0x200209c	0x9c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxClockFreqRaw	0x4	0	32	32	0	|"\
     "Top.PgpMon[1].TxFrameCount	UInt16	0x2002090	0x90	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxFrameCount	0x4	0	16	16	0	|"\
     "Top.PgpMon[1].TxFrameErrorCount	UInt8	0x2002094	0x94	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxFrameErrorCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[0]	UInt8	0x20020b0	0xb0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[0]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[1]	UInt8	0x20020b4	0xb4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[1]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[2]	UInt8	0x20020b8	0xb8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[2]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[3]	UInt8	0x20020bc	0xbc	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[3]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[4]	UInt8	0x20020c0	0xc0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[4]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[5]	UInt8	0x20020c4	0xc4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[5]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[6]	UInt8	0x20020c8	0xc8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[6]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[7]	UInt8	0x20020cc	0xcc	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[7]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[8]	UInt8	0x20020d0	0xd0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[8]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[9]	UInt8	0x20020d4	0xd4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[9]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[10]	UInt8	0x20020d8	0xd8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[10]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[11]	UInt8	0x20020dc	0xdc	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[11]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[12]	UInt8	0x20020e0	0xe0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[12]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[13]	UInt8	0x20020e4	0xe4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[13]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[14]	UInt8	0x20020e8	0xe8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[14]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxLocOverflowCount[15]	UInt8	0x20020ec	0xec	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxLocOverflowCount[15]	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxOpCodeCount	UInt8	0x20020a0	0xa0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxOpCodeCount	0x4	0	8	8	0	|"\
     "Top.PgpMon[1].TxOpCodeDataLastRaw	UInt56	0x20020a4	0xa4	RO	[0]	[56]	0	72057594037927935	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxOpCodeDataLastRaw	0x8	0	56	56	0	|"\
     "Top.PgpMon[1].TxOpCodeNumLastRaw	UInt3	0x20020a4	0xa4	RO	[56]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpMon[1].TxOpCodeDataLastRaw	0x8	0	3	3	0	|"\
     "Top.SystemRegs.AvccEn0	Bool	0x100000	0x0	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AvccEn0	0x4	0	1	1	0	Enable AVCC0 DCDC|"\
     "Top.SystemRegs.AvccEn1	Bool	0x100000	0x0	RW	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AvccEn0	0x4	0	1	1	0	Enable AVCC1 DCDC|"\
     "Top.SystemRegs.Ap5V5En	Bool	0x100000	0x0	RW	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AvccEn0	0x4	0	1	1	0	Enable analog buffers 5.5V DCDC|"\
     "Top.SystemRegs.Ap5V0En	Bool	0x100000	0x0	RW	[3]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AvccEn0	0x4	0	1	1	0	Enable analog buffers 5.0V LDO|"\
     "Top.SystemRegs.A0p3V3En	Bool	0x100000	0x0	RW	[4]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AvccEn0	0x4	0	1	1	0	Enable ADCs analog 3.3V LDO|"\
     "Top.SystemRegs.A1p3V3En	Bool	0x100000	0x0	RW	[5]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AvccEn0	0x4	0	1	1	0	Enable ADCs analog 3.3V LDO|"\
     "Top.SystemRegs.Ap1V8En	Bool	0x100000	0x0	RW	[6]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AvccEn0	0x4	0	1	1	0	Enable ADCs analog 1.8V LDO|"\
     "Top.SystemRegs.FpgaTmpCritLatch	Bool	0x100010	0x10	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTmpCritLatch	0x4	0	1	1	0	FPGA Critical Temperature Triggered|"\
     "Top.SystemRegs.AdcReset	Bool	0x100004	0x4	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AdcReset	0x4	0	1	1	0	ADC Reset|"\
     "Top.SystemRegs.AdcCtrl1	Bool	0x100004	0x4	RW	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AdcReset	0x4	0	1	1	0	ADC Cntrl 1|"\
     "Top.SystemRegs.AdcCtrl2	Bool	0x100004	0x4	RW	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AdcReset	0x4	0	1	1	0	ADC Cntrl 2|"\
     "Top.SystemRegs.TrigEn	Bool	0x100100	0x100	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.TrigEn	0x4	0	1	1	0	Trigger enable|"\
     "Top.SystemRegs.TrigSrcSel	UInt3	0x100104	0x104	RW	[0]	[3]	0	7	{0: 'ExternalTTL', 1: 'SoftwareTrig', 2: 'Reserved[2]', 3: 'Reserved[3]', 4: 'Reserved[4]', 5: 'Reserved[5]', 6: 'Reserved[6]', 7: 'InternalAutoTrig'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.TrigSrcSel	0x4	0	3	3	0	Trigger source select|"\
     "Top.SystemRegs.TrigDelay	UInt32	0x100108	0x108	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.TrigDelay	0x4	0	32	32	0	Trigger delay|"\
     "Top.SystemRegs.AutoTrigEn	Bool	0x10010c	0x10c	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AutoTrigEn	0x4	0	1	1	0	Auto Trigger enable|"\
     "Top.SystemRegs.AutoTrigPeriod	UInt32	0x100110	0x110	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.AutoTrigPeriod	0x4	0	32	32	0	Auto Trigger period|"\
     "Top.SystemRegs.timingRxUserRst	Bool	0x100008	0x8	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.timingRxUserRst	0x4	0	1	1	0	Timing RX reset|"\
     "Top.SystemRegs.timingTxUserRst	Bool	0x100008	0x8	RW	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.timingRxUserRst	0x4	0	1	1	0	Timing TX reset|"\
     "Top.SystemRegs.timingUseMiniTpg	Bool	0x100008	0x8	RW	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.timingRxUserRst	0x4	0	1	1	0	Enable Mini TPG|"\
     "Top.SystemRegs.TempDigRaw[0]	UInt16	0x130000	0x30000	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.TempDigRaw[0]	0x4	0	16	16	0	Digital board temperature sensor 0|"\
     "Top.SystemRegs.TempDigRaw[1]	UInt16	0x130400	0x30400	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.TempDigRaw[1]	0x4	0	16	16	0	Digital board temperature sensor 1|"\
     "Top.SystemRegs.TempAnaRaw[0]	UInt16	0x140000	0x40000	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.TempAnaRaw[0]	0x4	0	16	16	0	Analog board temperature sensor 0|"\
     "Top.SystemRegs.TempAnaRaw[1]	UInt16	0x140400	0x40400	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.TempAnaRaw[1]	0x4	0	16	16	0	Analog board temperature sensor 1|"\
     "Top.SystemRegs.FpgaTempMon.LocalTemperatureHighByte	UInt8	0x150000	0x0	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.LocalTemperatureHighByte	0x4	0	8	8	0	Local temperature high byte (LTHB)|"\
     "Top.SystemRegs.FpgaTempMon.RemoteTemperatureHighByte	UInt8	0x150004	0x4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.RemoteTemperatureHighByte	0x4	0	8	8	0	Remote temperature high byte (RTHB)|"\
     "Top.SystemRegs.FpgaTempMon.Busy	Bool	0x150008	0x8	RO	[7]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, A/D is busy converting. POR state = n/a.|"\
     "Top.SystemRegs.FpgaTempMon.Lhigh	Bool	0x150008	0x8	RO	[6]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, indicates local HIGH temperature alarm. POR state = 0.|"\
     "Top.SystemRegs.FpgaTempMon.Llow	Bool	0x150008	0x8	RO	[5]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, indicates a local LOW temperature alarm. POR state = 0.|"\
     "Top.SystemRegs.FpgaTempMon.Rhigh	Bool	0x150008	0x8	RO	[4]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, indicates a remote diode HIGH temperature alarm. POR state = 0.|"\
     "Top.SystemRegs.FpgaTempMon.Rlow	Bool	0x150008	0x8	RO	[3]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, indicates a remote diode LOW temperature alarm. POR state = 0.|"\
     "Top.SystemRegs.FpgaTempMon.Open	Bool	0x150008	0x8	RO	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, indicates a remote diode disconnect. POR state = 0.|"\
     "Top.SystemRegs.FpgaTempMon.Rcrit	Bool	0x150008	0x8	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, indicates a remote diode critical temperature alarm. POR state = 0.|"\
     "Top.SystemRegs.FpgaTempMon.Lcrit	Bool	0x150008	0x8	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.Busy	0x4	0	1	1	0	When logic 1, indicates a local critical temperature alarm. POR state = 0.|"\
     "Top.SystemRegs.FpgaTempMon.AlertMaskRead	Bool	0x15000c	0xc	RO	[7]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskRead	0x4	0	1	1	0	\
The ALERT interrupt is enabled when this bit is LOW. The\
ALERT interrupt is disabled (masked) when this bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.AlertMaskWrite	Bool	0x150024	0x24	WO	[7]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskWrite	0x4	0	1	1	0	\
The ALERT interrupt is enabled when this bit is LOW. The\
ALERT interrupt is disabled (masked) when this bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.StopRead	Bool	0x15000c	0xc	RO	[6]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskRead	0x4	0	1	1	0	\
Standby or run mode control. Running mode is enabled when\
this bit is LOW. The SA56004X is in standby mode when this\
bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.StopWrite	Bool	0x150024	0x24	WO	[6]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskWrite	0x4	0	1	1	0	\
Standby or run mode control. Running mode is enabled when\
this bit is LOW. The SA56004X is in standby mode when this\
bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.RcritMaskRead	Bool	0x15000c	0xc	RO	[4]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskRead	0x4	0	1	1	0	\
The T_CRIT output will be activated by a remote temperature\
that exceeds the remote T_CRIT setpoint when this bit is LOW.\
The T_CRIT output will not be activated under this condition\
when this bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.RcritMaskWrite	Bool	0x150024	0x24	WO	[4]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskWrite	0x4	0	1	1	0	\
The T_CRIT output will be activated by a remote temperature\
that exceeds the remote T_CRIT setpoint when this bit is LOW.\
The T_CRIT output will not be activated under this condition\
when this bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.LcritMaskRead	Bool	0x15000c	0xc	RO	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskRead	0x4	0	1	1	0	\
The T_CRIT output will be activated by a local temperature that\
exceeds the local T_CRIT setpoint when this bit is LOW. The\
T_CRIT output will not be activated under this condition when\
this bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.LcritMaskWrite	Bool	0x150024	0x24	WO	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskWrite	0x4	0	1	1	0	\
The T_CRIT output will be activated by a local temperature that\
exceeds the local T_CRIT setpoint when this bit is LOW. The\
T_CRIT output will not be activated under this condition when\
this bit is HIGH.\
|"\
     "Top.SystemRegs.FpgaTempMon.FaultQueueRead	Bool	0x15000c	0xc	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskRead	0x4	0	1	1	0	\
A single remote temperature measurement outside the HIGH,\
LOW or T_CRIT setpoints will trigger an outside limit condition\
resulting in setting the status bits and associated output pins\
when this bit is LOW. Three consecutive measurements outside of\
one of these setpoints are required to trigger an outside of\
limit condition when this bit is HIGH.|"\
     "Top.SystemRegs.FpgaTempMon.FaultQueueWrite	Bool	0x150024	0x24	WO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMaskWrite	0x4	0	1	1	0	\
A single remote temperature measurement outside the HIGH,\
LOW or T_CRIT setpoints will trigger an outside limit condition\
resulting in setting the status bits and associated output pins\
when this bit is LOW. Three consecutive measurements outside of\
one of these setpoints are required to trigger an outside of\
limit condition when this bit is HIGH.|"\
     "Top.SystemRegs.FpgaTempMon.ConvertRateRead	UInt4	0x150010	0x10	RO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.ConvertRateRead	0x4	0	4	4	0	conversion rate read access (CR)|"\
     "Top.SystemRegs.FpgaTempMon.ConvertRateWrite	UInt4	0x150028	0x28	WO	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.ConvertRateWrite	0x4	0	4	4	0	conversion rate write access (CR)|"\
     "Top.SystemRegs.FpgaTempMon.LocalHighSetpointRead	UInt8	0x150014	0x14	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.LocalHighSetpointRead	0x4	0	8	8	0	local high setpoint read access (LHS)|"\
     "Top.SystemRegs.FpgaTempMon.LocalHighSetpointWrite	UInt8	0x15002c	0x2c	WO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.LocalHighSetpointWrite	0x4	0	8	8	0	local high setpoint write access (LHS)|"\
     "Top.SystemRegs.FpgaTempMon.LocalLowSetpointRead	UInt8	0x150018	0x18	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.LocalLowSetpointRead	0x4	0	8	8	0	Local Low setpoint read access (LLS)|"\
     "Top.SystemRegs.FpgaTempMon.LocalLowSetpointWrite	UInt8	0x150030	0x30	WO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.LocalLowSetpointWrite	0x4	0	8	8	0	Local Low setpoint write access (LLS)|"\
     "Top.SystemRegs.FpgaTempMon.RemoteHighSetpointHighByteRead	UInt8	0x15001c	0x1c	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.RemoteHighSetpointHighByteRead	0x4	0	8	8	0	Remote high setpoint high byte read access (RHSHB)|"\
     "Top.SystemRegs.FpgaTempMon.RemoteHighSetpointHighByteWrite	UInt8	0x150034	0x34	WO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.RemoteHighSetpointHighByteWrite	0x4	0	8	8	0	Remote high setpoint high byte write access (RHSHB)|"\
     "Top.SystemRegs.FpgaTempMon.RemoteLowSetpointHighByteRead	UInt8	0x150020	0x20	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.RemoteLowSetpointHighByteRead	0x4	0	8	8	0	Remote Low setpoint high byte read access (RLSHB)|"\
     "Top.SystemRegs.FpgaTempMon.RemoteLowSetpointHighByteWrite	UInt8	0x150038	0x38	WO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.RemoteLowSetpointHighByteWrite	0x4	0	8	8	0	Remote Low setpoint high byte write access (RLSHB)|"\
     "Top.SystemRegs.FpgaTempMon.RemoteTcritSetpoint	Int8	0x150064	0x64	RW	[0]	[8]	-127	127	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.RemoteTcritSetpoint	0x4	0	8	8	0	Remote T_CRIT setpoint (RCS)|"\
     "Top.SystemRegs.FpgaTempMon.LocalTcritSetpoint	Int8	0x150080	0x80	RW	[0]	[8]	-127	127	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.LocalTcritSetpoint	0x4	0	8	8	0	Local T_CRIT setpoint (LCS)|"\
     "Top.SystemRegs.FpgaTempMon.TcritHysteresis	UInt5	0x150084	0x84	RW	[0]	[5]	0	31	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.TcritHysteresis	0x4	0	5	5	0	T_CRIT hysteresis (TH)|"\
     "Top.SystemRegs.FpgaTempMon.OneShot	UInt1	0x15003c	0x3c	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.OneShot	0x4	0	1	1	0	writing register initiates a one-shot conversion (One Shot)|"\
     "Top.SystemRegs.FpgaTempMon.AlertMode	Bool	0x1502fc	0x2fc	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.AlertMode	0x4	0	1	1	0	Alert mode (AM))|"\
     "Top.SystemRegs.FpgaTempMon.ManufacturerId	UInt8	0x1503f8	0x3f8	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.ManufacturerId	0x4	0	8	8	0	Read manufacturers ID (RMID) should be 0xA1|"\
     "Top.SystemRegs.FpgaTempMon.DieRevision	UInt8	0x1503fc	0x3fc	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.SystemRegs.FpgaTempMon.DieRevision	0x4	0	8	8	0	Read stepping or die revision (RDR) should be 0x00|"\
     "Top.Integrators.TrigDelay	UInt8	0x3000000	0x0	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.TrigDelay	0x4	0	8	8	0	Integrator trigger delay|"\
     "Top.Integrators.IntegralSize	UInt8	0x3000004	0x4	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.IntegralSize	0x4	0	8	8	0	Integrator size|"\
     "Top.Integrators.BaselineSize	UInt3	0x3000008	0x8	RW	[0]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.BaselineSize	0x4	0	3	3	0	Baseline size (power of 2)|"\
     "Top.Integrators.QuadrantSel	Bool	0x300000c	0xc	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.Integrators.QuadrantSel	0x4	0	1	1	0	Odd/even channel selector for floating point equations|"\
     "Top.Integrators.IntensityRaw	UInt64	0x3000010	0x10	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.IntensityRaw	0x8	0	64	64	0	Calculated Intensity in Float64|"\
     "Top.Integrators.PositionXRaw	UInt64	0x3000018	0x18	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.PositionXRaw	0x8	0	64	64	0	Calculated Position X in Float64|"\
     "Top.Integrators.PositionYRaw	UInt64	0x3000020	0x20	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.PositionYRaw	0x8	0	64	64	0	Calculated Position Y in Float64|"\
     "Top.Integrators.AdcIntegral[0]	UInt24	0x3000030	0x30	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[0]	0x4	0	24	24	0	Integral ADC channel0|"\
     "Top.Integrators.AdcIntegral[1]	UInt24	0x3000034	0x34	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[1]	0x4	0	24	24	0	Integral ADC channel1|"\
     "Top.Integrators.AdcIntegral[2]	UInt24	0x3000038	0x38	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[2]	0x4	0	24	24	0	Integral ADC channel2|"\
     "Top.Integrators.AdcIntegral[3]	UInt24	0x300003c	0x3c	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[3]	0x4	0	24	24	0	Integral ADC channel3|"\
     "Top.Integrators.AdcIntegral[4]	UInt24	0x3000040	0x40	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[4]	0x4	0	24	24	0	Integral ADC channel4|"\
     "Top.Integrators.AdcIntegral[5]	UInt24	0x3000044	0x44	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[5]	0x4	0	24	24	0	Integral ADC channel5|"\
     "Top.Integrators.AdcIntegral[6]	UInt24	0x3000048	0x48	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[6]	0x4	0	24	24	0	Integral ADC channel6|"\
     "Top.Integrators.AdcIntegral[7]	UInt24	0x300004c	0x4c	RO	[0]	[24]	0	16777215	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.AdcIntegral[7]	0x4	0	24	24	0	Integral ADC channel7|"\
     "Top.Integrators.Baseline[0]	UInt16	0x3000050	0x50	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[0]	0x4	0	16	16	0	Baseline ADC channel0|"\
     "Top.Integrators.Baseline[1]	UInt16	0x3000054	0x54	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[1]	0x4	0	16	16	0	Baseline ADC channel1|"\
     "Top.Integrators.Baseline[2]	UInt16	0x3000058	0x58	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[2]	0x4	0	16	16	0	Baseline ADC channel2|"\
     "Top.Integrators.Baseline[3]	UInt16	0x300005c	0x5c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[3]	0x4	0	16	16	0	Baseline ADC channel3|"\
     "Top.Integrators.Baseline[4]	UInt16	0x3000060	0x60	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[4]	0x4	0	16	16	0	Baseline ADC channel4|"\
     "Top.Integrators.Baseline[5]	UInt16	0x3000064	0x64	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[5]	0x4	0	16	16	0	Baseline ADC channel5|"\
     "Top.Integrators.Baseline[6]	UInt16	0x3000068	0x68	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[6]	0x4	0	16	16	0	Baseline ADC channel6|"\
     "Top.Integrators.Baseline[7]	UInt16	0x300006c	0x6c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.Baseline[7]	0x4	0	16	16	0	Baseline ADC channel7|"\
     "Top.Integrators.CorrCoefficientRaw[0]	UInt64	0x3000080	0x80	RW	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.CorrCoefficientRaw[0]	0x8	0	64	64	0	Gain correction coefficient 0 in Float64|"\
     "Top.Integrators.CorrCoefficientRaw[1]	UInt64	0x3000088	0x88	RW	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.CorrCoefficientRaw[1]	0x8	0	64	64	0	Gain correction coefficient 1 in Float64|"\
     "Top.Integrators.CorrCoefficientRaw[2]	UInt64	0x3000090	0x90	RW	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.CorrCoefficientRaw[2]	0x8	0	64	64	0	Gain correction coefficient 2 in Float64|"\
     "Top.Integrators.CorrCoefficientRaw[3]	UInt64	0x3000098	0x98	RW	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.CorrCoefficientRaw[3]	0x8	0	64	64	0	Gain correction coefficient 3 in Float64|"\
     "Top.Integrators.CntRst	Bool	0x3000100	0x100	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	False	4	False	False	0	True	True	Unnamed_5	Top.Integrators.CntRst	0x4	0	1	1	0	Reset counters|"\
     "Top.Integrators.ProcFifoPauseThreshold	UInt8	0x3000104	0x104	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.ProcFifoPauseThreshold	0x4	0	8	8	0	Processed data buffers threshold before throttling triggers from the timing core|"\
     "Top.Integrators.ProcFifoPauseCnt	UInt32	0x3000108	0x108	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.ProcFifoPauseCnt	0x4	0	32	32	0	Processed data buffer threshold event counter|"\
     "Top.Integrators.IntFifoPauseThreshold	UInt8	0x300010c	0x10c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.IntFifoPauseThreshold	0x4	0	8	8	0	Integral data buffers threshold before throttling triggers from the timing core|"\
     "Top.Integrators.IntFifoPauseCnt	UInt32	0x3000110	0x110	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.IntFifoPauseCnt	0x4	0	32	32	0	Integral data buffer threshold event counter|"\
     "Top.Integrators.TrigCnt	UInt32	0x3000070	0x70	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.Integrators.TrigCnt	0x4	0	32	32	0	Trigger counter|"\
     "Top.RawBuffers.BuffEn[0]	Bool	0x3100000	0x0	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer0|"\
     "Top.RawBuffers.BuffEn[1]	Bool	0x3100000	0x0	RW	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer1|"\
     "Top.RawBuffers.BuffEn[2]	Bool	0x3100000	0x0	RW	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer2|"\
     "Top.RawBuffers.BuffEn[3]	Bool	0x3100000	0x0	RW	[3]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer3|"\
     "Top.RawBuffers.BuffEn[4]	Bool	0x3100000	0x0	RW	[4]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer4|"\
     "Top.RawBuffers.BuffEn[5]	Bool	0x3100000	0x0	RW	[5]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer5|"\
     "Top.RawBuffers.BuffEn[6]	Bool	0x3100000	0x0	RW	[6]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer6|"\
     "Top.RawBuffers.BuffEn[7]	Bool	0x3100000	0x0	RW	[7]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffEn[0]	0x4	0	1	1	0	Enable buffer7|"\
     "Top.RawBuffers.BuffLen	UInt8	0x3100004	0x4	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.BuffLen	0x4	0	8	8	0	Buffer size|"\
     "Top.RawBuffers.TrigPrescale	UInt32	0x3100008	0x8	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.TrigPrescale	0x4	0	32	32	0	Trigger prescaler|"\
     "Top.RawBuffers.TrigCnt	UInt32	0x310000c	0xc	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.TrigCnt	0x4	0	32	32	0	Trigger counter|"\
     "Top.RawBuffers.OvflCntBuff[0]	UInt32	0x3100010	0x10	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[0]	0x4	0	32	32	0	Overflow counter buffer0|"\
     "Top.RawBuffers.OvflCntBuff[1]	UInt32	0x3100014	0x14	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[1]	0x4	0	32	32	0	Overflow counter buffer1|"\
     "Top.RawBuffers.OvflCntBuff[2]	UInt32	0x3100018	0x18	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[2]	0x4	0	32	32	0	Overflow counter buffer2|"\
     "Top.RawBuffers.OvflCntBuff[3]	UInt32	0x310001c	0x1c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[3]	0x4	0	32	32	0	Overflow counter buffer3|"\
     "Top.RawBuffers.OvflCntBuff[4]	UInt32	0x3100020	0x20	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[4]	0x4	0	32	32	0	Overflow counter buffer4|"\
     "Top.RawBuffers.OvflCntBuff[5]	UInt32	0x3100024	0x24	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[5]	0x4	0	32	32	0	Overflow counter buffer5|"\
     "Top.RawBuffers.OvflCntBuff[6]	UInt32	0x3100028	0x28	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[6]	0x4	0	32	32	0	Overflow counter buffer6|"\
     "Top.RawBuffers.OvflCntBuff[7]	UInt32	0x310002c	0x2c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.OvflCntBuff[7]	0x4	0	32	32	0	Overflow counter buffer7|"\
     "Top.RawBuffers.CntRst	Bool	0x3100030	0x30	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	False	4	False	False	0	True	True	Unnamed_5	Top.RawBuffers.CntRst	0x4	0	1	1	0	Reset counters|"\
     "Top.RawBuffers.FifoPauseThreshold	UInt8	0x3100034	0x34	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.FifoPauseThreshold	0x4	0	8	8	0	Raw data buffers threshold before throttling triggers from the timing core|"\
     "Top.RawBuffers.FifoPauseCnt	UInt32	0x3100038	0x38	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.RawBuffers.FifoPauseCnt	0x4	0	32	32	0	Raw data buffer threshold event counter|"\
     "Top.BatcherEventBuilder.DataCnt[0]	UInt32	0x4000000	0x0	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[0]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[1]	UInt32	0x4000004	0x4	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[1]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[2]	UInt32	0x4000008	0x8	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[2]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[3]	UInt32	0x400000c	0xc	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[3]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[4]	UInt32	0x4000010	0x10	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[4]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[5]	UInt32	0x4000014	0x14	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[5]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[6]	UInt32	0x4000018	0x18	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[6]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[7]	UInt32	0x400001c	0x1c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[7]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[8]	UInt32	0x4000020	0x20	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[8]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[9]	UInt32	0x4000024	0x24	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[9]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.DataCnt[10]	UInt32	0x4000028	0x28	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.DataCnt[10]	0x4	0	32	32	0	Increments every time a data frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[0]	UInt32	0x4000100	0x100	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[0]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[1]	UInt32	0x4000104	0x104	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[1]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[2]	UInt32	0x4000108	0x108	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[2]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[3]	UInt32	0x400010c	0x10c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[3]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[4]	UInt32	0x4000110	0x110	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[4]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[5]	UInt32	0x4000114	0x114	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[5]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[6]	UInt32	0x4000118	0x118	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[6]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[7]	UInt32	0x400011c	0x11c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[7]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[8]	UInt32	0x4000120	0x120	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[8]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[9]	UInt32	0x4000124	0x124	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[9]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.NullCnt[10]	UInt32	0x4000128	0x128	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NullCnt[10]	0x4	0	32	32	0	Increments every time a null frame is received|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[0]	UInt32	0x4000200	0x200	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[0]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[1]	UInt32	0x4000204	0x204	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[1]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[2]	UInt32	0x4000208	0x208	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[2]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[3]	UInt32	0x400020c	0x20c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[3]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[4]	UInt32	0x4000210	0x210	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[4]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[5]	UInt32	0x4000214	0x214	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[5]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[6]	UInt32	0x4000218	0x218	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[6]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[7]	UInt32	0x400021c	0x21c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[7]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[8]	UInt32	0x4000220	0x220	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[8]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[9]	UInt32	0x4000224	0x224	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[9]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TimeoutDropCnt[10]	UInt32	0x4000228	0x228	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TimeoutDropCnt[10]	0x4	0	32	32	0	Increments every time a timeout slave channel drop event happens|"\
     "Top.BatcherEventBuilder.TransactionCnt	UInt32	0x4000fc0	0xfc0	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TransactionCnt	0x4	0	32	32	0	Increments every time a transition frame is received|"\
     "Top.BatcherEventBuilder.TRANS_TDEST_G	UInt8	0x4000fc4	0xfc4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.TRANS_TDEST_G	0x4	0	8	8	0	TRANS_TDEST_G generic value|"\
     "Top.BatcherEventBuilder.Bypass	UInt11	0x4000fd0	0xfd0	RW	[0]	[11]	0	2047	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.Bypass	0x4	0	11	11	0	Mask to bypass a channel|"\
     "Top.BatcherEventBuilder.Timeout	UInt32	0x4000ff0	0xff0	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.Timeout	0x4	0	32	32	0	Sets the timer's timeout duration.  Setting to 0x0 (default) bypasses the timeout feature|"\
     "Top.BatcherEventBuilder.NUM_SLAVES_G	UInt8	0x4000ff4	0xff4	RO	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NUM_SLAVES_G	0x4	0	8	8	0	NUM_SLAVES_G generic value|"\
     "Top.BatcherEventBuilder.State	UInt1	0x4000ff8	0xff8	RO	[8]	[1]	0	1	{0: 'IDLE_S', 1: 'MOVE_S'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.State	0x4	0	1	1	0	current state of FSM (for debugging)|"\
     "Top.BatcherEventBuilder.BlowoffExt	Bool	0x4000ff4	0xff4	RO	[16]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.NUM_SLAVES_G	0x4	0	1	1	0	Status of external blowoff input|"\
     "Top.BatcherEventBuilder.Blowoff	Bool	0x4000ff8	0xff8	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.BatcherEventBuilder.State	0x4	0	1	1	0	Blows off the inbound AXIS stream (for debugging)|"\
     "Top.BatcherEventBuilder.CntRst	UInt1	0x4000ffc	0xffc	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.BatcherEventBuilder.CntRst	0x4	0	1	1	0	|"\
     "Top.BatcherEventBuilder.TimerRst	UInt1	0x4000ffc	0xffc	WO	[1]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.BatcherEventBuilder.CntRst	0x4	0	1	1	0	|"\
     "Top.BatcherEventBuilder.HardRst	UInt1	0x4000ffc	0xffc	WO	[2]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.BatcherEventBuilder.CntRst	0x4	0	1	1	0	|"\
     "Top.BatcherEventBuilder.SoftRst	UInt1	0x4000ffc	0xffc	WO	[3]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.BatcherEventBuilder.CntRst	0x4	0	1	1	0	|"\
     "Top.TimingFrameRx.sofCount	UInt32	0x5200000	0x0	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.sofCount	0x4	0	32	32	0	Start of frame count|"\
     "Top.TimingFrameRx.eofCount	UInt32	0x5200004	0x4	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.eofCount	0x4	0	32	32	0	End of frame count|"\
     "Top.TimingFrameRx.FidCount	UInt32	0x5200008	0x8	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.FidCount	0x4	0	32	32	0	Valid frame count|"\
     "Top.TimingFrameRx.CrcErrCount	UInt32	0x520000c	0xc	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.CrcErrCount	0x4	0	32	32	0	CRC error count|"\
     "Top.TimingFrameRx.RxClkCount	UInt32	0x5200010	0x10	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.RxClkCount	0x4	0	32	32	0	Recovered clock count div 16|"\
     "Top.TimingFrameRx.RxRstCount	UInt32	0x5200014	0x14	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.RxRstCount	0x4	0	32	32	0	Receive link reset count|"\
     "Top.TimingFrameRx.RxDecErrCount	UInt32	0x5200018	0x18	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.RxDecErrCount	0x4	0	32	32	0	Receive 8b/10b decode error count|"\
     "Top.TimingFrameRx.RxDspErrCount	UInt32	0x520001c	0x1c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.RxDspErrCount	0x4	0	32	32	0	Receive disparity error count|"\
     "Top.TimingFrameRx.ClearRxCounters	UInt1	0x5200020	0x20	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Reset receive counters|"\
     "Top.TimingFrameRx.RxLinkUp	UInt1	0x5200020	0x20	RO	[1]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Receive link status|"\
     "Top.TimingFrameRx.RxPolarity	UInt1	0x5200020	0x20	RW	[2]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Invert receive link polarity|"\
     "Top.TimingFrameRx.C_RxReset	UInt1	0x5200020	0x20	WO	[3]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Reset receive link|"\
     "Top.TimingFrameRx.ClkSel	UInt1	0x5200020	0x20	RW	[4]	[1]	0	1	{0: 'LCLS-I Clock', 1: 'LCLS-II Clock'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Select LCLS-I/LCLS-II Timing|"\
     "Top.TimingFrameRx.RxDown	UInt1	0x5200020	0x20	RW	[5]	[1]	0	1	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Rx down latch status|"\
     "Top.TimingFrameRx.BypassRst	UInt1	0x5200020	0x20	RW	[6]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Buffer bypass reset status|"\
     "Top.TimingFrameRx.RxPllReset	UInt1	0x5200020	0x20	WO	[7]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Reset RX PLL|"\
     "Top.TimingFrameRx.ModeSel	UInt1	0x5200020	0x20	RW	[9]	[1]	0	1	{0: 'Lcls1Protocol', 1: 'Lcls2Protocol'}	False	False	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Select timing mode|"\
     "Top.TimingFrameRx.ModeSelEn	UInt1	0x5200020	0x20	RW	[10]	[1]	0	1	{0: 'UseClkSel', 1: 'UseModeSel'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.ClearRxCounters	0x4	0	1	1	0	Enable ModeSel register|"\
     "Top.TimingFrameRx.MsgDelay	UInt20	0x5200024	0x24	RW	[0]	[20]	0	1048575	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.MsgDelay	0x4	0	20	20	0	LCLS-II timing frame pipeline delay (186MHz clks)|"\
     "Top.TimingFrameRx.TxClkCount	UInt32	0x5200028	0x28	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.TxClkCount	0x4	0	32	32	0	Transmit clock counter div 16|"\
     "Top.TimingFrameRx.BypassDoneCount	UInt16	0x520002c	0x2c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.BypassDoneCount	0x4	0	16	16	0	Buffer bypass done count|"\
     "Top.TimingFrameRx.BypassResetCount	UInt16	0x520002c	0x2c	RO	[16]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TimingFrameRx.BypassDoneCount	0x4	0	16	16	0	Buffer bypass reset count|"\
     "Top.XpmMiniWrapper.TPGMiniCore.TxPolarity	UInt1	0x5300000	0x0	RW	[1]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.TxPolarity	0x4	0	1	1	0	Invert transmit link polarity|"\
     "Top.XpmMiniWrapper.TPGMiniCore.TxLoopback	UInt3	0x5300000	0x0	RW	[2]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.TxPolarity	0x4	0	3	3	0	Set transmit link loopback|"\
     "Top.XpmMiniWrapper.TPGMiniCore.TxInhibit	UInt1	0x5300000	0x0	RW	[5]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.TxPolarity	0x4	0	1	1	0	Set transmit link inhibit|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BaseControl	UInt16	0x5300004	0x4	RW	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BaseControl	0x4	0	16	16	0	Base rate trigger divisor|"\
     "Top.XpmMiniWrapper.TPGMiniCore.PulseIdWr	UInt64	0x5300058	0x58	WO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.PulseIdWr	0x8	0	64	64	0	Pulse ID write|"\
     "Top.XpmMiniWrapper.TPGMiniCore.PulseIdRd	UInt64	0x5300008	0x8	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.PulseIdRd	0x8	0	64	64	0	Pulse ID read|"\
     "Top.XpmMiniWrapper.TPGMiniCore.PulseIdSet	UInt1	0x5300070	0x70	RW	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.PulseIdSet	0x4	0	1	1	0	Activates PulseId register value|"\
     "Top.XpmMiniWrapper.TPGMiniCore.TStampWr	UInt64	0x5300060	0x60	WO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.TStampWr	0x8	0	64	64	0	Time stamp Write|"\
     "Top.XpmMiniWrapper.TPGMiniCore.TStampRd	UInt64	0x5300010	0x10	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.TStampRd	0x8	0	64	64	0	Time stamp read|"\
     "Top.XpmMiniWrapper.TPGMiniCore.TStampSet	UInt1	0x5300074	0x74	RW	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.TStampSet	0x4	0	1	1	0	Activates Timestamp register value|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[0]	UInt32	0x5300018	0x18	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[0]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[1]	UInt32	0x530001c	0x1c	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[1]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[2]	UInt32	0x5300020	0x20	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[2]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[3]	UInt32	0x5300024	0x24	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[3]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[4]	UInt32	0x5300028	0x28	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[4]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[5]	UInt32	0x530002c	0x2c	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[5]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[6]	UInt32	0x5300030	0x30	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[6]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[7]	UInt32	0x5300034	0x34	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[7]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[8]	UInt32	0x5300038	0x38	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[8]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[9]	UInt32	0x530003c	0x3c	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.FixedRateDiv[9]	0x4	0	32	32	0	Fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.RateReload	UInt1	0x5300040	0x40	WO	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.RateReload	0x4	0	1	1	0	Loads cached fixed rate marker divisors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.NBeamSeq	UInt6	0x530004c	0x4c	RO	[0]	[6]	0	63	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.NBeamSeq	0x4	0	6	6	0	Number of beam request engines|"\
     "Top.XpmMiniWrapper.TPGMiniCore.NControlSeq	UInt8	0x530004c	0x4c	RO	[6]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.NBeamSeq	0x4	0	8	8	0	Number of control sequence engines|"\
     "Top.XpmMiniWrapper.TPGMiniCore.NArraysBsa	UInt8	0x530004c	0x4c	RO	[14]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.NBeamSeq	0x4	0	8	8	0	Number of BSA arrays|"\
     "Top.XpmMiniWrapper.TPGMiniCore.SeqAddrLen	UInt4	0x530004c	0x4c	RO	[22]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.NBeamSeq	0x4	0	4	4	0	Number of beam sequence engines|"\
     "Top.XpmMiniWrapper.TPGMiniCore.NAllowSeq	UInt6	0x530004c	0x4c	RO	[26]	[6]	0	63	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.NBeamSeq	0x4	0	6	6	0	Number of beam allow engines|"\
     "Top.XpmMiniWrapper.TPGMiniCore.TxReset	UInt1	0x5300068	0x68	WO	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.TxReset	0x4	0	1	1	0	Reset transmit link|"\
     "Top.XpmMiniWrapper.TPGMiniCore.CountIntervalReset	UInt1	0x530006c	0x6c	WO	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.CountIntervalReset	0x4	0	1	1	0	Count Interval Reset|"\
     "Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumSamples	UInt12	0x5300078	0x78	RW	[0]	[12]	0	4095	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumSamples	0x4	0	12	12	0	Lcls-1 BSA Number of Samples - 1|"\
     "Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaRate	UInt3	0x5300078	0x78	RW	[12]	[3]	0	7	{0: '120Hz', 1: '60Hz', 2: '30Hz', 3: '10Hz', 4: '5Hz', 5: '1Hz', 6: '0.5Hz'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumSamples	0x4	0	3	3	0	Lcls-1 BSA Rate|"\
     "Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaTimeSlot	UInt3	0x5300078	0x78	RW	[15]	[3]	0	7	{0: 'TS1', 1: 'TS2', 2: 'TS3', 3: 'TS4', 4: 'TS5', 5: 'TS6'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumSamples	0x4	0	3	3	0	Lcls-1 BSA Time Slot|"\
     "Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaSeverity	UInt2	0x5300078	0x78	RW	[18]	[2]	0	3	{0: 'INVALID', 1: 'MAJOR', 2: 'MINOR'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumSamples	0x4	0	2	2	0	Lcls-1 BSA Rejection Severity Threshold|"\
     "Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaEdefSlot	UInt4	0x5300078	0x78	RW	[20]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumSamples	0x4	0	4	4	0	Lcls-1 BSA EDEF Slot Number|"\
     "Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumAvgs	UInt8	0x5300078	0x78	RW	[24]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaNumSamples	0x4	0	8	8	0	Lcls-1 BSA Number of Values to Average per Sample - 1|"\
     "Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaStart	UInt32	0x530007c	0x7c	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.Lcls1BsaStart	0x4	0	32	32	0	Lcls-1 BSA Started by Writing any Value Here|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaCompleteWr	UInt64	0x5300050	0x50	WO	[0]	[64]	0	18446744073709551615	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaCompleteWr	0x8	0	64	64	0	BSA complete write|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaCompleteRd	UInt64	0x5300050	0x50	RO	[0]	[64]	0	18446744073709551615	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaCompleteWr	0x8	0	64	64	0	BSA complete read|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaActive[0]	UInt1	0x53001fc	0x1fc	RW	[0]	[1]	0	1	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaActive[0]	0x4	0	1	1	0	Activates/Deactivates BSA EDEF|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	UInt2	0x5300200	0x200	RW	[0]	[2]	0	3	{0: 'FixedRate', 1: 'ACRate', 2: 'Sequencer'}	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	0x4	0	2	2	0	BSA def rate mode selection|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaFixedRate[0]	UInt4	0x5300200	0x200	RW	[2]	[4]	0	15	{0: '1MHz', 1: '71kHz', 2: '10kHz', 3: '1kHz', 4: '100Hz', 5: '10Hz', 6: '1Hz'}	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	0x4	0	4	4	0	BSA fixed rate mode selection|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaACRate[0]	UInt3	0x5300200	0x200	RW	[6]	[3]	0	7	{0: '60Hz', 1: '30Hz', 2: '10Hz', 3: '5Hz', 4: '1Hz', 5: '0.5Hz'}	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	0x4	0	3	3	0	BSA AC rate mode selection|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaACTSMask[0]	UInt6	0x5300200	0x200	RW	[9]	[6]	0	63	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	0x4	0	6	6	0	BSA AC timeslot mask selection|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaSequenceSelect[0]	UInt5	0x5300200	0x200	RW	[15]	[5]	0	31	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	0x4	0	5	5	0	BSA sequencer selection|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaSequenceBitSelect[0]	UInt4	0x5300200	0x200	RW	[20]	[4]	0	15	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	0x4	0	4	4	0	BSA sequencer bit selection|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaDestMode[0]	UInt2	0x5300200	0x200	RW	[24]	[2]	0	3	{0: 'Dont_Care', 1: 'Inclusive', 2: 'Exclusive'}	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaRateSelMode[0]	0x4	0	2	2	0	BSA destination mode|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaDestInclusiveMask[0]	UInt16	0x5300204	0x204	RW	[0]	[16]	0	65535	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaDestInclusiveMask[0]	0x4	0	16	16	0	BSA inclusive destination mask|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaDestExclusiveMask[0]	UInt16	0x5300204	0x204	RW	[16]	[16]	0	65535	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaDestInclusiveMask[0]	0x4	0	16	16	0	BSA exclusive destination mask|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaNtoAvg[0]	UInt13	0x5300208	0x208	RW	[0]	[13]	0	8191	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaNtoAvg[0]	0x4	0	13	13	0	BSA def num acquisitions to average|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaAvgToWr[0]	UInt16	0x5300208	0x208	RW	[16]	[16]	0	65535	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaNtoAvg[0]	0x4	0	16	16	0	BSA def num averages to record|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BsaMaxSeverity[0]	UInt2	0x5300208	0x208	RW	[14]	[2]	0	3	{0: 'NoAlarm', 1: 'Minor', 2: 'Major', 3: 'Invalid'}	True	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BsaNtoAvg[0]	0x4	0	2	2	0	BSA def max alarm severity|"\
     "Top.XpmMiniWrapper.TPGMiniCore.PllCnt	UInt32	0x5300500	0x500	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.PllCnt	0x4	0	32	32	0	Count of PLL status changes|"\
     "Top.XpmMiniWrapper.TPGMiniCore.ClkCnt	UInt32	0x5300504	0x504	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.ClkCnt	0x4	0	32	32	0	Count of local 186M clock|"\
     "Top.XpmMiniWrapper.TPGMiniCore.SyncErrCnt	UInt32	0x5300508	0x508	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.SyncErrCnt	0x4	0	32	32	0	Count of 71k sync errors|"\
     "Top.XpmMiniWrapper.TPGMiniCore.CountInterval	UInt32	0x530050c	0x50c	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.CountInterval	0x4	0	32	32	0	Interval counters update period|"\
     "Top.XpmMiniWrapper.TPGMiniCore.BaseRateCount	UInt32	0x5300510	0x510	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.TPGMiniCore.BaseRateCount	0x4	0	32	32	0	Count of base rate triggers|"\
     "Top.XpmMiniWrapper.XpmMini.AxilRdEn	Bool	0x5301014	0x14	RW	[31]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.AxilRdEn	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Link	UInt4	0x5301000	0x0	RW	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Link	0x4	0	4	4	0	|"\
     "Top.XpmMiniWrapper.XpmMini.TxPllReset	UInt1	0x5301004	0x4	WO	[18]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.TxPllReset	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxPllReset	UInt1	0x5301004	0x4	WO	[19]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.TxPllReset	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Loopback	Bool	0x5301004	0x4	RW	[28]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.TxPllReset	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.TxReset	UInt1	0x5301004	0x4	WO	[29]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.TxPllReset	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxReset	UInt1	0x5301004	0x4	WO	[30]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.TxPllReset	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.HwEnable	Bool	0x5301004	0x4	RW	[31]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.TxPllReset	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxErrorCnts	UInt16	0x5301008	0x8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxErrorCnts	0x4	0	16	16	0	|"\
     "Top.XpmMiniWrapper.XpmMini.TxResetDone	Bool	0x5301008	0x8	RO	[16]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxErrorCnts	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.TxReady	Bool	0x5301008	0x8	RO	[17]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxErrorCnts	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxResetDone	Bool	0x5301008	0x8	RO	[18]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxErrorCnts	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxReady	Bool	0x5301008	0x8	RO	[19]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxErrorCnts	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxIsXpm	Bool	0x5301008	0x8	RO	[20]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxErrorCnts	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxId	UInt32	0x530100c	0xc	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxId	0x4	0	32	32	0	|"\
     "Top.XpmMiniWrapper.XpmMini.RxRcvCnts	UInt32	0x5301010	0x10	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.RxRcvCnts	0x4	0	32	32	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Config_L0Select_Reset	UInt1	0x5301014	0x14	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.AxilRdEn	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Config_L0Select_Enabled	Bool	0x5301014	0x14	RW	[16]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.AxilRdEn	0x4	0	1	1	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Config_L0Select_RateSel	UInt16	0x5301018	0x18	RW	[0]	[16]	0	65535	{0: '929 kHz', 1: '71 kHz', 2: '10 kHz', 3: '1 kHz', 4: '100 Hz', 5: '10 Hz', 6: '1 Hz', 32768: 'Undefined'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Config_L0Select_RateSel	0x4	0	16	16	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Config_L0Select_DestSel	UInt16	0x5301018	0x18	RW	[16]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Config_L0Select_RateSel	0x4	0	16	16	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Status_L0Select_Enabled	UInt40	0x5301020	0x20	RO	[0]	[40]	0	1099511627775	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Status_L0Select_Enabled	0x8	0	40	40	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Status_L0Select_Inhibited	UInt40	0x5301028	0x28	RO	[0]	[40]	0	1099511627775	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Status_L0Select_Inhibited	0x8	0	40	40	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Status_L0Select_Num	UInt40	0x5301030	0x30	RO	[0]	[40]	0	1099511627775	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Status_L0Select_Num	0x8	0	40	40	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Status_L0Select_NumInh	UInt40	0x5301038	0x38	RO	[0]	[40]	0	1099511627775	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Status_L0Select_NumInh	0x8	0	40	40	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Status_L0Select_NumAcc	UInt40	0x5301040	0x40	RO	[0]	[40]	0	1099511627775	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Status_L0Select_NumAcc	0x8	0	40	40	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Pipeline_Depth_Clks	UInt16	0x5301048	0x48	RW	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Pipeline_Depth_Clks	0x4	0	16	16	0	|"\
     "Top.XpmMiniWrapper.XpmMini.Pipeline_Depth_Fids	UInt8	0x5301048	0x48	RW	[16]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.Pipeline_Depth_Clks	0x4	0	8	8	0	|"\
     "Top.XpmMiniWrapper.XpmMini.PartitionMessage_Hdr	UInt16	0x530104c	0x4c	WO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.XpmMiniWrapper.XpmMini.PartitionMessage_Hdr	0x4	0	16	16	0	|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].EnableReg	Bool	0x5400000	0x0	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].EnableReg	0x4	0	1	1	0	Enable Register|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].RateType	UInt2	0x5400004	0x4	RW	[11]	[2]	0	3	{0: 'FixedRates', 1: 'AcRates', 2: 'ControlWord', 3: 'INVALID'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].RateType	0x4	0	2	2	0	|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].RateSel	UInt11	0x5400004	0x4	RW	[0]	[11]	0	2047	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].RateType	0x4	0	11	11	0	Rate select|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].DestType	UInt2	0x5400004	0x4	RW	[29]	[2]	0	3	{2: 'All', 0: 'BeamRequest', 1: 'NotBeamRequest', 3: 'Invalid'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].RateType	0x4	0	2	2	0	|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].DestSel	UInt16	0x5400004	0x4	RW	[13]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].RateType	0x4	0	16	16	0	Destination select|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].Count	UInt32	0x5400008	0x8	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2ChannelReg[0].Count	0x4	0	32	32	0	Counts|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].EnableTrig	Bool	0x5401000	0x0	RW	[31]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].EnableTrig	0x4	0	1	1	0	Trigger Enable|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].Source	UInt4	0x5401000	0x0	RW	[0]	[4]	0	15	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].EnableTrig	0x4	0	4	4	0	Source mask|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].Polarity	UInt1	0x5401000	0x0	RW	[16]	[1]	0	1	{0: 'Falling', 1: 'Rising'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].EnableTrig	0x4	0	1	1	0	Signal polarity|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].ComplEn	UInt1	0x5401000	0x0	RW	[29]	[1]	0	1	{0: 'Disabled', 1: 'Enabled'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].EnableTrig	0x4	0	1	1	0	Enable complementary trigger outputs|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].ComplAnd	UInt1	0x5401000	0x0	RW	[30]	[1]	0	1	{0: 'LogicOR', 1: 'LogicAND'}	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].EnableTrig	0x4	0	1	1	0	Complementary trigger logic|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].Delay	UInt28	0x5401004	0x4	RW	[0]	[28]	0	268435455	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].Delay	0x4	0	28	28	0	Delay in ticks|"\
     "Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].Width	UInt28	0x5401008	0x8	RW	[0]	[28]	0	268435455	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.EvrV2CoreTriggers.EvrV2TriggerReg[0].Width	0x4	0	28	28	0	Width in ticks|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[0]	UInt7	0x5408000	0x0	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[0]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[1]	UInt7	0x5408004	0x4	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[1]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[2]	UInt7	0x5408008	0x8	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[2]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[3]	UInt7	0x540800c	0xc	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[3]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[4]	UInt7	0x5408010	0x10	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[4]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[5]	UInt7	0x5408014	0x14	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[5]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[6]	UInt7	0x5408018	0x18	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[6]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[7]	UInt7	0x540801c	0x1c	RO	[0]	[7]	0	127	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.PartitionDelay[7]	0x4	0	7	7	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.TxId	UInt32	0x5408020	0x20	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.TxId	0x4	0	32	32	0	|"\
     "Top.TriggerEventManager.XpmMessageAligner.RxId	UInt32	0x5408024	0x24	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.XpmMessageAligner.RxId	0x4	0	32	32	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].MasterEnable	Bool	0x5409000	0x0	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].MasterEnable	0x4	0	1	1	0	Enables both the trigger and event processing in Firmware|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].TriggerCount	UInt32	0x5409028	0x28	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].TriggerCount	0x4	0	32	32	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].Partition	UInt3	0x5409004	0x4	RW	[0]	[3]	0	7	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].Partition	0x4	0	3	3	0	Selected Partition to listen for events on|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].PauseThreshold	UInt5	0x5409008	0x8	RW	[0]	[5]	0	31	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].PauseThreshold	0x4	0	5	5	0	Buffer level at which Pause is asserted|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].TriggerDelay	UInt32	0x540900c	0xc	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].TriggerDelay	0x4	0	32	32	0	Number of timingClk cycles to delay trigger output to application|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].XpmOverflow	Bool	0x5409010	0x10	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].XpmOverflow	0x4	0	1	1	0	Overflow signal to XPM Feedback|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].XpmPause	Bool	0x5409010	0x10	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].XpmOverflow	0x4	0	1	1	0	Pause condition and signal to XPM Feedback|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].FifoOverflow	Bool	0x5409010	0x10	RO	[2]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].XpmOverflow	0x4	0	1	1	0	Event Buffer Overflow condition|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].FifoPause	Bool	0x5409010	0x10	RO	[3]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].XpmOverflow	0x4	0	1	1	0	Event Buffer Pause condition|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].FifoWrCnt	UInt5	0x5409010	0x10	RO	[4]	[5]	0	31	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].XpmOverflow	0x4	0	5	5	0	Number of Events in Event Buffer|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].L0Count	UInt32	0x5409014	0x14	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].L0Count	0x4	0	32	32	0	Number of L0 Triggers received|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].L1AcceptCount	UInt32	0x5409018	0x18	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].L1AcceptCount	0x4	0	32	32	0	Number of L1 Triggers Accepted|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].L1RejectCount	UInt32	0x540901c	0x1c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].L1RejectCount	0x4	0	32	32	0	Number of L1 Triggers Rejected|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].TransitionCount	UInt32	0x5409020	0x20	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].TransitionCount	0x4	0	32	32	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].XpmMessageCount	UInt32	0x5409024	0x24	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].XpmMessageCount	0x4	0	32	32	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].LastPartitionAddr	UInt32	0x540902c	0x2c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].LastPartitionAddr	0x4	0	32	32	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].LastPartitionWord0	UInt48	0x5409030	0x30	RO	[0]	[48]	0	281474976710655	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].LastPartitionWord0	0x8	0	48	48	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].PauseToTrig	UInt12	0x5409038	0x38	RO	[0]	[12]	0	4095	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].PauseToTrig	0x4	0	12	12	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].NotPauseToTrig	UInt12	0x540903c	0x3c	RO	[0]	[12]	0	4095	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].NotPauseToTrig	0x4	0	12	12	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].ResetCounters	UInt1	0x5409040	0x40	WO	[0]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].ResetCounters	0x4	0	1	1	0	|"\
     "Top.TriggerEventManager.TriggerEventBuffer[0].FifoReset	UInt1	0x5409010	0x10	WO	[31]	[1]	0	1	None	False	False	2	False	False	0	False	True	Unnamed_5	Top.TriggerEventManager.TriggerEventBuffer[0].XpmOverflow	0x4	0	1	1	0	|"\
     "Top.PgpDataStreamMonitoring.CntRst	UInt1	0x2100000	0x0	WO	[0]	[1]	0	1	None	True	False	2	False	False	0	False	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	1	1	0	Counter Reset|"\
     "Top.PgpDataStreamMonitoring.AXIS_CONFIG_G_TDATA_BYTES_C	UInt8	0x2100000	0x0	RO	[24]	[8]	0	255	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	8	8	0	|"\
     "Top.PgpDataStreamMonitoring.AXIS_CONFIG_G_TDEST_BITS_C	UInt4	0x2100000	0x0	RO	[20]	[4]	0	15	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	4	4	0	|"\
     "Top.PgpDataStreamMonitoring.AXIS_CONFIG_G_TUSER_BITS_C	UInt4	0x2100000	0x0	RO	[16]	[4]	0	15	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	4	4	0	|"\
     "Top.PgpDataStreamMonitoring.AXIS_CONFIG_G_TID_BITS_C	UInt4	0x2100000	0x0	RO	[12]	[4]	0	15	None	True	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	4	4	0	|"\
     "Top.PgpDataStreamMonitoring.AXIS_CONFIG_G_TKEEP_MODE_C	UInt4	0x2100000	0x0	RO	[8]	[4]	0	15	{0: 'TKEEP_NORMAL_C', 1: 'TKEEP_COMP_C', 2: 'TKEEP_FIXED_C', 3: 'TKEEP_COUNT_C', 15: 'UNDEFINED'}	True	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	4	4	0	|"\
     "Top.PgpDataStreamMonitoring.AXIS_CONFIG_G_TUSER_MODE_C	UInt4	0x2100000	0x0	RO	[4]	[4]	0	15	{0: 'TUSER_NORMAL_C', 1: 'TUSER_FIRST_LAST_C', 2: 'TUSER_LAST_C', 3: 'TUSER_NONE_C', 15: 'UNDEFINED'}	True	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	4	4	0	|"\
     "Top.PgpDataStreamMonitoring.AXIS_CONFIG_G_TSTRB_EN_C	Bool	0x2100000	0x0	RO	[1]	[1]	0	1	{False: 'False', True: 'True'}	True	True	4	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	1	1	0	|"\
     "Top.PgpDataStreamMonitoring.COMMON_CLK_G	Bool	0x2100000	0x0	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	True	True	4	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.CntRst	0x4	0	1	1	0	|"\
     "Top.PgpDataStreamMonitoring.Ch[0].FrameCnt	UInt64	0x2100004	0x4	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].FrameCnt	0x8	0	64	64	0	Increments every time a tValid + tLast + tReady detected|"\
     "Top.PgpDataStreamMonitoring.Ch[0].FrameRate	Int32	0x210000c	0xc	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].FrameRate	0x4	0	32	32	0	Current Frame Rate|"\
     "Top.PgpDataStreamMonitoring.Ch[0].FrameRateMax	Int32	0x2100010	0x10	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].FrameRateMax	0x4	0	32	32	0	Max Frame Rate|"\
     "Top.PgpDataStreamMonitoring.Ch[0].FrameRateMin	Int32	0x2100014	0x14	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].FrameRateMin	0x4	0	32	32	0	Min Frame Rate|"\
     "Top.PgpDataStreamMonitoring.Ch[0].RawBandwidth	UInt64	0x2100018	0x18	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].RawBandwidth	0x8	0	64	64	0	Current Bandwidth|"\
     "Top.PgpDataStreamMonitoring.Ch[0].RawBandwidthMax	UInt64	0x2100020	0x20	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].RawBandwidthMax	0x8	0	64	64	0	Max Bandwidth|"\
     "Top.PgpDataStreamMonitoring.Ch[0].RawBandwidthMin	UInt64	0x2100028	0x28	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].RawBandwidthMin	0x8	0	64	64	0	Min Bandwidth|"\
     "Top.PgpDataStreamMonitoring.Ch[0].FrameSize	Int32	0x2100030	0x30	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].FrameSize	0x4	0	32	32	0	Current Frame Size. Note: Only valid for non-interleaved AXI stream frames|"\
     "Top.PgpDataStreamMonitoring.Ch[0].FrameSizeMax	Int32	0x2100034	0x34	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].FrameSizeMax	0x4	0	32	32	0	Max Frame Size. Note: Only valid for non-interleaved AXI stream frames|"\
     "Top.PgpDataStreamMonitoring.Ch[0].FrameSizeMin	Int32	0x2100038	0x38	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[0].FrameSizeMin	0x4	0	32	32	0	Min Frame Size. Note: Only valid for non-interleaved AXI stream frames|"\
     "Top.PgpDataStreamMonitoring.Ch[1].FrameCnt	UInt64	0x2100044	0x4	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].FrameCnt	0x8	0	64	64	0	Increments every time a tValid + tLast + tReady detected|"\
     "Top.PgpDataStreamMonitoring.Ch[1].FrameRate	Int32	0x210004c	0xc	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].FrameRate	0x4	0	32	32	0	Current Frame Rate|"\
     "Top.PgpDataStreamMonitoring.Ch[1].FrameRateMax	Int32	0x2100050	0x10	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].FrameRateMax	0x4	0	32	32	0	Max Frame Rate|"\
     "Top.PgpDataStreamMonitoring.Ch[1].FrameRateMin	Int32	0x2100054	0x14	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].FrameRateMin	0x4	0	32	32	0	Min Frame Rate|"\
     "Top.PgpDataStreamMonitoring.Ch[1].RawBandwidth	UInt64	0x2100058	0x18	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].RawBandwidth	0x8	0	64	64	0	Current Bandwidth|"\
     "Top.PgpDataStreamMonitoring.Ch[1].RawBandwidthMax	UInt64	0x2100060	0x20	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].RawBandwidthMax	0x8	0	64	64	0	Max Bandwidth|"\
     "Top.PgpDataStreamMonitoring.Ch[1].RawBandwidthMin	UInt64	0x2100068	0x28	RO	[0]	[64]	0	18446744073709551615	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].RawBandwidthMin	0x8	0	64	64	0	Min Bandwidth|"\
     "Top.PgpDataStreamMonitoring.Ch[1].FrameSize	Int32	0x2100070	0x30	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].FrameSize	0x4	0	32	32	0	Current Frame Size. Note: Only valid for non-interleaved AXI stream frames|"\
     "Top.PgpDataStreamMonitoring.Ch[1].FrameSizeMax	Int32	0x2100074	0x34	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].FrameSizeMax	0x4	0	32	32	0	Max Frame Size. Note: Only valid for non-interleaved AXI stream frames|"\
     "Top.PgpDataStreamMonitoring.Ch[1].FrameSizeMin	Int32	0x2100078	0x38	RO	[0]	[32]	-2147483647	2147483647	None	False	True	3	False	False	0	True	True	Unnamed_5	Top.PgpDataStreamMonitoring.Ch[1].FrameSizeMin	0x4	0	32	32	0	Min Frame Size. Note: Only valid for non-interleaved AXI stream frames|"\
     "Top.AdcReadout[0].DelayAdcALane[0]	UInt10	0x1000200	0x200	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcALane[1]	UInt10	0x1000204	0x204	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcALane[2]	UInt10	0x1000208	0x208	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcALane[3]	UInt10	0x100020c	0x20c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcALane[4]	UInt10	0x1000210	0x210	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcALane[5]	UInt10	0x1000214	0x214	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcALane[6]	UInt10	0x1000218	0x218	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcALane[7]	UInt10	0x100021c	0x21c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcALane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[0]	UInt10	0x1000220	0x220	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[1]	UInt10	0x1000224	0x224	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[2]	UInt10	0x1000228	0x228	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[3]	UInt10	0x100022c	0x22c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[4]	UInt10	0x1000230	0x230	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[5]	UInt10	0x1000234	0x234	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[6]	UInt10	0x1000238	0x238	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].DelayAdcBLane[7]	UInt10	0x100023c	0x23c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DelayAdcBLane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[0].AdcASample[0]	UInt16	0x1000180	0x180	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcASample[1]	UInt16	0x1000184	0x184	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcASample[2]	UInt16	0x1000188	0x188	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcASample[3]	UInt16	0x100018c	0x18c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcASample[4]	UInt16	0x1000190	0x190	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcASample[5]	UInt16	0x1000194	0x194	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcASample[6]	UInt16	0x1000198	0x198	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcASample[7]	UInt16	0x100019c	0x19c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcASample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[0]	UInt16	0x10001a0	0x1a0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[1]	UInt16	0x10001a4	0x1a4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[2]	UInt16	0x10001a8	0x1a8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[3]	UInt16	0x10001ac	0x1ac	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[4]	UInt16	0x10001b0	0x1b0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[5]	UInt16	0x10001b4	0x1b4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[6]	UInt16	0x10001b8	0x1b8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].AdcBSample[7]	UInt16	0x10001bc	0x1bc	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].AdcBSample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[0].DMode	UInt2	0x1000240	0x240	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].DMode	0x4	0	2	2	0	DMode|"\
     "Top.AdcReadout[0].Invert	UInt2	0x1000244	0x244	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].Invert	0x4	0	2	2	0	Invert|"\
     "Top.AdcReadout[0].Convert	UInt2	0x1000248	0x248	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[0].Convert	0x4	0	2	2	0	Convert|"\
     "Top.AdcReadout[1].DelayAdcALane[0]	UInt10	0x1100200	0x200	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcALane[1]	UInt10	0x1100204	0x204	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcALane[2]	UInt10	0x1100208	0x208	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcALane[3]	UInt10	0x110020c	0x20c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcALane[4]	UInt10	0x1100210	0x210	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcALane[5]	UInt10	0x1100214	0x214	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcALane[6]	UInt10	0x1100218	0x218	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcALane[7]	UInt10	0x110021c	0x21c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcALane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[0]	UInt10	0x1100220	0x220	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[1]	UInt10	0x1100224	0x224	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[2]	UInt10	0x1100228	0x228	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[3]	UInt10	0x110022c	0x22c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[4]	UInt10	0x1100230	0x230	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[5]	UInt10	0x1100234	0x234	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[6]	UInt10	0x1100238	0x238	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].DelayAdcBLane[7]	UInt10	0x110023c	0x23c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DelayAdcBLane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[1].AdcASample[0]	UInt16	0x1100180	0x180	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcASample[1]	UInt16	0x1100184	0x184	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcASample[2]	UInt16	0x1100188	0x188	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcASample[3]	UInt16	0x110018c	0x18c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcASample[4]	UInt16	0x1100190	0x190	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcASample[5]	UInt16	0x1100194	0x194	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcASample[6]	UInt16	0x1100198	0x198	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcASample[7]	UInt16	0x110019c	0x19c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcASample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[0]	UInt16	0x11001a0	0x1a0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[1]	UInt16	0x11001a4	0x1a4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[2]	UInt16	0x11001a8	0x1a8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[3]	UInt16	0x11001ac	0x1ac	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[4]	UInt16	0x11001b0	0x1b0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[5]	UInt16	0x11001b4	0x1b4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[6]	UInt16	0x11001b8	0x1b8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].AdcBSample[7]	UInt16	0x11001bc	0x1bc	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].AdcBSample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[1].DMode	UInt2	0x1100240	0x240	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].DMode	0x4	0	2	2	0	DMode|"\
     "Top.AdcReadout[1].Invert	UInt2	0x1100244	0x244	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].Invert	0x4	0	2	2	0	Invert|"\
     "Top.AdcReadout[1].Convert	UInt2	0x1100248	0x248	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[1].Convert	0x4	0	2	2	0	Convert|"\
     "Top.AdcReadout[2].DelayAdcALane[0]	UInt10	0x1200200	0x200	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcALane[1]	UInt10	0x1200204	0x204	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcALane[2]	UInt10	0x1200208	0x208	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcALane[3]	UInt10	0x120020c	0x20c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcALane[4]	UInt10	0x1200210	0x210	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcALane[5]	UInt10	0x1200214	0x214	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcALane[6]	UInt10	0x1200218	0x218	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcALane[7]	UInt10	0x120021c	0x21c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcALane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[0]	UInt10	0x1200220	0x220	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[1]	UInt10	0x1200224	0x224	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[2]	UInt10	0x1200228	0x228	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[3]	UInt10	0x120022c	0x22c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[4]	UInt10	0x1200230	0x230	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[5]	UInt10	0x1200234	0x234	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[6]	UInt10	0x1200238	0x238	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].DelayAdcBLane[7]	UInt10	0x120023c	0x23c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DelayAdcBLane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[2].AdcASample[0]	UInt16	0x1200180	0x180	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcASample[1]	UInt16	0x1200184	0x184	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcASample[2]	UInt16	0x1200188	0x188	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcASample[3]	UInt16	0x120018c	0x18c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcASample[4]	UInt16	0x1200190	0x190	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcASample[5]	UInt16	0x1200194	0x194	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcASample[6]	UInt16	0x1200198	0x198	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcASample[7]	UInt16	0x120019c	0x19c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcASample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[0]	UInt16	0x12001a0	0x1a0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[1]	UInt16	0x12001a4	0x1a4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[2]	UInt16	0x12001a8	0x1a8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[3]	UInt16	0x12001ac	0x1ac	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[4]	UInt16	0x12001b0	0x1b0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[5]	UInt16	0x12001b4	0x1b4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[6]	UInt16	0x12001b8	0x1b8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].AdcBSample[7]	UInt16	0x12001bc	0x1bc	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].AdcBSample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[2].DMode	UInt2	0x1200240	0x240	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].DMode	0x4	0	2	2	0	DMode|"\
     "Top.AdcReadout[2].Invert	UInt2	0x1200244	0x244	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].Invert	0x4	0	2	2	0	Invert|"\
     "Top.AdcReadout[2].Convert	UInt2	0x1200248	0x248	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[2].Convert	0x4	0	2	2	0	Convert|"\
     "Top.AdcReadout[3].DelayAdcALane[0]	UInt10	0x1300200	0x200	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcALane[1]	UInt10	0x1300204	0x204	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcALane[2]	UInt10	0x1300208	0x208	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcALane[3]	UInt10	0x130020c	0x20c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcALane[4]	UInt10	0x1300210	0x210	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcALane[5]	UInt10	0x1300214	0x214	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcALane[6]	UInt10	0x1300218	0x218	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcALane[7]	UInt10	0x130021c	0x21c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcALane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[0]	UInt10	0x1300220	0x220	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[0]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[1]	UInt10	0x1300224	0x224	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[1]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[2]	UInt10	0x1300228	0x228	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[2]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[3]	UInt10	0x130022c	0x22c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[3]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[4]	UInt10	0x1300230	0x230	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[4]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[5]	UInt10	0x1300234	0x234	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[5]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[6]	UInt10	0x1300238	0x238	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[6]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].DelayAdcBLane[7]	UInt10	0x130023c	0x23c	RW	[0]	[10]	0	1023	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DelayAdcBLane[7]	0x4	0	10	10	0	LVDS Lane Delay|"\
     "Top.AdcReadout[3].AdcASample[0]	UInt16	0x1300180	0x180	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcASample[1]	UInt16	0x1300184	0x184	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcASample[2]	UInt16	0x1300188	0x188	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcASample[3]	UInt16	0x130018c	0x18c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcASample[4]	UInt16	0x1300190	0x190	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcASample[5]	UInt16	0x1300194	0x194	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcASample[6]	UInt16	0x1300198	0x198	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcASample[7]	UInt16	0x130019c	0x19c	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcASample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[0]	UInt16	0x13001a0	0x1a0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[0]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[1]	UInt16	0x13001a4	0x1a4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[1]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[2]	UInt16	0x13001a8	0x1a8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[2]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[3]	UInt16	0x13001ac	0x1ac	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[3]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[4]	UInt16	0x13001b0	0x1b0	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[4]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[5]	UInt16	0x13001b4	0x1b4	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[5]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[6]	UInt16	0x13001b8	0x1b8	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[6]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].AdcBSample[7]	UInt16	0x13001bc	0x1bc	RO	[0]	[16]	0	65535	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].AdcBSample[7]	0x4	0	16	16	0	ADC Sample|"\
     "Top.AdcReadout[3].DMode	UInt2	0x1300240	0x240	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].DMode	0x4	0	2	2	0	DMode|"\
     "Top.AdcReadout[3].Invert	UInt2	0x1300244	0x244	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].Invert	0x4	0	2	2	0	Invert|"\
     "Top.AdcReadout[3].Convert	UInt2	0x1300248	0x248	RW	[0]	[2]	0	3	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcReadout[3].Convert	0x4	0	2	2	0	Convert|"\
     "Top.AdcConfig[0].AdcReg_0x0006	UInt8	0x1400018	0x18	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0006	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0007	UInt8	0x140001c	0x1c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0007	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0008	UInt8	0x1400020	0x20	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0008	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x000B	UInt8	0x140002c	0x2c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x000B	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x000C	UInt8	0x1400030	0x30	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x000C	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x000D	UInt8	0x1400034	0x34	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x000D	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x000F	UInt8	0x140003c	0x3c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x000F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0010	UInt8	0x1400040	0x40	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0010	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0011	UInt8	0x1400044	0x44	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0011	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0012	UInt8	0x1400048	0x48	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0012	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0013	UInt8	0x140004c	0x4c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0013	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0014	UInt8	0x1400050	0x50	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0014	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0015	UInt8	0x1400054	0x54	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0015	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0016	UInt8	0x1400058	0x58	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0016	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0017	UInt8	0x140005c	0x5c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0017	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0018	UInt8	0x1400060	0x60	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0018	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x001F	UInt8	0x140007c	0x7c	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x001F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[0].AdcReg_0x0020	UInt8	0x1400080	0x80	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[0].AdcReg_0x0020	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0006	UInt8	0x1400218	0x18	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0006	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0007	UInt8	0x140021c	0x1c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0007	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0008	UInt8	0x1400220	0x20	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0008	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x000B	UInt8	0x140022c	0x2c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x000B	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x000C	UInt8	0x1400230	0x30	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x000C	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x000D	UInt8	0x1400234	0x34	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x000D	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x000F	UInt8	0x140023c	0x3c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x000F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0010	UInt8	0x1400240	0x40	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0010	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0011	UInt8	0x1400244	0x44	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0011	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0012	UInt8	0x1400248	0x48	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0012	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0013	UInt8	0x140024c	0x4c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0013	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0014	UInt8	0x1400250	0x50	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0014	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0015	UInt8	0x1400254	0x54	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0015	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0016	UInt8	0x1400258	0x58	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0016	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0017	UInt8	0x140025c	0x5c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0017	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0018	UInt8	0x1400260	0x60	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0018	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x001F	UInt8	0x140027c	0x7c	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x001F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[1].AdcReg_0x0020	UInt8	0x1400280	0x80	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[1].AdcReg_0x0020	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0006	UInt8	0x1400418	0x18	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0006	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0007	UInt8	0x140041c	0x1c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0007	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0008	UInt8	0x1400420	0x20	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0008	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x000B	UInt8	0x140042c	0x2c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x000B	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x000C	UInt8	0x1400430	0x30	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x000C	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x000D	UInt8	0x1400434	0x34	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x000D	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x000F	UInt8	0x140043c	0x3c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x000F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0010	UInt8	0x1400440	0x40	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0010	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0011	UInt8	0x1400444	0x44	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0011	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0012	UInt8	0x1400448	0x48	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0012	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0013	UInt8	0x140044c	0x4c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0013	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0014	UInt8	0x1400450	0x50	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0014	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0015	UInt8	0x1400454	0x54	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0015	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0016	UInt8	0x1400458	0x58	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0016	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0017	UInt8	0x140045c	0x5c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0017	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0018	UInt8	0x1400460	0x60	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0018	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x001F	UInt8	0x140047c	0x7c	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x001F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[2].AdcReg_0x0020	UInt8	0x1400480	0x80	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[2].AdcReg_0x0020	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0006	UInt8	0x1400618	0x18	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0006	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0007	UInt8	0x140061c	0x1c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0007	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0008	UInt8	0x1400620	0x20	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0008	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x000B	UInt8	0x140062c	0x2c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x000B	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x000C	UInt8	0x1400630	0x30	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x000C	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x000D	UInt8	0x1400634	0x34	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x000D	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x000F	UInt8	0x140063c	0x3c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x000F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0010	UInt8	0x1400640	0x40	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0010	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0011	UInt8	0x1400644	0x44	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0011	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0012	UInt8	0x1400648	0x48	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0012	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0013	UInt8	0x140064c	0x4c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0013	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0014	UInt8	0x1400650	0x50	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0014	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0015	UInt8	0x1400654	0x54	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0015	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0016	UInt8	0x1400658	0x58	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0016	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0017	UInt8	0x140065c	0x5c	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0017	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0018	UInt8	0x1400660	0x60	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0018	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x001F	UInt8	0x140067c	0x7c	RW	[0]	[8]	0	255	None	False	False	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x001F	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcConfig[3].AdcReg_0x0020	UInt8	0x1400680	0x80	RW	[0]	[8]	0	255	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcConfig[3].AdcReg_0x0020	0x4	0	8	8	0	ADC Control Registers|"\
     "Top.AdcPatternTester.Channel	UInt32	0x1500000	0x0	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Channel	0x4	0	32	32	0	Channel|"\
     "Top.AdcPatternTester.Mask	UInt32	0x1500004	0x4	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Mask	0x4	0	32	32	0	Mask|"\
     "Top.AdcPatternTester.Pattern	UInt32	0x1500008	0x8	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Pattern	0x4	0	32	32	0	Pattern|"\
     "Top.AdcPatternTester.Samples	UInt32	0x150000c	0xc	RW	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Samples	0x4	0	32	32	0	Samples|"\
     "Top.AdcPatternTester.Request	Bool	0x1500010	0x10	RW	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Request	0x4	0	1	1	0	Request|"\
     "Top.AdcPatternTester.Done	Bool	0x1500014	0x14	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Done	0x4	0	1	1	0	Done|"\
     "Top.AdcPatternTester.Failed	Bool	0x1500018	0x18	RO	[0]	[1]	0	1	{False: 'False', True: 'True'}	False	True	4	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Failed	0x4	0	1	1	0	Failed|"\
     "Top.AdcPatternTester.Count	UInt32	0x150001c	0x1c	RO	[0]	[32]	0	4294967295	None	False	True	2	False	False	0	True	True	Unnamed_5	Top.AdcPatternTester.Count	0x4	0	32	32	0	Count|"\

#endif
