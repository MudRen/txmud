// qlist4.c : quest list 4
#include <ansi.h>

// �� qlist1 �� qlist4 ����������� 500,000 exp Ϊ��λ������ 2M exp ��Ϊ 3��4 ��
// ���������ʽ�������������Ʒ��ֻҪ����Ϸ���еļ��ɣ������Ǽ� ansi ��ɫ
mapping *quest_list = ({
        ([      "name":                 WHT"ʯ��"NOR,
                "id":                   "stone sword",
                "type":                 "��",
                "reward":               4000,   // ��߽���exp��Ǳ�������25%
        ]),
        ([      "name":                 "ţƤ��",
                "id":                   "armor",
                "type":                 "��",
                "reward":               2000,
        ]),
        ([      "name":                 MAG"��ϼ����"NOR,
                "id":                   "zixia yupei",
                "type":                 "��",
                "reward":               3200,
        ]),
        ([      "name":                 "��ǹ",
                "id":                   "spear",
                "type":                 "��",
                "reward":               1500,
        ]),
        ([      "name":                 "�ֽ��ͭ��",
                "id":                   "copper hammer",
                "type":                 "��",
                "reward":               2500,
        ]),
        ([      "name":                 HIC"�ϳ�����"NOR,
                "id":                   "duanchang dan",
                "type":                 "��",
                "reward":               6000,
        ]),
        ([      "name":                 HIY"�Ƴ���"NOR,
                "id":                   "zishou yi",
                "type":                 "��",
                "reward":               2200,
        ]),
        ([      "name":                 HIM"�ϳ���"NOR,
                "id":                   "zichou yi",
                "type":                 "��",
                "reward":               2200,
        ]),
        ([      "name":                 HIB"������"NOR,
                "id":                   "zishou yi",
                "type":                 "��",
                "reward":               2200,
        ]),
        ([      "name":                 HIM"������"NOR,
                "id":                   "ziqing sword",
                "type":                 "��",
                "reward":               4500,
        ]),
        ([      "name":                 HIW"��ѩ����"NOR,
                "id":                   "bingxue hanshan",
                "type":                 "��",
                "reward":               3300,
        ]),
        ([      "name":                 "��Ȫ����",
                "id":                   "longquan sword",
                "type":                 "��",
                "reward":               1600,
        ]),
        ([      "name":                 "��ͭԿ��",
                "id":                   "red copper key",
                "type":                 "��",
                "reward":               1800,
        ]),
        ([      "name":                 "��ɽ��",
                "id":                   "shan tao",
                "type":                 "��",
                "reward":               3500,
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

