// Room: /d/tangmen/ssl4.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ������ʵ���ʯ���̳ɵ�С·�����Ķ������죬·��
��������۲ݣ�·�����Ը���һ��С��̳�����濪�������Ļ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jiaomen",
  "west" : __DIR__"ssl3",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
