// Room: /d/hangzhou/paths1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你正站在西湖南岸的一条小路上，从这里看过去，西湖是一
望无际的荷花塘，微风吹过，万朵荷花竞相展媚，采莲的小舟在
湖中传行，不时可以听见采莲姑娘快乐的歌声。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"stoneroad4",
  "east" : __DIR__"paths2",
]));

	setup();
	replace_program(ROOM);
}
