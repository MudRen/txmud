// Room: /d/jinghai/wm1.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
        set("short", "����������ͷ");
        set("long", @LONG
�˴�����һ����ͷ�������ˮ��ǳ����������ͷ�������н�
��ĵط�бб������һ��ջ�ţ�ջ�ž�ͷ�������ͣ����һ��С
������ͷ�ߵĸ��������϶���һ��ľ�壬����д�ţ���������ר
����ͷ������Ҫ�ɺ��������Ұ�(yell)��
LONG
        );
        set("outdoors", "jinghai");
        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"wm11",
]));
        set("item_desc", ([
                "sea" : "��������ͣ��һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
]));


        set_boat_file(__DIR__"duw_t");
        set_max_passenger(6);
        set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫȥ�һ���������\n");

        set("outdoors", "jinghai");
        setup();
}

// �����������ʹ�������˲���Ǯ
protected int valid_passenger(object who)
{
        if(who->query("class") == "jinghai")
        {
                who->set_temp("payed_duchuan", 1);
                return 1;
        }

        else return ::valid_passenger(who);
}
