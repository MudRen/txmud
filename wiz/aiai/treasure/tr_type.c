// tr_type.c
#include <ansi.h>

///////////////////////////////////////////////////////////////
// �����������Ϣattribute 1
// �����ʵĵ�λ��ǧ��֮һ������ %
// ����������µ����ͣ��ں���ֱ��׷�Ӽ��ɣ�ӳ��˳�򲻻�Ӱ�������
// Ŀǰ����:    700 : 300
mapping *trm_a0type = ({
        ([      "type":                 "sword",        // ��������
                "random_name":  1,                      // ��"name/"mapping�������������
                "enable":               1,                      // �Ƿ񿪷Ÿ��� 
                "name/0":               "����",         // "0"=>"����"  // "0"��Ĭ������
                "name/1":               "�̽�",         // "1"=>"�̽�"
                "name/2":               "�ν�",         
                "name/3":               "�佣",         
                "name/4":               "�ֽ�",         
                "name/5":               "����",         
                "name/6":               "��ľ��",
                // δ��ʶʱ���������������Ҫ��һ��
                // ����ʱ��msg=replace_string(msg, "ch", ob->name()) �滻
                "long/0":               "����һ��ch�����������߽���ʱ������ı�����\n",
                "long/1":               "����һ�Ѵֲڵ�ch���ָ�һ�㡣\n",
                "long/2":               "����һ�Ѵֲڵ�ch���ָ�һ�㡣\n",
                "id":                   "sword",        // Ĭ��id�������ж��
                "chance":               700,            // �����ͱ�����ֵļ��� 700 ��  ����������Ӧ��=1000
        ]),
        ([      "type":                 "blade",        
                "random_name":  1,
                "enable":               0,                      // �Ƿ񿪷Ÿ��� 
                "name/0":               "��",
                "name/1":               "�̵�",
                "name/2":               "�ε�",         
                "name/3":               "�䵶",         
                "name/4":               "�ֵ�",         
                "name/5":               "ľ��",
                "long/0":               "����һ��ch��\n",       
                "id":                   "blade",        
                "chance":               300,            // ����������Ӧ��=1000
        ]),
});

////////////////////////////////////////////////////////////////////////////////
// �����������Ϣ attribute 2
// Ŀǰ����:    700 : 300
mapping *trm_a1type = ({
        ([      "type":                 "cloth",        // ��������
                "random_name":  1,                      // ��"name/"mapping�������������
                "random_id":    1,                      // ��"id/"mapping�������������
                                                                        // ����random��ʱ��mappingӦ�����Ӧ
                "enable":               0,
                "name/0":               "����",
                "name/1":               "����",
                "name/2":               "ս��",
                "id/0":                 "cloth",        // "0" => "cloth"
                "id/1":                 "armor",        // "1" => "armor"
                "id/2":                 "armor",        
                "long/0":               "����һ��ch��\n",       
                "chance":               1000,           // �����ͱ�����ֵļ��� 1000 ��  ����������Ӧ��=1000
        ]),
        /*
        ([      "type":                 "helmet",       
                "name":                 "ͷ��",         // ���� ͷ����
                "id":                   "helmet",       
                "long/0":               "����һ��ch��\n",       
                "chance":               300,            // ����������Ӧ��=1000
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
                "name/0":               "��ʯ",
                "name/1":               "��Ѫʯ",
                "name/2":               "��",
                "id/0":                 "gem",  
                "id/1":                 "stone",        
                "id/2":                 "jade", 
                "color/0":              RED,            // �ͼ������ɫ
                "color/1":              HIR,            // �߼������ɫ
                "long/0":               "����һ��ch��\n",       
                "chance":               200,            // ����������Ӧ��=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "enable":               0,
                "name/0":               "��ʯ",
                "name/1":               "����",
                "id/0":                 "gem",  
                "id/1":                 "jade", 
                "color/0":              YEL,
                "color/1":              HIY,
                "long/0":               "����һ��ch��\n",       
                "chance":               200,            // ����������Ӧ��=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "enable":               0,
                "name/0":               "��ʯ",
                "name/1":               "���",
                "id/0":                 "stone",        
                "id/1":                 "jade", 
                "color/0":              GRN,
                "color/1":              HIG,
                "long/0":               "����һ��ch��\n",       
                "chance":               200,            // ����������Ӧ��=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "name/0":               "��ʯ",
                "name/1":               "ˮ��",
                "id/0":                 "gem",  
                "id/1":                 "crystal",      
                "color/0":              BLU,
                "color/1":              HIB,
                "long/0":               "����һ��ch��\n",       
                "chance":               200,            // ����������Ӧ��=1000
        ]),
        ([      "type":                 "gem",  
                "random_name":  1,
                "random_id":    1,
                "enable":               0,
                "name/0":               "����",
                "name/1":               "����",
                "id/0":                 "pearl",        
                "id/1":                 "jade", 
                "color/0":              BLU,
                "color/1":              HIB,
                "long/0":               "����һ��ch��\n",       
                "chance":               200,            // ����������Ӧ��=1000
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

