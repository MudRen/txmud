// Room: /d/path5/ccg36.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ·");
	set("long", @LONG
���ߵ�һ����ԭɽ·�ϣ�����һ���޼ʡ������������Ʈ��
�����ƣ�ż���в�ӥ��ͷ���������㾯��ؿ��˿���ȴʲ
ôҲû�з��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ccg35",
  "westdown" : __DIR__"ccg37",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
