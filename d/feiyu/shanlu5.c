// Room: /wiz/louth/a/shanlu5.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ��һ��������С·������ɽ�������������Զ������
����֪��ͨ��ʲô�ط���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shanlu6",
  "northup" : __DIR__"shan1",
  "westdown" : __DIR__"shanlu4",
]));

	setup();
	replace_program(ROOM);
}
