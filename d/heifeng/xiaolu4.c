// Room: /d/heifeng/xiaolu4.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
�����Ǻڷ�կ�����һ��С·�����ܾ����ĵ��ƺ��������
��������·��������Ұ�ݡ�ż��������һ����կ����Ҳ�ǴҴ�æ
æ��·����
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lin4",
  "south" : __DIR__"xiaolu3",
  "east" : __DIR__"lin5",
  "north" : __DIR__"houshan",
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}
