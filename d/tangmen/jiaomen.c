// Room: /d/tangmen/jiaomen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������Ƽұ���һ������ţ����Ϲ���һ�Ѵ���������ܾ�
û�п����������ӣ������Ӻ������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ssl4",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
