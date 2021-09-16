// qlist1.c : quest list 1
#include <ansi.h>
#include <weapon.h>

mapping *quest_list = ({
        ([      "name":                 "����",
                "id":                   "ci wan",
                "type":                 "��",
                "reward":               200,
        ]),
        ([      "name":                 "������",
                "id":                   "ji tui",
                "type":                 "��",
                "reward":               200,
        ]),
        ([      "name":                 "����ʨ��ͷ",
                "id":                   "shizi tou",
                "type":                 "��",
                "reward":               300,
        ]),
        ([      "name":                 "ͭ������",
                "id":                   "wrists",
                "type":                 "��",
                "reward":               400,
        ]),
        ([      "name":                 "��������",
                "id":                   "hu wan",
                "type":                 "��",
                "reward":               380,
        ]),
        ([      "name":                 "���˿����",
                "id":                   "steel armguard",
                "type":                 "��",
                "reward":               380,
        ]),
        ([      "name":                 "�������󷨡�",
                "id":                   "force book",
                "type":                 "��",
                "reward":               280,
        ]),
        ([      "name":                 "ʮ�ָ�",
                "id":                   "shi zi gao",
                "type":                 "��",
                "reward":               240,
        ]),
        ([      "name":                 "���",
                "id":                   "torch",
                "type":                 "��",
                "reward":               220,
        ]),
        ([      "name":                 "��ȭ�����š�",
                "id":                   "unarmed book",
                "type":                 "��",
                "reward":               220,
        ]),
        ([      "name":                 "����",
                "id":                   "xiang",
                "type":                 "��",
                "reward":               300,
        ]),
        ([      "name":                 "�����ҩ��",
                "id":                   "yao miao",
                "type":                 "��",
                "reward":               200,
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


