// Room: /wiz/louth/c/wmlu2.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���ǳɶ����������·��������һ��С��ݣ��ɶ����ݲ��
������������춼�˿�ӯ�š�����һֱ����һ��Ƨ����С�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"chaguan",
  "west" : __DIR__"wmlu3",
  "east" : __DIR__"wmlu1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
