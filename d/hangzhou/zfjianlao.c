// Room: /d/hangzhou/zfjianlao.c

inherit ROOM;

void create()
{
	set("short", "监牢");
	set("long", @LONG
这里是杭州府衙的监牢，这里不仅关押杀人越货的江洋大盗
，不少本地的小混混和交不起赋税的穷人也常常在这里进进出出
。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath2",
]));

	setup();
	replace_program(ROOM);
}
