// Room: /d/path5/ccg30.c

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
  "west" : __DIR__"ccg31",
  "eastup" : __DIR__"ccg29",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
