// Room: /wiz/louth/a/shanlu3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ��һ��������С·������ɽ�������������Զ������
����֪��ͨ��ʲô�ط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"shanlu2",
  "northup" : __DIR__"shanlu4",
]));

	setup();
	replace_program(ROOM);
}
