// tr_a0t0in : attribute 0, type 0, instance
#include <ansi.h>

//material:"iron"  "steel"  "silver"  "gold"  "copper"  "paper"  "cloth"
//"wood"  "leather"  "silk"  "blacksteel"  "˿��"  "Ƥ��"  "gem"  "jade"
//level 0 to 7 is
//0 ��ͨ   1 ��ɫ   2 ��(�\)ɫ   3 ��ɫ   4 ��ɫ   5 ��ɫ   6 ����   7 ��ɫ
//��ʯ�ļ���Խ�ߣ���ɫ������ͨ��ɸ���ɫ���磺����ʯ����ɫ to ����ɫ

////////////////////////////////////////////////////
// �ȼ�0�Ķ�������һ���װ����
mapping *trm_lv0in = ({
(["ident": 1, // �Ƿ񱻼�����ͨ���� 0
              //Ϊ�����player�ļ�������
  "level": 0, // ���Ｖ�� max=8
  "name": "��ͨ��", // ��������
  "id":"sword", // ����id��
  "sprite": -1, // �Ƿ���������С��������>=0��ʾ������mapping array
                // -1 û�ж���
  "value": 100, // �ܼ�ֵ
  "material":           "iron", // ����
  "weight":             5000,   // ����
  "power":              23,             // �����˺���
  "limit/0": "0=10000", // װ������ 0 ��mapping code��exp>10000�ſ���
  "gems": -1, // -1��ʾ���Դ�׻�������ɿ�,0=�޿�
  //"gemed/0": -1, // �Ѿ���Ƕ��stone��ʵ������һ��û�б���Ƕstone
// -1��ʾû�б�ʯ
  "gift/0": "-1=2", // -1 ��ʾ�������һ������
                    //2=���������Եĸ���
                    // �˱�־�����Ƿ��� "gift/" �� "0" λ��
  "gift/1": "1=20", // 1 ��ʾ�������Ե�mapping codeΪ1 str>20�ſ���
  "green_set":-1,  // ��ɫװ����id, -1Ϊ����ɫװ��
// ����
"long": "ch����\n",     
"prefix": 2, //����ӵ�ǰ׺����, -1 ��ʾ���޸�
"surfix": 1, //����ӵĺ�׺����, -1 ��ʾ���޸�
"autoload": 0, // �˳�ʱ�Ƿ���
]),
(["ident":              1,              
"level":                0,              
"name":                 "�彣",         
"id":                   "sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                20,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=1", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

//////////////////////////////////////////////////
mapping *trm_lv1in = ({
(["ident":              1,              
"level":                1,
"name":                 "��֮��",               
"id":                   "moon sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                20,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                1,              
"name":                 "ˮ֮��",               
"id":                   "water sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                20,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

///////////////////////////////////////////////////////
mapping *trm_lv2in = ({
(["ident":              0,              
"level":                2,
"name":                 "ţ��",         
"id":                   "cow sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                30,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                2,              
"name":                 "�EĿ��",               
"id":                   "faint sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                35,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

////////////////////////////////////////////////////////////////
mapping *trm_lv3in = ({
(["ident":              0,              
"level":                3,
"name":                 "�ƺӽ�",               
"id":                   "yriver sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                40,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=3", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                3,              
"name":                 "������",               
"id":                   "lriver sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                45,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

///////////////////////////////////////////////////////////////
mapping *trm_lv4in = ({
(["ident":              0,              
"level":                4,
"name":                 "���ƽ�",               
"id":                   "cloud sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                50,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=3", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                4,              
"name":                 "��ˮ��",               
"id":                   "green sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                55,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

//////////////////////////////////////////////////////////////////
mapping *trm_lv5in = ({
(["ident":              0,              
"level":                5,
"name":                 "�콣",         
"id":                   "t sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                60,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����

"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                5,              
"name":                 "�½�",         
"id":                   "x sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                55,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

///////////////////////////////////////////////////////////////////
// �ȼ�6�Ķ�������Ʒװ��(����)
mapping *trm_lv6in = ({
(["ident":              0,
"level":                6,
"name":                 "���챦��",     
"id":                   "ori sword",
"sprite":               -1,     // 0,
                                
"value":                10000,
"material":             "gold",
"weight":               6000,
"power":                60,     
"limit/0":              "0=2000000",
"gems":                 -1,             
"gift/0":               "-1=2",
"gift/1":               "1=300",
"gift/2":               "2=25",
"green_set":    -1,             
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               2,              
"autoload":             1,
]),
(["ident":              0,
"level":                6,
"name":                 "�ٵر���",     
"id":                   "dic sword",
"sprite":               -1,     // 1,
                                
"value":                8000,
"material":             "silver",
"weight":               7000,
"power":                65,     
"limit/0":              "0=2400000",
"gems":                 -1,             
"gift/0":               "-1=1",
"gift/1":               "1=25",
"green_set":    -1,             
// ����
"long":                 "ch����",       
"prefix":               2,
"surfix":               2,              
"autoload":             1,
]),
(["ident":              0,              
"level":                6,
"name":                 "����֮��",             
"id":                   "tx sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                80,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=4", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                6,              
"name":                 "����֮��",             
"id":                   "test sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                90,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=5", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

////////////////////////////////////////////////////////////////////////////////
mapping *trm_lv7in = ({
(["ident":              0,              
"level":                7,
"name":                 "��ɫ��A",              
"id":                   "gset sword",
"sprite":               -1,             
"value":                100,    

"material":             "steel",
"weight":               2000,   
"power":                80,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=4", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                7,              
"name":                 "����װ֮��B",          
"id":                   "gset sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                90,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=5", // -1 ��ʾ�������һ������
"gift/1":               "1=15",
"green_set":    -1,
// ����
"long":                 "ch����\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

////////////////////////////////////////////////////////////////////////////////
mapping query(int lv, int n)
{
  mapping *ap;

  switch (lv)
  {
  case 0: ap=trm_lv0in; break;
  case 1:       ap=trm_lv1in; break;
  case 2:       ap=trm_lv2in; break;
  case 3:       ap=trm_lv3in; break;
  case 4:       ap=trm_lv4in; break;
  case 5:       ap=trm_lv5in; break;
  case 6:       ap=trm_lv6in; break;
  case 7:       ap=trm_lv7in; break;
  default: ap=trm_lv0in; break;
  }

  if (n<0) n=random(sizeof(ap));
  else if (n>=sizeof(ap)) n=sizeof(ap)-1;
  return ap[n];
}

int query_total(int lv)
{
  switch (lv)
  {
  case 0: return sizeof(trm_lv0in); break;
  case 1: return sizeof(trm_lv1in); break;
  case 2: return sizeof(trm_lv2in); break;
  case 3: return sizeof(trm_lv3in); break;
  case 4: return sizeof(trm_lv4in); break;
  case 5: return sizeof(trm_lv5in); break;
  case 6: return sizeof(trm_lv6in); break;
  case 7: return sizeof(trm_lv7in); break;
  default: return sizeof(trm_lv0in); break;
  }
  return 0;
}

void create()
{
        seteuid(getuid());
}

