// Room: /u/w/wangs/b/kai105.c

inherit ROOM;

void create()
{
	set("short", "工地");
	set("long", @LONG
这里就是开封城的工地了。工地上的人来来往往的，异常忙
碌。在这里工作的大多是开封城里的贫苦人家。也有一些从外地
来的人。但他们都有一个共同之处，就是凭他们的汗水来养活自
己和家人。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai103",
  "east" : __DIR__"kai107",
]));
        set("objects",([
        __DIR__"npc/gongtou":1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
