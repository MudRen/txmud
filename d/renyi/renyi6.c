// Room: /d/renyi/renyi6.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条静静的小土路一直向北延伸，两旁是茂密的竹子，
北面远处隐隐能看到一扇高大的竹门。
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"renyi5",
  "southwest" : "/d/path7/lu6",
]));

	set("outdoors", "renyi");

	setup();
	replace_program(ROOM);
}
