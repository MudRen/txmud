// Room: /d/path3/k_s1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
�����ǿ����������Ĵ�·��·�����߽�������������˷���
һЩС��������ȥ����Ϸˣ�����治Զ���ǿ�����ˣ�����һֱ
ͨ��פ��ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s2",
  "north" : "/d/kaifeng/out_kaifeng_s",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
