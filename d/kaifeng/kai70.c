// Room: /u/w/wangs/b/kai70.c

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这儿是一家小小的书院，供附近的孩子们求学。书院建在这
条繁华的商业街上似乎不太协条，不过据说这片宅子是一位倒霉
的秀才的，他连续三年赶考全都落第，他一气之下，就开了这家
书局，发誓要将他的学生个个都培养成状元。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai68",
]));

	setup();
	replace_program(ROOM);
}
