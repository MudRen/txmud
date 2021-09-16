// Room: /d/shaolin/shandao1.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条宽阔的山路，往上看少林寺已经隐约在望，宽大的
石阶上面就是少林寺高大的山门，门口人来人往，隐约还能听到
低沉的诵经声，不时传来声声洪亮的钟声。
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shandao2",
  "northeast" : __DIR__"taijie3",
]));

	setup();
	replace_program(ROOM);
}
