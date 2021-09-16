// Room: /d/huashan/w_daoguan.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "西道观");
	set("long", @LONG
据说处虚道长曾在此练丹试术。他总结的内丹道法，成为宋
以后道教修技方法的主流，在当时和后世的影响都很大。不少人
都想找到处虚道长留下的“陈丹秘法”，但均未成功。向西是一
个退休的老太监住的辞阳馆。
LONG
	);

	set("NONPC", 1);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xianguan",
  "west":__DIR__"ciyang",
]));
        set("outdoors", "huashan");
                set("item_desc", (["door": (: look_door, "west" :),
        ]) );

        //set("objects", ([__DIR__"npc/lm_guard": 2 ]) );

        create_door("west","内厅垂花门","east",DOOR_CLOSED);

        setup();

        setup();
	replace_program(ROOM);
}
