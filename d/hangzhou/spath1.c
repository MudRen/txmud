// Room: /d/hangzhou/spath1.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
һ������������������ȥ��������Ǻ��ݳǵ����š�·��
���������˺����ú����������������ĳ�����ʱ����������
�㲻�ò����Ա����㡣·�������ǴԴԵ����֣��ּ�С·������
�䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"stree1",
  "south" : __DIR__"spath2",
  "east" : __DIR__"stree3",
  "north" : __DIR__"out_hangzhou_s",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
