// Room: /d/path5/ccg31.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ·");
	set("long", @LONG
���ߵ�һ����ԭɽ·�ϣ�����һ���޼ʡ������������Ʈ��
�����ƣ�ż���в�ӥ��ͷ���������㾯��ؿ��˿���ֻ��
����һ�龲�ţ�������һ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ccg30",
  "northwest" : __DIR__"ccg32",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
