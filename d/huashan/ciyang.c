// Room: /d/huashan/ciyang.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "辞阳观");
	set("long", @LONG
这里是一个小小的房间，内外收拾的很是整齐，一个小童偶
尔在这里出出进进干点琐碎的家事。但是不知怎么地，总让你心
里觉得有点不对劲。
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

        create_door("east","内厅垂花门","west",DOOR_CLOSED);

        setup();
	replace_program(ROOM);
}
