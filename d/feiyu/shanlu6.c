// Room: /wiz/louth/a/shanlu6.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ����֪����ɽ·�������ǱȽ�ƫԶ��ԭ��ɣ����Ǿ�
�ס�������һ��ʮ���ưܵ�С��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shanlu8",
  "north" : __DIR__"shanlu7",
  "west" : __DIR__"shanlu5",
]));

	setup();
	replace_program(ROOM);
}
