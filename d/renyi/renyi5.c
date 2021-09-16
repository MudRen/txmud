// Room: /d/renyi/renyi5.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条静静的小土路一直向南延伸，两旁是茂密的竹子，
北面不远隐隐能看到一扇高大的竹门。
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"renyi4",
  "southwest" : __DIR__"renyi6",
]));

	set("outdoors", "renyi");

	setup();
	replace_program(ROOM);
}
