// Room: /d/shaolin/shandao2.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条宽阔的山路，山路右面是陡峭的山崖，左面是一望
无际的树林。路上经常能看到几个僧人来来往往，向上一直走就
是著名的少林寺了，隐约还能听到低沉的诵经声。
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandao3",
  "northeast" : __DIR__"shandao1",
]));

	set("objects",([
	__DIR__"npc/butterfly" : 1,
]));
	setup();
	replace_program(ROOM);
}
