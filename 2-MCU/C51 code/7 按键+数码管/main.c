  #include <reg52.h>
  //对系统默认数据类型进行重定义
  typedef unsigned char u8;
  typedef unsigned int u16;
  #define KEY_MATRIX_PORT P1   //使用宏定义矩阵按键控制口
  #define SMG_DX_PORT P0       //使用宏定义数码管段码口
  
  sbit LSA=P2^2;
  sbit LSB=P2^3;
  sbit LSC=P2^4;
  //共阴极数码管显示F~0 的段码数据
  u8 smg_code[17]=
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
  u8 string[8]={0,0,0,0,0,0,0,0};
  
    void delay_10us(u16 ten_us)
  {
    while(ten_us--);
  }
  //数码管扫描
  void smg()
  {
        u8 LSX,i;
        for(i=0;i<8;i++)
        {
          LSX=7-i;
          LSC=(LSX>>2)&1;LSB=(LSX>>1)&1;LSA=LSX&1;  //位选
          SMG_DX_PORT=smg_code[string[i]];          //传送段选数据
          delay_10us(100);                          //延时一段时间，等待显示稳定
          SMG_DX_PORT=0x00;                         //消音
        }
  }



  //扫描按键
  u8 key_scan(void)
  { 
    u8 temp, i, key=0;
    KEY_MATRIX_PORT = 0x0f;        //行为0，列为1
    if (KEY_MATRIX_PORT != 0x0f)
    {
        smg();//消抖并扫描
        if (KEY_MATRIX_PORT != 0x0f)
        {
            temp = KEY_MATRIX_PORT;
            KEY_MATRIX_PORT = 0xf0;
            key = temp | KEY_MATRIX_PORT;
            for (i = 0; i < 16; ++i)
                if (key == KEY_TABLE[i])
                    break;
            key=i+1;
            while(KEY_MATRIX_PORT!=0xf0)smg();//等待按键松开
        }
    }
    
    else
      key=0;
    
    return key;
  }

  void main()
  {
      u8 key,i=0; 
      while(1)
      {
          SMG_DX_PORT=0x00;
          key=key_scan();
          if(key!=0)
          {
            string[i]=key;
            i++;
            if(i==8)
              i=0;
          }
           smg();      
        		
      }
  }