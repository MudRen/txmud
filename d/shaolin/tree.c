// Room: /wiz/uudd/path2/tree.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ﻷ�����ܣ��ۼ�����һƬ������������ʱ��һ
ЩС����һ������������һƬ�̲����ͣ��㲻����������һ�ڴ�
��Ȼ�Ŀ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s14",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
