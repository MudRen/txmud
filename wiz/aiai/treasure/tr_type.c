// tr_type.c
#include <ansi.h>

///////////////////////////////////////////////////////////////
// 宝物的类型信息attribute 1
// 出现率的单位是千分之一，不是 %
// 如果想增加新的类型，在后面直接追加即可，映射顺序不会影响出现率
// 目前配置:    700 : 300
mapping *trm_a0type = ({
        ([      "type":                 "sword",        // 宝物类型
                "random_name":  1,                      // 由"name/"mapping中随机生成名字
                "enable":               1,                      // 是否开放该类 
                "name/0":               "长剑",         // "0"=>"长剑"  // "0"是默认名字
                "name/1":               "短剑",         // "1"=>"短剑"
                "name/2":               "饰剑",         
                "name/3":               "配剑",         
                "name/4":               "钢剑",         
                "name/5":               "铁剑",         
                "name/6":               "桃木剑",
                // 未辨识时的随机描述，至少要有一个
                // 操作时用msg=replace_string(msg, "ch", ob->name()) 替换
                "long/0":               "这是一把ch，是人们行走江湖时常佩戴的兵器。\n",
                "long/1":               "这是一把粗糙的ch，手感一般。\n",
                "long/2":               "这是一把粗糙的ch，手感一般。\n",
                "id":                   "sword",        // 默认id，可以有多个
                "chance":               700,            // 该类型宝物出现的几率 700 ‰  各类型总数应该=1000
        ]),
        ([      "type":                 "blade",        
                "random_name":  1,
                "enable":               0,                      // 是否开放该类 
                "name/0":               "刀",
                "name/1":               "短刀",
                "name/2":               "饰刀",         
                "name/3":               "配刀",         
                "name/4":               "钢刀",         
                "name/5":               "木刀",
                "long/0":               "这是一把ch。\n",       
                "id":                   "blade",        
                "chance":               300,            // 各类型总数应该=1000
        ]),
});

////////////////////////////////////////////////////////////////////////////////
// 宝物的类型信息 attribute 2
// 目前配置:    700 : 300
mapping *trm_a1type = ({
        ([      "type":                 "cloth",        // 宝物类型
                "random_name":  1,                      // 由"name/"mapping中随机生成名字
                "random_id":    1,                      // 由"id/"mapping中随机生成名字
                                                                        // 都是random的时候，mapping应该向对应
                "enable":               0,
                "name/0":               "护衣",
                "name/1":               "护甲",
                "name/2":               "战甲",
                "id/0":                 "cloth",        // "0" => "cloth"
                "id/1":                 "armor",        // "1" => "armor"
                "id/2":                 "armor",        
                "long/0":               "这是一件ch。\n",       
                "chance":               1000,           // 该类型宝物出现的几率 1000 ‰  各类型总数应该=1000
        ]),
        /*
        ([      "type":                 "helmet",       
                "name":                 "头盔",         // 还有 头巾……
                "id":                   "helmet",       
                "long/0":               "这是一个ch。\n",       
                "chance":               300,            // 各类型总数应该=1000
        ]),
        */
});

////////////////////////////////////////////////////////////////////////////////
mapping *trm_a2type = ({

});

////////////////////////////////////////////////////////////////////////////////
mapping *trm_a3type = ({
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "enable":               0,
                "name/0":               "宝石",
                "name/1":               "鸡血石",
                "name/2":               "玉",
                "id/0":                 "gem",  
                "id/1":                 "stone",        
                "id/2":                 "jade", 
                "color/0":              RED,            // 低级别的颜色
                "color/1":              HIR,            // 高级别的颜色
                "long/0":               "这是一个ch。\n",       
                "chance":               200,            // 各类型总数应该=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "enable":               0,
                "name/0":               "宝石",
                "name/1":               "黄玉",
                "id/0":                 "gem",  
                "id/1":                 "jade", 
                "color/0":              YEL,
                "color/1":              HIY,
                "long/0":               "这是一个ch。\n",       
                "chance":               200,            // 各类型总数应该=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "enable":               0,
                "name/0":               "奇石",
                "name/1":               "翡翠",
                "id/0":                 "stone",        
                "id/1":                 "jade", 
                "color/0":              GRN,
                "color/1":              HIG,
                "long/0":               "这是一个ch。\n",       
                "chance":               200,            // 各类型总数应该=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "name/0":               "宝石",
                "name/1":               "水晶",
                "id/0":                 "gem",  
                "id/1":                 "crystal",      
                "color/0":              BLU,
                "color/1":              HIB,
                "long/0":               "这是一个ch。\n",       
                "chance":               200,            // 各类型总数应该=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "enable":               0,
                "name/0":               "珍珠",
                "name/1":               "美玉",
                "id/0":                 "pearl",        
                "id/1":                 "jade", 
                "color/0":              BLU,
                "color/1":              HIB,
                "long/0":               "这是一个ch。\n",       
                "chance":               200,            // 各类型总数应该=1000
        ]),
});

////////////////////////////////////////////////////////////////////////////////
mapping *trm_a4type = ({

});


////////////////////////////////////////////////////////////////////////////////
mapping query(int attr, int n)
{
        mapping *ap;

        switch (attr)
        {
        case 0: ap=trm_a0type; break;
        case 1: ap=trm_a1type; break;
        case 2: ap=trm_a2type; break;
        case 3: ap=trm_a3type; break;
        default: ap=trm_a4type; break;
        }

        if (n<0) n=random(sizeof(ap));
        else if (n>=sizeof(ap)) n=sizeof(ap)-1;
        return ap[n];
}

int query_total(int attr)
{
        switch (attr)
        {
        case 0: return sizeof(trm_a0type); break;
        case 1: return sizeof(trm_a1type); break;
        case 2: return sizeof(trm_a2type); break;
        case 3: return sizeof(trm_a3type); break;
        default: return sizeof(trm_a4type); break;
        }
        return 0;
}

void create()
{
        seteuid(getuid());
}

