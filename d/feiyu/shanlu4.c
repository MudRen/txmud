// Room: /wiz/louth/a/shanlu4.c

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
  "eastup" : __DIR__"shanlu5",
  "southdown" : __DIR__"shanlu3",
]));

	setup();
	replace_program(ROOM);
}
