// Room: /d/huashan/ciyang.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��СС�ķ��䣬������ʰ�ĺ������룬һ��Сͯż
����������������ɵ�����ļ��¡����ǲ�֪��ô�أ���������
������е㲻�Ծ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zigongroom",
  "east":__DIR__"w_daoguan",
]));
        set("indoors", "huashan");
        set("item_desc", (["door": (: look_door, "east" :),
        ]) );

        //set("objects", ([__DIR__"npc/lm_guard": 2 ]) );

        create_door("east","����������","west",DOOR_CLOSED);

        setup();
	replace_program(ROOM);
}
