// Room: /wiz/uudd/path2/k_s24.c

inherit ROOM;

void create()
{
	set("short", "¿ÕµØ");
	set("long", @LONG
ÕâÀïÊÇÒ»Æ¬¿ÕµØ£¬¿´ÆğÀ´ÕâÀïÊÇÏÄÌì³ËÁ¹µÄºÃÈ¥´¦£¬¹ıÁË
ÕâÀï¾ÍÊÇÒ»¶ÎÍÁÂ·ÁË¡£Äã¼Ó¿ìÁË½Å²½¡££
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/shaolin/tulu3",
  "southeast" : __DIR__"k_s23",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
