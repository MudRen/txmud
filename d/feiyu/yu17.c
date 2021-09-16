// Room: /u/w/wangs/a/yu17.c

inherit __DIR__"patroling";

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小径上，两旁种满了松柏，四季常青，绿荫
满地，除了松涛声和鸟鸣声，听不到别的动静。西边是绯雨
阁的厨房，阵阵饭菜的香气从那里飘了出来。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"yu19",
  "west" : __DIR__"yu18",
  "northeast" : __DIR__"yu16",
]));
       set("outdoors","feiyu");

	setup();
}
