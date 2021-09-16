// Room: /u/w/wangs/b/kai145.c

inherit ROOM;

void create()
{
	set("short", "有缘客栈");
	set("long", @LONG
有缘客栈是开封城里最大的，最昂贵的客栈，也是花钱的客
栈。你若住在这客栈里，只要你有足够的钱，根本用不着走出客
栈的门，就可以获得一切最好的享受。在这里、只要你开口，就
有人会将开封城里最好的菜，最出名的歌妓，最美的女人送到你
屋里来。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai144",
]));

	setup();
	replace_program(ROOM);
}
