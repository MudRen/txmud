// Room: /d/shaolin/yongdao3.c

inherit ROOM;

void create()
{
	set("short", "青石甬道");
	set("long", @LONG
这里是少林寺的一条青石甬道，甬道的两边种满了旱柳，即
使是夏日也好不凉爽。不禁你想起那句流传很久的古诗：曲径通
幽处，禅房花木深。从这里向南和向北是青石甬道，向西是戒律
院，向东是藏经阁。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao2",
  "north" : __DIR__"yongdao4",
  "east" : __DIR__"cangjing1",
  "west" : __DIR__"jielv",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
