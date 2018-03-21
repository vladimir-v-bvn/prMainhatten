#define UNICODE
#include <windows.h>

extern	int	LngWgf;
extern	int	LngBgf;

extern	WCHAR	dWgf[64];
extern	WCHAR	dBgf[8192];

void ByteEToUnicode(byte smbl, char wb)
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
		//------------------------------------
	case 0x5C: cl = 0x24;//$
		break;
	case 0x6D: cl = 0x26;//&
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
	case 0x5D: cl = 0x40;//@
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
	case 0x7C: cl = 0x7E;//~
		break;
	case 0x7D: cl = 0x3C;//<
		break;
	case 0x7E: cl = 0x3E;//>
		break;
		//-------------------------------
	case 0x3C:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x72;
		break;
	case 0x3D:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x6E;
		break;
	case 0x3E:
		if (wb == 'w') dWgf[LngWgf++] = 0x29;
		if (wb == 'b') dBgf[LngBgf++] = 0x29;
		cl = 0x20;
		break;
	case 0x3F:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x20;
		break;
	case 0x40:
		if (wb == 'w') dWgf[LngWgf++] = 0x69;
		if (wb == 'b') dBgf[LngBgf++] = 0x69;
		cl = 0x6E;
		break;
	case 0x41:
		if (wb == 'w') dWgf[LngWgf++] = 0x63;
		if (wb == 'b') dBgf[LngBgf++] = 0x63;
		cl = 0x68;
		break;
	case 0x42:
		if (wb == 'w') dWgf[LngWgf++] = 0x3B;
		if (wb == 'b') dBgf[LngBgf++] = 0x3B;
		cl = 0x20;
		break;
	case 0x43:
		if (wb == 'w') dWgf[LngWgf++] = 0x2E;
		if (wb == 'b') dBgf[LngBgf++] = 0x2E;
		cl = 0x20;
		break;
	case 0x44:
		if (wb == 'w') dWgf[LngWgf++] = 0x6E;
		if (wb == 'b') dBgf[LngBgf++] = 0x6E;
		cl = 0x20;
		break;
	case 0x45:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x28;
		break;
	case 0x46:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x64;
		break;
	case 0x47:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x73;
		break;
	case 0x48:
		if (wb == 'w') dWgf[LngWgf++] = 0x2C;
		if (wb == 'b') dBgf[LngBgf++] = 0x2C;
		cl = 0x20;
		break;
	case 0x49:
		if (wb == 'w') dWgf[LngWgf++] = 0x64;
		if (wb == 'b') dBgf[LngBgf++] = 0x64;
		cl = 0x65;
		break;
	case 0x4A:
		if (wb == 'w') dWgf[LngWgf++] = 0x74;
		if (wb == 'b') dBgf[LngBgf++] = 0x74;
		cl = 0x65;
		break;
	case 0x4B:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x61;
		break;
	case 0x4C:
		if (wb == 'w') dWgf[LngWgf++] = 0x68;
		if (wb == 'b') dBgf[LngBgf++] = 0x68;
		cl = 0x65;
		break;
	case 0x4D:
		if (wb == 'w') dWgf[LngWgf++] = 0x69;
		if (wb == 'b') dBgf[LngBgf++] = 0x69;
		cl = 0x65;
		break;
	case 0x4E:
		if (wb == 'w') dWgf[LngWgf++] = 0x65;
		if (wb == 'b') dBgf[LngBgf++] = 0x65;
		cl = 0x69;
		break;
	case 0x4F:
		if (wb == 'w') dWgf[LngWgf++] = 0x73;
		if (wb == 'b') dBgf[LngBgf++] = 0x73;
		cl = 0x74;
		break;
	case 0x50:
		if (wb == 'w') dWgf[LngWgf++] = 0x72;
		if (wb == 'b') dBgf[LngBgf++] = 0x72;
		cl = 0x20;
		break;
	case 0x51:
		if (wb == 'w') dWgf[LngWgf++] = 0x72;
		if (wb == 'b') dBgf[LngBgf++] = 0x72;
		cl = 0x65;
		break;
	case 0x52:
		if (wb == 'w') dWgf[LngWgf++] = 0x74;
		if (wb == 'b') dBgf[LngBgf++] = 0x74;
		cl = 0x20;
		break;
	case 0x53:
		if (wb == 'w') dWgf[LngWgf++] = 0x73;
		if (wb == 'b') dBgf[LngBgf++] = 0x73;
		cl = 0x20;
		break;
	case 0x54:
		if (wb == 'w') dWgf[LngWgf++] = 0x67;
		if (wb == 'b') dBgf[LngBgf++] = 0x67;
		cl = 0x65;
		break;
	case 0x55:
		if (wb == 'w') dWgf[LngWgf++] = 0x6E;
		if (wb == 'b') dBgf[LngBgf++] = 0x6E;
		cl = 0x67;
		break;
	case 0x56:
		if (wb == 'w') dWgf[LngWgf++] = 0x20;
		if (wb == 'b') dBgf[LngBgf++] = 0x20;
		cl = 0x74;
		break;
	case 0x57:
		if (wb == 'w') dWgf[LngWgf++] = 0x61;
		if (wb == 'b') dBgf[LngBgf++] = 0x61;
		cl = 0x6E;
		break;
	case 0x58:
		if (wb == 'w') dWgf[LngWgf++] = 0x6F;
		if (wb == 'b') dBgf[LngBgf++] = 0x6F;
		cl = 0x6E;
		break;
	case 0x59:
		if (wb == 'w') dWgf[LngWgf++] = 0x69;
		if (wb == 'b') dBgf[LngBgf++] = 0x69;
		cl = 0x74;
		break;
	case 0x5A:
		if (wb == 'w') dWgf[LngWgf++] = 0x64;
		if (wb == 'b') dBgf[LngBgf++] = 0x64;
		cl = 0x69;
		break;
	case 0x5B:
		if (wb == 'w') dWgf[LngWgf++] = 0x74;
		if (wb == 'b') dBgf[LngBgf++] = 0x74;
		cl = 0x68;
		break;
	default:
		cl = 0x25;//%
	}
	if (wb == 'w') dWgf[LngWgf++] = cl;
	if (wb == 'b') dBgf[LngBgf++] = cl;
}