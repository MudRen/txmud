
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "破院");
        set("long", @LONG
这是个破旧大院,听说以前是个大富人家的宅子,可是后来主人
突然间就消失了,再也没有出现过,仆人都散光了,慢慢地房子就破旧了,
据说主人消失当日有个浑身破旧的乞丐曾在这里乞讨过,主人还请他
一起吃过饭,这也是传闻罢了.
LONG
        );

	set("exits", ([
               "west"            : __DIR__"road2",
               "east"             : __DIR__"road1",
]) );


	set("objects",([
//:    NPC_DIR"stdnpc/stdnpc_1" : 4,
]));

        create_door("east", "破门", "west", DOOR_CLOSED);

         setup();
}
