// Room: /d/path3/k_s2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ǿ����������Ĵ�·��·�����߽�������������˷���
һЩС��������ȥ����Ϸˣ�����治Զ���ǿ�����ˣ�����һֱ
ͨ��פ��ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s3",
  "north" : __DIR__"k_s1",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}