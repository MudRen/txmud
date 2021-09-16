// Room: /d/shaolin/e_pei.c

inherit ROOM;

void create()
{
	set("short", "右配殿");
	set("long", @LONG
这里是少林寺的右配殿，供奉着的是药师光王佛，是东方琉
璃世界的主宰之佛，左右是药师菩萨和镜心菩萨二胁侍。四下是
一些东方世界菩萨的圣像。大殿里高大空旷，十分的壮观。从这
向西是大雄宝殿。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baodian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
