// Room: /u/w/wangs/a/yu16.c

inherit __DIR__"patroling";

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小径上，两旁种满了松柏，四季常青，绿荫
满地，除了松涛声和鸟鸣声，听不到别的动静。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"yu17",
	"east" : __DIR__"yu15",
	"north" : __DIR__"chitang"
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/zhenhuimin" : 1,
]));
       set("outdoors","feiyu");

	setup();
}
