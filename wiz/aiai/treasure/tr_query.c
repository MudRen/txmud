// tr_query.c : query other treasure mappings
#include <ansi.h>
//#include <weapon.h>

////////////////////////////////////////////////////////////////////////////////
// 附加属性的表，代码越靠后，越值钱
// 属性的代码信息，可以附加名字在tr的名字上
mapping *trm_gift = ({
        ([      "name":                 "虚幻",         // 基本附加名字
                // (other_fix + pre_prefix+) name + pre_surfix + tr_base_name
                //  + sur_prefix + name (+sur_surfix)
                "pre_prefix":   "与",           // 前缀附加名的前缀：如果之前有其他附加属性
                                                                        //   则总名字为："pre_prefix" + "name"
                "pre_surfix":   "之",           // 前缀附加名的后缀：如果之后没有任何附加名
                                                                        //   则总名字为："name"+(宝物基础名)
                                                                        //  可以和 "pre_prefix" 结合使用
                                                                        //  目的是让缀名叫着比较舒服

                //"sur_prefix": "的",           // 后缀附加名的前缀：如果此缀为第一个后缀
                                                                        //   则总名字为：(宝物基础名)+"sur_prefix"+"name"
                //"sur_surfix": "与",           // 后缀附加名的后缀：如果此缀不是第一个后缀
                                                                        //   则总名字为：(宝物基础名)+"name"+"sur_surfix"
                                                                        //  可以和 "sur_", "pre_" 结合使用
                                                                        //  "none" 表示没有最后缀

                "id":           "void",                 // 附加id
                "gift":         "none=0",                       // 附加属性的函数mapping id
                                                                        // none为无附加属性，0为默认值
                "type":  "none",        // none=仅为装饰
                                                        // +temp=临时增加 
                                                        // +max=增加上限（永久），一次性
                                                        //              其中会有"add_type":  0=add 普通query;
                                                        //                                                       1=add skills
                                                        // -temp=临时减少
                                                        // -max=减少上限（永久），一次性
                                                        // "uni=0" = 特殊功效，0为函数mapping id
                "gift_name":    "装饰=效果",
        ]),
        ([      "name":                 "红",           
                "pre_prefix":   "与",           
                "pre_surfix":   "色",
                "id":           "red",  
                //"gift":               "bellicosity=50",
                "gift":                 "shaqi=50",
                "type":  "+temp",
                "gift_name":    "杀气=点",
        ]),
        ([      "name":                 "力",
                "pre_prefix":   "和",
                "pre_surfix":   "之",
                "id":                   "power",        
                "gift":         "strength=5",
                "type":  "+temp",
                "gift_name":    "臂力=点",
        ]),
        ([      "name":         "将士",
                "id":           "brave",
                "pre_prefix":   "与",
                "pre_surfix":   "之",
                "gift":         "courage=5",
                "type":  "+temp",
                "gift_name":    "胆识=点",
        ]),
        ([      "name":                 "慧智",
                "pre_prefix":   "与",
                "pre_surfix":   "的",
                "id":                   "bright",       
                "gift":         "intelligence=5",
                "type":  "+temp",
                "gift_name":    "悟性=点",
        ]),
        ([      "name":                 "苦力",
                "pre_prefix":   "与",
                "pre_surfix":   "之",
                "id":                   "endure",
                "gift":         "constitution=5",
                "type":  "+temp",
                "gift_name":    "根骨=点",
        ]),
        ([      "name":                 "幸福",
                "pre_prefix":   "与",
                "pre_surfix":   "的",
                "id":                   "happy",        
                "gift":         "karma=5",
                "type":  "+temp",
                "gift_name":    "福缘=点",
        ]),
        ([      "name":                 "秀美",
                "pre_prefix":   "和",
                "pre_surfix":   "的",
                "id":                   "pretty",       
                "gift":         "personality=5",
                "type":  "+temp",
                "gift_name":    "容貌=点",
        ]),
        ([      "name":                 "怪力",
                "pre_prefix":   "和",
                "pre_surfix":   "之",
                "id":                   "mpow", 
                "gift":         "str=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "臂力=点",
        ]),
        ([      "name":                 "勇猛",
                "id":                   "frave",
                "pre_prefix":   "与",
                "pre_surfix":   "之",
                "gift":         "cor=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "胆识=点",
        ]),
        ([      "name":                 "天智",
                "pre_prefix":   "与",
                "pre_surfix":   "的",
                "id":                   "genus",        
                "gift":                 "int=5",
                "type":                 "+max",
                "add_type":  0,
                "gift_name":    "悟性=点",
        ]),
        ([      "name":                 "苦难",
                "pre_prefix":   "与",
                "pre_surfix":   "之",
                "id":                   "andure",
                "gift":                 "con=5",
                "type":                 "+max",
                "add_type":  0,
                "gift_name":    "根骨=点",
        ]),
        ([      "name":                 "福分",
                "pre_prefix":   "与",
                "pre_surfix":   "的",
                "id":                   "karma",        
                "gift":                 "kar=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "福缘=点",
        ]),
        ([      "name":                 "倾国",
                "pre_prefix":   "和",
                "pre_surfix":   "的",
                "id":                   "bretty",       
                "gift":                 "per=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "容貌=点",
        ]),
});

