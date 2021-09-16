// tr_a0t0in : attribute 0, type 0, instance
#include <ansi.h>

//material:"iron"  "steel"  "silver"  "gold"  "copper"  "paper"  "cloth"
//"wood"  "leather"  "silk"  "blacksteel"  "丝质"  "皮革"  "gem"  "jade"
//level 0 to 7 is
//0 普通   1 蓝色   2 灰(黒)色   3 白色   4 粉色   5 金色   6 暗金   7 绿色
//宝石的级别越高，颜色会由普通变成高亮色，如：蓝宝石：蓝色 to 亮蓝色

////////////////////////////////////////////////////
// 等级0的东东，最一般的装备啦
mapping *trm_lv0in = ({
(["ident": 1, // 是否被鉴定，通常是 0
              //为了提高player的鉴定技能
  "level": 0, // 宝物级别 max=8
  "name": "普通剑", // 基础中文
  "id":"sword", // 基础id名
  "sprite": -1, // 是否有灵气（小动作），>=0表示动作的mapping array
                // -1 没有动作
  "value": 100, // 总价值
  "material":           "iron", // 材料
  "weight":             5000,   // 重量
  "power":              23,             // 武器伤害度
  "limit/0": "0=10000", // 装备限制 0 是mapping code，exp>10000才可用
  "gems": -1, // -1表示可以打孔或随机生成孔,0=无孔
  //"gemed/0": -1, // 已经镶嵌的stone，实例宝物一律没有被镶嵌stone
// -1表示没有宝石
  "gift/0": "-1=2", // -1 表示随机生成一个属性
                    //2=最大随机属性的个数
                    // 此标志必须是放在 "gift/" 的 "0" 位置
  "gift/1": "1=20", // 1 表示附加属性的mapping code为1 str>20才可用
  "green_set":-1,  // 绿色装备的id, -1为非绿色装备
// 描述
"long": "ch武器\n",     
"prefix": 2, //允许加的前缀数量, -1 表示无限个
"surfix": 1, //允许加的后缀数量, -1 表示无限个
"autoload": 0, // 退出时是否保留
]),
(["ident":              1,              
"level":                0,              
"name":                 "绣剑",         
"id":                   "sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                20,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=1", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

//////////////////////////////////////////////////
mapping *trm_lv1in = ({
(["ident":              1,              
"level":                1,
"name":                 "月之剑",               
"id":                   "moon sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                20,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                1,              
"name":                 "水之剑",               
"id":                   "water sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                20,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

///////////////////////////////////////////////////////
mapping *trm_lv2in = ({
(["ident":              0,              
"level":                2,
"name":                 "牛剑",         
"id":                   "cow sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                30,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                2,              
"name":                 "睧目剑",               
"id":                   "faint sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                35,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

////////////////////////////////////////////////////////////////
mapping *trm_lv3in = ({
(["ident":              0,              
"level":                3,
"name":                 "黄河剑",               
"id":                   "yriver sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                40,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=3", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                3,              
"name":                 "长江剑",               
"id":                   "lriver sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                45,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

///////////////////////////////////////////////////////////////
mapping *trm_lv4in = ({
(["ident":              0,              
"level":                4,
"name":                 "流云剑",               
"id":                   "cloud sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                50,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=3", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                4,              
"name":                 "碧水剑",               
"id":                   "green sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                55,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

//////////////////////////////////////////////////////////////////
mapping *trm_lv5in = ({
(["ident":              0,              
"level":                5,
"name":                 "天剑",         
"id":                   "t sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                60,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述

"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                5,              
"name":                 "下剑",         
"id":                   "x sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                55,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=2", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

///////////////////////////////////////////////////////////////////
// 等级6的东东，极品装备(暗金)
mapping *trm_lv6in = ({
(["ident":              0,
"level":                6,
"name":                 "开天宝剑",     
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
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               2,              
"autoload":             1,
]),
(["ident":              0,
"level":                6,
"name":                 "辟地宝剑",     
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
// 描述
"long":                 "ch武器",       
"prefix":               2,
"surfix":               2,              
"autoload":             1,
]),
(["ident":              0,              
"level":                6,
"name":                 "天下之剑",             
"id":                   "tx sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                80,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=4", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                6,              
"name":                 "测试之剑",             
"id":                   "test sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                90,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=5", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
});

////////////////////////////////////////////////////////////////////////////////
mapping *trm_lv7in = ({
(["ident":              0,              
"level":                7,
"name":                 "绿色剑A",              
"id":                   "gset sword",
"sprite":               -1,             
"value":                100,    

"material":             "steel",
"weight":               2000,   
"power":                80,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=4", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
"prefix":               2,
"surfix":               1,
"autoload":             0,
]),
(["ident":              0,              
"level":                7,              
"name":                 "绿套装之剑B",          
"id":                   "gset sword",
"sprite":               -1,             
"value":                100,    
"material":             "steel",
"weight":               2000,   
"power":                90,             
"limit/0":              "0=10000",
"gems":                 -1,             
"gift/0":               "-1=5", // -1 表示随机生成一个属性
"gift/1":               "1=15",
"green_set":    -1,
// 描述
"long":                 "ch武器\n",     
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

