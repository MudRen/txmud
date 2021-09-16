// Room: /d/hangzhou/paths2.c

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

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"paths1",
]));

	set("objects",([
	__DIR__"npc/shusheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
