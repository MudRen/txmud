// Room: /d/path5/ccg37.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ·");
	set("long", @LONG
���ߵ�һ����ԭɽ·�ϣ�����һ���޼ʡ������������Ʈ��
�����ƣ�ż���в�ӥ��ͷ���������㾯��ؿ��˿���ȴʲ
ôҲû�з��֡�������Լ��һ�����䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  //"west" : "/d/linzhi/linzhie",
  "eastup" : __DIR__"ccg36",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);

	setup();
	replace_program(ROOM);
}
