// Room: /d/tangmen/keting.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����Ĵ����������ô���ʯ�̾͵ĵ��汻��ĥ����
����һ���⻬�����е�����̨���ϰڷ���һ����ľ��̫ʦ�Σ���
�ӵĳ����������ǳ滢�����ǳ����ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fyuan",
]));

	set("objects", ([
	__DIR__"npc/guanjia" : 1,
]));

	setup();
	replace_program(ROOM);
}
