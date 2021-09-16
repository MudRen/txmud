// tr_query.c : query other treasure mappings
#include <ansi.h>
//#include <weapon.h>

////////////////////////////////////////////////////////////////////////////////
// �������Եı�����Խ����ԽֵǮ
// ���ԵĴ�����Ϣ�����Ը���������tr��������
mapping *trm_gift = ({
        ([      "name":                 "���",         // ������������
                // (other_fix + pre_prefix+) name + pre_surfix + tr_base_name
                //  + sur_prefix + name (+sur_surfix)
                "pre_prefix":   "��",           // ǰ׺��������ǰ׺�����֮ǰ��������������
                                                                        //   ��������Ϊ��"pre_prefix" + "name"
                "pre_surfix":   "֮",           // ǰ׺�������ĺ�׺�����֮��û���κθ�����
                                                                        //   ��������Ϊ��"name"+(���������)
                                                                        //  ���Ժ� "pre_prefix" ���ʹ��
                                                                        //  Ŀ������׺�����űȽ����

                //"sur_prefix": "��",           // ��׺��������ǰ׺�������׺Ϊ��һ����׺
                                                                        //   ��������Ϊ��(���������)+"sur_prefix"+"name"
                //"sur_surfix": "��",           // ��׺�������ĺ�׺�������׺���ǵ�һ����׺
                                                                        //   ��������Ϊ��(���������)+"name"+"sur_surfix"
                                                                        //  ���Ժ� "sur_", "pre_" ���ʹ��
                                                                        //  "none" ��ʾû�����׺

                "id":           "void",                 // ����id
                "gift":         "none=0",                       // �������Եĺ���mapping id
                                                                        // noneΪ�޸������ԣ�0ΪĬ��ֵ
                "type":  "none",        // none=��Ϊװ��
                                                        // +temp=��ʱ���� 
                                                        // +max=�������ޣ����ã���һ����
                                                        //              ���л���"add_type":  0=add ��ͨquery;
                                                        //                                                       1=add skills
                                                        // -temp=��ʱ����
                                                        // -max=�������ޣ����ã���һ����
                                                        // "uni=0" = ���⹦Ч��0Ϊ����mapping id
                "gift_name":    "װ��=Ч��",
        ]),
        ([      "name":                 "��",           
                "pre_prefix":   "��",           
                "pre_surfix":   "ɫ",
                "id":           "red",  
                //"gift":               "bellicosity=50",
                "gift":                 "shaqi=50",
                "type":  "+temp",
                "gift_name":    "ɱ��=��",
        ]),
        ([      "name":                 "��",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
                "id":                   "power",        
                "gift":         "strength=5",
                "type":  "+temp",
                "gift_name":    "����=��",
        ]),
        ([      "name":         "��ʿ",
                "id":           "brave",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
                "gift":         "courage=5",
                "type":  "+temp",
                "gift_name":    "��ʶ=��",
        ]),
        ([      "name":                 "����",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
                "id":                   "bright",       
                "gift":         "intelligence=5",
                "type":  "+temp",
                "gift_name":    "����=��",
        ]),
        ([      "name":                 "����",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
                "id":                   "endure",
                "gift":         "constitution=5",
                "type":  "+temp",
                "gift_name":    "����=��",
        ]),
        ([      "name":                 "�Ҹ�",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
                "id":                   "happy",        
                "gift":         "karma=5",
                "type":  "+temp",
                "gift_name":    "��Ե=��",
        ]),
        ([      "name":                 "����",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
                "id":                   "pretty",       
                "gift":         "personality=5",
                "type":  "+temp",
                "gift_name":    "��ò=��",
        ]),
        ([      "name":                 "����",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
                "id":                   "mpow", 
                "gift":         "str=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "����=��",
        ]),
        ([      "name":                 "����",
                "id":                   "frave",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
                "gift":         "cor=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "��ʶ=��",
        ]),
        ([      "name":                 "����",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
                "id":                   "genus",        
                "gift":                 "int=5",
                "type":                 "+max",
                "add_type":  0,
                "gift_name":    "����=��",
        ]),
        ([      "name":                 "����",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
                "id":                   "andure",
                "gift":                 "con=5",
                "type":                 "+max",
                "add_type":  0,
                "gift_name":    "����=��",
        ]),
        ([      "name":                 "����",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
                "id":                   "karma",        
                "gift":                 "kar=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "��Ե=��",
        ]),
        ([      "name":                 "���",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
                "id":                   "bretty",       
                "gift":                 "per=5",
                "type":         "+max",
                "add_type":  0,
                "gift_name":    "��ò=��",
        ]),
});

