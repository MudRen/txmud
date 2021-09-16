// Room: /wiz/find/huapu/huatan.c

inherit ROOM;

void create()
{
	set("short", "花坛");
	set("long", @LONG
这里是一个小小的三层花坛，花坛里的土湿润而松软，看样
子经常有人翻弄，奇怪的是花坛里练颗小草也没有。
LONG
	);

	set("exits",([
	"south" : __DIR__"hua_pu/exit",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
