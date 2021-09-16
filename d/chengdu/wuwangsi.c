// Room: /wiz/louth/c/wuwangsi.c

inherit ROOM;

void create()
{
	set("short", "武王祠");
	set("long", @LONG
这里就是为了纪念三国时蜀汉丞相候诸葛亮而修建的武候祠。
始建于西晋末年，祠内翠柏森森，殿宇重重，布局严谨，庄严肃
穆。祠中以岳飞手书的诸葛亮《出师表》和文、书、刻号称“三
绝的《汉丞相诸葛武候祠堂碑》最为知名。从西面出来就是成都
武侯道。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao3",
]));

	setup();
	replace_program(ROOM);
}
