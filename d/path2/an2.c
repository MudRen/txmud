// Room: /d/path2/an2.c

inherit ROOM;

void create()
{
	set("short", "黄河岸边");
	set("long", @LONG
这里是黄河下游岸边，汹涌的河水不时地拍打着岸边，怒驰
着向前而去，浪花飞溅，水雾迷漫，你被这雄伟的景象惊呆了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ch_k29",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
