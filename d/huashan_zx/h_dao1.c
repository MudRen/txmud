// h_dao1.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ǰС·");
        set("long", @LONG
��������ϼ������ǰ��һ��С·��, ·���Կ���һЩ��֪��
�Ļ���, ���Ͽ��Բ�Զ����������һ�Ⱥ�����š����߾�����ϼ
������ǣ���Ҫ�ǰ�ʲô���¿�������ȥ��
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"houmen",
  "northup" : "/d/huashan/qitu3",
]));

        set("outdoors", "huashan_zx");

	setup();
        create_door("south", "�������", "north", DOOR_CLOSED);
}
