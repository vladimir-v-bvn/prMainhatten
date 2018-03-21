#define UNICODE
#include <windows.h>

extern	int	LngWgf;
extern	int	LngBgf;

extern	WCHAR	dWgf[64];
extern	WCHAR	dBgf[8192];

void ByteRToUnicode(byte smbl, char wb)
{
	WCHAR cl;
	switch (smbl)
	{
	case 0x00: cl = 0x20;//
		break;
	case 0x01: cl = 0x61;//a
		break;
	case 0x02: cl = 0x62;//b
		break;
	case 0x03: cl = 0x63;//c
		break;
	case 0x04: cl = 0x64;//d
		break;
	case 0x05: cl = 0x65;//e
		break;
	case 0x06: cl = 0x66;//f
		break;
	case 0x07: cl = 0x67;//g
		break;
	case 0x08: cl = 0x68;//h
		break;
	case 0x09: cl = 0x69;//i
		break;
	case 0x0A: cl = 0x6A;//j
		break;
	case 0x0B: cl = 0x6B;//k
		break;
	case 0x0C: cl = 0x6C;//l
		break;
	case 0x0D: cl = 0x6D;//m
		break;
	case 0x0E: cl = 0x6E;//n
		break;
	case 0x0F: cl = 0x6F;//o
		break;
	case 0x10: cl = 0x70;//p
		break;
	case 0x11: cl = 0x71;//q
		break;
	case 0x12: cl = 0x72;//r
		break;
	case 0x13: cl = 0x73;//s
		break;
	case 0x14: cl = 0x74;//t
		break;
	case 0x15: cl = 0x75;//u
		break;
	case 0x16: cl = 0x76;//v
		break;
	case 0x17: cl = 0x77;//w
		break;
	case 0x18: cl = 0x78;//x
		break;
	case 0x19: cl = 0x79;//y
		break;
	case 0x1A: cl = 0x7A;//z
		break;
	case 0x1B: cl = 0x41;//A
		break;
	case 0x1C: cl = 0x42;//B
		break;
	case 0x1D: cl = 0x43;//C
		break;
	case 0x1E: cl = 0x44;//D
		break;
	case 0x1F: cl = 0x45;//E
		break;
	case 0x20: cl = 0x46;//F
		break;
	case 0x21: cl = 0x47;//G
		break;
	case 0x22: cl = 0x48;//H
		break;
	case 0x23: cl = 0x49;//I
		break;
	case 0x24: cl = 0x4A;//J
		break;
	case 0x25: cl = 0x4B;//K
		break;
	case 0x26: cl = 0x4C;//L
		break;
	case 0x27: cl = 0x4D;//M
		break;
	case 0x28: cl = 0x4E;//N
		break;
	case 0x29: cl = 0x4F;//O
		break;
	case 0x2A: cl = 0x50;//P
		break;
	case 0x2B: cl = 0x51;//Q
		break;
	case 0x2C: cl = 0x52;//R
		break;
	case 0x2D: cl = 0x53;//S
		break;
	case 0x2E: cl = 0x54;//T
		break;
	case 0x2F: cl = 0x55;//U
		break;
	case 0x30: cl = 0x56;//V
		break;
	case 0x31: cl = 0x57;//W
		break;
	case 0x32: cl = 0x58;//X
		break;
	case 0x33: cl = 0x59;//Y
		break;
	case 0x34: cl = 0x5A;//Z
		break;
	case 0x35: cl = 0xE4;//ae
		break;
	case 0x36: cl = 0xF6;//oe
		break;
	case 0x37: cl = 0xFC;//ue
		break;
	case 0x38: cl = 0xDF;//ss
		break;
	case 0x39: cl = 0xC4;//AE
		break;
	case 0x3A: cl = 0xD6;//OE
		break;
	case 0x3B: cl = 0xDC;//UE
		break;
	case 0x3C: cl = 0x430;//r01 a
		break;
	case 0x3D: cl = 0x431;//r02 b
		break;
	case 0x3E: cl = 0x432;//r03 v
		break;
	case 0x3F: cl = 0x433;//r04 g
		break;
	case 0x40: cl = 0x434;//r05 d 
		break;
	case 0x41: cl = 0x435;//r06 e
		break;
	case 0x42: cl = 0x436;//r07 
		break;
	case 0x43: cl = 0x437;//r08 z
		break;
	case 0x44: cl = 0x438;//r09 i
		break;
	case 0x45: cl = 0x439;//r10 ii
		break;
	case 0x46: cl = 0x43A;//r11 k
		break;
	case 0x47: cl = 0x43B;//r12 l
		break;
	case 0x48: cl = 0x43C;//r13 m
		break;
	case 0x49: cl = 0x43D;//r14 n
		break;
	case 0x4A: cl = 0x43E;//r15 o
		break;
	case 0x4B: cl = 0x43F;//r16 p
		break;
	case 0x4C: cl = 0x440;//r17 r
		break;
	case 0x4D: cl = 0x441;//r18 s
		break;
	case 0x4E: cl = 0x442;//r19 t
		break;
	case 0x4F: cl = 0x443;//r20
		break;
	case 0x50: cl = 0x444;//r21
		break;
	case 0x51: cl = 0x445;//r22
		break;
	case 0x52: cl = 0x446;//r23
		break;
	case 0x53: cl = 0x447;//r24
		break;
	case 0x54: cl = 0x448;//r25
		break;
	case 0x55: cl = 0x449;//r26
		break;
	case 0x56: cl = 0x44A;//r27
		break;
	case 0x57: cl = 0x44B;//r28
		break;
	case 0x58: cl = 0x44C;//r29
		break;
	case 0x59: cl = 0x44D;//r30
		break;
	case 0x5A: cl = 0x44E;//r31
		break;
	case 0x5B: cl = 0x44F;//r32
		break;
	case 0x5C: cl = 0x24;//$
		break;
	case 0x5D: cl = 0x26;//&
		break;
	case 0x5E://#
		cl = 0x0D;
		if (wb == 'w') dWgf[LngWgf++] = cl;
		if (wb == 'b') dBgf[LngBgf++] = cl;
		cl = 0x0A;
		break;
	case 0x5F: cl = 0x27;//'
		break;
	case 0x60: cl = 0x22;//"
		break;
	case 0x61: cl = 0x2E;//.
		break;
	case 0x62: cl = 0x3A;//:
		break;
	case 0x63: cl = 0x2C;//,
		break;
	case 0x64: cl = 0x3B;//;
		break;
	case 0x65: cl = 0x21;//!
		break;
	case 0x66: cl = 0x3F;//?
		break;
	case 0x67: cl = 0x3D;//=
		break;
	case 0x68: cl = 0x5B;//[
		break;
	case 0x69: cl = 0x5D;//]
		break;
	case 0x6A: cl = 0x2D;//-
		break;
	case 0x6B: cl = 0x28;//(
		break;
	case 0x6C: cl = 0x29;//)
		break;
	case 0x6D: cl = 0x40;//@
		break;
	case 0x6E: cl = 0x2A;//*
		break;
	case 0x6F: cl = 0x2F;///
		break;
	case 0x70: cl = 0x30;//0
		break;
	case 0x71: cl = 0x31;//1
		break;
	case 0x72: cl = 0x32;//2
		break;
	case 0x73: cl = 0x33;//3
		break;
	case 0x74: cl = 0x34;//4
		break;
	case 0x75: cl = 0x35;//5
		break;
	case 0x76: cl = 0x36;//6
		break;
	case 0x77: cl = 0x37;//7
		break;
	case 0x78: cl = 0x38;//8
		break;
	case 0x79: cl = 0x39;//9
		break;
	case 0x7A: cl = 0x2B;//+
		break;
	case 0x7B: cl = 0x25;//%
		break;
	case 0x7C:// m -s,_
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x6D;
		if (wb == 'b') dBgf[LngBgf++] = 0x6D;
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x2D;//-
		if (wb == 'b') dBgf[LngBgf++] = 0x2D;//-
		if (wb == 'w') dWgf[LngWgf++] = 0x73;//s
		if (wb == 'b') dBgf[LngBgf++] = 0x73;//s
		if (wb == 'w') dWgf[LngWgf++] = 0x2C;//,
		if (wb == 'b') dBgf[LngBgf++] = 0x2C;//,
		cl = 0x20;//=
		break;
	case 0x7D:// m -(e)s
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x6D;
		if (wb == 'b') dBgf[LngBgf++] = 0x6D;
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x2D;
		if (wb == 'b') dBgf[LngBgf++] = 0x2D;
		if (wb == 'w') dWgf[LngWgf++] = 0x28;
		if (wb == 'b') dBgf[LngBgf++] = 0x28;
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		if (wb == 'w') dWgf[LngWgf++] = 0x29;
		if (wb == 'b') dBgf[LngBgf++] = 0x29;
		cl = 0x73;
		break;
	case 0x7E:// f =, -
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x66;
		if (wb == 'b') dBgf[LngBgf++] = 0x66;
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x3D;
		if (wb == 'b') dBgf[LngBgf++] = 0x3D;
		if (wb == 'w') dWgf[LngWgf++] = 0x2C;
		if (wb == 'b') dBgf[LngBgf++] = 0x2C;
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x2D;
		break;
	case 0x7F://_razg.
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x440;
		if (wb == 'b') dBgf[LngBgf++] = 0x440;
		if (wb == 'w') dWgf[LngWgf++] = 0x430;
		if (wb == 'b') dBgf[LngBgf++] = 0x430;
		if (wb == 'w') dWgf[LngWgf++] = 0x437;
		if (wb == 'b') dBgf[LngBgf++] = 0x437;
		if (wb == 'w') dWgf[LngWgf++] = 0x433;
		if (wb == 'b') dBgf[LngBgf++] = 0x433;
		cl = 0x2E;
		break;
	case 0x80:// n -
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x6E;
		if (wb == 'b') dBgf[LngBgf++] = 0x6E;
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x2D;
		break;
	case 0x81:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		if (wb == 'w') dWgf[LngWgf++] = 0x2D;
		if (wb == 'b') dBgf[LngBgf++] = 0x2D;
		cl = 0x20;
		break;
	case 0x82:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x2D;
		break;
	case 0x83:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		if (wb == 'w') dWgf[LngWgf++] = 0x6E;
		if (wb == 'b') dBgf[LngBgf++] = 0x6E;
		cl = 0x20;
		break;
	case 0x84:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x6E;
		break;
	case 0x85:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x20;
		break;
	case 0x86:
		if (wb == 'w') dWgf[LngWgf++] = 0x2C;
		if (wb == 'b') dBgf[LngBgf++] = 0x2C;
		cl = 0x20;
		break;
	case 0x87:
		if (wb == 'w') dWgf[LngWgf++] = 0x6E;
		if (wb == 'b') dBgf[LngBgf++] = 0x6E;
		cl = 0x20;
		break;
	case 0x88:
		if (wb == 'w') dWgf[LngWgf++] = 0x2E;
		if (wb == 'b') dBgf[LngBgf++] = 0x2E;
		cl = 0x20;
		break;
	case 0x89:
		if (wb == 'w') dWgf[LngWgf++] = 0x442;
		if (wb == 'b') dBgf[LngBgf++] = 0x442;
		if (wb == 'w') dWgf[LngWgf++] = 0x44C;
		if (wb == 'b') dBgf[LngBgf++] = 0x44C;
		cl = 0x20;
		break;
	case 0x8A:
		if (wb == 'w') dWgf[LngWgf++] = 0x442;
		if (wb == 'b') dBgf[LngBgf++] = 0x442;
		cl = 0x44C;
		break;
	case 0x8B:
		if (wb == 'w') dWgf[LngWgf++] = 0x442;
		if (wb == 'b') dBgf[LngBgf++] = 0x442;
		cl = 0x43E;
		break;
	case 0x8C:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x72;
		break;
	case 0x8D:
		if (wb == 'w') dWgf[LngWgf++] = 0x441;
		if (wb == 'b') dBgf[LngBgf++] = 0x441;
		cl = 0x442;
		break;
	case 0x8E:
		if (wb == 'w') dWgf[LngWgf++] = 0x63;
		if (wb == 'b') dBgf[LngBgf++] = 0x63;
		cl = 0x68;
		break;
	case 0x8F:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x43F;
		break;
	case 0x90:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x441;
		break;
	case 0x91:
		if (wb == 'w') dWgf[LngWgf++] = 0x430;
		if (wb == 'b') dBgf[LngBgf++] = 0x430;
		if (wb == 'w') dWgf[LngWgf++] = 0x442;
		if (wb == 'b') dBgf[LngBgf++] = 0x442;
		cl = 0x44C;
		break;
	case 0x92:
		if (wb == 'w') dWgf[LngWgf++] = 0x440;
		if (wb == 'b') dBgf[LngBgf++] = 0x440;
		cl = 0x430;
		break;
	case 0x93:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x28;
		break;
	case 0x94:
		if (wb == 'w') dWgf[LngWgf++] = 0x435;
		if (wb == 'b') dBgf[LngBgf++] = 0x435;
		cl = 0x43D;
		break;
	case 0x95:
		if (wb == 'w') dWgf[LngWgf++] = 0x43D;
		if (wb == 'b') dBgf[LngBgf++] = 0x43D;
		cl = 0x438;
		break;
	case 0x96:
		if (wb == 'w') dWgf[LngWgf++] = 0x43D;
		if (wb == 'b') dBgf[LngBgf++] = 0x43D;
		cl = 0x430;
		break;
	case 0x97:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x69;
		break;
	case 0x98:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x432;
		break;
	case 0x99:
		if (wb == 'w') dWgf[LngWgf++] = 0x43F;
		if (wb == 'b') dBgf[LngBgf++] = 0x43F;
		cl = 0x43E;
		break;
	case 0x9A:
		if (wb == 'w') dWgf[LngWgf++] = 0x74;
		if (wb == 'b') dBgf[LngBgf++] = 0x74;
		cl = 0x20;
		break;
	case 0x9B:
		if (wb == 'w') dWgf[LngWgf++] = 0x43D;
		if (wb == 'b') dBgf[LngBgf++] = 0x43D;
		cl = 0x43E;
		break;
	case 0x9C:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x3D;
		break;
	case 0x9D:
		if (wb == 'w') dWgf[LngWgf++] = 0x69;
		if (wb == 'b') dBgf[LngBgf++] = 0x69;
		cl = 0x6E;
		break;
	case 0x9E:
		if (wb == 'w') dWgf[LngWgf++] = 0x440;
		if (wb == 'b') dBgf[LngBgf++] = 0x440;
		cl = 0x435;
		break;
	case 0x9F:
		if (wb == 'w') dWgf[LngWgf++] = 0x440;
		if (wb == 'b') dBgf[LngBgf++] = 0x440;
		cl = 0x43E;
		break;
	case 0xA0:
		if (wb == 'w') dWgf[LngWgf++] = 0x432;
		if (wb == 'b') dBgf[LngBgf++] = 0x432;
		cl = 0x430;
		break;
	case 0xA1:
		if (wb == 'w') dWgf[LngWgf++] = 0x43E;
		if (wb == 'b') dBgf[LngBgf++] = 0x43E;
		cl = 0x432;
		break;
	case 0xA2:
		if (wb == 'w') dWgf[LngWgf++] = 0x43F;
		if (wb == 'b') dBgf[LngBgf++] = 0x43F;
		cl = 0x440;
		break;
	case 0xA3:
		if (wb == 'w') dWgf[LngWgf++] = 0x43A;
		if (wb == 'b') dBgf[LngBgf++] = 0x43A;
		cl = 0x43E;
		break;
	case 0xA4:
		if (wb == 'w') dWgf[LngWgf++] = 0x43A;
		if (wb == 'b') dBgf[LngBgf++] = 0x43A;
		cl = 0x430;
		break;
	case 0xA5:
		if (wb == 'w') dWgf[LngWgf++] = 0x435;
		if (wb == 'b') dBgf[LngBgf++] = 0x435;
		cl = 0x20;
		break;
	case 0xA6:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x43E;
		break;
	case 0xA7:
		if (wb == 'w') dWgf[LngWgf++] = 0x44F;
		if (wb == 'b') dBgf[LngBgf++] = 0x44F;
		cl = 0x20;
		break;
	case 0xA8:
		if (wb == 'w') dWgf[LngWgf++] = 0x74;
		if (wb == 'b') dBgf[LngBgf++] = 0x74;
		cl = 0x65;
		break;
	case 0xA9:
		if (wb == 'w') dWgf[LngWgf++] = 0x72;
		if (wb == 'b') dBgf[LngBgf++] = 0x72;
		cl = 0x20;
		break;
	case 0xAA:
		if (wb == 'w') dWgf[LngWgf++] = 0x432;
		if (wb == 'b') dBgf[LngBgf++] = 0x432;
		cl = 0x43E;
		break;
	case 0xAB:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x43D;
		break;
	case 0xAC:
		if (wb == 'w') dWgf[LngWgf++] = 0x435;
		if (wb == 'b') dBgf[LngBgf++] = 0x435;
		cl = 0x440;
		break;
	case 0xAD:
		if (wb == 'w') dWgf[LngWgf++] = 0x43E;
		if (wb == 'b') dBgf[LngBgf++] = 0x43E;
		cl = 0x441;
		break;
	case 0xAE:
		if (wb == 'w') dWgf[LngWgf++] = 0x67;
		if (wb == 'b') dBgf[LngBgf++] = 0x67;
		cl = 0x65;
		break;
	case 0xAF:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x66;
		break;
	case 0xB0:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x43A;
		break;
	case 0xB1:
		if (wb == 'w') dWgf[LngWgf++] = 0x43E;
		if (wb == 'b') dBgf[LngBgf++] = 0x43E;
		cl = 0x440;
		break;
	case 0xB2:
		if (wb == 'w') dWgf[LngWgf++] = 0x43D;
		if (wb == 'b') dBgf[LngBgf++] = 0x43D;
		cl = 0x44B;
		break;
	case 0xB3:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x6D;
		break;
	case 0xB4:
		if (wb == 'w') dWgf[LngWgf++] = 0x43E;
		if (wb == 'b') dBgf[LngBgf++] = 0x43E;
		cl = 0x20;
		break;
	case 0xB5:
		if (wb == 'w') dWgf[LngWgf++] = 0x438;
		if (wb == 'b') dBgf[LngBgf++] = 0x438;
		cl = 0x442;
		break;
	case 0xB6:
		if (wb == 'w') dWgf[LngWgf++] = 0x43E;
		if (wb == 'b') dBgf[LngBgf++] = 0x43E;
		cl = 0x442;
		break;
	case 0xB7:
		if (wb == 'w') dWgf[LngWgf++] = 0x439;
		if (wb == 'b') dBgf[LngBgf++] = 0x439;
		cl = 0x20;
		break;
	default:
		cl = 0x25;//%
	}
	if (wb == 'w') dWgf[LngWgf++] = cl;
	if (wb == 'b') dBgf[LngBgf++] = cl;
}