// qlist3.c : quest list 3
#include <ansi.h>

mapping *quest_list = ({
        ([      "name":                 HIW"����黨"NOR,
                "id":                   "zhu hua",
                "type":                 "��",
                "reward":               1000,
        ]),
        ([      "name":                 "����",
                "id":                   "mang pao",
                "type":                 "��",
                "reward":               1000,
        ]),
        ([      "name":                 "��г�ȹ",
                "id":                   "long skirt",
                "type":                 "��",
                "reward":               800,
        ]),
        ([      "name":                 HIW"��ʯ��ָ"NOR,
                "id":                   "diamond ring",
                "type":                 "��",
                "reward":               900,
        ]),
        ([      "name":                 "ͭԿ��",
                "id":                   "tong key",
                "type":                 "��",
                "reward":               800,
        ]),
        ([      "name":                 HIW"��꽣"NOR,
                "id":                   "feiyu sword",
                "type":                 "��",
                "reward":               800,
        ]),
        ([      "name":                 "�಼ɮ��",
                "id":                   "seng pao",
                "type":                 "��",
                "reward":               800,
        ]),
        ([      "name":                 "ȭ��ͼ��",
                "id":                   "quanfa tupu",
                "type":                 "��",
                "reward":               1000,
        ]),
        ([      "name":                 "Ұ�ջ�",
                "id":                   "mum",
                "type":                 "��",
                "reward":               1000,
        ]),
        ([      "name":                 "ϸ��ȹ",
                "id":                   "skirt",
                "type":                 "��",
                "reward":               800,
        ]),
        ([      "name":                 "����",
                "id":                   "lumber axe",
                "type":                 "��",
                "reward":               1000,
        ]),
        ([      "name":                 "����֥",
                "id":                   "zi lingzhi",
                "type":                 "��",
                "reward":               1000,
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

