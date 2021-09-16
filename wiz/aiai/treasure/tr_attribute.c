// tr_attribute.c : only save mappings & 1 query function
#include <ansi.h>

// ����������Ϣ
// �����ʵĵ�λ��ǧ��֮һ �� ������ %
// ����������µ����ͣ��ں���ֱ��׷�Ӽ��ɣ�ӳ��˳�򲻻�Ӱ�������
// Ŀǰ����:    300 : 300 : 150 : 200 : 50
mapping *trm_attribute = ({
        ([      "system":               "EQUIP",        // ����
                "attribute":    "weapon",       // ��������
                "enable":               1,                      // �Ƿ񿪷�                        
                "chance":               300,            // �����Ա�����ֵļ��� 300 ��  ����������Ӧ��=1000
                "need_equip":   1,                      // �Ƿ���Ҫװ���ż�Ч��-1��ʹ�ã�-2����Ƕ
                "is_gem":               0,                      // �Ƿ������Ϊ��Ƕ��ʯ
//              "is_real":              1,                      // �Ƿ���ϵͳ���ɣ����ﲻ��д����������ɵ�ʱ��set
        ]),
        ([      "system":               "EQUIP",        // ����
                "enable":               0,
                "attribute":    "armor",        
                "chance":               300,            // ����������Ӧ��=1000
                "need_equip":   1,                      
                "is_gem":               0,                      
        ]),
        ([      "system":               "ITEM",         
                "attribute":    "item", 
                "enable":               0,
                "chance":               150,            // ����������Ӧ��=1000
                "need_equip":   -1,                     
                "is_gem":               0,                      
        ]),
        ([      "system":               "ITEM",         
                "attribute":    "gem",  
                "enable":               0,
                "chance":               200,            // ����������Ӧ��=1000
                "need_equip":   -2,                     
                "is_gem":               1,                      
        ]),
        ([      "system":               "ITEM",         
                "attribute":    "charm",        
                "enable":               0,
                "chance":               50,                     // ����������Ӧ��=1000
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

