sfr P0 = 0x80;
sfr P1 = 0x90;
//对系统默认数据类型进行重定义
typedef unsigned char u8;
typedef unsigned int u16;
#define juzhen P1 //使用宏定义矩阵按键控制口
#define duanma P0 //使用宏定义数码管段码口

//共阴极数码管显示F~0 的段码数据
u8 gsmg_code[17]=
{
    0x71,0x79,0x5e,0x39,
    0x7c,0x77,0x6f,0x7f,
    0x07,0x7d,0x6d,0x66,
    0x4f,0x5b,0x06,0x3f
};
//对应矩形按键
u8 code KEY_TABLE[] =
{
    0x77, 0x7B, 0x7D, 0x7E,
    0xB7, 0xBB, 0xBD, 0xBE,
    0xD7, 0xDB, 0xDD, 0xDE,
    0xE7, 0xEB, 0xED, 0xEE
};

void delay_10us(u16 ten_us)
{
  while(ten_us--);
}


void main()
{
    u8 temp, key, i;
    while(1)
    {
        juzhen = 0xF0;        //列扫描
        if (juzhen != 0xF0)
        {
            delay_10us(2000);
            if (juzhen != 0xF0)
            {
                temp = juzhen;
                juzhen = 0x0F;
                key = temp | juzhen;
                for (i = 0; i < 16; ++i)
                    if (key == KEY_TABLE[i])
                        break;
                duanma = gsmg_code[i];
            }
        }
    }
}