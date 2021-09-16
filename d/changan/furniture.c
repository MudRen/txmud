// Room: /d/changan/furniture.c

inherit ROOM;

void create()
{
	set("short", "廉德家私城");
	set("long", @LONG
这是一间宽敞的大厅，里面摆放着各式各样的家具。显得有
一些杂乱，仔细望去里面的每件家具都各具特色，令人目不暇及，
门边挂着一块木牌子(sign)。
LONG
	);

	set(SAFE_ENV,1);
	set("item_desc",([
	"sign" : "本号专营各式家具，你可以 list 得到所售家具的清单，
买(buy)家具之前请您仔细察看(chakan)，本号商品一经
售出概不退换。
",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wroad7",
]));

	set("objects",([
	__DIR__"npc/f_seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
