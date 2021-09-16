// Room: /u/w/wangs/b/kai48.c

inherit ROOM;

void create()
{
	set("short", "戏院");
	set("long", @LONG
台上几名伶人穿差往来，好不热闹，你留神看了看，原来是
一出“定军山”。台下十余太见方的空地上围满了听戏的群众。
少说也有三五百人，但整个戏院中除了唱戏的外，人群竟没有发
出一点声音，可见大家听得很专心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai47",
]));
        set("objects",([
        __DIR__"npc/ximi":3,
]));

	setup();
	replace_program(ROOM);
}
