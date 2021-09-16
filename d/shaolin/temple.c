// Room: /wiz/uudd/path2/temple.c

inherit ROOM;

void create()
{
	set("short", "龙王庙");
	set("long", @LONG
这是一座一般小村庄里常见能见到的小庙，不时有一两个村
民进来上香，保佑他们能有个好收成，看到他们虔诚的样子，你
不禁觉得有些好笑。但你不禁又想：“龙王呀！如果你真存在的
话就保佑他们吧！”
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s12",
]));

	setup();
	replace_program(ROOM);
}
