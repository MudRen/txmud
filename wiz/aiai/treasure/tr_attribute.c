// tr_attribute.c : only save mappings & 1 query function
#include <ansi.h>

// 宝物属性信息
// 出现率的单位是千分之一 ‰ ，不是 %
// 如果想增加新的类型，在后面直接追加即可，映射顺序不会影响出现率
// 目前配置:    300 : 300 : 150 : 200 : 50
mapping *trm_attribute = ({
        ([      "system":               "EQUIP",        // 总类
                "attribute":    "weapon",       // 宝物属性
                "enable":               1,                      // 是否开放                        
                "chance":               300,            // 该属性宝物出现的几率 300 ‰  各属性总数应该=1000
                "need_equip":   1,                      // 是否需要装备才见效，-1是使用，-2是镶嵌
                "is_gem":               0,                      // 是否可以作为镶嵌宝石
//              "is_real":              1,                      // 是否是系统生成，这里不必写，在最后生成的时候set
        ]),
        ([      "system":               "EQUIP",        // 总类
                "enable":               0,
                "attribute":    "armor",        
                "chance":               300,            // 各属性总数应该=1000
                "need_equip":   1,                      
                "is_gem":               0,                      
        ]),
        ([      "system":               "ITEM",         
                "attribute":    "item", 
                "enable":               0,
                "chance":               150,            // 各属性总数应该=1000
                "need_equip":   -1,                     
                "is_gem":               0,                      
        ]),
        ([      "system":               "ITEM",         
                "attribute":    "gem",  
                "enable":               0,
                "chance":               200,            // 各属性总数应该=1000
                "need_equip":   -2,                     
                "is_gem":               1,                      
        ]),
        ([      "system":               "ITEM",         
                "attribute":    "charm",        
                "enable":               0,
                "chance":               50,                     // 各属性总数应该=1000
                "need_equip":   0,                      
                "is_gem":               0,                      
        ]),
});

mapping query(int n)
{
        if (n<0) n=random(sizeof(trm_attribute));
        else if (n>=sizeof(trm_attribute)) n=sizeof(trm_attribute)-1;
        return trm_attribute[n];
}

int query_total()
{
        return sizeof(trm_attribute);
}

void create()
{
        seteuid(getuid());
}