////////////////////////////////////////////////////////////////////////////////
// 鉴定时的随机名字前缀
mapping *trm_random_namefix = ({
// 前缀
        ([      "name":         "幻",
                "id":           "unreal",       
                "pre_prefix":   "与",   // 缀方法同上
                "pre_surfix":   "之",
        ]),
        ([      "name":         "缘分",
                "id":           "lot",
                "pre_prefix":   "与",
                "pre_surfix":   "之",
        ]),
        ([      "name":         "欲望",
                "id":           "desire",
                "pre_prefix":   "和",
                "pre_surfix":   "的",
        ]),
        ([      "name":         "火",
                "id":           "fire",
                "pre_prefix":   "与",
                "pre_surfix":   "之",
        ]),
        ([      "name":         "神圣",
                "id":           "holy",
                "pre_prefix":   "none",
                "pre_surfix":   "之",
        ]),
        ([      "name":         "巨人",
                "id":           "giant",
                "pre_prefix":   "none",
                "pre_surfix":   "之",
        ]),
        ([      "name":         "心",
                "id":           "heart",
                "pre_prefix":   "与",
                "pre_surfix":   "之",
        ]),
        ([      "name":         "天命",
                "id":           "god",
                "pre_prefix":   "none",
                "pre_surfix":   "之",
        ]),
        ([      "name":         "帝王",
                "id":           "king",
                "pre_prefix":   "none",
                "pre_surfix":   "之",
        ]),
        ([      "name":         "爱",
                "id":           "love",
                "pre_prefix":   "和",
                "pre_surfix":   "的",
        ]),
// 后缀
        ([      "name":         "妖魂",
                "id":           "soul",
                "sur_prefix":   "的",
                "sur_surfix":   "与",
        ]),
        ([      "name":         "心",
                "id":           "hrt",
                "sur_prefix":   "之",
                "sur_surfix":   "和",
        ]),
        ([      "name":         "力",
                "id":           "str",
                "sur_prefix":   "之",
                "sur_surfix":   "和",
        ]),
        ([      "name":         "吻",
                "id":           "kiss",
                "sur_prefix":   "之",
                "sur_surfix":   "与",
        ]),
        ([      "name":         "王",
                "id":           "king",
                "sur_prefix":   "之",
                "sur_surfix":   "与",
        ]),
        ([      "name":         "手",
                "id":           "hand",
                "sur_prefix":   "之",
                "sur_surfix":   "和",
        ]),
        ([      "name":         "灾难",
                "id":           "diz",
                "sur_prefix":   "的",
                "sur_surfix":   "与",
        ]),
});

////////////////////////////////////////////////////////////////////////////////
// 装备/使用限制代码
mapping *trm_limit = ({
        ([      "name":         "实战经验",
                "id":           "combat_exp",   
                "type":         0,      // 0是通过query("",1)
                                                // -1是query_skill("",1)
                                                // 1是query_str()
                                                // 2是query_cor()
                                                // 3是query_int()
                                                // 4是query_con()
                                                // 5是query_kar()
                                                // 6是query_per()
        ]),
        ([      "name":         "潜能",         // 装备之后吸收潜能
                "id":           "potential",    
                "type":         0,
        ]),
        ([      "name":         "先天臂力",
                "id":           "str",  
                "type":         0,              
        ]),
        ([      "name":         "臂力",
                "id":           "str",  
                "type":         1,      
        ]),
        ([      "name":         "先天胆识",
                "id":           "cor",  
                "type":         0,              
        ]),
        ([      "name":         "胆识",
                "id":           "cor",  
                "type":         2,      
        ]),
        ([      "name":         "先天悟性",
                "id":           "int",  
                "type":         0,              
        ]),
        ([      "name":         "悟性",
                "id":           "int",  
                "type":         3,      
        ]),
        ([      "name":         "先天根骨",
                "id":           "con",  
                "type":         0,              
        ]),
        ([      "name":         "根骨",
                "id":           "con",  
                "type":         4,      
        ]),
        ([      "name":         "先天福缘",
                "id":           "kar",  
                "type":         0,              
        ]),
        ([      "name":         "福缘",
                "id":           "kar",  
                "type":         5,      
        ]),
        ([      "name":         "先天容貌",
                "id":           "per",  
                "type":         0,              
        ]),
        ([      "name":         "容貌",
                "id":           "per",  
                "type":         6,
        ]),
        ([      "name":         "华山剑法",
                "id":           "huashan-sword",        
                "type":         -1,                     
        ]),
        ([      "name":         "独孤九剑",
                "id":           "dugu-sword",   
                "type":         -1,                     
        ]),
});

////////////////////////////////////////////////////////////////////////////////
mapping query_gift(int n)
{
        if (n<0) n=random(sizeof(trm_gift));
        else if (n>=sizeof(trm_gift)) n=sizeof(trm_gift)-1;
        return trm_gift[n];
}

int query_gift_total()
{
        return sizeof(trm_gift);
}

////////////////////////////////////////////////////////////////////////////////
mapping query_random_namefix(int n)
{
        if (n<0) n=random(sizeof(trm_random_namefix));
        else if (n>=sizeof(trm_random_namefix)) 
                n=sizeof(trm_random_namefix)-1;
        return trm_random_namefix[n];

}

int query_random_namefix_total()
{
        return sizeof(trm_random_namefix);
}

////////////////////////////////////////////////////////////////////////////////
mapping query_limit(int n)
{
        if (n<0) n=random(sizeof(trm_limit));
        else if (n>=sizeof(trm_limit)) 
                n=sizeof(trm_limit)-1;
        return trm_limit[n];
}

int query_limit_total()
{
        return sizeof(trm_limit);
}

////////////////////////////////////////////////////////////////////////////////
void create()
{
        seteuid(getuid());
}

