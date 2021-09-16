#include <room.h>
inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这是一所小院，两旁生满了乔木，除了鸟鸣声，听不到
别的动静。北面似乎有一扇小门，在林木的掩映下若隐若现。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu103",
  "west" : __DIR__"yu101",
]));
        set("objects", ([
        __DIR__"npc/shibi3" : 1,
        __DIR__"npc/shibi4" : 1,
                        ]) );
       set("outdoors","feiyu");

	setup();
       create_door("north", "木门", "south", DOOR_CLOSED);
}
