// Room: /d/path3/k_h39.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条用青石铺成的官道，道路上人来人往，显得十分热
闹。路的两边有不少的摊贩，看到你走来，热情的叫卖着，还不
时向你挥着手指指点点，像是在叫你过去看看。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h40",
  "north" : __DIR__"k_h38",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
