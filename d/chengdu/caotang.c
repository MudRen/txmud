// Room: /wiz/louth/c/caotang.c

inherit ROOM;

void create()
{
	set("short", "杜甫草堂");
	set("long", @LONG
这里是位于成都西郊浣花溪畔的杜甫草堂，是唐代伟大诗人
杜甫流寓时的故居，杜甫在此居住的四年里，伤时感事，写下了
二百四十余首现实主义诗作。后人景仰先贤，便在草堂遗址建立
祠宇，供人凭吊。由西边可以来到武王道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao5",
]));

	setup();
	replace_program(ROOM);
}
