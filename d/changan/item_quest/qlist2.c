// qlist2.c : quest list 2
#include <ansi.h>

mapping *quest_list = ({
        ([      "name":                 "����",
                "id":                   "yangshen dan",
                "type":                 "��",
                "reward":               300,    // ��߽���exp��Ǳ�������25%
        ]),
        ([      "name":                 "ţƤ����",
                "id":                   "niupi hujia",
                "type":                 "��",
                "reward":               500,
        ]),
        ([      "name":                 "��֬",
                "id":                   "yan zhi",
                "type":                 "��",
                "reward":               400,
        ]),
        ([      "name":                 "�󻹵�",
                "id":                   "huan dan",
                "type":                 "��",
                "reward":               300,
        ]),
        ([      "name":                 "��˿ͷ��",
                "id":                   "head armor",
                "type":                 "��",
                "reward":               300,
        ]),
        ([      "name":                 "��������",
                "id":                   "hongshao liyu",
                "type":                 "��",
                "reward":               300,
        ]),
        ([      "name":                 HIR"��ָ"NOR,
                "id":                   "jie zhi",
                "type":                 "��",
                "reward":               300,
        ]),
        ([      "name":                 MAG"��ɫС��"NOR,
                "id":                   "xiao gua",
                "type":                 "��",
                "reward":               400,
        ]),
        ([      "name":                 HIW"����"NOR,
                "id":                   "xiang lian",
                "type":                 "��",
                "reward":               400,
        ]),
        ([      "name":                 "������",
                "id":                   "ji guan",
                "type":                 "��",
                "reward":               300,
        ]),
});

mapping query()
{
        return quest_list[random(sizeof(quest_list))];
}

void create()
{
        seteuid(getuid());
}