////////////////////////////////////////////////////////////////////////////////
// ����ʱ���������ǰ׺
mapping *trm_random_namefix = ({
// ǰ׺
        ([      "name":         "��",
                "id":           "unreal",       
                "pre_prefix":   "��",   // ׺����ͬ��
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "Ե��",
                "id":           "lot",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "����",
                "id":           "desire",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
        ]),
        ([      "name":         "��",
                "id":           "fire",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "��ʥ",
                "id":           "holy",
                "pre_prefix":   "none",
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "����",
                "id":           "giant",
                "pre_prefix":   "none",
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "��",
                "id":           "heart",
                "pre_prefix":   "��",
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "����",
                "id":           "god",
                "pre_prefix":   "none",
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "����",
                "id":           "king",
                "pre_prefix":   "none",
                "pre_surfix":   "֮",
        ]),
        ([      "name":         "��",
                "id":           "love",
                "pre_prefix":   "��",
                "pre_surfix":   "��",
        ]),
// ��׺
        ([      "name":         "����",
                "id":           "soul",
                "sur_prefix":   "��",
                "sur_surfix":   "��",
        ]),
        ([      "name":         "��",
                "id":           "hrt",
                "sur_prefix":   "֮",
                "sur_surfix":   "��",
        ]),
        ([      "name":         "��",
                "id":           "str",
                "sur_prefix":   "֮",
                "sur_surfix":   "��",
        ]),
        ([      "name":         "��",
                "id":           "kiss",
                "sur_prefix":   "֮",
                "sur_surfix":   "��",
        ]),
        ([      "name":         "��",
                "id":           "king",
                "sur_prefix":   "֮",
                "sur_surfix":   "��",
        ]),
        ([      "name":         "��",
                "id":           "hand",
                "sur_prefix":   "֮",
                "sur_surfix":   "��",
        ]),
        ([      "name":         "����",
                "id":           "diz",
                "sur_prefix":   "��",
                "sur_surfix":   "��",
        ]),
});

////////////////////////////////////////////////////////////////////////////////
// װ��/ʹ�����ƴ���
mapping *trm_limit = ({
        ([      "name":         "ʵս����",
                "id":           "combat_exp",   
                "type":         0,      // 0��ͨ��query("",1)
                                                // -1��query_skill("",1)
                                                // 1��query_str()
                                                // 2��query_cor()
                                                // 3��query_int()
                                                // 4��query_con()
                                                // 5��query_kar()
                                                // 6��query_per()
        ]),
        ([      "name":         "Ǳ��",         // װ��֮������Ǳ��
                "id":           "potential",    
                "type":         0,
        ]),
        ([      "name":         "�������",
                "id":           "str",  
                "type":         0,              
        ]),
        ([      "name":         "����",
                "id":           "str",  
                "type":         1,      
        ]),
        ([      "name":         "���쵨ʶ",
                "id":           "cor",  
                "type":         0,              
        ]),
        ([      "name":         "��ʶ",
                "id":           "cor",  
                "type":         2,      
        ]),
        ([      "name":         "��������",
                "id":           "int",  
                "type":         0,              
        ]),
        ([      "name":         "����",
                "id":           "int",  
                "type":         3,      
        ]),
        ([      "name":         "�������",
                "id":           "con",  
                "type":         0,              
        ]),
        ([      "name":         "����",
                "id":           "con",  
                "type":         4,      
        ]),
        ([      "name":         "���츣Ե",
                "id":           "kar",  
                "type":         0,              
        ]),
        ([      "name":         "��Ե",
                "id":           "kar",  
                "type":         5,      
        ]),
        ([      "name":         "������ò",
                "id":           "per",  
                "type":         0,              
        ]),
        ([      "name":         "��ò",
                "id":           "per",  
                "type":         6,
        ]),
        ([      "name":         "��ɽ����",
                "id":           "huashan-sword",        
                "type":         -1,                     
        ]),
        ([      "name":         "���¾Ž�",
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

