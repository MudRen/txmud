// Room: /wiz/louth/a/shanlu2.c

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
  "eastdown" : __DIR__"shanlu1",
  "westup" : __DIR__"shanlu3",
]));

	setup();
	replace_program(ROOM);
}
