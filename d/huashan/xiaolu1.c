// Room: /d/huashan/xiaolu1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
��ɽ��������������������Ȼ�����鴫�������ɽ��ֱ�ζ�
��ɽ�����ɴ�أ�ʱ���뵵���������ɽ����ɽ·ʱ��ʱ�֡�
����������һ����˸ߵ�ʯ�� (bei)�������ּ����Ӷ��پ���һ
��ɽ����������ʧ��ɽ��䣬ɽ����������ɢ������С������
̯����
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"xiaolu2",
  "southdown" : "/d/huayin/tl9",
]));

                set("item_desc", ([ /* sizeof() == 1 */
                "bei" : HIR"
                �� ɽ �� ��\n\n"NOR,
        ]));

	set("objects",([
	__DIR__"npc/fengnong" : 1,
	__DIR__"npc/tiaofu" : 1,
]));
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}
