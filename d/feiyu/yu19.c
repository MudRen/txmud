// Room: /u/w/wangs/a/yu19.c

inherit __DIR__"patroling";

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小径上，两旁种满了松柏，四季常青，绿荫
满地，除了松涛声和鸟鸣声，听不到别的动静。西南方是一
间禁闭室。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu20",
  "northeast" : __DIR__"yu17",
	"west" : __DIR__"yaofang",
]));
       set("outdoors","feiyu");

	setup();
}
